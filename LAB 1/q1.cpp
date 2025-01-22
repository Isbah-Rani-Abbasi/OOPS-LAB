// Write a program that finds the second highest number in a float type array of 20
// elements using pointer.
# include<iostream>
using namespace std;
float find( float *array , int size);
int main()
{
    int size;
    cout<< "Enter the size of array:"<<endl;
    cin>>size;
    float array[size];
    int i;
    for (i=0 ; i<size ;i++)
    {
        cout<<"Enter the "<<i+1<<" element of array:\n";
        cin>>array[i];
    }
    float result = find (array , size);
    cout<<"The second highest element of array is:"<<result<<endl;

}
float find( float *array , int size)
{
  float highest = array[0];
  float secondHighest = array[1];
  float temp;
  int i;
  if (secondHighest > highest)
  {
    temp = secondHighest;
    secondHighest = highest;
    highest = temp;
  }
  for ( i =2 ; i<size ; i++)
  {
    if (array[i]>highest)
    {
        secondHighest = highest;
        highest = array[i];
    }
    else if (array[i] > secondHighest && array[i] != highest)
    {
        secondHighest = array[i];
    }
  }
  return secondHighest;
}
