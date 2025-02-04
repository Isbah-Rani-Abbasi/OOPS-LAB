// Create a class User with two public fields: int Age and string Name. In the Main method, create an object of class
// User and set Name to &quot;Teo&quot; and Age to 24. Then, output to the screen: &quot;My name is {Name} and I&#39;m {Age} years
// old.&quot; using object fields for Name and Age.
# include<iostream>
# include<string>
using namespace std;
class User
{
  public:
  int age;
  string name;
};
int main( int argc , char* argv[])
{
    User u1;
    u1.name="Teo";
    u1.age=24;
    cout<<"My name is "<<u1.name<<endl;
    cout<<"My age is "<<u1.age;
}