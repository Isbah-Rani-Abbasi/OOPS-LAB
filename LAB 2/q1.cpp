// Task 1: Write a program that calculates the sum of all the elements in array using pointers
// (Note: Generate the array via user in the main function use argv)
# include<iostream>
# include<string>
using namespace std;
int main(int argc , char *argv[])
{
    int sum=0;
    for (int i=1; i<argc ; i++)
    {
        sum=sum + atoi(argv[i]);
    }
    cout <<"The sum of array is: "<<sum;
}