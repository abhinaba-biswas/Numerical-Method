#include <stdio.h>
#define PI 3.141592653589793

// Function to compute step size h
double compute_h(double x[], int n) {
    return (x[n] - x[0]) / n;
}
// Function to generate a formatted table of x and D(x)
void gen_table(double x[], double D[], int n) {
    printf("\n-----------------------------------------\n");
    printf("|    Distance (x in cm)    |");
    for (int i = 0; i <= n; i++) {
        printf("  %.1lf  ", x[i]);
    }
    printf("|\n");

    printf("|    Diameter (D in cm)    |");
    for (int i = 0; i <= n; i++) {
        printf("  %.1lf  ", D[i]);
    }
    printf("|\n");
    printf("-----------------------------------------\n");
}

// Function to compute volume using Trapezoidal Rule
double compute_volume(double x[], double D[], int n) {
    double h = compute_h(x, n);
    double sum = 0.0;

    // Compute volume integral using Trapezoidal Rule
    for (int i = 1; i < n; i++) {
        double R = D[i] / 2.0;
        sum += 2.0 * PI * R * R;
    }

    // Add first and last terms separately
    sum += PI * (D[0] / 2.0) * (D[0] / 2.0) + PI * (D[n] / 2.0) * (D[n] / 2.0);
    
    return (h / 2.0) * sum;
}

int main() {
    // Given data
    double x[] = {0, 1, 2, 3, 4, 5, 6}; // Distance values
    double D[] = {2, 2.2, 2.4, 2.7, 2.5, 2.2, 2}; // Diameter values

    int n = sizeof(x) / sizeof(x[0]) - 1; // Number of intervals
    double h = compute_h(x, n); // Step size
    double volume = compute_volume(x, D, n);
    gen_table(x, D, n);
    // Display result with 3 decimal places
    printf("Number of subintervals (n) = %d\n", n); 
    printf("Step size (h) = %.2lf\n", h);
    printf("Approximate Volume = %.3lf cubic cm\n", volume);

    return 0;
}
