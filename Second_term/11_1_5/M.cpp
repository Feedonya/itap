#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct group {
    string Fam, Imya, Otch;
    short Year;
    int Marks[5];
    int sumM = 0;

    group(ifstream &in);//объявляем фукнцию для ввода
    group() {Fam = "0", Imya = "0", Otch = "0", Year = 0, sumM=0; for (int i = 0; i < 5; i++) Marks[i] = 0;}//конструктор структуры
    void Write(ofstream &out);// объявляем функцию для вывода
};

group::group(ifstream &in){//вводим
    in >> Fam >> Imya >> Otch >> Year;

    for (int i = 0; i < 5; i++) in >> Marks[i];

    for (int i = 0; i < 5; i++) sumM +=Marks[i];
}

void group::Write(ofstream &out) {//выводим
    out << Fam << " " << Imya << " " << Otch << " " << Year << " ";
    for (int i = 0; i < 5; i++) out << Marks[i]<<" ";
    out << sumM;
    out << "\n";
}

void sort(group* mass, int size) {//сортировка пузырьком
    for (int i = 0; i < size - 1; i++) {
    for (int j = size - 1; j > i; j--) {
    if (mass[j].sumM > mass[j - 1].sumM) {
        group temp = mass[j - 1];
        mass[j - 1] = mass[j];
        mass[j] = temp;
            }
        }
    }
}

int StrN(ifstream  &in){//подсчитываем кол-во учеников(строк)
    int i=0;
    string s;
    while (getline(in,s)) i++; 

    in.clear();
    in.seekg(0);

    return i;
}

int main(){
    ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_1_5\\input.txt");
    ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\11_1_5\\output.txt");

    
    short n = StrN(in);//подсчитываем кол-во учеников при помощи ф-ции
    group *Mass = new group[n];//создаем массив со суммой оценок для сортировки

    int ngroup;
    in >> ngroup;

    for (int i = 0; i < n-1; i++) Mass[i] = group(in);//заполняем этот массив

    sort(Mass, n);//сортируем 
    out << ngroup << '\n';
    for (int i = 0; i < n-1; i++) Mass[i].Write(out);//выводим

    in.close();
    out.close();


    return 0;
}