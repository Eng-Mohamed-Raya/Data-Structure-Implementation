#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED
#include<iostream>
#include<queue>
using namespace std;
template<class T>
struct Node{
public:
    T data;
    Node*left;
    Node*right;
    Node(T data):data(data),left(nullptr),right(nullptr){}
};
template<class T>
class Binary_Tree{
private:
    Node<T>*root;
public:
    Binary_Tree():root(nullptr){}
    ~Binary_Tree(){}
    //insert by level order
    void insert_by_LO(T element){
        if(root==nullptr){
            root=new Node<T>(element);
            return;
        }
        queue<Node<T>*>q;
        q.push(root);
        while(!q.empty()){
            Node<T>*current=q.front();
            q.pop();

            if(!current->left){
                current->left=new Node<T>(element);
                return;
            }else{
                q.push(current->left);
            }
              if(!current->right){
                current->right=new Node<T>(element);
                return;
            }else{
                q.push(current->right);
            }
        }

    }


  //traversals
        //breadth first search algorithm (BFS):
            //level order
            void travers_level_order()const{
                if(root!=nullptr){
                    queue<Node<T>*>q;
                    q.push(root);
                    while(!q.empty()){
                         Node<T>*current=q.front();
                        q.pop();
                        cout<<current->data<<" ";
                        if(current->left!=nullptr)q.push(current->left);
                        if(current->right!=nullptr)q.push(current->right);
                    }

                }
            }
          //Depth first search algorithm (DFS) :
            //1.pre order root->left->right
            void pre_order(Node<T>*node)const{
             if(node!=nullptr){
                cout<<node->data<<" ";
                pre_order(node->left);
                pre_order(node->right);
             }
            }
            //to call in main function
            void traverse_pre_order()const{
                    pre_order(root);
                }
                //2.in order left->root->right
            void in_order(Node<T>*node)const{
             if(node!=nullptr){
                in_order(node->left);
                cout<<node->data<<" ";
                in_order(node->right);
             }
            }
            //to call in main function
            void traverse_in_order()const{
                    in_order(root);
                }
                //3.post order left->right->root
            void post_order(Node<T>*node)const{
             if(node!=nullptr){
                post_order(node->left);
                post_order(node->right);
                cout<<node->data<<" ";
             }
            }
            //to call in main function
            void traverse_post_order()const{
                    post_order(root);
                }
        //searching
         //- Depth First Search DFS
         bool search_DFS(Node <T>*se_root,T value){
        if(se_root==nullptr)return false;
         if(se_root->data==value)return true;
          bool left_search=search_DFS(se_root->left,value);
          bool right_search=search_DFS(se_root->right,value);
          return left_search || right_search;
         }
         bool Search(T value){
         return search_DFS(root,value);
         }

};

#endif // BINARY_TREE_H_INCLUDED
