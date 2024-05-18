#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Shoes{

private:

string firma;
string name;
string color;
int size;

public:

void SetShoes(){
  int y;
  cout << "Enter size: ";
  cin >> y;
  size = y;
}
Shoes(){
  cout << "Enter firma ";
  cin >> firma;
  cout << "Enter name ";
  cin >> name;
  cout << "Enter color ";
  cin >> color;
  cout << "Enter size ";
  cin >> size;
}
  
void GetFirma(){
  cout << firma << endl;
}

void GetName(){
  cout << name << endl;
}

void GetColor(){
  cout << color << endl;
}

void GetSize(){
  cout << size << endl;
}
int SetColor(){
  if (color == "red"){
    return 1;
  }
  if (color == "green"){
    return 2;
  }
  if (color == "blue"){
    return 3;
  }
  return 0;
}
static void sort(Shoes *a, int n)
{
  Shoes temp;
  int i, j;
  for(i = 0; i < n-1; i++)
    for (j = n-1; j>i; j--)
      if (a[j].color < a[j-1].color)
      {
        temp = a[j];
        a[j] = a[j-1];
        a[j-1] = temp;
      }
  
  }
friend istream& operator>>(istream& is,Shoes& shoes){
  is >> shoes.firma >> shoes.name >>  shoes.color >> shoes.size;
  return is;
}
friend ostream& operator<<(ostream& os, const Shoes& shoes){
  os << "Firma: " << shoes.firma << ", Name: " << shoes.name << ", Color: " << shoes.color << ", Size: " << shoes.size << endl;
  return os;
}
};


int main(){
  Shoes shoes[3];
  for (int i = 0; i < 3;i++){
    
    shoes[i].SetColor();
    shoes[i].SetShoes();
        
  }
  Shoes::sort(shoes,3);
  for (int i = 0;i<3;i++){
    shoes[i].GetFirma();
    shoes[i].GetName();
    shoes[i].GetColor();
    shoes[i].GetSize();
  }
  return 0;
}
