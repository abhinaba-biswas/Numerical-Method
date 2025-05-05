//
// Created by abhis on 05-05-2025.
//

#include <stdio.h>
int factorial(int n) {
    int fact = 1;
    for (int i =2; i<=n;i++){
        fact *= i;
    }
    return fact;
}

int main(){
    int n;
    float x[10], y[10][10], value, h, u, result;

    // receiving the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Take the values of x and y from the user

    printf("Enter the values of x:\n");
    for(int i=0; i<n; i++){
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    printf("ENter the values of y:\n");
    for(int i=0; i<n; i++){
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);
    }

    //Generate difference table
    for(int j=1; j<n; j++){
        for(int i=0; i<n-j; i++){
            y[i][j]=y[i+1][j-1]-y[i][j-1];
        }
    }
    //Print the difference table
    printf("\nThe difference table is:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            printf("%.1f\t", y[i][j]);
        }
        printf("\n");
    }

    

}
