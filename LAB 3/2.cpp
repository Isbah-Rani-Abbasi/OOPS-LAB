# include<iostream>
using namespace std;
class person
{
    public:
    int id;
    string name;
    void another(string var);
    protected:
    int age;
};
class c: public person
{
 public:
 int sub=age;
};
void person::another(string var)
{
    cout<<"Hello";
}
int main()
{
    person obj[2];
    c c1;
    c1.sub=45;
    cout<<c1.sub;
    obj[1].id = 1234;
    obj[1].name = "isbah";
    cout <<obj[1].name;
    obj[1].another("isbah");
}