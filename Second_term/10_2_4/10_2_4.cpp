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
    void input();
    void output();
};

void student::input() {
	in >> surname >> name_of_student >> patronymic >> id_group >> mark_of_first_exam >> mark_of_second_exam >> mark_of_third_exam;
}

void student::output(){
	out << surname << '\t' << name_of_student << '\t' << patronymic << '\t' << id_group << '\t' << mark_of_first_exam << '\t' << mark_of_second_exam << '\t' << mark_of_third_exam << endl;
}

// ???? ??????? ???? ???????? - ?????????? ?? ???????? ????
bool student::delete_student() {
    return (mark_of_first_exam > 2 && mark_of_second_exam > 2 && mark_of_third_exam > 2);
}


int main() {
    setlocale(LC_ALL, "Russian");
    
    student st1;

    while (in.peek() != EOF) {
    	st1.input();
    	if(st1.delete_student()){
    		st1.output();
		}
    }

    in.close();
    out.close();

    return 0;
}
