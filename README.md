# ♟️ Chess-OpenGL ♟️

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![OpenGL](https://img.shields.io/badge/OpenGL-%23FFFFFF.svg?style=for-the-badge&logo=opengl)
![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)

Here you will find a hands-on work on a 3D-chess made with heart 💖 

# ⚙️ Installation ⚙️

Before you begin, ensure that you have the following prerequisites installed on your system:

## 🛠 Requirements 🛠

Install the build-essential package along with CMake:

```bash
  sudo apt-get install build-essential cmake
```

Then, install the necessary OpenGL libraries:

```bash
  apt-get install libglew-dev libglfw3-dev libglu1-mesa-dev libgl-dev libxrandr-dev libxi-dev libxinerama-dev libx11-dev libglm-dev
```

Once the prerequisites are installed, you can clone the project repository using the following command:

```bash
  git clone https://github.com/Vpech77/chess-opengl.git
```

# 🚀 Run the project 🚀

After cloning the repository and installing the necessary dependencies, follow these steps to build and run the project:

1. Create a Build Directory, generate Build Files with CMake and compile the project:
   
```bash
  mkdir build
  cd build
  cmake ..
  make
```

2. Once the compilation is complete, you can run the program with:

```bash
  ./chessProj
```

# 😇 Enjoy! 😇

## 🕹️ Game Mechanics 🕹️

- Pieces are chosen at random, and their moves are also random.
- White and black pieces move alternately.

## 🎮 Controls 🎮

- Next Turn: Press the Space button to make a turn.

- Movement: Use the arrow keys to navigate the chessboard:

    - Up Arrow: Move forward

    - Down Arrow: Move backward

    - Right Arrow: Move right

    - Left Arrow: Move left

    - Press U to move up.

    - Press Left Shift to move down.
