#include<stdio.h>

int main(){
    int row;
    printf("Enter the no. of rows: ");
    scanf("%d", &row);
    
    for (int i = 0; i<=row; i++)
    {
        for(int j=row-i; j>0; j--){
            printf("* ");

        }
        printf("\n");

    }
    return 0;
}