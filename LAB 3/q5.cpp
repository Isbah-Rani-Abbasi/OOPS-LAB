# include<iostream>
# include<string>
using namespace std;
class book
{
	private:
		string bookname;
		string isbn_no;
		string author;
		string publisher;
	public:
		book(string bookname , string isbn_no , string author , string publisher)
		{
			this->bookname = bookname;
			this->isbn_no = isbn_no;
			this->author = author;
			this-> publisher = publisher;
		}
		string getBookName()
		{
        return this->bookname;
        }

        string getIsbnNumber() 
		{
        return this->isbn_no;
        }
        string getAuthorName() 
		{
        return this->author;
        } 
		string getPublisher()
		{
			return this->publisher;
		}  
		void setBookName(string bookname)
		{
			this->bookname = bookname;
		}
		void setIsbnNo(string isbn_no)
		{
			this->isbn_no = isbn_no;
		}
		void setAuthor(string author)
		{
		    this->author = author;
		}
		void setPublisher(string publisher)
		{
			this-> publisher = publisher;
		}
		// although i have make an fetinfobook function which gives me all details about books but i also am making seperate getters
		string getBookInfo()
		{
			return "Book Name: " + this->bookname + "\n" +
               "ISBN Number: " + this->isbn_no + "\n" +
               "Author Name: " + this->author + "\n" +
               "Publisher: " + this->publisher;

		}
};
int main()
{
	book arr[5] = {book("The Lord of the Rings", "978-0547928227", "J.R.R. Tolkien", "Houghton Mifflin Harcourt"),
                   book("Pride and Prejudice", "978-0141439518", "Jane Austen", "Penguin Classics"),
                   book("1984", "978-0451524935", "George Orwell", "Signet Classics"),
                   book("To Kill a Mockingbird", "978-0061120084", "Harper Lee", "Harper Perennial"),
                   book("The Great Gatsby", "978-0743273565", "F. Scott Fitzgerald", "Scribner")};
      // i have inistialised all objects by using parameterized constructor and i can change thse by using my setter functions   
	   arr[1].setAuthor("isbah rani abbasi") ;  // this will change the author name of pride and prejudice to isbah rani abbasi         
    for (int i = 0; i < 5; i++) {
           
            cout<<(arr[i].getBookInfo());
        }               
}
