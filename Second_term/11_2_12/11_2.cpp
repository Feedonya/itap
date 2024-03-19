#include <iostream>
#include <fstream>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    //std::ifstream inputFile("input.txt");
    //std::ofstream outputFile("output.txt");
    std::ifstream inputFile("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\input.txt");
    std::ofstream outputFile("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\output.txt");

    int n;
    inputFile >> n;

    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> matrix[i][j];
        }
    }

    int diagonal[n];

    for (int i = 0; i < n; i++) {
        diagonal[i] = matrix[i][i];
    }

    bubbleSort(diagonal, n);

    for (int i = 0; i < n; i++) {
        matrix[i][i] = diagonal[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}