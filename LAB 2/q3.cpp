// Write a program that can resize a single dimension int array if the elements exceed the total size.
// Consider an int array of size 5 (uninitialized), you start adding items to the array and if the quantity of
// the elements exceeds double the array size. Once finished resizing the array again to the max quantity of
// the elements present in the array.
#include <iostream>
#include <cstring> // For std::memcpy
using namespace std;

int main() {
    int initialsize =5;
    int size=initialsize;
   int *arr1 =new int[initialsize];
  
   int flag=0 , i=0 , check=0 ,j=0;
   while (1)
   {
    cout<<"Enter the element or -1 to break:\n";
    cin>>check;
    if (check == -1)
    {
        break;
    }
    if (i>=size)
    {
       int  newsize=size*2;
        int  *arr2 = new int[newsize];
        memcpy(arr2 , arr1 , size*sizeof(int));
        delete[] arr1;
        arr1=arr2;
        size = newsize;
       
    }
   arr1[i]=check;
   i++;
   }
   if (i<size)
   {

    int *temp = new int[size];
    memcpy(temp , arr1, size * sizeof(int));
    delete[] arr1;
    arr1 = temp;
    size =i ;
   }
   
    cout<<"element of array"<<endl;
    for (j=0;j<size;j++)
    {
        cout<<arr1[j]<<" ";
    }
    delete[] arr1;
    return 0;
   
}
