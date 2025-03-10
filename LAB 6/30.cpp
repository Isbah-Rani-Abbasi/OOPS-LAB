# include<iostream>
# include<string>
using namespace std;
class Vehicle
{
    private:
    double price;
    public:
    Vehicle(double p):price(p){};
    double getVPrice()const
    {
        return price;
    }
};
class Car:public Vehicle
{
    private:
    int seat_cap;
    int no_of_doors;
    string fuel_type;
    public:
    Car(int s ,int d, string f, double p):seat_cap(s) , no_of_doors(d) , fuel_type(f) ,Vehicle(p){}
    int getCSeat()
    {
        return seat_cap;
    }
    int getCDoors()
    {
        return no_of_doors;
    }
    string getCFuelType()
    {
        return fuel_type;
    }
    double getCPrice()
    {
        return getVPrice();
    }
    
};
class Motorcycle:public Vehicle
{
    private:
    int no_of_cylinders;
    int no_of_gears;
    int no_of_wheels;
    public:
    Motorcycle(int c, int g, int w ,double p):no_of_cylinders(c) ,no_of_gears(g) ,no_of_wheels(w) ,Vehicle(p){}
    int getMCylinders()
    {
        return no_of_cylinders;
    }
    int getMWheels()
    {
        return no_of_wheels;
    }
    int getMGears()
    {
        return no_of_gears;
    }
    double getMPrice()
    {
        return getVPrice();
    }


};
class Audi:public Car
{
    private:
    string model_type;
    public:
    Audi(string m,int s, int d,string f,double p):model_type(m) ,Car(s,d,f,p){}
    int getASeat()
    {
        return getCSeat();
    }
    int getADoors()
    {
        return getCDoors();
    }
    string getAFuelType()
    {
        return getCFuelType();
    }
    double getAPrice()
    {
        return getCPrice();
    }
    string getAModel()
    {
        return model_type;
    }
    void display()
    {
        cout<<"Model Type:"<<model_type<<endl;
        cout<<"Price:"<<getAPrice()<<endl;
        cout<<"Seats:"<<getASeat()<<endl;
        cout<<"Door:"<<getADoors()<<endl;
        cout<<"Fuel:"<<getAFuelType()<<endl;
    }

};
class Yamaha:public Motorcycle
{
   private:
   string make_type;
   public:
   Yamaha(string m, int c, int g, int w, double p):make_type(m),Motorcycle(c,g,w,p){}
   int getYCylinders()
   {
       return getMCylinders();
   }
   int getYWheels()
   {
       return getMWheels();
   }
   int getYGears()
   {
       return getMGears();
   }
   double getYPrice()
   {
       return getMPrice();
   }
   string getYMake()
    {
        return make_type;
    }
    void display()
    {
        cout<<"Model Type:"<<make_type<<endl;
        cout<<"Price:"<<getYPrice()<<endl;
        cout<<"Cylinders:"<<getYCylinders()<<endl;
        cout<<"Gear:"<<getYGears()<<endl;
        cout<<"Wheel:"<<getYWheels()<<endl;
    }
};
int main()
{
    Yamaha y("Honda" ,3,4,4,1200);
    Audi a("AudiA3" ,4,4,"diesel",1800);
    y.display();
    a.display();
}