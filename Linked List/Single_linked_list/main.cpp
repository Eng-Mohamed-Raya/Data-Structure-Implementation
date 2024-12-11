#include <iostream>
using namespace std;
template <class T>
struct Node
{
public :
    T data;
    Node *Next;//self referential structure

    Node(T data):Next(nullptr)
    {
        this->data=data;
    }
};
template <class T>
class Sll
{
private:
    Node<T> *head;

public:
    Sll():head(nullptr) {} //defoult constractor

    T midlle_element()const{
    if(head==nullptr){
            cout<<"No Element. \n";
            return NULL;
        }else{
            size_t mid=1+(get_size()-1)/2;
            Node<T>*temp=head;
            for(size_t i=1;i<mid;i++){
                temp=temp->Next;
            }
            return temp->data;
        }
    }

    //traverse :access the elements from list (display linked list element)
    void traverse()const
    {
        Node <T>* node=head;
        if(head==nullptr)
            cout<<"No Element. \n";
        else
        {
            while(node)
            {
                cout<<node->data<<" ";
                node=node->Next;
            }
        }
    }

    //get size :get number of elements in list
    size_t get_size()const
    {
        Node<T>* node=head;
        int num_of_element=0;
        if(head==nullptr)
            num_of_element=0;
        else
        {
            while(node)
            {
                num_of_element++;
                node=node->Next;
            }
        }
        return num_of_element;
    }

    //---Inserts---
    //1:-Insert (add) element at beginning
    void insert_begin(T value)
    {
        Node<T>* newNode=new Node<T>(value);
        if(head==nullptr) //if list is null (not elements in list)
        {
            head=newNode;
            newNode->Next=nullptr;

        }
        else
        {
            newNode->Next=head;
            head=newNode;
        }

    }

    //2:-add element at end
    void Append(T value)
    {
        Node<T>* newNode=new Node<T>(value);
        if(head==nullptr) //if list is null (not elements in list)
        {
            head=newNode;
            newNode->Next=nullptr;

        }
        else
        {
            Node<T>* temp=head;
            for(int i=1; i<get_size(); i++)
                temp=temp->Next;
            temp->Next=newNode;
            newNode->Next=nullptr;
        }


    }

    //3:-Insert (add) element at position
    void insert_from_position(size_t position,T value)
    {
        if(position>get_size())cout<<"Out of range ...!\n";
        else
        {
            Node<T>* newNode=new Node<T>(value);
            if(head==nullptr) //if list is null (not elements in list)
            {
                head=newNode;
                newNode->Next=nullptr;

            }

            else
            {
                Node<T>* temp=head;
                for(int i=1; i<position-1; i++)
                    temp=temp->Next;
                newNode->Next=temp->Next;
                temp->Next=newNode;
            }
        }
    }

    //---Deletes---
    //1:-Deletes element from beginning
    void delete_from_begin()
    {
        if(head==nullptr)cout<<"List is empty...!\n";
        else
        {
            Node<T>*temp=head;
            head=head->Next;
            delete temp;//delete first node(data and address)
        }
    }


    //2:-Deletes element from end
    void delete_from_end()
    {
        if(head==nullptr)cout<<"List is empty...!\n";
        else if(head->Next==nullptr)  //if the list contain one node
        {
            delete head;
            head=nullptr;
        }
        else
        {
            Node<T>*temp=head;
            size_t n=get_size();
            for(size_t i=1; i<n-1; i++)
                temp=temp->Next;
            Node<T>*endNode=temp->Next;
            temp->Next=nullptr;
            delete endNode;//delete end node(data and address)
        }
    }

