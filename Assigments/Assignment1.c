#include <stdio.h>

// Function to calculate step size h based on x-values
double func_h(double s[], int n) {
    return (s[n] - s[0]) / n;
}

// trapezoidal_volume function to compute volume using Trapezoidal Rule
double trapezoidal_volume(double f[], double s[], int n) {
    double h = func_h(s, n); // Step size calculation
    double sum = f[0] + f[n]; // First and last terms

    // Summing intermediate values
    for (int i = 1; i < n; i++) {
        sum += 2 * f[i];
    }

    return (h / 2) * sum; // Trapezoidal Rule formula
}

int main() {
    // Given x-values (s) and function values (f)
    double s[] = {0, 1, 2, 3, 4, 5, 6};
    double f[] = {2, 2.2, 2.4, 2.7, 2.5, 2.2, 2};

    int n = sizeof(f) / sizeof(f[0]) - 1; // Number of subintervals
    double h = func_h(s, n); // Compute step size

    // Compute volume using Trapezoidal Rule
    double volume = trapezoidal_volume(f, s, n);

    // Output
    printf("Number of subintervals (n) = %d\n", n); 
    printf("Step size (h) = %.2lf\n", h);
    printf("Approximate Volume = %.4lf cubic units\n", volume);
    return 0;
}
