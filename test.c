#include <stdio.h>
#include <stdlib.h>

int **matCreate(int *matRow, int *matCol);
void matPrint(int **matrix, int matDim[2]);

int main()
{
    int mat1Size[2], mat2Size[2];

    printf("Please enter the two dimensions for 1st matrix\n"); //1st matrix
    int **matrix1 = matCreate(&mat1Size[0], &mat1Size[1]);
    printf("Please enter the two dimensions for 2nd matrix\n"); //2nd matrix
    int **matrix2 = matCreate(&mat2Size[0], &mat2Size[1]);

    return 1;
}

/*
  *Function: matCreate
  *Purpose: allocates memory and creates matrix
  *Param: matRow - size of the row
  *      matCol - size of the column
  *Return: matrix
*/
int **matCreate(int *matRow, int *matCol)
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
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return matrix;
}

void matPrint(int **matrix, int matDim[2])
{
    int row = matDim[0];
    int column = matDim[1];
  
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}