#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int row, int col)
{
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX][MAX], int row, int col)
{
    printf("The matrix is:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int row, int col)
{
    int result[MAX][MAX];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printMatrix(result, row, col);
}

void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int row, int col)
{
    int result[MAX][MAX];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    printMatrix(result, row, col);
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int row1, int col1, int row2, int col2)
{
    int result[MAX][MAX] = {0};
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printMatrix(result, row1, col2);
}

void transposeMatrix(int mat[MAX][MAX], int row, int col)
{
    int result[MAX][MAX];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[j][i] = mat[i][j];
        }
    }
    printMatrix(result, col, row);
}

void inverseMatrix2x2(int mat[MAX][MAX])
{
    int determinant = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    if (determinant == 0)
    {
        printf("Inverse does not exist (determinant is 0).\n");
        return;
    }
    int inverse[MAX][MAX];
    inverse[0][0] = mat[1][1];
    inverse[0][1] = -mat[0][1];
    inverse[1][0] = -mat[1][0];
    inverse[1][1] = mat[0][0];

    printf("The inverse matrix is:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.2f ", (float)inverse[i][j] / determinant);
        }
        printf("\n");
    }
}

void menu()
{
    printf("Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("4. Transpose Matrix\n");
    printf("5. Inverse of 2x2 Matrix\n");
    printf("6. Exit\n");
}

void inputForMatrixOperations(int mat1[MAX][MAX], int mat2[MAX][MAX], int *row1, int *col1, int *row2, int *col2, int operation)
{
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", row1, col1);
    inputMatrix(mat1, *row1, *col1);

    if (operation == 3)
    { // For multiplication, enter rows and columns of matrix 2 separately
        printf("Enter the number of rows of matrix 2: ");
        scanf("%d", row2);
        printf("Enter the number of columns of matrix 2: ");
        scanf("%d", col2);
    }
    else
    {
        printf("Enter the number of rows and columns of matrix 2: ");
        scanf("%d %d", row2, col2);
    }
    inputMatrix(mat2, *row2, *col2);
}

void inputForSingleMatrixOperation(int mat[MAX][MAX], int *row, int *col)
{
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", row, col);
    inputMatrix(mat, *row, *col);
}

int main()
{
    int mat1[MAX][MAX], mat2[MAX][MAX];
    int row1, col1, row2, col2;
    int choice;

    while (1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputForMatrixOperations(mat1, mat2, &row1, &col1, &row2, &col2, choice);
            if (row1 == row2 && col1 == col2)
            {
                addMatrices(mat1, mat2, row1, col1);
            }
            else
            {
                printf("Matrices must have the same dimensions for addition.\n");
            }
            break;
        case 2:
            inputForMatrixOperations(mat1, mat2, &row1, &col1, &row2, &col2, choice);
            if (row1 == row2 && col1 == col2)
            {
                subtractMatrices(mat1, mat2, row1, col1);
            }
            else
            {
                printf("Matrices must have the same dimensions for subtraction.\n");
            }
            break;
        case 3:
            inputForMatrixOperations(mat1, mat2, &row1, &col1, &row2, &col2, choice);
            if (col1 == row2)
            {
                multiplyMatrices(mat1, mat2, row1, col1, row2, col2);
            }
            else
            {
                printf("Number of columns in matrix 1 must be equal to number of rows in matrix 2 for multiplication.\n");
            }
            break;
        case 4:
            inputForSingleMatrixOperation(mat1, &row1, &col1);
            transposeMatrix(mat1, row1, col1);
            break;
        case 5:
            inputForSingleMatrixOperation(mat1, &row1, &col1);
            if (row1 == 2 && col1 == 2)
            {
                inverseMatrix2x2(mat1);
            }
            else
            {
                printf("Inverse function is implemented only for 2x2 matrices.\n");
            }
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}