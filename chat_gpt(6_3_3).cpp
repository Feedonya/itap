#include <iostream>

int main(){
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) 
        arr[i] = new int[cols];
    

    // Input values into the array
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++){
            std::cout << "Enter value for arr[" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    

    // Replace even columns with user input vector
    int* vec = new int[rows];
    std::cout << "Enter " << rows << " values for the vector: ";
    for (int i = 0; i < rows; i++) 
        std::cin >> vec[i];
    

    for (int i = 0; i < rows; i++) 
        //if (i 
            for (int j = 0; j < cols; j += 2) 
                arr[i][j] = vec[i];
            
        
    

    // Output the modified array
    std::cout << "Modified array:" << std::endl;
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            std::cout << arr[i][j] << " ";
        
        std::cout << std::endl;
    

    // Deallocate memory
    for (int i = 0; i < rows; i++) 
        delete[] arr[i];
    
    delete[] arr;
    delete[] vec;

    return 0;
}