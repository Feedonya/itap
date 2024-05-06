#include <queue>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main(){
    queue<char> myQueue;
    char symbol;
    
    int quantity;
    in >> quantity;

    while(in.peek() != EOF){
        in.get(symbol);

        if (isdigit(symbol)){
            if (myQueue.size() < quantity){
                myQueue.push(symbol);

            } else if (myQueue.size() == quantity){
                myQueue.pop();
                myQueue.push(symbol);
            }
        } else if (symbol == '*'){
            if (myQueue.empty()){
                out << '*';
            } else{
                out << (myQueue.front());
                myQueue.pop();
            }
        }  
    }

    in.close();
    out.close();
    
    return 0;
}