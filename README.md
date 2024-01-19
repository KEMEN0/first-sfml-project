# SFML Shapes

This project is a simple C++ application that reads shape data from a text file and displays the shapes moving around the window.

## Getting Started

To run this project, you need to have SFML installed on your machine and a c++ compiler.

## Usage

1. Compile the `main.cpp` file.
2. Create a `shapes.txt` file with the shape data. Each shape should be defined as follows:

- `ShapeType` is either `Circle` or `Rectangle`.
- `Dimensions` is the radius for circles or the width and height for rectangles.
- `Position` is the initial x and y positions of the shape.
- `Speed` is the x and y speeds of the shape. These determine the direction and speed at which the shape moves.
- `Color` is the RGB color values for the shape.

Here's an example of a `shapes.txt` file:

`
Circle
50
100 100 0.1 0.1 255 0 0
Rectangle
100 50
200 200 0.1 -0.1 0 255 0
Circle
75
300 300 -0.1 0.1 0 0 255
Rectangle
150 75
400 400 -0.1 -0.1 255 255 255
`


3. Run the compiled application.

