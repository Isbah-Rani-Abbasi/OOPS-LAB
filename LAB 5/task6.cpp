# include<iostream>
using namespace std;
struct MenuItem {
    string name;
    string type;
    int price;
};
class CoffeShop
{
	private:
		const string name:
		MenuItem menu[5];
		string order[10];
		int order_count;
		int menu_count;
	public:
		CoffeShop(string name , MenuItem *m)
		{
			this->name = name;
			menu=m;
			order_count = 0;
			menu_count = 0;
			for (int i = 0;i<10;i++)
			{
				order[i]="null";
			}
		}
		void addOrder(string order)
		{
			bool check=false;
			for(int i=0 ;i<5;i++)
			{
				if (order == menu[i].name)
				{
					check = true;
				}
			}
			if(check = ture && order_count<10)
			{
				order[order_count++] = order;
			}
			else
			{
				cout<<"This item is unavailable"<<endl;
			}
		}
		void fulfillOrder(string item )
		{
			if(order_count==10)
			{
				cout<<"The "<<item<<" is ready!"<<endl;
			}
			else
			{
				cout<<"All order have been fulfilled"<<endl;
			}
		}
	  void listOrder()
	  {
	  	if(order_count==0)
	  	{
	  		cout<<"No order"<<endl;
		  }
		else
		{
			for(int i=0 ;i<order_count;i++)
			{
				cout<<order[i]<<ndl;
			}
		}
	  }
	  void drinkonly
	  {
	  	for(int i=0;i<menu_count;i++)
	  	{
	  	if (menu[i].type=="drink")
	  	{
	  		cout<<menu[i].name<<endl<<menu[i].price<<endl;
		  }

		}
	  	
	  }
	  void foodonly
	  {
	  	for(int i=0;i<menu_count;i++)
	  	{
	  	if (menu[i].type=="food")
	  	{
	  		cout<<menu[i].name<<endl<<menu[i].price<<endl;
		  }

		}

	  }
	  float dueAmount(int price )
	  {
	  	for(i=0;i<)
	  }
};
