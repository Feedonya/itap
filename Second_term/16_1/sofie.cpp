#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
#include "C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\16_1\\queue.cpp"

ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\16_1\\input.txt");
ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\16_1\\output.txt");

int main()
{
  Queue<int> t, t1;
  int i, x;
  int max = INT_MIN;
  in >> x;
  while (in >> i){
      t.Put(i);
      if (i > max) {
          max = i;
      }
  }
  in.close();

  while (!t.Empty()){
      if (i == max) {
          while (!t.Empty() && t.Get() == max) {
              t.Get();
          }
      } else {
          t1.Get();
      }
  }

  while (!t1.Empty()){
      out << t1.Get() << endl;
  }
  out.close();

  return 0;
}