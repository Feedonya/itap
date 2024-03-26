#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
//ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_1_5\\input.txt");
//ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_1_5\\output.txt");

struct student{
    string name_of_student, surname, patronymic;
    int mark_of_first_exam, mark_of_second_exam, mark_of_third_exam, mark_of_fourth_exam, mark_of_fifth_exam, date_of_birth;
    int sum_of_students();
    void input();
    void output(int[], int);
    void insertionSort(int* , int);
};

void student::input(){
	in >> surname >> name_of_student >> patronymic >> date_of_birth >> mark_of_first_exam >> mark_of_second_exam >> mark_of_third_exam >> mark_of_fourth_exam >> mark_of_fifth_exam;
}

void student::output(int arr[], int i){
    out << surname << " " << name_of_student << " " << patronymic << " " << date_of_birth << " " << mark_of_first_exam << " " << mark_of_second_exam << " " << mark_of_third_exam << " " << mark_of_fourth_exam << " " << mark_of_fifth_exam << " ";
	out << arr[i] << '\n';
}

int student::sum_of_students(){
    return (mark_of_first_exam + mark_of_second_exam + mark_of_third_exam + mark_of_fourth_exam + mark_of_fifth_exam);
}

void student::insertionSort(int* arr, int n){
   for (int i = 1; i < n; i++) {
       int key = arr[i];
       int j = i - 1;

       while (j >= 0 && arr[j] < key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

int main(){
    setlocale(LC_ALL, "Russian");
    student st1;

    int i = 0, group, n = 20;
    in >> group;

	int sum[n];

    n = 0;
    while (in.peek() != EOF){
    	st1.input();
    	sum[i] = st1.sum_of_students();
    	i++;
	}
    n = i;
	
	st1.insertionSort(sum, n);
    out << group << '\n';
    for (int i = 0; i < n; i++){
	    st1.output(sum, i);
    }

    in.close();
    out.close();

    return 0;
}