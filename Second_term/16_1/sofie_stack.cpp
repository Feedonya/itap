#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void RemoveMaximumElement(stack<int>& originalStack, int maximum) {
    stack< int> tempStack;

    while (!originalStack.empty()) {
        int i = originalStack.top();
        originalStack.pop();

        if (i != maximum){
            tempStack.push(i);
        }
    }

    while (!tempStack.empty()) {
    	originalStack.push(tempStack.top());
        tempStack.pop();
    }
    
}

int main() {
    setlocale(LC_ALL,"Russian");
    stack <int> MyStack;
    int maximum = INT_MIN;

    while (in.peek() != EOF) {
        int i;
        in >> i;
        MyStack.push(i);
        if (i > maximum)
            maximum = i;
	}

    RemoveMaximumElement(MyStack, maximum);
    
    stack <int> tempStack;
    while (!MyStack.empty()) {
    	tempStack.push(MyStack.top());
        MyStack.pop();
    }

    while (!tempStack.empty()) {
    	out << tempStack.top() <<  endl;
        tempStack.pop();
    }

    return 0;
}
