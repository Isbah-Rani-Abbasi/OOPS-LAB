// A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as
// author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person inputs the
// title and author and the system searches the list and displays whether it is available or not. If it is not, an
// appropriate message is displayed. If it is, then the system displays the book details and requests for the number
// of copies required. If the requested copies are available, the total cost of the requested copies is displayed;
// otherwise “Required copies not in stock” is displayed. Design a system using a class called books with suitable
// member functions and constructors.
# include<iostream>
# include<string>
using namespace  std;
class Book
{
    private:
    string title;
    string author;
    string publisher;
    float price;
    int stockposition;
    public:
    Book (string author, string title , float price , string publisher , int stockposition)
    {
        this -> title = title;
        this -> author = author;
        this -> publisher = publisher;
        this -> price = price;
        this -> stockposition = stockposition;
    }
    void printbookdetails()
    {
        cout<<"THe name of book is:"<<title<<endl;
        cout<<"THe author of book is:"<<author<<endl;
        cout<<"THe publisher of book is:"<<publisher<<endl;
        cout<<"THe price of book is:"<<price<<endl;
        cout<<"THe total no of book is:"<<stockposition<<endl;
    }
    bool isavailable(string t , string a)
    {
        if(title == t && author == a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    float stockcheck(int copies)
    {
        if (copies <= stockposition)
        {
            return copies * price;
        }
        else
        {
          return -1;
        }

    }
    int stockupdate(int copies)
    {
       return stockposition -=copies;
    }
};
int main()
{
    Book arr[4]={Book("J.R.R. Tolkien", "The Hobbit", 12.99, "Allen & Unwin", 10),
                 Book("George R.R. Martin", "A Game of Thrones", 19.99, "Bantam Spectra", 5),
                 Book("Jane Austen", "Pride and Prejudice", 9.95, "Penguin Classics", 15),
                 Book("Stephen King", "The Shining", 14.50, "Doubleday", 8)};
    string bookname , authorname;
    int stock;
    cout<<"Enter the book you want to search:"<<endl;
    getline(cin >> ws , bookname );
    cout<<"Enter the author name you want to search:"<<endl;
    //cin>>authorname;
    getline(cin >> ws, authorname );
    cout<<"Enter the stock no:"<<endl;
    cin>>stock;
    float total;
    bool flag = false;
    for (int i =0 ;i<4 ; i++)
    {
        
          if (arr[i].isavailable(bookname , authorname) == true)
          {
            flag = true;
            arr[i].printbookdetails();
            total = arr[i].stockcheck(stock);
            if (total>=0)
            {
                cout<<"Total bill is "<<total;
                cout<<"The reamining books in stock are: "<<arr[i].stockupdate(stock);
            }
            else if (total < 0)
            {
               cout<<"Stock is not available!";
            }
            
            break;


          }
    }
    if (flag == false)
    {
        cout<<"Book not found"<<endl;
    }


}
