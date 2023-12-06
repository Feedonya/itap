#include <iostream>
#include <string>

using namespace std;

/* КОД ДЛЯ РАЗДЕЛЕНИЯ СЛОВ В СТРОКЕ
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string s="information security";
    
    size_t pos=s.find(' ');
    
    s=s.substr(pos+1)+ ' ' + s.substr(0,pos);
    
    cout << s << "\n";
    
    return 0;
}
*/

//1) ищем первый пробел - ставим разделение между текущим символом и следующим пробелом
//2) записываем это слово в строку типа char
//3) смотрим 0 и последний индекс char, если элементы совпадают - удаляем из строки подстроку char
// повторяем это действие пока мы находим пробел 

/*
void insertStringAfterChar(string& mainStr){
    size_t pos = mainStr.find(" ");//первое вхождение
    while (pos != string::npos) {//пока в строке есть пробелы
        
        pos = mainStr.find(" ", pos + .length() + 1);//для поиска следующего символа
    }
}
*/

int main() {
    string mainStr;

    cout << "Введите последовательность: ";
    getline(cin, mainStr);

    //insertStringAfterChar(mainStr);

    cout << "Преобразованная строка: " << mainStr << endl;

    return 0;
}