#include <iostream>
using namespace std;
template<class T>
class Circular_Queue
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
        for(size_t i=0; i<size_of_queue; i++)
        {
            newQueue[i]=Queue[(front+i)%capacity];
        }
        delete []Queue;
        Queue =newQueue;
        capacity=newcapacity;
        rear=size_of_queue-1;
        front=0;
    }
    //IsEmpty
    bool IsEmpty()
    {
        return front==-1;
    }
    //IsFull
    bool IsFull()
    {
        return (rear+1)%capacity==front;
    }
public:
    Circular_Queue(size_t capacity=2):capacity(capacity)
    {
        Queue=new T[capacity];
        front=rear=-1;
        size_of_queue=0;
    }
    ~Circular_Queue()
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
        rear=(rear+1)%capacity;
        Queue[rear]=element;
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
            front=(front+1)%capacity;
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
            for(size_t i=0; i<size_of_queue; i++)
            {
                cout<<Queue[(front+i)%capacity]<<" ";
            }
            cout<<endl;
        }

    }

};



int main()
{
    Circular_Queue<double>sq;
    sq.Enqueue(6);
    sq.Enqueue(7);
    sq.Enqueue(9);
    sq.Enqueue(10);
    sq.Enqueue(15);
    sq.display();
    sq.Dequeue();
    //sq.display();
    sq.Dequeue();
    sq.display();
    sq.Enqueue(55);
    sq.display();
    sq.Enqueue(919);
    sq.display();
    sq.Enqueue(33);
    sq.display();

    double x=sq.peek();
    cout<<x<<endl;
    cout<<sq.getsize()<<endl;
    return 0;
}
