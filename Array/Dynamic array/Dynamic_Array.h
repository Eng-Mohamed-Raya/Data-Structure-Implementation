#ifndef DYNAMIC_ARRAY_H_INCLUDED
#define DYNAMIC_ARRAY_H_INCLUDED
#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class Array
{
private:
   size_t size;
   size_t capacity;
   T* arr;
   void resize(size_t newcapacity)
   {
       T* newarr=new T[newcapacity];
       for(size_t i=0;i<size;i++){
           newarr[i]=arr[i];
       }
       delete []arr;
       arr=newarr;
       capacity=newcapacity;
   }
public:
   Array(size_t cap=2) : capacity(cap),size(0)
   {
       arr=new T [capacity];
   }
   void Append(T element)
   {
       if(size>=capacity){
           resize(capacity * 2);
       }
       arr[size++]=element;
   }
   void insert(size_t pos,T element)
   {
       if(size>=capacity){
           resize(capacity * 2);
       }
       for(size_t i=size;i>=pos;i--){
           arr[i]=arr[i-1];
       }
       arr[pos]=element;
       size++;
   }
   void Remove(){
       size--;
       if(size < capacity/4)
       {
           resize(capacity/2);
       }
   }
   void Delete(size_t pos)
   {
       if(pos<0||pos>=size){
           throw out_of_range("out of range");
       }
       for(size_t i=pos;i<size;i++){
           arr[i]=arr[i+1];
       }
       size--;
       if(size < capacity/4)
       {
           resize(capacity/2);
       }
   }
   void reverse()
   {
       if(size==0)
         return;
       size_t start=0,end=size-1;
       while(start<end){
           T temp=arr[start];
           arr[start]=arr[end];
           arr[end]=temp;

           start++,end--;
       }
   }
   T Get(size_t pos) const
   {
       if(pos<0||pos>=size){
           throw out_of_range("out of range");
       }
       else
         return arr[pos];
   }
   size_t Getsize() const
   {
       return size;
   }
   void bubblesort()
   {
       for(size_t i=0;i<size-1;i++){
           for(size_t j=0;j<size-i-1;j++){
               if(arr[j]>arr[j+1]){
                   T temp=arr[j];
                   arr[j]=arr[j+1];
                   arr[j+1]=temp;
               }
           }
       }
   }
   size_t linearsearch(T key)
   {
       for(size_t i=0;i<size;i++){
           if(arr[i]==key)
             return i;
       }
       return -1;
   }
   size_t binaysearch(T key)
   {
       size_t lower=0,high=size-1,mid;
       while(lower<=high){
           mid=(lower+(high-lower))/2;
           if(arr[mid]==key)
             return mid;
           if(arr[mid]>key)
             high=mid-1;
           else
             lower=mid+1;
       }
       return -1;
   }
   void Access(size_t index,T item)
   {
       if(index>=0&&index<size){
           arr[index]=item;
       }
       throw out_of_range("out of range");
   }
   void Display()
   {
       for(size_t i=0;i<size;i++){
           cout<<arr[i];
       }
       cout<<endl;
   }
   void clear()
   {
       size=0;
       resize(2);
   }
   T operator [](size_t index){
    if(index>=0&&index<size){
     return arr[index];
    }
    throw out_of_range("out of range");
   }
   ~Array()
   {
       delete []arr;
   }

};



#endif // DYNAMIC_ARRAY_H_INCLUDED
