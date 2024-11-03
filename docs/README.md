# Lua Reaper Documentation

Welcome to the documentation for **Lua Reaper**, a C++ utility for dumping Lua scripts as bytecode files. This documentation provides details on setup, configuration, code usage, and troubleshooting for developers who wish to integrate or modify the tool.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Basic Usage](#basic-usage)
- [Configuration](#configuration)
- [Advanced Features](#advanced-features)
- [Code Structure](#code-structure)
- [Troubleshooting](#troubleshooting)
- [FAQs](#faqs)

## Introduction

Lua Reaper is designed to streamline the process of compiling Lua scripts into bytecode format, allowing developers to protect, optimize, and distribute Lua-based projects efficiently. This tool includes modular design, configurable options, and detailed logging for professional use cases.

## Installation

### Requirements

- **C++17** or later
- **CMake 3.15+**
- **Lua 5.x** (included or can be installed separately)
- **nlohmann/json** library for configuration

### Build Instructions

1. Clone the repository:
   ```
   git clone https://github.com/0x0060/LuaReaper.git
   cd LuaReaper
   ```

2. Set up the build environment:
   ```
   mkdir build && cd build
   ```

3. Run CMake:
   ```
   cmake ..
   ```

4. Build the project:
   ```
   make -j4
   ```

5. Run the tests (optional):
   ```
   ctest --output-on-failure
   ```

### Installation Verification

To ensure the installation was successful, try running the tool with:
```
./LuaReaper --help
```
This should display the help information with available commands and options.

## Basic Usage

To dump a Lua script into bytecode:
```
./LuaReaper path/to/your_script.lua
```
This command converts `your_script.lua` into a bytecode file with a `.luac` extension in the configured output directory.

### Example

```
./LuaReaper scripts/example.lua
```

This creates a `example.lua.luac` file in the output directory.

## Configuration

Configuration is managed through the `config/dumper_config.json` file. Below is an example configuration:

```
{
    "log_level": "INFO",
    "output_directory": "./bytecode_output",
    "include_debug_info": false
}
```

### Configuration Options

- **log_level**: Specifies the verbosity of logs. Options include:
  - `INFO`: Standard information
  - `DEBUG`: Detailed debug output
  - `ERROR`: Errors only
- **output_directory**: Sets the folder for storing `.luac` files.
- **include_debug_info**: (Boolean) If `true`, includes debug information in the bytecode output.

## Advanced Features

- **Logging**: Logs are categorized by type (`INFO`, `DEBUG`, `ERROR`, etc.) and include timestamps for precise tracking.
- **Custom Output Directory**: Configure the output directory in `dumper_config.json` for more organized file storage.
- **Debug Information in Bytecode**: Optionally include debug information to assist in debugging Lua bytecode.

## Code Structure

The project is organized into distinct directories for clarity and modularity:

- **src/**: Contains core source code files.
- **include/**: Contains header files.
- **config/**: Holds the configuration files, such as `dumper_config.json`.
- **logs/**: Default directory for output logs.
- **tests/**: Unit tests and example Lua scripts.
- **libs/**: External libraries, including Lua (if bundled) and any others required.

### Key Classes and Files

- `LuaDumper`: Main class handling Lua script loading and bytecode dumping.
- `Logger`: Utility class for logging messages with different severity levels.
- `config/dumper_config.json`: Configuration file controlling runtime settings.

## Troubleshooting

### Common Issues

- **Lua Script Loading Error**:
  - **Cause**: The Lua script may contain syntax errors or the specified path is incorrect.
  - **Solution**: Verify the Lua script path and ensure it is syntactically correct.

- **Output File Not Created**:
  - **Cause**: Insufficient permissions or invalid output directory path.
  - **Solution**: Ensure the specified output directory exists and has write permissions.

- **Lua Library Not Found**:
  - **Cause**: Lua library is not installed or the path is incorrect.
  - **Solution**: Install the Lua library, or adjust the path in your build settings.

## FAQs

- **Can I dump multiple Lua scripts at once?**
  - Not currently, but batch processing could be added in future releases.

- **Does this support LuaJIT?**
  - LuaJIT support has not been fully tested. The tool is designed for standard Lua 5.x.

- **Is there a limit to script size?**
  - No practical limit; however, large scripts may increase memory usage.