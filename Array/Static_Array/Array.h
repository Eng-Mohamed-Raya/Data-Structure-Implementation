#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include<stdexcept>
#include<iostream>
using namespace std;
template<class T>
class Array
{
private:
    int limit;
    int sizeofarray;
    T arr[];
public:

    Array(int limit)
    {
        this->limit=limit;
        arr[limit];
        sizeofarray=0;
    }
    //Append :add element from end
    void Append(T element)
    {
        if(sizeofarray>=limit)
        {
            throw overflow_error("Array is full...");
        }
        arr[sizeofarray++]=element;
    }
    //Insert :add element at specific location
    void Insert(T element,int index)
    {
        if(sizeofarray>=limit)
        {
            throw overflow_error("Array is full...");
        }
        if(index>sizeofarray)
        {
            throw overflow_error("Out of range...");
        }
        for(int i=sizeofarray; i>=index; i--)
        {
            arr[i]=arr[i-1];
        }
        arr[index]=element;
        sizeofarray++;
    }
    //remove element from end
    void Remove()
    {
        sizeofarray--;
    }
    //delete element at specific location
    void Delete(int index)
    {
        if(index>sizeofarray)
        {
            throw overflow_error("Out of range...");
        }
        for(int i=index; i<sizeofarray; i++)
        {
            arr[i]=arr[i+1];
        }
        sizeofarray--;
    }

    //return element at specific index
    T Get_element(int index)const
    {
        if(index>sizeofarray)
        {
            throw overflow_error("undefined...");
        }
        return arr[index];
    }
    //return size of  array
    int Get_size()const
    {
        return sizeofarray;
    }
    //reverse array element
    void Reverse()
    {
        int i=0,j=sizeofarray-1;
        while(i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }


//search algorithm
    //linear search
    bool linear_search(T element)
    {
        for(int i=0; i<sizeofarray; i++)
        {
            if(arr[i]==element)return true;
        }
        return false;
    }


    //Binary search

    bool Binary_search(T element)
    {
        int i=0,j=sizeofarray-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(arr[mid]==element)
            {
                return true;
            }
            else if(arr[mid]<element)
            {
                i=mid+1;
            }
            else j=mid-1;
        }

        return false;

    }

//sort algorithm

//Bubble sort
    void Bubble_sort()
    {
        bool flag=false;
        for(int i=0; i<sizeofarray-1; i++)
        {

            for(int j=0; j<sizeofarray-i-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                    flag=true;
                }

            }
            if(!flag) break;
        }

    }

//Selection sort

    void Selection_sort()
    {
        for(int i=0; i<sizeofarray-1; i++)
        {
            int min_index=i;
            for(int j=i+1; j<sizeofarray; j++)
            {
                if(arr[min_index]>arr[j])

                    min_index=j;
            }
            swap(arr[min_index],arr[i]);
        }
    }
//inSertion sort

    void InSertion_sort()
    {
        for(int i=1; i<sizeofarray; i++)
        {
            T key=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }


//Display element

    void Display()
    {
        for(int i=0; i<sizeofarray; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


#endif // ARRAY_H_INCLUDED
