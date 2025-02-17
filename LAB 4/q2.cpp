
// Create an Account class that a bank might use to represent customers bank accounts. Include a data member to
// represent the account balance. Provide three member functions. Member function credit should add an amount
// to the current balance. Member function debits should withdraw money from the Account. Member function get
// Balance should return the current balance.
# include<iostream>
# include<string>
using namespace std;
class Account 
{
  private :
  float bankBalance;
  public:
  Account ()
  {
      bankBalance =0.0;
  }
  void setbalance(float balance)
  {
      bankBalance = balance;
  }
  void credit(float amount)
  {
      bankBalance +=amount;
  }
  void debit(float amount)
  {
      bankBalance -=amount;
  }
  float getBalance()
  {
      return bankBalance;
  }
  
};
int main()
{
    Account a1;
    float totalbalance ;
     cout<<"Enter the total balance:"<<endl;
     cin>>totalbalance;
    float addbalance;
    cout<<"Enter the balance you want to add:"<<endl;
     cin>>addbalance;
    float withdrawbalance;
    cout<<"Enter the balance you want to withdraw:"<<endl;
     cin>>withdrawbalance;
     a1.setbalance(totalbalance);
     a1.credit(addbalance);
     a1.debit(withdrawbalance);
     cout<<"Your total balnce is:"<<a1.getBalance();
}
