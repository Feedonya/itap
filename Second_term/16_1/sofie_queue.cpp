#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void RemoveMaximumElement(queue<int>& originalStack, int maximum) {
    queue< int> tempStack;

    while (!originalStack.empty()) {
        int i = originalStack.front();
        originalStack.pop();

        if (i != maximum){
            tempStack.push(i);
        }
    }

    while (!tempStack.empty()) {
    	originalStack.push(tempStack.front());
        tempStack.pop();
    }
}

int main() {
    setlocale(LC_ALL,"Russian");
    queue <int> MyStack;
    int maximum = INT_MIN;

    while (in.peek() != EOF) {
        int i;
        in >> i;
        MyStack.push(i);
        if (i > maximum)
            maximum = i;
	}

    RemoveMaximumElement(MyStack, maximum);
    
    while (!MyStack.empty()) {
    	out << MyStack.front() <<  endl;
        MyStack.pop();
    }

    return 0;
}
