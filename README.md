# C++ Problems

This repository contains implementations of various C++ problems and projects. Each problem or project is organized into its own folder for clarity and ease of navigation.

## Projects

### Task Manager

The Task Manager project provides functionality to manage processes on different operating systems. It includes classes for Process and ProcessList, demonstrating basic operations like adding processes, sorting, and retrieving process information.

#### Files:
- `Task Manager/`
  - `CMakeLists.txt`
  - `cmake-build-debug/`
  - `Task Manager.cpp`

#### Usage:
To compile and run the Task Manager program, follow these steps:
1. Navigate to the `Task Manager/` directory.
2. Use CMake to generate build files:
     ```bash
     cmake .
     ```
3. Build the executable:
     ```bash
     make
     ```
4. Run the program:
     ```bash
     ./TaskManager
     ```
5. Follow the on-screen instructions to interact with the Task Manager.

### Document Similarity

The Document Similarity project calculates the similarity between two sets of words extracted from text files. It utilizes set operations to find the union, intersection, and similarity coefficient between sets of strings.

#### Files:
- `Document Similarity/`
- `CMakeLists.txt`
- `cmake-build-debug/`
- `Document Similarity.cpp`
- `text.txt` (example input file)

#### Usage:
To compile and run the Document Similarity program, follow these steps:
1. Navigate to the `Document Similarity/` directory.
2. Use CMake to generate build files:
     ```bash
     cmake .
     ```
3. Build the executable:
     ```bash
     make
     ```
4. Run the program:
     ```bash
     ./DocumentSimilarity
     ```
5. Follow the on-screen instructions to interact with the Task Manager.

## Future Additions

Additional folders and projects will be added soon to address more C++ problems and exercises.

## Contributing

Contributions to enhance existing projects or add new ones are welcome! Fork the repository, make your changes, and submit a pull request.
