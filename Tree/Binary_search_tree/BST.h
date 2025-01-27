#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<iostream>
#include<queue>
using namespace std;
template<class T>
struct Node
{
public:
    Node<T>*right_child;
    Node<T>*left_child;
    T data;
    Node(T data):data(data)
    {
        right_child=left_child=nullptr;
    }

};

template<class T>
class Binary_Search_Tree
{
private:
    Node<T>*root;
    //helper insertion function
    Node<T>* insert_node(Node<T>*sub_root,T element) //sub_root ->root of subtree
    {
        if(sub_root==nullptr)
        {
            sub_root=new Node<T>(element);
            return sub_root;
        }
        if(sub_root->data>element)
        {
            sub_root->left_child=insert_node(sub_root->left_child,element);
        }
        else // sub_root->data<=element
        {
            sub_root->right_child=insert_node(sub_root->right_child,element);
        }
        return sub_root;
    }
    //helper traverse function
    void traverse_in_order(Node<T>*node)
    {
        if(node!=nullptr)
        {
            traverse_in_order(node->left_child);
            cout<<node->data<<" ";
            traverse_in_order(node->right_child);
        }
    }
    //helper search function
    Node<T>* _search(Node<T>*sub_root,T element)
    {
        if(sub_root==nullptr)return nullptr;
        if(sub_root->data==element)return sub_root;
        if(element<sub_root->data)
        {
            return _search(sub_root->left_child,element);
        }
        else
        {
            return _search(sub_root->right_child,element);
        }
    }
    //helper function to return address of min node
    Node<T>*min_node(Node<T>*sub_root)
    {
        if(sub_root==nullptr)return nullptr;
        if(sub_root->left_child==nullptr)return sub_root;
        return min_node(sub_root->left_child);
    }
    //helper function to return address of max node
    Node<T>* max_node(Node<T>*sub_root)
    {
        if(sub_root==nullptr)return nullptr;
        if(sub_root->right_child==nullptr)return sub_root;
        return max_node(sub_root->right_child);
    }
    //delete node
    Node<T>* _delete(Node<T>*sub_root,T element)
    {
        if(element<sub_root->data)
        {
            sub_root->left_child=_delete(sub_root->left_child,element);
        }
        else if(element>sub_root->data)
        {
            sub_root->right_child=_delete(sub_root->right_child,element);
        }
        else
        {
            //leaf node
            if(sub_root->left_child==nullptr && sub_root->right_child==nullptr)
            {
                sub_root=nullptr;
            }
            else
                //internal node contain one child in left
                if(sub_root->left_child!=nullptr && sub_root->right_child==nullptr)
                {
                    Node<T>*temp=sub_root;
                    sub_root=sub_root->left_child;
                    delete temp;
                }
                else
                    //internal node contain one child in right
                    if(sub_root->left_child==nullptr && sub_root->right_child!=nullptr)
                    {
                        Node<T>*temp=sub_root;
                        sub_root=sub_root->right_child;
                        delete temp;
                    }
                    else //internal node contain two child
                    {
                        //role of max in left childs
                        Node<T>*Max=max_node(sub_root->left_child);
                        sub_root->data=Max->data;
                        sub_root->left_child=_delete(sub_root->left_child,Max->data);
                            /*
                            //role of min in right childs
                            Node<T>*Min=min_node(sub_root->right_child);
                            sub_root->data=Min->data;
                            sub_root->right_child=_delete(sub_root->right_child,Min->data);
                            */
                    }
        }

        return sub_root;
    }
public:
    Binary_Search_Tree():root(nullptr) {}
    ~Binary_Search_Tree() {}

    //insertion function
    void insert_node(T element)
    {
        (root==nullptr)?root=new Node<T>(element) :root=insert_node(root,element);
    }
    //traverse
    void traverse()
    {
        if(root==nullptr)cout<<"tree is null...";
        else traverse_in_order(root);
        cout<<"\n";
    }
    //Search
    bool _search(T element)
    {
        Node<T>*is_found= _search(root,element);
        if(is_found!=nullptr)return true;
        return false;
    }
    //min element
    T _min_element()
    {
        Node<T>*result=min_node(root);
        return result->data;
    }
    //max element
    T _max_element()
    {
        Node<T>*result=max_node(root);
        return result->data;
    }
    //delete node
    void _delete(T element)
    {
        _delete(root,element);
        return;
    }
};



#endif // BST_H_INCLUDED
