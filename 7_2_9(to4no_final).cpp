#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
  setlocale(LC_ALL,"Russian");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  string str;
  string word = "";
  cout << "Введите строку:" << endl;
  getline(cin, str);

  char c;
  cout << "Введите символ:" << endl;
  cin >> c;

  string comp = " ,.;!?";
  bool f = false;

  for (int i = 0; i < str.size(); ++i){//проходим по строке
    if (str[i] == c){//если находим символ равный заданной букве
      int k = str.find_first_of(comp, i+1);//переменная, которая хранит позицию препинания после слова
      if (str[i] == str[k-1] && i != k-1){//если это не отдельно взятый символ и последний символ слова равен первому
        for (int j = i; j < k; j++){//выводим это слово
          cout << str[j];
          f = true;
        }
        cout << endl;
      }
    }
  }

  if(!f) {//если таких слов нет - выводим
    cout << "В строке не нашлось таких слов!";
  }

  return 0;
}

/*
test_input:
1) hello. level, kayak, world!
   l
2) зима; акула, собака; ломал! кидать?
   л

test_output:
1) level
2) ломал
*/