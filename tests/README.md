# Tests

This directory contains unit tests and integration tests for the PersonalDevControl application.

## Test Framework

The project will use Qt Test framework for testing Qt-specific functionality and Google Test for general C++ unit tests.

## Test Structure

```
tests/
├── unit/              # Unit tests for individual classes
│   ├── core/         # Tests for core functionality
│   ├── models/       # Tests for data models
│   └── utils/        # Tests for utility classes
├── integration/       # Integration tests
└── fixtures/         # Test data and fixtures
```

## Running Tests

```bash
cd build
cmake .. -DBUILD_TESTING=ON
make
ctest
```

## Test Guidelines

- Each source file should have a corresponding test file
- Tests should be independent and repeatable
- Use descriptive test names that explain what is being tested
- Mock external dependencies (MongoDB API, file system, etc.)