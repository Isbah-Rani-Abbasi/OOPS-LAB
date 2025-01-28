# include<iostream>
# include <string>
using namespace std;
struct organisation
{
    string org_name;
    int org_id;
    struct employee
    {
        string name;
        int id;
        float salary;
    }emp;
    void printORG( string name , int id)
    {
        cout<<"The name of organisation :"<<org_name<<endl<<"The id of organisation: "<<org_id<<endl;
    }
    void printEmp( string name , int id , float salary)
    {
        cout<<"The name of organisation :"<<emp.name<<endl<<"The id of organisation: "<<emp.id<<endl<<"The salary of employee: "<<emp.salary<<endl;
    }
};
int main()
{
    struct organisation org;
    cout<<"Enter name of oraganisaton: "<<endl;
    cin>>org.org_name;
    cout<<"Enter id of oraganisaton: "<<endl;
    cin>>org.org_id;
    cout<<"Enter name of employee: "<<endl;
    cin>>org.emp.name;
    cout<<"Enter id of oraganisaton: "<<endl;
    cin>>org.emp.id;
    cout<<"Enter salary of oraganisaton: "<<endl;
    cin>>org.emp.salary;
    org.printORG(org.org_name , org.org_id);
    org.printEmp(org.emp.name , org.emp.id , org.emp.salary);
    
}