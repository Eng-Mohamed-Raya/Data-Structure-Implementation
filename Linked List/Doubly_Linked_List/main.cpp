#include <iostream>
using namespace std;
template<class T>

struct Node
{
public:
    T data;
    Node *ptr_last_node;
    Node* Next_node;


    Node(T element):data(element),ptr_last_node(nullptr),Next_node(nullptr) {}
};
template<class T>
class DLL
{
private:
    Node<T>* head;
    Node<T>* tail;
    // static  size_t numbers_of_nodes;
public:
    size_t numbers_of_nodes=0;
    DLL():head(nullptr),tail(nullptr) {}
    //traverse
    void traverse()const
    {
        if(numbers_of_nodes==0)cout<<"The list is empty..."<<endl;
        else
        {
            Node<T>*temp=head;
            for(size_t i=1; i<=numbers_of_nodes; i++)
            {
                cout<<temp->data<<endl;
                temp=temp->Next_node;
            }
        }


    }
    //get element
    T get_element(size_t position)const
    {
        if(numbers_of_nodes==0)cout<<"The list is empty..."<<endl;
        else if(position>numbers_of_nodes )cout<<"Out Of Range...\n";
        else
        {
            Node<T> *temp=head;
            for(size_t i=1; i<=position-1; i++)
            {
                temp=temp->Next_node;

            }
            cout<<temp->data;
        }
    }

    //return numbers of nodes
    size_t size_of_list()const
    {
        return numbers_of_nodes;
    }

    //insert element
    //1: Append
    void Append(T element)
    {
        Node<T>*newNode=new Node <T>(element);
        numbers_of_nodes++;
        if(head==nullptr&&tail==nullptr)
        {
            head=tail=newNode;
        }
        else
        {
            newNode->ptr_last_node=tail;
            tail->Next_node=newNode;
            newNode->Next_node=nullptr;
            tail=newNode;
        }
    }

    //2-insert

    void insert_at_begin(T element)
    {
        Node<T>*newNode=new Node<T>(element);
        numbers_of_nodes++;
        if(head==nullptr&&tail==nullptr)
        {
            head=tail=newNode;
        }
        else
        {
            newNode->Next_node=head;
            head->ptr_last_node=newNode;
            newNode->ptr_last_node=nullptr;
            head=newNode;
        }
    }

    //3.insert at position
    void insert_at_position(T element,size_t position)
    {


        if(numbers_of_nodes==0&&position!=1)cout<<"The list is empty..."<<endl;
        else if(position>numbers_of_nodes &&position!=1)cout<<"Out Of Range...\n";
        else if(position ==numbers_of_nodes)
        {
            Append(element);
        }
        else if(position ==1)
        {
            insert_at_begin(element);
        }
        else
        {
            Node<T>*newNode=new Node<T>(element);
            Node<T> *first=head,*last=tail;

            for(size_t i=2; i<position; i++)
            {
                first=first->Next_node;
            }
            for(size_t j=numbers_of_nodes-1; j>=position; j--)
            {
                last=last->ptr_last_node;
            }
            newNode->ptr_last_node=first;
            newNode->Next_node=last;
            first->Next_node=newNode;
            last->ptr_last_node=newNode;
            numbers_of_nodes++;

        }
    }

    //search
    bool Search(T element)const
    {
        if(numbers_of_nodes==0)cout<<"The list is empty..."<<endl;
        else
        {
            Node<T>*temp=head;
            for(size_t i=1; i<=numbers_of_nodes; i++)
            {
                if(element==temp->data)return true;
                temp=temp->Next_node;
            }
        }
        return false;
    }


    //reverse
    void reverse_list()
    {
        if(numbers_of_nodes==0)cout<<"The list is empty..."<<endl;
        else
        {
            Node<T>* current = head;
            Node<T>* temp = nullptr;

            // Swap next and prev pointers for each node to reverse the list
            while (current != nullptr)
            {
                temp = current->ptr_last_node;
                current->ptr_last_node = current->Next_node;
                current->Next_node = temp;
                current = current->ptr_last_node;
            }

            // Swap head and tail
            temp = head;
            head = tail;
            tail = temp;
        }

    }


    //operator overload

