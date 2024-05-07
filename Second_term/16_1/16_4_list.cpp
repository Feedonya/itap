#include <fstream>
#include <list>
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL,"Russian");

    list<string> wordsList;

	char letter;
	cout << "Введите букву: ";
	cin >> letter;
      
	ifstream in("input.txt");
	string temp;
	while (in >> temp){
		wordsList.push_back(temp);
	}
    in.close();

	list<string> tempList;
	int count = 0;
    for (list<string>::iterator i = wordsList.begin(); i != wordsList.end(); i++){
		string word = *i;
		if (word[0] == letter){
			count++;
		} else {
			tempList.push_back(*i);
		}
	}

    ofstream out("output.txt");
	out << "Удалено слов: " << count << '\n';
    for (list<string>::iterator i = tempList.begin(); i != tempList.end(); i++){
		out << *i << '\n';
    }
    out.close();

    return 0;
}