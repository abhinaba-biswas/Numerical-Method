#include <stdio.h>

// Example derivative function: dy/dx = f(x, y) = x + y
double f(double x, double y) {
    return x + y;
}

void rungeKutta(double x0, double y0, double x_end, double h) {
    double x = x0;
    double y = y0;

    printf("x = %.2lf, y = %.5lf\n", x, y);

    while (x < x_end) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);

        y += (k1 + 2*k2 + 2*k3 + k4) / 6;
        x += h;

        printf("x = %.2lf, y = %.5lf\n", x, y);
    }
}

int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double x_end = 2.0;
    double h = 0.1;

    rungeKutta(x0, y0, x_end, h);

    return 0;
}
