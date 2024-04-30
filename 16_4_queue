#include <iostream>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int countAndRemoveWords(queue<string>& originalQueue, char letter) {
    queue <string> tempQueue;
    int count = 0;

    while (!originalQueue.empty()) {
        string word = originalQueue.front();
        originalQueue.pop();

        if (word[0] == letter) {
            count++;
        } else {
            tempQueue.push(word);
        }
    }

    while (!tempQueue.empty()) {
    	originalQueue.push(tempQueue.front());
        tempQueue.pop();
    }

    return count;
}

int main() {
    setlocale(LC_ALL,"Russian");
    queue <string> wordsQueue;
    
    while (in.peek() != EOF) {
        string i;
        in >> i;
        wordsQueue.push(i);
	}

    char letter = 'c';

    int count = countAndRemoveWords(wordsQueue, letter);
    
    out << "Êîë-âî ñëîâ ñ çàäàííîé áóêâû'" << letter << "': " << count <<  endl;
    out << "Ñëîâà ïîñëå óäàëåíèÿ: " <<  endl;
    
    while (!wordsQueue.empty()) {
    	out << wordsQueue.front() <<  endl;
        wordsQueue.pop();
    }

    return 0;
}

