#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");
ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_1_5\\input.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_1_5\\output.txt");

struct student{
    string name_of_student, surname, patronymic;
    int date_of_birth, sum_of_marks = 0;
    int Marks[5];

    student();
    //student() {surname = "0", name_of_student = "0", patronymic = "0", date_of_birth = 0, sum_of_marks = 0; for (int i = 0; i < 5; i++) Marks[i] = 0;}
    void output();
};

student::student(){
    in >> surname >> name_of_student >> patronymic >> date_of_birth;

    for (int i = 0; i < 5; i++)
        in >> Marks[i];
    
    for (int i = 0; i < 5; i++)
        sum_of_marks +=Marks[i];
}

int Ni(){
    int i = 0;
    string temp;
    while (getline(in,temp))
        i++;
        
    in.clear();
    in.seekg(0);
    return i;
}

//выводить весь инпут и после него вставлять отсортированную сумму
void student::output(){
    out << surname << " " << name_of_student << " " << patronymic << " " << date_of_birth << " ";
    for (int i = 0; i < 5; i++) out << Marks[i]<<" ";
    out << sum_of_marks;
    out << "\n";
}

// Реализовать сортировку вставками
void insertionSort(student* mass, int size){
    for (int i = 1; i < size; i++){
        int j = 1;
        while (j > 0 && mass[j].sum_of_marks<mass[j-1].sum_of_marks){
            swap(mass[j],mass[j-1]);
            --j;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    int n;
    n = Ni();

    int group;
    in >> group;

    student *Mass = new student[n];

    for (int i = 0; i < n; i++){
        Mass[i] = student();
    }
	
	insertionSort(Mass, n);

    out << group << '\n';
    for (int i = 0; i < n; i++){
	    Mass[i].output();
    }

    in.close();
    out.close();

    return 0;
}