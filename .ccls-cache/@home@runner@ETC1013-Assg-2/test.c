#include <stdio.h>
#include <stdlib.h>

int **matCreate(int *matRow, int *matCol); // matCreate prototype
void matPrint(int **matrix, int matDim[2]); // matPrint prototype
int **matAdd(int **matrix1, int **matrix2, int matDim[2]); // matAdd prototype
int **matSub(int **matrix1, int **matrix2, int matDim[2]); // matSub prototype
int **matMult(int **matrix1, int **matrix2, int matDim[2]); // matMult prototype
void matFree(int **matrix, int matDim[2]); // matFree prototype

int main()
{
  int mat1Size[2], mat2Size[2];

  //Getting size and values of matrix from user
  printf("Please enter the two dimensions for 1st matrix\n"); //1st matrix
  int **matrix1 = matCreate(&mat1Size[0], &mat1Size[1]);
  printf("Please enter the two dimensions for 2nd matrix\n"); //2nd matrix
  int **matrix2 = matCreate(&mat2Size[0], &mat2Size[1]);

  //asking user type of operation
  printf("Please choose one of the following operations to perform:\n");
  printf("1 - Addition\n");
  printf("2 - Subtraction\n");
  printf("3 - Multiplication\n");
  int choice;
    scanf("%d", &choice);
    //performing operation
    if (choice == 1)
      matPrint(matAdd(matrix1, matrix2, mat1Size), mat1Size);
    else if (choice == 2)
      matPrint(matSub(matrix1, matrix2, mat1Size), mat1Size);
    else if (choice == 3)
      matPrint(matSub(matrix1, matrix2, mat1Size), mat1Size);
    else
      printf("Invalid choice\n");

  //freeing memory
  matFree(matrix1, mat1Size);
  matFree(matrix2, mat2Size);

  return 0;
}

/*
  *Function: matCreate
  *Purpose: allocates memory and creates matrix
  *Param: matRow - size of the row
  *       matCol - size of the column
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
    matrix[i] = (int *) malloc(column * sizeof(int));

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

/*
  *Function: matAdd
  *Purpose: adds two matrices
  *Param: matrix1 - first matrix
  *       matrix2 - second matrix
  *       matDim - dimensions of the matrix
  *Return: sum of the two matrices
*/
int **matAdd(int **matrix1, int **matrix2, int matDim[2])
{
  int row = matDim[0];

  int **sum = (int **) malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++)
    sum[i] = (int *) malloc(matDim[1] * sizeof(int));

  for (int i = 0; i < row; i++)
    for (int j = 0; j < matDim[1]; j++)
      sum[i][j] = matrix1[i][j] + matrix2[i][j];
  return sum;
}

/*
  *Function: matMult
  *Purpose: multiplies two matrices
  *Param: matrix1 - first matrix
  *       matrix2 - second matrix
  *       matDim - dimensions of the matrix
  *Return: product of the two matrices
*/
int **matMult(int **matrix1, int **matrix2, int matDim[2])
{
  int row = matDim[0];
  int column = matDim[1];

  int **product = (int **) malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
      product[i] = (int *) malloc(matDim[1] * sizeof(int));

    for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
        product[i][j] = 0;

    for (int i = 0; i < row; i++) 
      for (int j = 0; j < column; j++)
          for (int k = 0; k < row; k++)
            product[i][j] += matrix1[i][k] * matrix2[k][j];
    return product;
}

/*
  *Function: matFree
  *Purpose: frees memory
  *Param: matrix - matrix to free
  *       matDim - dimensions of the matrix
  *Return: none
*/
void matFree(int **matrix, int matDim[2])
{
  int row = matDim[0];
  for (int i = 0; i < row; i++)
    free(matrix[i]);
  free(matrix);
  return;
}