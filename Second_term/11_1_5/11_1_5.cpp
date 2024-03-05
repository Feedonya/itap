#include <fstream>
#include <iostream>
#include <string>

using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");

struct student {
    string name_of_student, surname, patronymic;
    int id_group, mark_of_first_exam, mark_of_second_exam, mark_of_third_exam, mark_of_fourth_exam, mark_of_fifth_exam, date_of_birth;
    int sum[4];
    int sum_of_student();
    void input();
    void output();
    void chose_sort(int *, int);
};

void student::input() {
	in >> id_group >> surname >> name_of_student >> patronymic >> date_of_birth >> mark_of_first_exam >> mark_of_second_exam >> mark_of_third_exam >> mark_of_fourth_exam >> mark_of_fifth_exam;
}

void student::output(){
	out << sum << '\n';
}

int student::sum_of_student() {
    return (mark_of_first_exam + mark_of_second_exam + mark_of_third_exam + mark_of_fourth_exam + mark_of_fifth_exam);
}

void student::chose_sort(int *sum, int n){
	int temp[n];
	int i,j;
	for (i = 2; i <=n; i++){
		j = i;
		while (sum[i].key < sum[i+1].key){
			temp  = sum[j];
			sum[j] = sum[j-1];
			sum[j] = temp;
			j--;
		}
	}
}

int main() {
    setlocale(LC_ALL, "Russian");
    student st1;
    int i = 0;

    while (in.peek() != EOF) {
    	st1.input();
    	sum[i] = st1.sum_of_students;
    	i++;
		}
	
	chose_sort(sum, 4);
	st1.output();

    in.close();
    out.close();

    return 0;
}
