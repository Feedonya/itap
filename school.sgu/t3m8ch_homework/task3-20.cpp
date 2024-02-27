#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string currentLine;

    while (getline(inputFile, currentLine)) {
        for (size_t i = 0; i < currentLine.size() - 1; i += 2) {
            outputFile << currentLine[i];
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
