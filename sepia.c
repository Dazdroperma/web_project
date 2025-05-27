#include <emscripten.h>
#include <stdint.h>

EMSCRIPTEN_KEEPALIVE
void sepia_filter(uint8_t* data, int width, int height) {
    for (int i = 0; i < width * height * 4; i += 4) {
        uint8_t r = data[i];
        uint8_t g = data[i+1];
        uint8_t b = data[i+2];
        
        int new_r = (r * 0.393) + (g * 0.769) + (b * 0.189);
        int new_g = (r * 0.349) + (g * 0.686) + (b * 0.168);
        int new_b = (r * 0.272) + (g * 0.534) + (b * 0.131);
        
        data[i] = new_r > 255 ? 255 : new_r;
        data[i+1] = new_g > 255 ? 255 : new_g;
        data[i+2] = new_b > 255 ? 255 : new_b;
    }
}