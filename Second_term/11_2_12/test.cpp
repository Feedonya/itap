#include <iostream>
using namespace std;

// Функция для сортировки массива методом пузырька
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для сортировки диагонали матрицы по возрастанию элементов
void sortDiagonal(int matrix[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int row = i;
        int col = i;
        int diagonalLength = 0;
        while (row < n && col < n)
        {
            diagonalLength++;
            row++;
            col++;
        }

        int *diagonal = new int[diagonalLength];
        row = i;
        col = i;
        for (int j = 0; j < diagonalLength; j++)
        {
            diagonal[j] = matrix[row * n + col];
            row++;
            col++;
        }

        bubbleSort(diagonal, diagonalLength);

        row = i;
        col = i;
        for (int j = 0; j < diagonalLength; j++)
        {
            matrix[row * n + col] = diagonal[j];
            row++;
            col++;
        }

        delete[] diagonal;
    }
}

int main()
{
    int n = 4;
    int matrix[4][4] = {
        {6, 8, 3, 2},
        {4, 9, 1, 5},
        {7, 5, 2, 3},
        {1, 6, 4, 7}};

    sortDiagonal((int *)matrix, n);

    cout << "Sorted matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}