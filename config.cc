#include "src/mandelbrot.hh"

uint32_t maxRez = 1 << 10; // Default: 1024     Maximum resolution (preferably a power of 2)
uint32_t resolution = 1;   // Default: 1        Initial resolution (square)
double viewX = 0;          // Default: -1.5     Position the screen is centred on. (x + yi)
double viewY = 0;          // Default: 0
double viewZoom = 4;       // Default: 4        Radius of the screen.