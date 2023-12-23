#include <stdio.h>
#include <stdlib.h>

int **matCreate(int *matRow, int *matCol); // matCreate prototype
void matPrint(int **matrix, int matDim[2]); // matPrint prototype
int **matAdd(int **matrix1, int **matrix2, int mat1Dim[2], int mat2Dim[2]); // matAdd prototype
int **matSub(int **matrix1, int **matrix2, int mat1Dim[2], int mat2Dim[2]); // matSub prototype
int **matMult(int **matrix1, int **matrix2, int mat1Dim[2], int mat2Dim[2]); // matMult prototype
void matFree(int **matrix, int matDim[2]); // matFree prototype

int main()
{
  int mat1Size[2], mat2Size[2];

  //Getting size and values of matrix from user
  printf("Please enter the two dimensions for 1st matrix\n"); //1st matrix
  int **matrix1 = matCreate(&mat1Size[0], &mat1Size[1]);
  printf("\nPlease enter the two dimensions for 2nd matrix\n"); //2nd matrix
  int **matrix2 = matCreate(&mat2Size[0], &mat2Size[1]);

  while (1)
  {
    //asking user type of operation
    printf("\nPlease choose one of the following operations to perform:\n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Exit\n");

    int choice;
    scanf("%d", &choice);
    //performing operation
    switch(choice)
    {
      case 1:
        printf("\nAddition, resulting matrix:\n");
        matPrint(matAdd(matrix1, matrix2, mat1Size, mat2Size), mat1Size);
        break;
      case 2:
        printf("\nSubtraction, resulting matrix\n");
        matPrint(matSub(matrix1, matrix2, mat1Size, mat2Size), mat1Size);
        break;
      case 3:
        printf("\nMultiplication, resulting matrix\n");
        matPrint(matMult(matrix1, matrix2, mat1Size, mat2Size), mat1Size);
        break;
      case 4:
        printf("\nExit program\n");
        //freeing memory
        matFree(matrix1, mat1Size);
        matFree(matrix2, mat2Size);
        //exit while loop
        exit(0);
      default:
        printf("Invalid choice\n");
        break;
    }

  }

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
    for (int j = 0; j < size[1]; j++)
      scanf("%d", &matrix[i][j]);

  printf("\nthe matrix that you have entered is:\n");
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

  if (matrix == NULL) {
    printf("Matrix is empty\n");
    return;
  }

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
int **matAdd(int **matrix1, int **matrix2, int matDim[2], int matDim2[2])
{
  int row = matDim[0];
  int column = matDim[1];
  int row2 = matDim2[0];
  int column2 = matDim2[1];

  //check if matrix can be added
  if (row != row2 || column != column2)
  {
    printf("Error: matrices cannot be added\n");
    return NULL;
  }

  int **sum = (int **) malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++)
    sum[i] = (int *) malloc(matDim[1] * sizeof(int));

  for (int i = 0; i < row; i++)
    for (int j = 0; j < matDim[1]; j++)
      sum[i][j] = matrix1[i][j] + matrix2[i][j];

  return sum;
}

/*
  *Function: matSub
  *Purpose: subtracts two matrices
  *Param: matrix1 - first matrix
  *       matrix2 - second matrix
  *       matDim - dimensions of the matrix
  *Return: difference of the two matrices
*/
int **matSub(int **matrix1, int **matrix2, int matDim[2], int matDim2[2])
{
  int row = matDim[0];
  int column = matDim[1];
  int row2 = matDim2[0];
  int column2 = matDim2[1];

  //check if matrix can be subtracted
  if (row != row2 || column != column2)
  {
    printf("Error: matrices cannot be subtracted\n");
    return NULL;
  }

  int **diff = (int **) malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++)
    diff[i] = (int *) malloc(column * sizeof(int));

  for (int i = 0; i < row; i++)
     for (int j = 0; j < column; j++)
       diff[i][j] = matrix1[i][j] - matrix2[i][j];

  return diff;
}

/*
  *Function: matMult
  *Purpose: multiplies two matrices
  *Param: matrix1 - first matrix
  *       matrix2 - second matrix
  *       matDim - dimensions of the matrix
  *Return: product of the two matrices
*/
int **matMult(int **matrix1, int **matrix2, int matDim[2], int matDim2[2])
{
  int row = matDim[0];
  int column = matDim[1];
  int row2 = matDim2[0];
  int column2 = matDim2[1];

  //check if matrix can be multiplied
  if (column != row2)
  {
    printf("Error: matrices cannot be multiplied\n");
    return NULL;
  }

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