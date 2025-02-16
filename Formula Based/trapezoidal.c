#include <stdio.h>
#include <math.h>

// Function to calculate step size h
float trapezoidal_h(float a, float b, int n) {
    return (b - a) / n;
}

// Function whose integral we want to calculate
float f(float x) {
    return 1 / (1 + x * x);
}

// Table Generation
void gen_table(float a, float b, int n) {
    float h = trapezoidal_h(a, b, n);
    printf("\nh = %.2f\n", h);
    printf("x\t\tf(x)\n");
    for (int i = 0; i <= n; i++) {
        printf("%.2f\t\t%.5f\n", a + i * h, f(a + i * h));
    }
}

// Trapezoidal Rule Integration
float trapezoidal_rule(float a, float b, int n) {
    float h = trapezoidal_h(a, b, n);
    float sum = f(a) + f(b); // First and last terms

    // Summing intermediate values
    for (int i = 1; i < n; i++) {
        float x = a + i * h;
        sum += 2 * f(x);
    }

    return (h / 2) * sum; // Trapezoidal Rule Formula
}

// Main function
int main() {
    float a, b;
    int n;

    // Input from user
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    printf("Enter the lower limit (a): ");
    scanf("%f", &a);

    printf("Enter the upper limit (b): ");
    scanf("%f", &b);

    // Generate function table
    gen_table(a, b, n);

    // Compute integral using Trapezoidal Rule
    float I = trapezoidal_rule(a, b, n);

    // Display result
    printf("\nThe approximate integral value is: %.5f\n", I);

    return 0;
}
