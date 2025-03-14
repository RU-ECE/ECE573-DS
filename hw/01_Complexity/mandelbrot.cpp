#include <iostream>
using namespace std;

void mandel(uint32_t w, uint32_t h, uint32_t counts[], // each pixel value is the time
    double magnify,
    const int itermax) {
    magnify *= 3;
    const double invdy = 1.0 / h, invdx = 1.0 / w;
    uint32_t c = 0;
    for (int hy = 1; hy <= h; hy++) {
        const double cy = (((float)hy) * invdy - 0.5) * magnify;
        for (int hx = 1; hx <= w; hx++) {
            const double cx = (((float)hx) * invdx - 0.5) * magnify - 0.7;
            double x = 0.0, y = 0.0;
            int iteration;
            for (iteration = 1; iteration < itermax; iteration++) {
                double xx = x*x-y*y+cx;
                y = 2.0 * x * y + cy;
                x = xx;
                if (x*x + y*y > 2) {
                    counts[c++] = iteration;
                    goto next;
                }
            }
            counts[c++] = iteration;
        next:;
        }
    }
}

int main(int argc, char* argv[]) {
    const int w = 500, h = 500; // resolution of image
    const double magnify = 1.0; /* no magnification */
    constexpr int itermax = 100; // maximum number of iterations

    uint32_t* counts = new uint32_t[w*h];
    mandel(w, h, counts, magnify, itermax);
    delete [] counts;
}
