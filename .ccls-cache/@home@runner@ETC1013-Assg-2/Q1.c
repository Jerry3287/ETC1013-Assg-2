#include <stdio.h>
#include <stdlib.h>

int **matCreate(int row, int column);
void matPrint(int matrix, int matDim);

int main()
{
    int row, column;
    //get the dimensions and values for 1st matrix
    printf("Please enter the two dimensions for 1st matrix\n");
    printf("row: ");
    scanf("%d", &row);
    printf("column: ");
    scanf("%d", &column);
    int mat1Dim[] = {row, column};
    int **mat1 = matCreate(row, column);
    
    //get the dimensions and values for 2nd matrix
    printf("Please enter the two dimensions for 1st matrix\n");
    printf("row: ");
    scanf("%d", &row);
    printf("column: ");
    scanf("%d", &column);
    int mat2Dim[] = {row, column};
    int **mat2 = matCreate(row, column);

    printf("Please enter the values for 1st matrix (row by row)\n");
    for (int i = 0; i < mat1Dim[0]; i++)
    {
        for (int j = 0; j < mat1Dim[1]; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("the matrix that you have entered is:\n");
    for (int i = 0; i < mat1Dim[0]; i++)
    {
        for (int j = 0; j < mat1Dim[1]; j++)
        {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }


    return 1;
}

int **matCreate(int row, int column)
{
    int **matrix = malloc(row * sizeof(int));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = malloc(column * sizeof(int));
    }

    return matrix;
}

void matPrint(int matrix, int matDim)
{
    
}