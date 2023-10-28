# Mandelbrot

Native, cross-platform mandelbrot set explorer

## Building

In order to build the project, run

```bash
make
```

## Executing

In order to run the program made, run either

```bash
make run
```

or

```bash
./mandelbrot
```

If you wish to install this permanently for some reason, simply copy it to a directory that is in the PATH, like `/usr/local/bin/ on Linux` or `C:\Program Files (x86)\mandelbrot\` on Windows (make sure to add the directory to PATH if needed).

## Configuring

In order to change the part of the mandelbrot set that you're looking at, you must change the values in [config.cc][1], then recompile.

[1]: config.cc
