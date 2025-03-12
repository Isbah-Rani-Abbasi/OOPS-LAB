# include<iostream>
# include<string>
using namespace std;

class Books
{
    private:
    string genre;
    public:
    Books(string g):genre(g){};
    void setGenre(string g)
    {
        genre = g;
    }
    string getGenre()const
    {
        return genre;
    }
};
class ch1:public Books
{
  private:
  string author;
  string title;
  public:
  ch1(string g ,string a ,string t):Books(g) , author(a) , title(t){}
  void display()
  {
    cout<<"BOOK 1 DETAILS!"<<endl;
    cout<<"Book name is:"<<title<<endl;
    cout<<"Book Genre is:"<<getGenre()<<endl;
    cout<<"Book Author is:"<<author<<endl;
  }

};
class ch2:public Books
{
    private:
    string author;
    string title;
    public:
    ch2(string g ,string a ,string t):Books(g) , author(a) , title(t){}
    void display()
  {
    cout<<"BOOK 2 DETAILS!"<<endl;
    cout<<"Book name is:"<<title<<endl;
    cout<<"Book Genre is:"<<getGenre()<<endl;
    cout<<"Book Author is:"<<author<<endl;
  }
};
int main()
{
    ch1  c1("Novel" , "Isbah" , "Namal" );
    ch2  c2("Narrative" , "Nemrah" ,"Haalim");
    c1.display();
    c2.display();
}
