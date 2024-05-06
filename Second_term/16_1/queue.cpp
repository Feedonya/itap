#include "exception.cpp"
template <class Item>
class Queue{
  struct Element
{
  Item inf;
  Element *next;
  Element(Item x) : inf(x), next(0) {}
};
Element *head, *tail;
public:
Queue() : head(0), tail(0){}
bool Empty(){
  return head == 0;
}
Item Get(){
  if (Empty()){
    //throw QueueException("QueueException: get - queue empty");
  }
  else{
    Element *r = head;
    Item i = r->inf;
    head = r->next;
    if(head == NULL){
      tail = NULL;
    }
    delete r;
    return i;
  }
}
void Put(Item data){
  Element *r = tail;
  tail = new Element(data);
  if (!head){
    head = tail;
  }
  else{
    r->next = tail;
  }
}
};