#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct group {
 short N;
 string Fam, Imya, Otch;
 short Year;
 int Marks[5];
 int sumM;
 
 group(ifstream &in);
 group() { N = 0, Fam = "0", Imya = "0", Otch = "0", Year = 0, sumM=0; for (int i = 0; i < 5; i++) Marks[i] = 0;}
 void Write(ofstream &out);
};

group::group(ifstream &in){
 in >> N >> Fam >> Imya >> Otch >> Year;

 for (int i = 0; i < 5; i++) in >> Marks[i];

 int summ = 0;
 for (int i = 0; i < 5; i++) summ +=Marks[i];
 sumM = summ;
}

void group::Write(ofstream &out) {
 out << N << " " << Fam << " " << Imya << " " << Otch << " " << Year << " ";
 for (int i = 0; i < 5; i++) out << Marks[i]<<" ";
 out << sumM;
 out << "\n";
}

void sort(group* mass, int size) {
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

int StrN(ifstream  &in){
 int i=0;
 string s;
 while (getline(in,s)) i++; 

 in.clear();
 in.seekg(0);

 return i;
}

int main(){
 ifstream in("input.txt");
 ofstream out("output.txt");
 
 short n = StrN(in);
 group *Mass = new group[n];

 for (int i = 0; i < n; i++) Mass[i] = group(in);

 sort(Mass, n);
 for (int i = 0; i < n; i++) Mass[i].Write(out);

 in.close();
 out.close();


 return 0;
}