#include <iostream>
#include <fstream>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDiagonals(int matrix[100][100], int n) {
    // Sort main diagonal
    int mainDiagonal[100];
    for (int i = 0; i < n; i++) {
        mainDiagonal[i] = matrix[i][i];
    }
    bubbleSort(mainDiagonal, n);
    for (int i = 0; i < n; i++) {
        matrix[i][i] = mainDiagonal[i];
    }

    // Sort parallel diagonals
    for (int k = 1; k < n; k++) {
        int diagonal[100];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i + k < n) {
                diagonal[count] = matrix[i][i + k];
                count++;
            }
        }
        bubbleSort(diagonal, count);
        count = 0;
        for (int i = 0; i < n; i++) {
            if (i + k < n) {
                matrix[i][i + k] = diagonal[count];
                count++;
            }
        }
    }
}

int main() {
    int n;
    int matrix[100][100];

    std::ifstream input("input.txt");
    input >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> matrix[i][j];
        }
    }
    input.close();

    sortDiagonals(matrix, n);

    std::ofstream output("output.txt");
    output << "Sorted Matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            output << matrix[i][j] << " ";
        }
        output << std::endl;
    }
    output.close();

    return 0;
}