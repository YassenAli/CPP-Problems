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

### Add spaces to string

Contains `dictionary.txt` to check the word in it or no.
`main.cpp` check the word in dictionary.txt or no.
`Add spaces to string.cpp` check the word in very little dictinary using unordered set dictionary.

### converts date format

converts dates from numerical month/day format to alphabetic month/day


### Drawing House

If you select the paint bucket and click inside the door, the drawing program fills the area bounded by the door frame. If you instead click somewhere on the front wall of the house, the program fills the entire wall space except for the windows and doors.
In order to understand how this process works, it is important to understand that the screen of the computer is broken down into an array of tiny dots called pixels. On a monochrome display, pixels can be either white or black. The paint-fill operation consists of painting black the starting pixel (i.e., the pixel you click while using the paint-bucket tool) along with any pixels connected to that starting point by an unbroken chain of white pixels.

### Maze

returns all possible solutions and returns the shortest path.

### Nim Game

`Variant1.cpp`: The player whose pile contains an even number of coins after the last one is taken wins the game.
`Variant2.cpp`: Each player takes 1, 2 or 3 coins from any pile he likes. The player that takes the last coin loses.
`Nim Game by Minimax.cpp`: Nim Game by Minimax.

### Rockets Game

played on a board of size n, assume 5. Each player starts with n – 2 rockets, one player has rockets in the left side facing right and one player has rockets on the top side facing down. Rockets can ONLY move forward.

### Stack

create a template stack class with methods of stack.

### Traffic lights

an exhaustive recursion algorithm that generates all possible combinations of traffic lights that the person may meet while he walk through.

### wildcard matching

The problem involves implementing a function bool wildcardMatch(string filename, string pattern) that determines if a given filename matches a specified wildcard pattern. 
Wildcard patterns use special characters like ? to match any single character and * to match any sequence of characters. 
The function should return true if the filename matches the pattern according to these rules, and false otherwise. 
Examples include wildcardMatch("US.txt", "*.*") returning true and wildcardMatch("test.cpp", "test.?") returning false.

## Future Additions

Additional folders and projects will be added soon to address more C++ problems and exercises.

## Contributing

Contributions to enhance existing projects or add new ones are welcome! Fork the repository, make your changes, and submit a pull request.
