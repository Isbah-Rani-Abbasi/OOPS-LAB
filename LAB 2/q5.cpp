// Write a program that creates N structures. Inside each struct are two entities, id and name. You are
// required to first sort this structure first via ID then via the first character of the name in ascending order.
// Print all the struct data in both formations.
# include<iostream>
# include<string>
using namespace std;
struct person
{
  string name;
  int id;
};
int main()
{
 int n ,temp;
 string temp1;
 cout<<"Enter no of persons:"<<endl;
 cin>>n;
 struct person p[n];
 int i , j;
 for (i=0 ;i<n ;i++)
 {
    cout<<"Enter name of person "<<i+1<<":"<<endl;
    cin>>p[i].name;
    cout<<"Enter id of person "<<i+1<<";"<<endl;
    cin>>p[i].id;
 }
 cout<<"UNSORTED FORMATION!"<<endl;
 for (i=0 ;i<n ;i++)
 {
    cout<<"The name of person "<<i+1<<" is:"<<p[i].name<<endl;
    cout<<"The id of person "<<i+1<<" is:"<<p[i].id<<endl;
 }

 for (i=0 ;i<n ;i++)
 {
    for (j=0 ;j<n-1-i ;j++)
    {
        if (p[j].id > p[j+1].id)
        {
            temp = p[j].id;
            p[j].id = p[j+1].id;
            p[j+1].id = temp;
        }
    }
   
 }
 cout<<"SORTED FORMATION THROUG ID!"<<endl;
 for (i=0 ;i<n ;i++)
 {
    cout<<"The name of person "<<i+1<<" is:"<<p[i].name<<endl;
    cout<<"The id of person "<<i+1<<" is:"<<p[i].id<<endl;
 }
 for (i=0 ;i<n ;i++)
 {
    for (j=0 ;j<n-1-i ;j++)
    {
        if (p[j].name[0] > p[j+1].name[0])
        {
            temp1 = p[j].name;
            p[j].name = p[j+1].name;
            p[j+1].name = temp1;
        }
    }
 }
 cout<<"SORTED FORMATION THROUG NAME!"<<endl;
 for (i=0 ;i<n ;i++)
 {
    cout<<"The name of person "<<i+1<<" is:"<<p[i].name<<endl;
    cout<<"The id of person "<<i+1<<" is:"<<p[i].id<<endl;
 }
}