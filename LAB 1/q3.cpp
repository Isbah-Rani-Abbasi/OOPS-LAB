// Write a program in C++ to calculate and print the Electricity bill of a given customer. The customer id,
// name and unit consumed by the user should be taken from the keyboard and display the total amount to
// pay to the customer. The charges are as follow:
# include<iostream>
# include<bits/stdc++.h>
# include<string>
using namespace std;
struct bill
{
    string name;
    int id;
    float unitsConsumed;
    float amountCharges;
    float surchargeAmout;
    float netAmout;
};
int main()
{
    struct bill b1;
    b1.surchargeAmout = 0;
    cout <<"Enter the name of customer:\n";
    getline(cin , b1.name);
    //cin>>b1.name;
    cout<<"Enter the customer id:\n";
    cin>>b1.id;
    cout<<"Enter the unit consumed by customer:\n";
    cin>>b1.unitsConsumed;
    if (b1.unitsConsumed >= 0 && b1.unitsConsumed <= 199)
    {
        b1.amountCharges = b1.unitsConsumed * 16.20;
    }
    else if (b1.unitsConsumed >= 200 && b1.unitsConsumed <300)
    {
        b1.amountCharges = b1.unitsConsumed * 20.10;
    }
    else if (b1.unitsConsumed >= 300 && b1.unitsConsumed <500)
    {
        b1.amountCharges = b1.unitsConsumed * 27.10;
    }
     else if (b1.unitsConsumed >= 500 )
    {
        b1.amountCharges = b1.unitsConsumed * 35.90;
    }

    if (b1.amountCharges > 18000)
    {
       b1.surchargeAmout = (b1.amountCharges * 15) / 100;
    }
    b1.netAmout = b1.surchargeAmout + b1.amountCharges ;
    cout <<"The name of customer: "<<b1.name<<endl;
    cout <<"The id of customer: "<<b1.id<<endl;
    cout <<"Total unit consumed: "<<fixed << setprecision(2)<<b1.unitsConsumed<<endl;
    cout <<"The charge amount: "<<fixed << setprecision(2)<<b1.amountCharges<<endl;
    cout <<"The surcharge amount: "<<fixed << setprecision(2)<<b1.surchargeAmout<<endl;
    cout <<"The NET amount: "<<fixed << setprecision(2)<<b1.netAmout<<endl;
}