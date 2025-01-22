// Write a program that calculates the sum of all the elements in array using pointers
# include<iostream>
using namespace std;
int sum( int * array , int size);
int main()
{
    int size;
    cout <<"Enter the size of array:\n";
    cin >> size ;
    int array[size];
    int i;
    for (i=0 ;i<size ;i++)
    {
        cout <<"Enter the "<<i+1<<" element:\n";
        cin>>array[i];
    }
    int result = sum (array , size);
    cout<<"The sum of given array is :" << result<<endl;
}
int sum( int * array , int size)
{
    int sum = 0 , i;
    for (i=0 ; i<size ; i++)
    {
        sum +=array[i];
    }
    return sum;
}