# Design Patterns in C++ Repository

This repository contains a collection of design patterns implemented in C++. Each design pattern is organized in a separate folder, including a UML diagram for better visualization and one or more C++ files that demonstrate the pattern's usage. The repository aims to provide practical examples of design patterns and promote best practices in software design.

## Table of Contents

- [Design Patterns Included](#design-patterns-included)
- [Usage](#usage)
- [Prerequisites](#prerequisites)
- [How to Compile and Run](#how-to-compile-and-run)
- [Viewing UML Diagrams](#viewing-uml-diagrams)
- [Contributing](#contributing)

## Design Patterns Included

1. **Singleton Pattern**: [Folder](./Singleton)
   - Demonstrates the Singleton design pattern, ensuring a class has only one instance.

2. **Factory Pattern**: [Folder](./Factory)
   - Illustrates the Factory design pattern, used for creating objects without specifying the exact class to create.

3. **Observer Pattern**: [Folder](./Observer)
   - Provides an example of the Observer design pattern, which defines a one-to-many dependency between objects.

4. **Strategy Pattern**: [Folder](./Strategy)
   - Contains an implementation of the Strategy design pattern, allowing you to define a family of algorithms, encapsulate each one, and make them interchangeable.

5. **Decorator Pattern**: [Folder](./Decorator)
   - Demonstrates the Decorator design pattern, which allows you to add new functionalities to objects dynamically by placing them inside special wrapper classes.

6. **Composite Pattern**: [Folder](./Composite)

## Usage

To use this repository, follow these steps:

### Prerequisites

Before you start, make sure you have the following tools and libraries installed:

- **C++ Compiler (g++)**: If you don't have it already, you can download and install it by following the instructions at [GCC](https://gcc.gnu.org/).

### How to Compile and Run

1. Navigate to the folder of the specific design pattern you want to explore. For example, to work with the Singleton pattern:

    ```bash
    cd singleton
    ```

2. Compile the C++ source code using g++. Replace `<filename>` with the name of the C++ file you want to compile:

    ```bash
    g++ <filename>.cpp -o <filename>
    ```

3. Run the compiled program:

    ```bash
    ./<filename>
    ```

4. Observe the output of the program, which demonstrates the usage of the respective design pattern.

### Viewing UML Diagrams

To view the UML diagrams for each design pattern, you can use the [draw.io](https://www.draw.io/) extension in Visual Studio Code. Open the `.drawio` file in the respective design pattern folder to visualize the diagram. This provides a graphical representation of the design pattern's structure and relationships.

## Contributing

If you'd like to contribute to this repository, please follow these guidelines:

1. Fork the repository to your own account.
2. Create a new branch for your feature or fix.
3. Make your changes and commit them.
4. Push your changes to your forked repository.
5. Create a pull request to this repository.

Your contributions are greatly appreciated!

Feel free to reach out if you have any questions or need further assistance. Happy coding!
