#include <stdio.h>

// Define the differential equation: dy/dx = x + x*y^2
double f(double x, double y) {
    return x + (x * y * y);
}

// Runge-Kutta Method (RK4)
void rungeKutta(double x0, double y0, double x_end, double h) {
    double x = x0;
    double y = y0;
    double n = ((x_end - x0) / h);

    for (int i = 0; i < n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        x = x + h;
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }

    printf("Using Runge-Kutta Method, y(%.2lf) = %.6lf\n", x, y);
}

// Euler Method
void euler(double x0, double y0, double x_end, double h) {
    double x = x0;
    double y = y0;
    double n = ((x_end - x0) / h);

    for (int i = 0; i < n; i++) {
        y = y + h * f(x, y);
        x = x + h;
    }

    printf("Using Euler Method,      y(%.2lf) = %.6lf\n", x, y);
}

int main() {
    double x0, y0, x_end, h;

    printf("Enter the initial value of x0: ");
    scanf("%lf", &x0);

    printf("Enter the initial value of y0: ");
    scanf("%lf", &y0);

    printf("Enter the final value of x_end: ");
    scanf("%lf", &x_end);

    printf("Enter the step size h: ");
    scanf("%lf", &h);

    rungeKutta(x0, y0, x_end, h);
    euler(x0, y0, x_end, h);

    return 0;
}
