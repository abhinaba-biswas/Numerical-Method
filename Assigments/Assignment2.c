#include <stdio.h>

double func_h(double t[], int n) {
    return (t[n] - t[0]) / n;
}
void gen_table(double t[], double f[], int n) {
    printf("\n-----------------------------------------------\n");
    printf("|    Time (t in sec)         |");
    for (int i = 0; i <= n; i++) {
        printf("  %.2lf  ", t[i]);
    }
    printf(" |\n");

    printf("| Acceleration (f in cm/s²) |");
    for (int i = 0; i <= n; i++) {
        printf("  %.2lf  ", f[i]);
    }
    printf("|\n");
    printf("-----------------------------------------------\n");
}

// Function to implement Simpson's 1/3 Rule
double simpsons_rule(double f[], int n, double h) {
    double integral = f[0] + f[n]; // First and last terms

    // Sum of odd-indexed terms
    for (int i = 1; i < n; i += 2) {
        integral += 4 * f[i];
    }

    // Sum of even-indexed terms
    for (int i = 2; i < n; i += 2) {
        integral += 2 * f[i];
    }

    integral *= h / 3.0; // Multiply by step size factor
    return integral;
}

int main() {
    // Given data
    double t[] = {0, 10, 20, 30, 40, 50, 60, 70, 80};
    double f[] = {30, 31.63, 33.34, 35.47, 37.75, 40.33, 43.25, 46.69, 50.67};
    int n = sizeof(f) / sizeof(f[0]) - 1; // Number of intervals
    double h = func_h(t, n); // Step size

    // Ensure n is even for Simpson's rule
    if (n % 2 != 0) {
        printf("Simpson's rule requires an even number of intervals.\n");
        return 1;
    }

    gen_table(t, f, n);
    double velocity = simpsons_rule(f, n, h);
    printf("The velocity of the rocket at t = 80 sec is: %.2f cm/sec\n", velocity);

    return 0;
}
