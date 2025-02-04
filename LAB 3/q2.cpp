// Create a class called Date that includes three pieces of information as instance variables—a month (typeint), a day
// (typeint) and a year (typeint). Provide a method displayDate that displays the month, day and year separated by
// forward slashes(/). Write a test application named DateTest that demonstrates classDate’s capabilities.
# include<iostream>
# include<string>
using namespace std;
class Date
{
  public:
  int day;
  int month;
  int year;
  void displayDate()
  {
    cout<<"Today's date is: "<<day<<"/"<<month<<"/"<<year<<".";
  }
};
int main()
{
    Date d1;
    d1.day = 23;
    d1.month = 9;
    d1.year = 2025;
    d1.displayDate();
}