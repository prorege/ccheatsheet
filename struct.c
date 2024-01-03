#include <stdio.h>

struct pixel {
    int x,y,z;
    double intensity;
    double luminance;
};

int main(){
    struct pixel one_pixel;
    struct pixel allPixels[128];
    double sum = one_pixel.intensity + one_pixel.luminance;
    printf("%f", sum);

    return 0;
}