# Algorithms-C

A comprehensive C data structures and algorithms library designed for learning and implementing common data structures and algorithms.

## Project Structure

```
algorithms-c/
├── CMakeLists.txt            # Main CMake configuration file
├── include/                  # Header files
│   ├── data_structures.h     # Common header for all data structures
│   └── linked_list.h         # Linked list header
├── src/                      # Source files
│   ├── data_structures/      # Data structure implementations
│   │   └── linked_list.c     # Linked list implementation
│   └── algorithms/           # Algorithm implementations (to be added)
├── examples/                 # Example usage of the library
│   └── linked_list_example.c # Example using the linked list
└── tests/                    # Test files
    └── test_linked_list.c    # Tests for the linked list
```

## Getting Started

### Prerequisites

- CMake (version 3.10 or higher)
- C compiler (GCC, Clang, etc.)
- JetBrains CLion (recommended for development)

### Building the Project

#### Using CMake Command Line

```bash
# Create a build directory
mkdir -p build && cd build

# Configure the project
cmake ..

# Build the project
cmake --build .
```

#### Using CLion

1. Open the project directory in CLion
2. CLion should automatically detect the CMakeLists.txt file and configure the project
3. Click the build button or press Ctrl+F9 (Cmd+F9 on macOS) to build the project

### Running Examples

After building the project, you can run the examples:

```bash
# From the build directory
./linked_list_example
```

### Running Tests

```bash
# From the build directory
./test_linked_list

# Or run all tests
ctest
```

## Adding New Data Structures

To add a new data structure:

1. Create a header file in the `include/` directory (e.g., `include/stack.h`)
2. Implement the data structure in `src/data_structures/` (e.g., `src/data_structures/stack.c`)
3. Include the header in `include/data_structures.h`
4. Add the source file to the `SOURCES` list in `CMakeLists.txt`
5. Create examples and tests as needed

## Adding New Algorithms

To add a new algorithm:

1. Implement the algorithm in `src/algorithms/` (e.g., `src/algorithms/sorting.c`)
2. Create a corresponding header file in `include/` if necessary
3. Add the source file to the `SOURCES` list in `CMakeLists.txt`
4. Create examples and tests as needed

## CLion Integration

This project is optimized for development in CLion:

1. CMake integration for easy building and running
2. Integrated debugging with built-in GDB/LLDB
3. Code navigation and refactoring
4. Run/debug configurations for examples and tests

To open the project in CLion:

1. Launch CLion
2. Select "Open" and navigate to the project directory
3. CLion will automatically configure the project based on the CMakeLists.txt file

## License

This project is open source and available under the MIT License.
