#include <fstream>
#include <iostream>
#include <string>

using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");

struct student {
    string name_of_student, surname, patronymic;
    int id_group, mark_of_first_exam, mark_of_second_exam, mark_of_third_exam;
    bool delete_student();
};

// Если студент сдал экзамены - записываем во выходной файл
bool student::delete_student() {
    return (mark_of_first_exam > 2 && mark_of_second_exam > 2 && mark_of_third_exam > 2)
       
}


int main() {
    setlocale(LC_ALL, "Russian");
    
    student name;
    student group;
    student mark;

    while (in.peek() != EOF) {
        in >> name.surname;
        in >> name.name_of_student;
        in >> name.patronymic;

        in >> group.id_group;

        in >> mark.mark_of_first_exam;
        in >> mark.mark_of_second_exam;
        in >> mark.mark_of_third_exam;

        if (mark.delete_student()){
            out << name.surname << " ";
            out << name.name_of_student << " ";
            out << name.patronymic << " ";

            out << group.id_group << " ";

            out << mark.mark_of_first_exam << " ";
            out << mark.mark_of_second_exam << " ";
            out << mark.mark_of_third_exam << endl;
        }
    }

    in.close();
    out.close();

    return 0;
}