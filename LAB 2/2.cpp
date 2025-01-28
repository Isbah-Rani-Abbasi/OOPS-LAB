# include<iostream>
# include<vector>
using namespace std;
int main()
{
    vector<int>numbers;
    numbers={1,2,3,4,5};
    numbers.push_back(20);
    numbers.insert(numbers.begin()+2 , 16);
    numbers.erase(numbers.begin()+4);
    for (int num:numbers)
    {
        cout<<num<<endl;
    }
    cout <<"size"<<numbers.size();
}