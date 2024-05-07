#include <fstream>
#include <string>

using namespace std;

// Для обработки пустых стеков
class StackException{
private:
    string str;
public:
    StackException(string message) : str(message){}
    string what(){
        return str;
    }
};

// Шаблон стека
template <class Item> class Stack{
private:
    struct Element{
        Item inf;
        Element* next;
        Element(Item inf, Element* next) : inf(inf), next(next) {}
    };

    Element* head;
    unsigned count = 0;

public:
    Stack() : head(0){}

    bool isEmpty(){
        return head == 0;
    }
    
    Item pop(){
        if (isEmpty()){
        throw StackException("Stack is empty");
        }

        Element* r = head;
        Item i = r->inf;
        head = r->next;

        delete r;
        count--;
        return i;
    }

    void push(Item data){
        head = new Element(data, head);
        count++;
    }

    Item getTop(){
        if (isEmpty()){
        throw StackException("Stack is empty");
        }

        return head->inf;
    }

    unsigned getCount(){
        return count;
    }
};

int main(){
    ifstream in("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\16_2\\input.txt");

    int number;
    Stack<int> MyStack;
    while (in >> number){
        MyStack.push(number);
    }

    in.close();

    Stack<int> stackEven;
    Stack<int> stackOdd;
    while (!MyStack.isEmpty()){
        int w = MyStack.pop();
        if (w%2==0 ) {
            stackEven.push(w);
        } else{
            stackOdd.push(w);
        }
    }

    ofstream out("C:\\Users\\Fedor\\Desktop\\itap\\Second_term\\16_2\\output.txt");
    while (!stackEven.isEmpty()){
        out << stackEven.pop() << ' ';
    }
    while (!stackOdd.isEmpty()){
        out << stackOdd.pop() << ' ';
    }

    out.close();

    return 0;
}