    friend istream &operator>>(istream&input,DLL&value)
    {
        T element;
        input>>element;
        value.Append(element);
        return input;

    }
    friend ostream &operator<<(ostream&output,DLL&element)
    {
        Node<T>*node=element.head;
        while(node!=nullptr)
        {
            output<<node->data<<" ";
            node=node->Next_node;
        }
        return output;

    }
    DLL& operator=(const DLL&lis) //lis=list
    {
        if(this!=&lis) //if sender list not equal this list
        {
            clear_list();//delete the list
            if(lis.head==nullptr) //if sender list is empty
            {
                head=tail=nullptr;//the list will be empty
            }
            else
            {
                Node<T>*newhead=lis.head;
                head=new Node<T>(newhead->data);
                Node<T>*current=head;
                while(newhead->Next_node!=nullptr)
                {
                    newhead=newhead->Next_node;
                    current->Next_node=new Node<T>(newhead->data);
                    current=current->Next_node;
                }
            }
        }
        return *this;
    }
 bool operator==( DLL<T>&other){
     if(numbers_of_nodes!=other.numbers_of_nodes)return false;
     else{
        Node<T>*first=head;
        Node<T>*first_other=other.head;
        for(size_t i=1;i<=numbers_of_nodes;i++){
            if(first->data!=first_other->data)return false;
            first=first->Next_node;
            first_other=first_other->Next_node;
        }

         return true;
     }

 }




    //----Deleted----
    //1.delete from end (remove)
    void delete_from_end()
    {
        if(numbers_of_nodes==0)cout<<"The list is empty..."<<endl;
        else if(numbers_of_nodes==1)
        {
            delete head;
            head=tail=nullptr;
            numbers_of_nodes--;
        }
        else
        {
            Node<T> *temp=tail;
            tail=tail->ptr_last_node;
            if (tail)
            {
                tail->Next_node = nullptr;
            }
            delete temp;
            numbers_of_nodes--;

        }
    }
    //2.delete from begin
    void delete_from_begin()
    {
        if(numbers_of_nodes==0)cout<<"The list is empty..."<<endl;
        else if(numbers_of_nodes==1)
        {
            delete head;
            head=tail=nullptr;
            numbers_of_nodes--;
        }
        else
        {
            Node<T> *temp=head;
            head=head->Next_node;
            tail->ptr_last_node=nullptr;
            delete temp;
            numbers_of_nodes--;

        }
    }

    //3.delete from position
    void delete_from_position(size_t position)
    {
        if (numbers_of_nodes == 0)
        {
            cout << "The list is empty..." << endl;
        }
        else if (numbers_of_nodes == 1 && position == 1)
        {
            delete head;
            head = tail = nullptr;
            numbers_of_nodes--;
        }
        else if (position > numbers_of_nodes)
        {
            cout << "Out Of Range...\n";
        }
        else if (position == numbers_of_nodes)
        {
            delete_from_end();
        }
        else
        {
            Node<T> *first = head;

            for (size_t i = 1; i < position - 1; i++)
            {
                first = first->Next_node;
            }


            Node<T> *temp = first->Next_node;


            first->Next_node = temp->Next_node;
            if (temp->Next_node)
            {
                temp->Next_node->ptr_last_node = first;
            }
            else
            {
                tail = first;
            }

            delete temp;
            numbers_of_nodes--;
        }
    }
//delete every elements
    void clear_list()
    {
        if(numbers_of_nodes==0)cout<<"The list is empty..."<<endl;
        else
        {
            Node<T>*temp=head;
            for(size_t i=1; i<=numbers_of_nodes; i++)
            {
                temp=temp->Next_node;
                delete head;

                head=temp;
            }
            head=tail=nullptr;
            numbers_of_nodes=0;
        }

    }


};





int main()
{
    DLL<DLL<int>>play_list;



    /*
    DLL<int>node;
    DLL<int>node2=node;
(node==node2)?cout<<"true":cout<<"false";
    cout<<"append\n";
    node.Append(5);
    node.Append(7);
    node.Append(1);
    node.traverse();
    (node==node2)?cout<<"true":cout<<"false";
    cout<<"Reverse\n";
    node.reverse_list();
    node.traverse();
    (node==node2)?cout<<"true":cout<<"false";

      cout<<"insert from begin\n";
        node.insert_at_begin(15);
              node.traverse();
        cout<<"insert from pos\n";
         node.insert_at_position(20,2);
               node.traverse();
                cout<<"delete\n";
         node.clear_list();
               node.traverse();
      cout<<"size "<<node.size_of_list()<<endl;;
        cout<<"delet from begin\n";
         node.delete_from_begin();
               node.traverse();
        cout<<"delete from pos\n";
        node.delete_from_position(2);
              node.traverse();
        cout<<"delete from end\n";
        node.delete_from_end();
              node.traverse();
      cout<<" get \n";
        node.get_element(3);*/
    // node.insert_at_position(5,4);
    // node.insert_at_position(5,4);

    return 0;
}
