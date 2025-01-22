// Write a program that prompts the user to enter the weight of a person in kilograms and outputs the
// equivalent weight in pounds. Output both the weights rounded to two decimal places. (Note that 1
// kilogram = 2.2 pounds.) Format your output with two decimal places.
# include<iostream>
# include<bits/stdc++.h>
using namespace std;
int main()
{
    float weightKGS , weightPOUN;
    cout <<"Enter the wiight in kilograms:\n";
    cin>>weightKGS;
    if (weightKGS < 0)
    {
      cout <<"Invalid input! Since weight is a positive quantity.\n";
    }
    else
    {
    weightPOUN = weightKGS * 2.2 ;
    cout <<"The given weight in pounds is: " << fixed << setprecision(2) <<weightPOUN ;
    }
}