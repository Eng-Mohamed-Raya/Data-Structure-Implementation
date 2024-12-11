#include <iostream>
using namespace std;
template<class T>
struct Node{
    T Data;
    size_t priority;
    Node<T>*ptr_nextnode;
    Node(T element,size_t priority){
    Data=element;
    this->priority=priority;
    ptr_nextnode=nullptr;
    }
};
template<class T>
class Priority_Queue{
private:
    Node<T>*head;
   bool IsEmpty(){
    return head==nullptr;
    }
public:
    Priority_Queue():head(nullptr){}
    ~Priority_Queue(){
    Node<T>*temp=head;
    while(temp!=nullptr){
            delete head;
        temp=temp->ptr_nextnode;
        head=temp;
    }
    }
    //Enqueue
    void Enqueue(T element,size_t priotity_element){
        Node<T>*newNode=new Node<T>(element,priotity_element);
        if(IsEmpty()||priotity_element>head->priority){//if queue empty or priority element of first node less than priority element of new node
            newNode->ptr_nextnode=head;
            head=newNode;
        }else{
            Node<T>*temp=head;
        while(temp->ptr_nextnode!=nullptr&&priotity_element<=temp->ptr_nextnode->priority){
            temp=temp->ptr_nextnode;
        }
        newNode->ptr_nextnode=temp->ptr_nextnode;
        temp->ptr_nextnode=newNode;
        }
    }
    //Dequeue
    void Dequeue(){
    if(IsEmpty()){
        cout<<"Already Queue is empty...\n";
        return;
    }
    Node<T>*temp=head;
    head=head->ptr_nextnode;
    T element=temp->Data;
    delete temp;
    cout<<element<<" is Dequeued .\n";
    }
    //peek (get element)
    T peek(){
    if(IsEmpty()){
        cout<<"Queue is empty...\n";
        return NULL;
    }
    return head->Data;
    }
    //get priority element
    size_t get_priority_element(){
    if(IsEmpty()){
        cout<<"Queue is empty...\n";
        return 0;
    }
    return head->priority;
    }
    //display
    void display(){
     if(IsEmpty()){
        cout<<"Queue is empty...\n";
        return;
    }
    Node<T>*temp=head;
    cout<<"[ ";
    while(temp!=nullptr){
        cout<<temp->Data<<"||"<<temp->priority<<" ";
        temp=temp->ptr_nextnode;
    }
    cout<<"]\n";
    }

};




int main()
{
    Priority_Queue<char>pq;
    pq.Enqueue('A',3);
    pq.Enqueue('C',8);
    pq.Enqueue('B',3);
    pq.display();
    pq.Enqueue('Z',3);
    pq.display();
    pq.Dequeue();
    pq.display();
  cout<<pq.peek()<<endl;
cout<<pq.get_priority_element();
    return 0;
}
