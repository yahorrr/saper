# Saper (Minesweeper)

A C++ implementation of the classic **Minesweeper** (Saper) game, with both console and GUI views (using SFML).  

---

## Table of Contents

- [About](#about)  
- [Features](#features)  
- [Architecture & Components](#architecture--components)  
- [Requirements](#requirements)  

---

## About

This project recreates the Minesweeper (“Saper”) game in C++. It provides:

- A board with hidden mines  
- Number hints showing counts of adjacent mines  
- Safe cell reveal logic (flood-fill)  
- GUI view (using SFML) and possibly a text mode  
- Ensures first move is safe (i.e. you don’t immediately lose)  

The repository includes source code such as `MinesweeperBoard`, view controllers, SFML view files, and build configuration (via CMake).  

---

## Features

- Dynamically sized board (configurable)  
- Random mine placement  
- Safe-first-move guarantee  
- Flood-fill reveal for empty cells  
- Graphical rendering via SFML  
- Text/controller modules for abstraction (MVC-ish structure)  

---

## Architecture & Components

Here’s a high-level breakdown of major modules/files:

| Module / File | Responsibility |
|----------------|----------------|
| `MinesweeperBoard.*` | Core game board logic: mine placement, counting adjacent mines, reveal logic |
| `MSBoardTextView.*` | Text-based view / console mode rendering (if present) |
| `MSSFMLView.*` | SFML-based graphical rendering of board, UI elements, event loop |
| `MSTextController.*` | Bridges input (keyboard/mouse) to game logic |
| `main.cpp` | Entry point: initializes components, starts game loop |
| `Array2D.h` | Utility for 2D array operations |
| `CMakeLists.txt` | Build configuration for cross-platform compilation |

This separation helps in isolating the game logic from presentation and input.  

---

## Requirements

To build and run this project, you’ll need:

- C++ compiler supporting C++17 (or the standard used)  
- CMake (version 3.x or higher)  
- SFML library for graphical mode (window, events, graphics)  
- (Optional) Development packages for SFML (on Linux: `libsfml-dev`, etc.)  

Make sure SFML is properly installed and linkable.
