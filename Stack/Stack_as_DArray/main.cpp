#include <iostream>
using namespace std;
template<class T>
class Stack_AS_Darray{
private:
    T*arr;
    size_t capacity;
    int top_ptr;
public:
    Stack_AS_Darray(size_t capacity=2):capacity(capacity){
    arr=new T[capacity];
    top_ptr=-1;//no element
    }
    ~Stack_AS_Darray(){
    delete arr;
    }

    //is a helper function to resize capacity if this need
    void resize_capacity(size_t new_capacity){
        T *new_arr=new T[new_capacity];
        for(size_t i=0;i<=top_ptr;i++){
            new_arr[i]=arr[i];
        }
        delete []arr;
        arr=new_arr;
        capacity=new_capacity;
    }
    //to check if stack is empty or not
    bool IsEmpty()const{
    return (top_ptr==-1);
    }
    //to check if stack is full or not
    bool IsFull()const{
    return (top_ptr+1==capacity);
    }
    //push :add element from top and print this if added
    void push(const T element){
        if(IsFull()){
            resize_capacity(capacity*2);
        }
        arr[++top_ptr]=element;
        cout<<arr[top_ptr]<<" pushed in stack .\n";
    }
    //pop :remove element at top and print this if remove
    void pop(){
        if(IsEmpty()){
            cout<<"Already stack is empty .\n";
        }else {
            T element_of_remove=arr[top_ptr--];
            cout<<element_of_remove<<" Pop from stack .\n";
            if(capacity/2>top_ptr&&capacity>2){ //if element in stack less than 0.5 capacity
                resize_capacity(capacity/2);//capacity= capacity /2
            }
        }

    }
    //return end element (top element).
    T peek()const{
        if(IsEmpty()){
            cout<<"Stack is empty .\n";
            return 0;
        }
    return arr[top_ptr];
    }
    //return size of stack
    size_t getsize()const{
    return top_ptr+1;
    }
    //return capacity of stack
    size_t getcapacity()const{
    return capacity;
    }
    //delete all element of stack
    void clear_stack(){
        top_ptr=-1;
    capacity=2;
    delete arr;
    }
    void display()const{
    if(IsEmpty()){
        cout<<"Stack is empty .\n";
        return;
    }
         for(size_t i=0;i<getsize();i++){
            cout<<arr[i]<<" ";
        }
    cout<<"\n";


    }

};




int main()
{
    Stack_AS_Darray<size_t>s;
    s.push(2);
    s.push(4);
    s.push(20);
    s.push(22);
    s.push(9);
    s.push(0);
    cout<<"capacity :"<<s.getcapacity()<<"\n Size :"<<s.getsize()<<"\n";
    s.display();
    s.pop();
    cout<<"capacity :"<<s.getcapacity()<<"\n Size :"<<s.getsize()<<"\n";
    s.display();
    cout<<s.peek()<<"\n";
    s.display();
    s.clear_stack();
    s.display();
cout<<"capacity :"<<s.getcapacity()<<"\n Size :"<<s.getsize()<<"\n";
s.pop();
cout<<s.peek()<<"\n";
    return 0;
}
