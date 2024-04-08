#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");
ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\input.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_2_12\\output.txt");

void read(int**& matrix, int& n){
    in >> n;

    matrix = new int* [n];
    for (int i = 0; i < n; ++i){
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            in >> matrix[i][j];
        }
    }
}

void print(int** matrix, int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            out << matrix[i][j] << " ";
        }
        out << endl;
    }
}

void sort(int* arr, int n){
    int temp;
    for (int i = 0; i < n-1; ++i){
        for (int j = n-1; j > i; --j){
            if (arr[j] < arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}



int main(){
    int** matrix;
    int n;

    read(matrix, n);

	int i = 0, j = 1, len_of_mas = 0;
	for (int k = 0; k < n/2; k++){
        len_of_mas = 0;
        int* a = new int[n-2+k];//обнуляем массив
        for (; j>=0; i++, j--){//обходим с 1 по n (диагонали сверху)
            a[len_of_mas] = matrix[i][j];
            //cout << matrix[i][j] << ' ';//ДОБАВЛЯЕМ ЭТО В МАССИВ ДЛЯ ДАЛЬНЕЙШЕЙ СОРТИРОВКИ
            len_of_mas++;
        }

        sort(a,len_of_mas); //вызываем сортировку с элементами массива

        //for (int l = 0; l < len_of_mas; l++)
        //    cout << a[l] << ' ';
        i = 0, j = 1+k;
        for (int l = 0; l < len_of_mas; i++, j--, l++){//выводим отсортированный массив в файл
            matrix[i][j] = a[l];
        }
        /*for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
        */
        
        i = 0;
        j = 2+k;
    }
	cout << '\n';

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
	
	i = 1;
    j = 3;
	for (int k = 0; k < n/2; k++){
        for (; j>0 && i < n; i++, j--){//обходим с 1 по n (диагонали снизу)
            cout << matrix[i][j] << ' ';
        }
        i = 2;
        j = 3+k;
        //вызываем сортировку с элементами массива
        //выводим отсортированный массив в файл
        //обнуляем массив
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    print(matrix, n);

    in.close();
    out.close();
    return 0;
}
