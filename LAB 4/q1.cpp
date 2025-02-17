//Your task is to create a Circle constructor that creates a circle with a radius provided by an argument. The circles constructed must have two getters getArea() (PIr^2) and getPerimeter() (2PI*r) 
//which give both respective areas and perimeter (circumference).
# include<iostream>
# include<string>
# include<cmath>
using namespace std;

class circle
{
    private:
	float radius;
	public:
	circle (float r)
	{
		radius = r;
		if (radius < 0)
		{
		    cout<<"Invlaid input"<<endl;
		    radius = 0;
		}
		
	}
	float getArea()
	{
		return M_PI*pow(radius,2);
	}
	float getPerimeter()
	{
		return M_PI*2*radius;
	}
};
int main()
{
	int radius;
	cout<<"Enter radius:"<<endl;
	cin>>radius;
	circle c1(radius);
	cout<<"The area of circle is "<<c1.getArea()<<endl;
	cout<<"The perimeter of circle is "<<c1.getPerimeter();
	
}
