# LuaReaper

A high-performance C++ tool to dump Lua scripts into bytecode files (`.luac`). This project allows developers to efficiently convert Lua scripts into bytecode format, useful for distribution, optimization, and security purposes.

## Overview

LuaReaper is designed for developers who work with Lua scripts and need a reliable way to manage bytecode for enhanced performance or source code protection. This tool loads Lua scripts, compiles them into bytecode, and saves the bytecode files to a specified output directory.

## Table of Contents

- [Features](#features)
- [Pros and Cons](#pros-and-cons)
- [Requirements](#requirements)
- [Download and Build](#download-and-build)
- [Usage](#usage)
- [Configuration](#configuration)
- [Testing](#testing)
- [Contributing](#contributing)
- [Contact](#contact)
- [License](#license)

## Features

- **Fast Lua Compilation**: Quickly converts Lua scripts to bytecode format.
- **Configurable Output**: Specify output directories and logging levels for better control.
- **Detailed Logging**: Verbose logging options to debug and monitor operations.
- **Modular Structure**: Organized codebase for easy expansion and maintenance.

## Pros and Cons

### Pros
- Efficient conversion of Lua scripts to bytecode.
- Flexible configuration options.
- Structured logging with different levels for better control.
- High modularity for maintainable code.

### Cons
- Requires Lua library as a dependency.
- No GUI; command-line only.
- Limited to Lua 5.x versions (compatibility with Lua 5.x).

## Requirements

- **C++17** or later
- **CMake 3.15+** for building
- **Lua 5.x** library (included in the `libs/` folder or installed separately)
- **nlohmann/json** library for configuration management (if not installed, download from [https://github.com/nlohmann/json](https://github.com/nlohmann/json))

## Download and Build

1. Clone the repository:
```
git clone https://github.com/0x0060/LuaReaper.git
cd LuaReaper
```

2. Set up the build environment:
```
mkdir build && cd build
```

3. Run CMake to configure the project:
```
cmake ..
```

4. Build the project:
```
make -j4
```

## Usage

To dump a Lua script as bytecode, use:

```
./LuaReaper path/to/script.lua
```

By default, bytecode files will be saved in the output directory specified in `config/dumper_config.json`.

Example usage:

```
./LuaReaper examples/hello.lua
```

## Configuration

The `dumper_config.json` file in the `config/` folder allows you to adjust the settings for the project.

```json
{
    "log_level": "INFO",
    "output_directory": "./bytecode_output"
}
```

### Configuration Options

- **log_level**: Adjusts logging verbosity. Options include `INFO`, `DEBUG`, `ERROR`, etc.
- **output_directory**: Specifies the folder where bytecode files will be saved.

## Testing

Unit tests are provided in the `tests/` folder using the Catch2 framework.

### Running Tests

1. Build the tests:
```
cd build
make RunTests
```

2. Run the tests:
```
ctest --output-on-failure
```

## Contributing

We welcome contributions from the community! To contribute to this project, please follow these steps:

1.  **Fork the repository**.
2.  **Create a new branch** for your feature or bug fix.
3.  **Make your changes** and commit them.
4.  **Push your branch** to your forked repository.
5.  **Create a pull request**.


## Contact

If you have any questions or feedback, feel free to reach out:

- [0x0060](https://0x0060.dev)
- [Email](mailto:ren@0x0060.dev)


## License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/0x0060/LuaReaper/blob/main/LICENSE) file for more information.
