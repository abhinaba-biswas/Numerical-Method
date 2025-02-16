#include <stdio.h>
#define PI 3.141592653589793

// Function to calculate step size h
double func_h(double a, double b, int n) {
    return (b - a) / n;
}

// Function to integrate
double f(double x) {
    return 1 / (1 + x * x);
}

// Table Generation Function
void gen_table(double a, double b, int n) {
    double h = func_h(a, b, n);
    printf("\nh = %.4lf\n", h);
    
    // Print x values in one row
    printf("\nx values:  ");
    for (int i = 0; i <= n; i++) {
        double xi = a + i * h;
        printf("  %.4lf", xi);
    }

    // Print f(x) values in one row
    printf("\nf(x) values:");
    for (int i = 0; i <= n; i++) {
        double xi = a + i * h;
        printf(" %.4lf ", f(xi));
    }
    printf("\n");
}

// Simpson's Rule Implementation
double simpsons(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Error: n must be even for Simpson's Rule.\n");
        return 0;
    }
    
    double h = func_h(a, b, n);
    double sum = f(a) + f(b);
    double even_sum = 0.0, odd_sum = 0.0;

    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        if (i % 2 == 0) {
            even_sum += f(xi);  // Even index terms
        } else {
            odd_sum += f(xi);   // Odd index terms
        }
    }

    return (h / 3) * (sum + 4 * odd_sum + 2 * even_sum);
}

// Main function
int main() {
    double a, b;
    int n;

    printf("Enter the number of subintervals (n must be even): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Error: n must be even for Simpson's Rule.\n");
        return 1;
    }

    printf("Enter the lower limit (a): "); 
    scanf("%lf", &a);
    printf("Enter the upper limit (b): "); 
    scanf("%lf", &b);

    printf("\nTable Generation:\n");
    gen_table(a, b, n);

    double I = simpsons(a, b, n);
    printf("\nApproximate Integral Value: %.4lf\n", I);

    return 0;
}
