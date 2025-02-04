// Task 2: You are required to pass a single dimension array to a function (type of the array can be your
// choice) and perform add operations to each element. Return the array to the main function after
// completion. One small catch is that the arguments and the return type should be void*. (Create an array
// via the main arguments)
# include<iostream>
# include<string>
using namespace std;
void * multiply(void *arr , void * size,int multiply)
{
    int * pptr =(int*)arr;
    int  psize=*(int*)size;
   for (int i=0 ; i<psize ; i++)
   {
      multiply= multiply * pptr[i];
   }
   //cout<<multiply;
   void * ptr = (void*)&multiply;
   return ptr;
}
int main()
{
   int a=5;
   int arr[5]={1,2,3,4,5,};
   void * ptr=(void*) arr;
   void * retur=multiply (ptr , (void*)&a,1);
   int as=*(int*)retur;
   cout<<as;
}
