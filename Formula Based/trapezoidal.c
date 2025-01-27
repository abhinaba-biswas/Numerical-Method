#include<stdio.h>
#include<math.h>

// Function to calculate h
float trapezoidal_h(float a, float b, int n){
    return (b-a)/n;

}

// Value of function
float f(float x){
    return 1/(1+x*x);
}

// Table Generation
void gen_table(float a, float b, int n){
    float h = trapezoidal_h(a,b,n);
    printf("h = %.2f\n", h);
    printf("x\tf(x)\n");
    for(int i = 0; i <= n; i++){
        printf("%.2f\t%.2f\n", a + i*h, f(a + i*h));
    }
}

// Main function
int main(){
    float a, b, h;
    int n;

    printf("Enter the number of subintervals(n): ");
    scanf("%d", &n);

    printf("Enter the lower limit(a): "); 
    scanf("%f", &a);
    printf("Enter the upper limit(b): "); 
    scanf("%f", &b);

    h = trapezoidal_h(a,b,n);

    printf("The value of h is: %.2f", h);

    gen_table(a,b,n);

    int I = 
}