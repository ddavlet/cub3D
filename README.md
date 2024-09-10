# cub3D

## 🎮 Overview
**cub3D** is a 3D game project developed as part of the 42 curriculum, inspired by the classic **Wolfenstein 3D**. The project focuses on understanding and implementing **raycasting** algorithms to create a simple first-person shooter (FPS) engine. It simulates a 3D environment using 2D rendering techniques, allowing the player to navigate and interact within a maze-like world.

## ✨ Features
- **3D rendering using raycasting**
- **Player movement** with first-person controls
- **Grid-based map** with customizable layout
- **Texture mapping** for walls and objects
- **Collision detection** for walls and objects
- **Smooth frame rendering** for real-time gameplay

## 🔥 Bonus Features
In addition to the core functionalities, the project includes several **bonus features**:
- **Mouse control**: Added mouse movement for enhanced player control.
- **Sprite rendering**: Support for rendering 2D sprites within the 3D environment (e.g. mushroom items).
- **Minimap**: A functional minimap for real-time player navigation.
- **Multiple Levels**: Added support for multiple maps with varying layout.
- **Dynamic lighting**: Introduced lighting effects for a more immersive environment.
- **Shadowing**: Enhanced shadowing for immersive distance environment

## 🛠️ Getting Started
1. Clone the repository:
  ```bash
  git clone https://github.com/ddavlet/cub3D.git
  ```
Compile the project:
  ```bash
  make
  ```
Run the game:
  ```bash
  ./cub3D maps/map.cub
  ```
## 🎯 Objectives
Mastering raycasting algorithms for real-time 3D rendering.
Implementing efficient game loop and input handling.
Enhancing gameplay through advanced features like mouse control and dynamic lighting.

## 🧪 Testing
To ensure the performance and stability of **cub3D**, the following testing tools are available:

### 1. **Performance Testing (timing.d)**
- A `timing.d` script is used to monitor the performance and ensure the game runs smoothly without frame drops or lag. This script measures the time taken by key functions during gameplay.

### 2. **Map Testing Script**
- A script is provided to automatically test all the maps in the `maps/` directory, ensuring that each map is loaded and rendered correctly without issues.

To run the performance test:
  ```bash
  ./timing.d
  ```
To run all maps test:
  ```bash
  ./test.sh
  ```
## Demo

![demo](https://github.com/ddavlet/cub3D/blob/main/gif/cub3D.gif)
