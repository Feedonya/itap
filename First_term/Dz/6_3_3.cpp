#include <iostream>

int main(){
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) 
        arr[i] = new int[cols];
    

    // Вводим значения в двумерный массив
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++){
            std::cout << "Введите значение в [" << i << "][" << j << "] позиции: ";
            std::cin >> arr[i][j];
        }
    

    // Меняем четные столбцы на вектор
    int* vec = new int[rows];
    std::cout << "Enter " << rows << " values for the vector: ";
    for (int i = 0; i < rows; i++) 
        std::cin >> vec[i];
    

    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j += 2) 
            arr[i][j] = vec[i];
            
        
    

    // Выводим преобразованный массив
    std::cout << "Преобразованный массив:" << std::endl;
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            std::cout << arr[i][j] << " ";
        
        std::cout << std::endl;
    

    // Очищаем память
    for (int i = 0; i < rows; i++) 
        delete[] arr[i];
    
    delete[] arr;
    delete[] vec;

    return 0;
}