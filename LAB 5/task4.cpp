# include<iostream>
# include<string>
using namespace std;
class BlendJuice
{
	public:
	void blendfruit(string f)
	{
		for (int i=0; i<5;i++)
		{
			int temp=2;            //a random statement inside loop
		}
		cout<<"Blending of "<<f<<" Completed"<<endl;
	}
};
class GrindJuice
{
	public:
	void grindfruit(string f)
	{
		for (int i=0; i<4;i++)
		{
			int temp=2;            //a random statement inside loop
		}
		cout<<"Grinding of "<<f<<" Completed"<<endl;
	}
};
class JuiceMaker
{
	private:
	string fruit;   
	BlendJuice b;
	GrindJuice g;               // jusr some members
	public:
	JuiceMaker(string f):fruit(f){
		b.blendfruit(fruit);
		g.grindfruit(fruit);
	};
	void setfruit(string f)
	{
	   fruit = f;	
	}
	string getfruit()const
	{
		return fruit;
	}
	

	
};
int main()
{
	JuiceMaker j("apple");

}
