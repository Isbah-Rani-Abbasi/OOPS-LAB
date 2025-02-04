// Create a class called Employee that includes three pieces of information as instance variables—a first name (type
// String), a last name (type String) and a monthly salary (double). If the monthly salary is not positive, set it to 0.0.
// Write a test application named EmployeeTest that demonstrates class Employee’s capabilities. Create two
// Employee objects and display each object’s yearly salary. Then give each Employee a 10% raise and display each
// Employee’s yearly salary again.
# include<iostream>
# include<string>
using namespace std;
class Employee{
    public:
    string firstName;
    string lastName;
    double salary;
    void set()
    {
    if (salary< 0.0)
    {
        salary= 0.0;
    }
    else
    {
        salary = salary * 12+(10/100);
    }
    }
};
int main(int argc , char* argv[])
{
   Employee e[2];
   int temp[2];
   int i;
   string name;
   for (i=0 ;i<2; i++)
   {
    cout <<"Enter first name of employee "<<i+1<<" "<<endl;
    cin>>e[i].firstName;
    cout <<"Enter last name of employee "<<i+1<<" "<<endl;
    cin>>e[i].lastName;
   }
   for (i=0 ;i<2;i++)
   {
    cout <<"Enter salary of employee "<<i+1<<" "<<endl;
    cin>>e[i].salary;
    temp[i]=e[i].salary;
    e[i].set();
   }
   cout<<"The actual detail is!"<<endl;
   cout<<endl;
    for (i=0 ;i<2;i++)
   {
    cout <<"The first name of employee "<<i+1<<"is:"<<e[i].firstName<<endl;
    cout <<"The last name of employee "<<i+1<<"is:"<<e[i].lastName<<endl;
    cout <<"The mothnly salary of employee "<<i+1<<"is:"<<temp[i]<<endl;
    cout<<endl;
   }
   
    cout<<"The modified detail is!"<<endl;
    cout<<endl;
   for (i=0 ;i<2;i++)
   {
    cout <<"The first name of employee "<<i+1<<"is:"<<e[i].firstName<<endl;
    cout <<"The last name of employee "<<i+1<<"is:"<<e[i].lastName<<endl;
    cout <<"The annual salary of employee "<<i+1<<"is:"<<12*e[i].salary<<endl;
   }




}