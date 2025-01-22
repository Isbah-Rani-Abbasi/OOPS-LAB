# include<iostream>
# include<string>
# include<bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    getline (cin , name);
    float m1 , m2 , m3 , m4 , m5;
    cout<<"Enter the marks of five subjects:\n";
    cin >>m1>>m2>>m3>>m4>>m5;
    float average=(m1+m2+m3+m4+m5)/5;
    cout<<"The average marks of "<<name<<" is "<<fixed<<setprecision(3)<<average<<endl;
}