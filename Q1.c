#include <stdio.h>
#include <stdlib.h>

int matCreate(int d1, int d2){};
void matPrint(int matrix, int matDim){};

void main()
{
    int dimension1, dimension2;
    //get the dimensions and values for 1st matrix
    printf("Please enter the two dimensions for 1st matrix\n");
    printf("1st dimension: ");
    scanf("%d", &dimension1);
    printf("2nd dimension: ");
    scanf("%d", &dimension2);
    int mat1Dim[] = {dimension1, dimension2};
    int mat1 = matCreate(dimension1, dimension2);
    
    //get the dimensions and values for 2nd matrix
    printf("Please enter the two dimensions for 1st matrix\n");
    printf("1st dimension: ");
    scanf("%d", &dimension1);
    printf("2nd dimension: ");
    scanf("%d", &dimension2);
    int mat2Dim[] = {dimension1, dimension2};
    int mat2 = matCreate(dimension1, dimension2);

    for (int i = 1; i < 2; i++)
    {
        printf("Please enter the two dimensions for matrix %d\n", i);
        printf("1st dimension: ");
        scanf("%d", &dimension1);
        printf("2nd dimension: ");
        scanf("%d", &dimension2);
        if (i == 1)
        {
            int mat1Dim[] = {dimension1, dimension2};
            int mat1 = matCreate(dimension1, dimension2);
        } else {
            int mat2Dim[] = {dimension1, dimension2};
            int mat2 = matCreate(dimension1, dimension2);
        }
    }

    printf("the matrix that you have entered is:\n");



}

int matCreate(int d1, int d2)
{
    int *matrix = malloc(d1 * sizeof(int));
    for (int i = 0; i < d1; i++)
    {
        matrix[i] = malloc(d2 * sizeof(int));
    }

    return matrix;
}

void matPrint(int matrix)
{
    
}