#include <iostream>
#include"BST.h"
using namespace std;

int main()
{
    cout << "\t\t\t   Hello everybody ." << endl;
    cout << "\t\t\tEng.Mohamed Yasser Raya ." << endl;
    cout << "\t\t.................................................." << endl;
    Binary_Search_Tree<char>bst;
     bst.traverse();
    cout<<"\n...Test insert function...\n";
    bst.insert_node('g');
    bst.insert_node('d');
    bst.insert_node('h');
    bst.insert_node('b');
    bst.insert_node('e');
    bst.insert_node('i');
    bst.insert_node('a');
    bst.insert_node('f');
    bst.insert_node('z');
    bst.insert_node('c');
    cout<<"\n...Test traverse function...\n";
    bst.traverse();
    cout<<"\n...Test search function...\n";
    if(bst._search('i'))cout<<"Is found .\n";
    else cout<<"Is not found .\n";
    cout<<"\n...Test max and min function...\n";
   cout<<"Min element in tree is "<<bst._min_element()<<endl;
   cout<<"Max element in tree is "<<bst._max_element()<<endl;
   cout<<"\n...Test delete function...\n";
    bst._delete('d');
    bst.traverse();
    return 0;
}
