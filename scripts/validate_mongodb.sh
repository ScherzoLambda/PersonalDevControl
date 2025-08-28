#!/bin/bash
# MongoDB Connection Validation Script
# This script helps validate the MongoDB setup for PersonalDevControl

echo "=== MongoDB Connection Validation ==="

# Check if mongocxx is installed
echo "1. Checking mongocxx installation..."
if pkg-config --exists libmongocxx; then
    echo "✅ mongocxx is installed"
    pkg-config --modversion libmongocxx
else
    echo "❌ mongocxx is not found. Please install it first."
    exit 1
fi

# Check if environment variable is set
echo "2. Checking MongoDB URI configuration..."
if [ -n "$MONGODB_URI" ]; then
    echo "✅ MONGODB_URI environment variable is set"
    # Hide password for security
    echo "   URI: $(echo $MONGODB_URI | sed 's/:.*@/:****@/')"
else
    echo "⚠️  MONGODB_URI not set. Using default development configuration."
fi

# Check if project builds
echo "3. Testing project build..."
cd "$(dirname "$0")/.."
if [ ! -d "build" ]; then
    mkdir build
fi

cd build
if cmake .. > /dev/null 2>&1; then
    echo "✅ CMake configuration successful"
    if make -j4 > /dev/null 2>&1; then
        echo "✅ Project builds successfully"
    else
        echo "❌ Build failed. Check dependencies."
        exit 1
    fi
else
    echo "❌ CMake configuration failed"
    exit 1
fi

echo ""
echo "=== Validation Complete ==="
echo "Your MongoDB migration setup appears to be working correctly!"
echo ""
echo "To test the application:"
echo "1. Set MONGODB_URI environment variable with your MongoDB connection string"
echo "2. Run: ./bin/PersonalDevControl"
echo "3. Check console output for 'Successfully connected to MongoDB!'"