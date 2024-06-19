#include "color.h"
#include "interval.h"
#include <cmath>

double linear_to_gamma(double linear) {
    if (linear > 0)
        return std::sqrt(linear);
    return 0;
}

void write_color(std::ostream &out, const color &pixel_color) {
    auto r = pixel_color.x;
    auto g = pixel_color.y;
    auto b = pixel_color.z;

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    static const interval intensity{0.0, 0.999};
    int rbyte = static_cast<int>(256 * intensity.clamp(r));
    int gbyte = static_cast<int>(256 * intensity.clamp(g));
    int bbyte = static_cast<int>(256 * intensity.clamp(b));

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
