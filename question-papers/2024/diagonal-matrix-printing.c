#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("Enter the number of rows in the matrix");
    int m, n;
    scanf("%d", &m);
    printf("Enter the number of columns in the matrix");
    scanf("%d", &n);

    int matrix[m][n];
    printf("Enter the numbers in the matrix");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix is\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    int count = 1;
    int i = 0, j = 0;
    int verticalIncrement = false;
    while ((i + j) < (m + n))
    {
        printf("\n%d", matrix[i][j]);
        if (i == m -1 && j == n -1){
            break;
        }
        if (verticalIncrement == false)
        {
            verticalIncrement = true;
            if (j == 0 || j == n - 1)
            {
                if (i < m - 1)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
            else if (i == 0 || i == m - 1)
            {
                if (j < n - 1)
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
        else
        {
            if ((i + j) % 2 == 1)
            {
                i--;
                j++;
            }
            else
            {
                i++;
                j--;
            }
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            {
                verticalIncrement = false;
            }
        }
    }
}