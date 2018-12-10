# amath2

amath2 is yet another new and improved calculator

amath2 is free and open source (FOSS) software released under the terms of the GNU General Public License v3

amath2 can handle polynomials, manipulate trigonometric functions, and more

## Building

### Dependencies

* GiNaC

To build `amath2`, an out-of-source build directory is recommended. Create a new directory, generate CMake build files, and compile.

```
mkdir build
cd build
cmake ..
make -j <processor count>
```

## Usage

Windows (from build directory): `amath2 <operation> <arguments>`

Linux (from build directory): `./amath2 <operation> <arguments>`

Available operations can be printed to the terminal by running `amath2` with no arguments.

Each argument should be passed with no spaces. If an argument must contain spaces, it should be encapsulated in quotes.

### Usage Examples

Add 2 + 3: `./amath2 add 2 3`

Subtract 2x + 6y: `./amath2 sub 2*x 6*y`

Multiply (x + 1) * (x^2 + 3x): `./amath2 mul x+1 x^2+3*x`

## Contributing

I develop `amath2` in my free time. I am a college student, and I will likely work everything I learn in my math classes into `amath2`.

Unfortunately, I don't have much free time. For that reason, contributions are in fact encouraged. If you see something wrong with `amath2` or would like a feature implemented, don't hesitate to open an issue on the GitHub issue tracker. Even better, if you can write C++, open a pull request!

## Why I Made `amath2`

I have a private calculator similar to this one that I made in Python. The main issue was it was very slow due to having to import all of the libraries it needed on every run. It was called `amath-py` and I may or may not release it in the future.

`amath2` is written in C++. Because of this, it is much faster than other calculators I've written (Java, Python, etc). I wanted something that was very fast, robust, and reliable. As `amath2` is constantly developed, it will continue to improve.

`amath2` currently does not show work. I plan to implement this very soon.

`amath2` is beta development software. It could be perfectly functional or it could not work at all. In its current state, I don't recommend trusting it for sensitive calculations.

## Why You Should Use `amath2`

`amath2` is lightning fast. Currently, most problems can be solved in less than 50 microseconds. Obviously, this depends on how powerful your computer is, but this should give you an idea of how fast it is.

`amath2` is always growing in functionality. I am a college student taking lots of math classes, and I intend to implement everything I learn into `amath2`. The fields I plan on implementing include, but are not necessarily limited to, calculus, linear algebra, and discrete mathematics.


