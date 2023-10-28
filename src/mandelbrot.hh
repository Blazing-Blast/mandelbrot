#pragma once
#include <MiniFB.h>
#include <iostream>

constexpr uint32_t colorWidth = sizeof(uint32_t);

extern uint32_t maxRez;
extern uint32_t resolution;
extern double viewX;
extern double viewY;
extern double viewZoom;

int main(int argc, char *args[]);

namespace Man
{
    void OnFrame(uint32_t *buffer, bool rerender, uint32_t deltaTime_ns, int &state);
}