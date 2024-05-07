#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class QueueException {
private:
	string str;

public:
	QueueException(string message) : str(message) {}
	string what() {
		return str;
	}
};

template <class Item> class Queue {
private:
	struct Element {
		Item inf;
		Element* next;
		Element(Item x) : inf(x), next(0) {}
	};
	Element *head, *tail;
	unsigned count = 0;
public:
	Queue() : head(0), tail(0) {}
	bool isEmpty() {
		return head == 0;
	}

	Item pop() {
		if (isEmpty()) {
		throw QueueException("Queue is empty");
		} else {
		Element* t = head;
		Item i = t->inf;
		head = t->next;

		if (head == NULL) {
			tail = NULL;
		}

		delete t;
		count--;
		return i;
		}
	}

	void push(Item data) {
		Element* t = tail;
		tail = new Element(data);

		if (!head) {
		head = tail;
		} else {
		t->next = tail;
		}

		count++;
	}

	unsigned getCount() {
		return count;
	}
};

int main() {
  	ifstream in("input.txt");

	int number;
	Queue<int> MyQueue;
	while (in >> number){
		MyQueue.push(number);
	}

	in.close();

	Queue<int> queueEven;
	Queue<int> queueOdd;
	while (!MyQueue.isEmpty()){
		int w = MyQueue.pop();
		if (w%2==0 ) {
			queueEven.push(w);
		} else{
			queueOdd.push(w);
		}
	}

	ofstream out("output.txt");
	while (!queueEven.isEmpty()){
		out << queueEven.pop() << ' ';
	}
	while (!queueOdd.isEmpty()){
		out << queueOdd.pop() << ' ';
	}

	out.close();

	return 0;
}