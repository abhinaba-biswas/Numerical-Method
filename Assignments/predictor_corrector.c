#include <stdio.h>

double f(double x, double y) {
    return x - y;
}

int main() {
    double x0 = 0.0, y0 = 1.0;
    double h = 0.1;
    double x, y, yp, yc;
    int n = 6;

    x = x0;
    y = y0;

    printf("x\t\ty\n");
    printf("%.1f\t\t%.4f\n", x, y);

    for (int i = 0; i < n; i++) {
        
        yp = y + h * f(x, y);

        
        yc = y + (h / 2.0) * (f(x, y) + f(x + h, yp));

        
        x = x + h;
        y = yc;

        printf("%.1f\t\t%.4f\n", x, y);
    }

    return 0;
}
