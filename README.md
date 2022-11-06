# Fractals

![License](https://img.shields.io/github/license/leoraclet/cpp-skeleton)

This is a simple C / C++ application that allows you to generate and explore colored fractals.
These fractals are generated in real time thanks to the GPU power.
It is possible to zoom in and out and move in the complex plane with your mouse.

Deep zooms are made possible by emulating doubles on the GPU so the precision of 
calculations is almost doubled, and we can then zoom deeper.

## Summary

* **[Fractals](#fractals)**
* **[Libraries](#libraries)**
* **[Build](#build)**
* **[Releases](#releases)**
* **[License](#license)**
* **[Credits](#credits)**

## Fractals

### Mandelbrot

![](shared/misc/mandelbrot_colored.png)

### Julia

![](shared/misc/julia_1.png)
![](shared/misc/julia_2.png)

### Burning Ship

![](shared/misc/burning_ship.png)

### Newton

![](shared/misc/newton_1.png)
![](shared/misc/newton_2.png)

## Build

To build this project, you need to have Cmake installed on your system.

#### Linux

#### Windows

## Libraries

- [**Dear ImGui**](https://github.com/ocornut/imgui) ~ Bloat-free Graphical User interface for C++ with minimal dependencies
- [**SFML**](https://github.com/SFML/sfml) ~ Simple and Fast Multimedia Library
- [**GLAD**](https://glad.dav1d.de/) ~ OpenGl loader
- [**stb**](https://github.com/nothings/stb) ~ STB single-file public domain libraries for C/C++
- [**glm**](https://github.com/g-truc/glm) ~ OpenGL Mathematics

## License

This project is released under the 
[**MIT**](https://github.com/leoraclet/cpp_skeleton/LICENSE)
license.

## Releases

To run the program without editing the source code or building
it yourself, go see the 
[**Releases**](https://github.com/leoraclet/cpp_skeleton/releases).

## Credits

* [**Léo Raclet**](https://github.com/leoraclet) : Creator of the project.
