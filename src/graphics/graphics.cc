#include "graphics.hh"

constexpr uint32_t accuracy = 200;

constexpr double dub_div(const uint32_t num, const uint32_t denom)
{
    return (double)num / (double)denom;
}

constexpr complex coord(const uint32_t x, const uint32_t y, const double vx, const double vy, const double zoom, uint32_t resolution)
{
    return complex(
        vx + std::lerp(-zoom, zoom, dub_div(x, resolution)) / 2,
        vy + std::lerp(-zoom, zoom, dub_div(y, resolution)) / 2);
}

constexpr bool mandel_bound(const complex c)
{
    return (c.real() * c.real() + c.imag() * c.imag()) >= 4;
}

constexpr void
mandel_iter(const complex c, complex &z)
{
    z = z * z + c;
}

constexpr uint32_t mandel(const complex c, const double zoom)
{
    const uint32_t maxi = accuracy / zoom;
    const double dmaxi = (double)maxi;
    complex z(0, 0);

    for (uint32_t i = 0; i < maxi; i++)
    {
        mandel_iter(c, z);
        if (mandel_bound(z))
            return std::lerp(0xFF, 0xFFFFFF, i / dmaxi);
    }
    return 0;
}

void Man::OnFrame(uint32_t *buffer, bool rerender, uint32_t deltaTime_ns, int &state)
{
    for (uint32_t y = 0; y < resolution; y++)
    {
        for (uint32_t x = 0; x < resolution; x++)
        {
            complex c = coord(x, y, viewX, viewY, viewZoom, resolution);
            buffer[y * resolution + x] = mandel(c, viewZoom);
        }
    }
}