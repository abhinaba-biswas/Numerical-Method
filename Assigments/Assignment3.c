#include <stdio.h>
#define PI 3.141592653589793
#include<math.h>

// Function to calculate step size h
double func_h(double a, double b, int n) {
    return (b - a) / n;
}

// Function to integrate
double f(double x) {
    return sqrt(x);
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

// Weddle's Rule Implementation
double weddle(double a, double b, int n) {
    
    double h = func_h(a, b, n);
    double sum = f(a) + f(b);
    double s1=0, s2=0, s3=0, s4=0;
    for (int i = 1; i < n; i++) {
        double xi = a + i * h;
        if (i % 2 == 0 && i % 3 != 0) {
            s1 += f(xi);  
        }
        else if (i % 3 == 0 && i % 2 != 0) {
            s2 += f(xi);
        }
        else if (i % 6 == 0) {
            s3 += f(xi);
        }
        else {
            s4 += f(xi);
        }
    }

    return ((3*h)/10) * (sum + 1 * s1 + 6 * s2 + 2 * s3 + 5 * s4);
}

// Main function
int main() {
    double a, b;
    int n;

    printf("Enter the number of subintervals (n must be multiple of 6): ");
    scanf("%d", &n);

    if (n % 6 != 0) {
        printf("Error: n (must be multiple of 6) for Weddle's Rule.\n");
        return 1;
    }

    printf("Enter the lower limit (a): "); 
    scanf("%lf", &a);
    printf("Enter the upper limit (b): "); 
    scanf("%lf", &b);

    printf("\nTable Generation:\n");
    gen_table(a, b, n);

    double I = weddle(a, b, n);
    printf("\nApproximate Integral Value: %.6lf\n", I);

    return 0;
}
