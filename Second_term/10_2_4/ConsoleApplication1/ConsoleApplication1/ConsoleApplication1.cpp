#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct student {
    string name;
    int id_group, mark_of_first_exam, mark_of_second_exam, mark_of_third_exam;
    void delete_student();
};

void student::delete_student() {
    if (mark_of_first_exam < 3 or mark_of_second_exam < 3 or mark_of_third_exam < 3) {
        //удалить строчку со студентом
    }
}


int main() {
    setlocale(LC_ALL, "Russian");

    ifstream in("input.txt");
    ofstream out("output.txt");
    
    student name;
    student mark;

    while (in.peek() != EOF) {

        in >> 

        in >> mark.mark_of_first_exam;
        in >> mark.mark_of_second_exam;
        in >> mark.mark_of_third_exam;

        mark.delete_student();

    }


    in.close();
    out.close();

    return 0;
}