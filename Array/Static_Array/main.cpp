#include<iostream>
#include"Array.h"

using namespace std;

int main()
{
   Array<int>a(7);
   a.Append(60);
   a.Append(30);
   a.Append(50);
   a.Append(10);
   a.Append(20);
a.Display();
a.InSertion_sort();
a.Display();
cout<<a.Get_size();

  // a.InSertion_sort();
  // a.Display();
 // if(a.linear_search(5))cout<<"yes"<<endl;else cout<<"no"<<endl;
  // if(a.Binary_search(20))cout<<"yes"<<endl;else cout<<"no"<<endl;
    return 0;
}
