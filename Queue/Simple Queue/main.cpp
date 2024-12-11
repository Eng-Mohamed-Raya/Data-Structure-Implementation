#include <iostream>
using namespace std;
template<class T>
class Simple_Queue
{
private:
    size_t capacity,size_of_queue;
    int front,rear;
    T *Queue;

    //helper Functions
    //resize
    void resize(size_t newcapacity)
    {
        T*newQueue=new T[newcapacity];
        for(size_t i=front; i<=rear; i++)
        {
            newQueue[i]=Queue[i];
        }
        delete []Queue;
        Queue =newQueue;
        capacity=newcapacity;
    }
    //IsEmpty
    bool IsEmpty()
    {
        return front==-1;
    }
    //IsFull
    bool IsFull()
    {
        return rear==capacity-1;
    }
public:
    Simple_Queue(size_t capacity=2):capacity(capacity)
    {
        Queue=new T[capacity];
        front=rear=-1;
        size_of_queue=0;
    }
    ~Simple_Queue()
    {
        delete []Queue;
    }
    //Enqueue : add element to the end the queue (Append)
    void Enqueue(T element)
    {
        if(IsEmpty())
        {
            front=0;
        }
        else if(IsFull())
        {
            cout<<"Queue is Full . Resizing...\n";
            resize(capacity*2);
        }
        Queue[++rear]=element;
        cout<<Queue[rear]<<" added in Queue.\n";
        size_of_queue++;

    }
    //Dequeue : remove element from the front of the Queue (removed element from begin)
    void Dequeue()
    {
        if(IsEmpty())
        {
            cout<<"Already Queue is empty .\n";
        }
        else
        {
            cout<<"Done removed "<<Queue[front]<<" from Queue .\n";
            front++;
            size_of_queue--;
        }
        if(front>rear)
        {
            front=rear=-1;
            size_of_queue=0;
        }
        //shrink
        if(capacity/2>size_of_queue){
            resize(capacity/2);
        }
    }
    //peek (get front),get element from begin
    T peek()
    {
        if(IsEmpty())
        {
            cout<<"Queue is empty...\n";
            return NULL;
        }
        return Queue[front];
    }
    //get number of element in Queue
    size_t getsize()const
    {
        return size_of_queue;
    }
    //display all element
    void display()
    {
        if(IsEmpty())
        {
            cout<<"Queue is empty...\n";
        }
        else
        {
            for(size_t i=front; i<=rear; i++)
            {
                cout<<Queue[i]<<" ";
            }
            cout<<endl;
        }

    }

};



int main()
{
    Simple_Queue<double>sq;
    sq.Enqueue(1.2);
    sq.Enqueue(25);
    sq.Enqueue(10);
    sq.Enqueue(12.2555);
    sq.Enqueue(0.26);
    sq.display();
    sq.Dequeue();
    sq.display();
    sq.Dequeue();
    sq.display();
    double x=sq.peek();
    cout<<x<<endl;
    cout<<sq.getsize()<<endl;
    return 0;
}
