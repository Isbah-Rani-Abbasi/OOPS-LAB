# include<iostream>
# include<string>
# include<bits/stdc++.h>
using namespace std;
struct movie
{
  string movieName;
  float adultTicketPrice;
  float childTicketPrice;
  int noAdultTicket;
  int noChildTicket;
  float grossPercenntage;
};
int main()
{
  struct movie m1;
  cout<<"Enter movie name: "<<endl;
  getline(cin , m1.movieName);
  cout<<"Enter adult ticket price: "<<endl;
  cin>>m1.adultTicketPrice;
  cout<<"Enter child ticket price: "<<endl;
  cin>>m1.childTicketPrice;
  cout<<"Enter total no of adults: "<<endl;
  cin>>m1.noAdultTicket;
  cout<<"Enter total no child: "<<endl;
  cin>>m1.noChildTicket;
  cout<<"Enter gross perecentage: "<<endl;
  cin>>m1.grossPercenntage;
  int totalNo = m1.noAdultTicket + m1.noChildTicket;
  float totalPrice = (m1.noAdultTicket * m1.adultTicketPrice) + (m1.noChildTicket * m1.childTicketPrice);
  float donatedAmount = (totalPrice * m1.grossPercenntage) / 100;
  float netSale = totalPrice - donatedAmount ;
  cout <<"Movie Name: "<<m1.movieName<<endl;
  cout <<"Number of ticket sale: "<<totalNo<<endl;
  cout <<"Gross Amount: "<<fixed<<setprecision(2)<<totalPrice<<endl;
  cout <<"Percentage of Gross Amount Donated: "<<fixed<<setprecision(2)<<m1.grossPercenntage<<"%"<<endl;
  cout <<"Amount Donated: "<<fixed<<setprecision(2)<<donatedAmount<<endl;
  cout <<"Net Sale: "<<fixed<<setprecision(2)<<netSale<<endl;
}