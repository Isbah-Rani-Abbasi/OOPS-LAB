// We are prototyping a robot that refills glasses during dinner. Every glass holds 200 milliliters. During dinner,
// people either drink water or juice, and as soon as there is less than 100 ml left in the glass, the robot refills it back
// to 200 ml.
// Create a class Glass with one public int field LiquidLevel and methods public Drink(int milliliters) that takes the
// amount of liquid that a person drank and public Refill() that refills the glass to be 200 ml full. Both methods
// should not return any value. Initially set LiquidLevel to 200. In the Main method create an object of class Glass
// and read commands from the screen until the user terminates the program (see next). Don&#39;t forget to refill the glass
// when needed!
# include<iostream>
# include<string>
using namespace std;
class Glass
{
  public:
  int liquidlevel=200;
  void drink(int milliliters)
  {
    liquidlevel= liquidlevel-milliliters;
    if (liquidlevel<100 && liquidlevel>=0)
    {
        refill();
    }
     else if(liquidlevel < 0)
     {
        cout<<"The liquid levelis less than 0"<<endl;
        
    }
    else
    {
        cout<<"The liquid levelis:"<<liquidlevel<<endl;
    }
  }
  void refill()
  {
    liquidlevel=200;
    cout<<"The liquid level is:"<<liquidlevel<<endl;
  }
};
int main()
{
    Glass g1;
    g1.liquidlevel = 200;
    int drink;
   
    int check;
    while(1)
    {
        cout<<"Entr -2 to terminte:";
        cin>>check;
        if(check >200 || check == -2)
        {
            break;
        }
        g1.drink(check);
    }
}