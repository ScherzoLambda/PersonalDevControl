# MongoDB DataAPI to mongocxx Migration - Testing Guide

## Overview
This document provides guidance for testing the migrated MongoDB implementation.

## Testing the Migration

### 1. Environment Setup
Set your MongoDB connection string:
```bash
export MONGODB_URI="mongodb+srv://username:password@cluster.mongodb.net/database"
```

### 2. Build and Run
```bash
cd PersonalDevControl
mkdir build && cd build
cmake ..
make -j4
./bin/PersonalDevControl
```

### 3. Testing User Registration
1. Click "Registrar-se" button
2. Fill in user details (nome, email, senha)
3. Click "Registrar"
4. Check console output for MongoDB connection messages

### 4. Testing Login
1. Enter registered email and password
2. Click "Entrar"
3. Application should authenticate via MongoDB

### 5. Testing Data Operations
1. In the main window, operations will use `do_find()` method
2. Check console for "Successfully connected to MongoDB!" message
3. Monitor application behavior for data retrieval

## Expected Behavior Changes

### Success Indicators
- ✅ "Successfully connected to MongoDB!" in console
- ✅ User registration returns success message with MongoDB ObjectId
- ✅ Login authentication works with stored user data
- ✅ No cURL or HTTP-related error messages

### Debug Output
The new implementation includes debug output:
- `Parsed document JSON: {...}` for insert operations
- `Parsed filter JSON: {...}` for find operations

### Error Handling
- MongoDB connection errors are logged to console
- JSON parsing errors are handled gracefully
- Database operation failures return "0" (maintaining compatibility)

## Troubleshooting

### Connection Issues
1. Verify MongoDB URI is correct
2. Check network connectivity to MongoDB cluster
3. Verify database user permissions

### Compilation Issues
1. Ensure mongocxx is installed: `pkg-config --exists libmongocxx`
2. Check CMake finds mongocxx: Look for "Found mongocxx" in cmake output
3. Verify include paths in CMakeLists.txt

### Runtime Issues
1. Check console for connection error messages
2. Verify JSON format in debug output
3. Test with simple operations first

## Migration Verification Checklist
- [ ] Application builds without cURL dependencies
- [ ] MongoDB connection established successfully
- [ ] User registration inserts documents to "users_1" collection
- [ ] Login queries work with stored user credentials
- [ ] Main application data operations function correctly
- [ ] No DataAPI HTTP calls in application behavior