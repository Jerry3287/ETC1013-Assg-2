#include <stdio.h>
#include <stdlib.h>

int **matCreate(int *matRow, int *matCol, int *address); // matCreate prototype
void matPrint(int **matrix, int matDim[2]); // matPrint prototype


int main()
{
    int mat1Size[2], mat2Size[2];
    int address;

    printf("Please enter the two dimensions for 1st matrix\n"); //1st matrix
    int **matrix1 = matCreate(&mat1Size[0], &mat1Size[1], &address);
    printf("Please enter the two dimensions for 2nd matrix\n"); //2nd matrix
    int **matrix2 = matCreate(&mat2Size[0], &mat2Size[1]);

  
  
    return 1;
}

/*
  *Function: matCreate
  *Purpose: allocates memory and creates matrix
  *Param: matRow - size of the row
  *       matCol - size of the column
  *Return: matrix
*/
int **matCreate(int *matRow, int *matCol, int *address)
{
    int row, column;
  
    printf("row: ");
    scanf("%d", &row);
    printf("column: ");
    scanf("%d", &column);
  
    int size[] = {row, column};
    *matRow = row;
    *matCol = column;

    //create blank matrix with dimensions input
    int **matrix = (int **) malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int*) malloc(column * sizeof(int));
    }

    //get values for the matrix
    printf("\nPlease enter the values for matrix (row by row)\n");
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
  
    printf("the matrix that you have entered is:\n");
    matPrint(matrix, size);

    return matrix;
}

/*
  *Function: matPrint
  *Purpose: prints matrix
  *Param: matrix - matrix to print
  *       matDim - dimensions of the matrix
  *Return: none
*/
void matPrint(int **matrix, int matDim[2])
{
    int row = matDim[0];
    int column = matDim[1];

    for (int i = 0; i < row; i++)
    {
        printf("[");
        for (int j = 0; j < column; j++)
        {
            if (j != 0) printf(", ");
            printf("%3d", matrix[i][j]);
        }
        printf("]\n");
    }
}