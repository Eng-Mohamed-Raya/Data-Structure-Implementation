#include <iostream>
#include"Binary_Tree.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Binary_Tree<char>bt;
     if(bt.Search('n'))cout<<"True";
    else cout<<"false";
    char x;
    for(int i=1;i<=6;i++){
        cin>>x;
        bt.insert_by_LO(x);
    }
    bt.travers_level_order();
    cout<<endl;
    bt.traverse_pre_order();
    cout<<endl;
    bt.traverse_in_order();
    cout<<endl;
    bt.traverse_post_order();
    if(bt.Search('n'))cout<<"True";
    else cout<<"false";
    return 0;
}
