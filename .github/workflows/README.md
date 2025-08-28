# GitHub Actions Workflows

This directory contains organized GitHub Actions workflows for the PersonalDevControl project.

## Workflow Overview

### 🔨 [build-and-test.yml](.github/workflows/build-and-test.yml)
**Main CI/CD Pipeline**
- **Triggers**: Push/PR to main/develop branches, releases
- **Jobs**:
  - `build-windows`: Builds on Windows with Visual Studio (Debug/Release)
  - `build-linux`: Builds on Linux with CMake
  - `code-quality`: Runs cppcheck for static analysis
  - `create-release`: Creates release artifacts for published releases

**Features**:
- Multi-platform builds (Windows/Linux)
- Qt 6.6.3 installation and configuration
- Dependency management (libcurl via vcpkg)
- Automated release artifact creation
- Build artifact uploads

### 🔍 [dependency-check.yml](.github/workflows/dependency-check.yml)
**Security and Dependency Monitoring**
- **Triggers**: Weekly schedule (Sundays), manual dispatch
- **Jobs**:
  - `security-scan`: Trivy vulnerability scanning
  - `license-check`: License compatibility verification

**Features**:
- SARIF upload to GitHub Security tab
- License compatibility reporting
- Weekly automated security scans

### 🎨 [code-style.yml](.github/workflows/code-style.yml)
**Code Quality and Formatting**
- **Triggers**: Push/PR to main/develop branches
- **Jobs**:
  - `format-check`: clang-format validation
  - `static-analysis`: cppcheck static analysis

**Features**:
- Automated code formatting validation
- Configurable clang-format rules (Google style based)
- Static analysis with cppcheck
- Formatting suggestions in PR comments

### 📚 [documentation.yml](.github/workflows/documentation.yml)
**Documentation Validation**
- **Triggers**: Push/PR affecting markdown files
- **Jobs**:
  - `validate-docs`: Markdown linting and validation
  - `suggest-docs`: Documentation improvement suggestions

**Features**:
- Markdown linting with markdownlint
- Documentation completeness checking
- Automated suggestions for missing documentation

## Configuration Details

### Dependencies
- **Qt**: 6.6.3 with qtbase and qtwidgets modules
- **Build Tools**: MSBuild (Windows), CMake (Linux)
- **Libraries**: libcurl for HTTP/MongoDB connectivity
- **Package Manager**: vcpkg for Windows dependencies

### Supported Platforms
- **Windows**: Latest with MSVC 2019/2022
- **Linux**: Ubuntu Latest with GCC

### Build Configurations
- **Windows**: Debug and Release configurations
- **Linux**: Release configuration with CMake

## Usage

### For Developers

1. **Local Development**: 
   - Follow the build instructions from the main workflow
   - Use clang-format for code formatting: `find . -name "*.cpp" -o -name "*.h" | grep -v ui_ | xargs clang-format -i`

2. **Pull Requests**:
   - All workflows run automatically on PR creation
   - Check workflow results before merging
   - Address any formatting or static analysis issues

3. **Releases**:
   - Create a GitHub release to trigger artifact creation
   - Windows and Linux binaries will be automatically attached

### For Maintainers

1. **Workflow Updates**:
   - Modify individual workflow files as needed
   - Test changes in feature branches first
   - Keep documentation updated

2. **Security**:
   - Review weekly security scan results
   - Update dependencies when vulnerabilities are found
   - Monitor license compatibility

## Troubleshooting

### Common Issues

1. **Qt Installation Failures**:
   - Check Qt version compatibility
   - Verify module availability
   - Update jurplel/install-qt-action if needed

2. **vcpkg Dependency Issues**:
   - Update vcpkg commit hash in workflow
   - Check package availability for target platform
   - Verify vcpkg integration

3. **Build Failures**:
   - Check MSBuild/CMake configuration
   - Verify all source files are included
   - Check for missing dependencies

### Getting Help

1. Check workflow run logs for detailed error messages
2. Review this documentation for configuration details
3. Check individual workflow files for specific requirements
4. Create an issue if workflows need updates

## Maintenance

### Regular Updates Needed
- Qt version updates (quarterly)
- vcpkg commit hash updates (monthly)
- GitHub Actions updates (as needed)
- Security scan tool updates (as needed)

### Monitoring
- Review weekly security scan results
- Monitor build success rates
- Check for deprecated GitHub Actions