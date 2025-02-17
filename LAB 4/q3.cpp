# include<iostream>
# include<string>
using namespace std;
class Invoice
{
    private:
    string no;
    string description;
    int quantity;
    double price;
    public:
    Invoice ()
    {
      no ="null";
      description = "null";
      quantity = 0;
      price = 0.00;
    }
    void setNo(string no)
    {
        this -> no = no;
    }
    void setedescriptiom(string description)
    {
        this -> description = description;
    }
    void setQuantity(int quantity)
    {
        if (quantity < 0)
        {
            quantity =0;
        }
        else
        {
            this -> quantity = quantity;
        }
        }

       
    void setprice(double price)
    {
        if (price < 0)
        {
            price =0;
        }
        else
        {
            this -> price = price;
        }

    }
       
    
    string getNo()
    {
       return no;
    }
    string getedescriptiom()
    {
        return description;
    }
    int getQuantity()
    {
        return quantity;
    }
    double getprice()
    {
        return price;
    }

    double getInvoiceAmount()
    {
        double x = (double)quantity * price;
       return x;
    }


};
int main()
{
    Invoice i1;
    int quantity;
    cout<<"Enter the quantity: "<<endl;
    cin>>quantity;
    double price;
    cout<<"Enter the price: "<<endl;
    cin>>price;
    string description;
    cout<<"Enter the description: "<<endl;
    cin>>description;
    string no;
    cout<<"Enter the no: "<<endl;
    cin>>no;
    i1.setNo(no);
    i1.setedescriptiom(description);
    i1.setprice(price);
    i1.setQuantity(quantity);
    cout<<"The description of product is: "<<i1.getedescriptiom()<<endl;
    cout<<"The no of product is: "<<i1.getNo()<<endl;
    cout<<"The price of product is: "<<i1.getprice()<<endl;
    cout<<"The quantity of product is: "<<i1.getQuantity()<<endl;
    cout<<"The invoice amount of of product is: "<<i1.getInvoiceAmount()<<endl;

    

}