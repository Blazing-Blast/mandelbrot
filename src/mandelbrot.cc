#include "mandelbrot.hh"
uint32_t area = maxRez * maxRez;
uint32_t stride = maxRez * colorWidth;
uint32_t size = maxRez * stride;

void resize(struct mfb_window *window, int width, int height)
{
    resolution = 1;
}

int main(int argc, char *args[])
{
    struct mfb_window *window = mfb_open_ex("my display", maxRez, maxRez, WF_RESIZABLE);
    if (!window)
        return 1;
    mfb_set_resize_callback(window, resize);

    uint32_t *buffer = (uint32_t *)malloc(size);

    while (mfb_wait_sync(window))
    {
        int state;

        Man::OnFrame(buffer, false, 0, state);

        state = mfb_update_ex(window, buffer, resolution, resolution);

        if (state < 0)
        {
            window = NULL;
            break;
        }
        if (resolution < maxRez)
            resolution <<= 1;
    }
    return 0;
}
