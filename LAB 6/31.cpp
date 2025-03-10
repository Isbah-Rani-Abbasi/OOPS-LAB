# include<iostream>
# include<string>
using namespace std;
class Student
{
  int id;
  string name;
  public:
  Student(int id , string n):id(id) , name(n){}
  void getStudentDetails()
  {
    cout<<"Name of student is:"<<name<<endl;
    cout<<"Idd of student is:"<<id<<endl;
  }
};
class Marks:public Student
{
  protected:
  int oop;
  int mvc;
  int dld;
  public:
  Marks(int oop , int mvc , int dld , int id ,string name):oop(oop),mvc(mvc),dld(dld),Student(id , name){}
  
  void displayMarks()
  {
    cout<<"OOP marks:"<<oop<<endl;
    cout<<"MVC marks:"<<mvc<<endl;
    cout<<"DLD marks:"<<dld<<endl;
  }
};
class Result:public Marks
{
 protected:
 int total_marks;
 double avg_makrs;
 public:
 Result(int oop ,int mvc, int dld, int id ,string n):total_marks(0),avg_makrs(0),Marks(oop ,mvc ,dld, id ,n){}
 void displayResult()
 {
    cout<<"Total marks are:"<<oop+mvc+dld<<endl;
    cout<<"Average marks are:"<<(oop+mvc+dld)/3<<endl;
 }
};
int main()
{
    Result r(10,10,10,1234,"isbah");
    r.getStudentDetails();
    r.displayMarks();
    r.displayResult();
 
}