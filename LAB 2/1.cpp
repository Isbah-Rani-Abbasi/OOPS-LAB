# include<iostream>
# include<string>
using namespace std;
 int main(int argc, char* argv[]) 
 {
  for (int i=1;i<argc;i++)
  cout<<argv[i]<<endl;
 }
 //{
//   std::cout << "Number of arguments: " << argc << std::endl;

//   for (int i = 0; i < argc; ++i) {
//     std::cout << "Argument " << i << ": " << argv[i] << std::endl;
//   }

//   return 0;
// }