    //3:-Deletes element from Position
    void delete_from_position(size_t position)
    {
        if(head==nullptr)cout<<"List is empty...!\n";
        else if(position>get_size())cout<<"Out of range ...!\n";
        else if(position==1)  //if the position equal one
        {
            delete_from_begin();
        }
        else
        {
            Node<T>*temp=head;
            for(size_t i=1; i<position-1; i++)
                temp=temp->Next;
            Node<T>*positionNode=temp->Next;
            temp->Next=positionNode->Next;
            delete positionNode;//delete node at position(data and address)
        }
    }
    //Clear list
    void clear_list()
    {
        if(head==nullptr)cout<<"List is empty...!\n";
        else
        {

            Node<T>*delete_element=head;
            while(delete_element!=nullptr)
            {
                Node<T>*temp=delete_element->Next;
                delete delete_element;
                delete_element=temp;
            }
            head=nullptr;
        }
    }
    //Search
    bool search_element(const T element)const
    {
        if(head==nullptr)cout<<"List is empty...!\n";
        else
        {
            Node<T>*iselement=head;
            for(size_t i=1; i<=get_size(); i++)
            {
                if(iselement->data==element)return true;
                iselement=iselement->Next;
            }

        }
        return false;

    }
    Node<T> *tail()const
    {
        Node<T>*tails=head;
        for(size_t i=1; i<=get_size(); i++)
        {
            tails=tails->Next;
        }
        return tails;
    }

    //Reverse list elements
    void reverse_list()
    {
        if(head==nullptr)cout<<"List is empty...!\n";
        else
        {
            Node<T> *newhead,*start,*end;
            newhead=nullptr;
            start=head;
            end=start->Next;
          while(end!=nullptr)
            {
                end=start->Next;
                start->Next=newhead;
                newhead=start;
                start=end;
            }
            head=newhead;
        }

    }
    friend istream&operator>>(istream&input,Sll&element)
    {
        T value;
        input>>value;
        element.Append(value);
        return input;
    }
    friend ostream&operator<<(ostream&output,Sll&element)
    {
        Node<T>*node=element.head;
        while(node!=nullptr)
        {
            output<<node->data<<" ";
            node=node->Next;
        }
        return output;
    }
    Sll& operator=(const Sll&lis) //lis=list
    {
        if(this!=&lis) //if sender list not equal this list
        {
            clear_list();//delete the list
            if(lis.head==nullptr) //if sender list is empty
            {
                head=nullptr;//the list will be empty
            }
            else
            {
                Node<T>*newhead=lis.head;
                head=new Node<T>(newhead->data);
                Node<T>*current=head;
                while(newhead->Next!=nullptr)
                {
                    newhead=newhead->Next;
                    current->Next=new Node<T>(newhead->data);
                    current=current->Next;
                }
            }
        }
        return *this;
    }

};
int main()
{
    Sll <int>s;
    s.traverse();
    cout<<"\nAppend element ----------\n";
    s.Append(10);
    s.Append(5);
    s.Append(1);
    s.Append(100);
    s.traverse();
    cout<<"\nmidle id:"<<s.midlle_element();
    cout<<"\ninsert from begin element ----------\n";
    s.insert_begin(9);
    s.traverse();
        cout<<"\nmidle id:"<<s.midlle_element();

    cout<<"\ninsert from position element ----------\n";
    s.insert_from_position(4,50);
    s.traverse();
    cout<<"\nsearch element ----------\n";
    s.search_element(3)?cout<<"found\n":cout<<"Unfound\n";
    cout<<"\nsize of element ----------\n";
    cout<< s.get_size();
    cout<<"\nreverse element ----------\n";
    // s.traverse();
    s.reverse_list();
    s.traverse();
    // cout<<"\ncleard element ----------\n";
  //  s.clear_list();
    //  s.traverse();
    cout<<"\ndelete last element ----------\n";
    s.Append(0);
    // s.delete_from_position(1);
    // s.insert_from_position(3,9);
    // s.traverse();
    cin>>s;
    cout<<s;
     Sll <int>s1;
     cout<<s1<<endl;
     s1=s;
     cout<<s1;
    return 0;
}
