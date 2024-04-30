#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");

int countAndRemoveWords( stack<string>& originalStack, char letter) {
    stack< string> tempStack;
    int count = 0;

    while (!originalStack.empty()) {
        string word = originalStack.top();
        originalStack.pop();

        if (word[0] == letter) {
            count++;
        } else {
            tempStack.push(word);
        }
    }

    while (!tempStack.empty()) {
    	originalStack.push(tempStack.top());
        tempStack.pop();
    }

    return count;
}

int main() {
    setlocale(LC_ALL,"Russian");
    stack <string> wordsStack;
    
    while (in.peek() != EOF) {
        string i;
        in >> i;
        wordsStack.push(i);
	}


    char letter = 'c';

    int count = countAndRemoveWords(wordsStack, letter);
    
    out << "Êîë-âî ñëîâ ñ çàäàííîé áóêâû'" << letter << "': " << count <<  endl;
    out << "Ñëîâà ïîñëå óäàëåíèÿ: " <<  endl;
    
    while (!wordsStack.empty()) {
    	out << wordsStack.top() <<  endl;
        wordsStack.pop();
    }

    return 0;
}
