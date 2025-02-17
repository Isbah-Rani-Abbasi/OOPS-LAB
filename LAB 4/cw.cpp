# include<iostream>
# include<string>
#include <vector>

using namespace std;
class matrix
{
  public:
  int rows;
  int cols;
  double **matrices;
   matrix()
   {
    rows =0;
    cols =0;
   
   }
   matrix( int r, int c) 
   {
    rows = r;
    cols =c;
    matrices = new double *[rows];
    for (int i=0 ;i<rows ;i++)
    {
        matrices[i] = new double [cols];
    }
   
    
    
     for (int i=0 ;i<rows;i++)
    {
        for(int j=0 ; j<cols ;j++)
        {
            matrices[i][j]=0;
        }
    }
   }
   matrix( const matrix &obj ): rows(obj.rows) , cols(obj.cols) 
   {
    matrices = new double *[rows];
    for (int i=0 ;i<rows ;i++)
    {
        matrices[i] = new double [cols];
    }
    for (int i=0 ;i<rows;i++)
    {
        for(int j=0 ; j<cols ;j++)
        {
            matrices[i][j]=obj.matrices[i][j];
        }
    }
   
   }
   matrix (matrix && obj) noexcept : rows(obj.rows) , cols(obj.cols) , matrices(obj.matrices) 
   {
    obj.cols=0;
    obj.rows=0;
    obj.matrices = nullptr;
   }
   ~matrix()
   {
   
    for (int i=0 ;i<rows ;i++)
    {
        delete []matrices[i];
    }
    delete []matrices;
   }
    matrix& operator=(matrix && obj) noexcept {
        if (this != &obj) {
            delete obj.matrices;
            matrices = obj.matrices;
            obj.matrices = nullptr;
        }
        return *this;
    }
    
    int getrows()
    {
        return rows;
    }
    int getcols()
    {
        return cols;
    }
    void fill( double value)
    {
        for (int i=0 ;i<rows;i++)
    {
        for(int j=0 ; j<cols ;j++)
        {
            matrices[i][j]=value;
        }
    }
    }
    double * transpose()
    {
      double ** transpose = new double *[rows];
    for (int i=0 ;i<rows ;i++)
    {
        matrices[i] = new double [cols];
    }
      
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrices[i][j];
        }
        return *transpose;
    }
   
    }
    void print()
    {
        for (int i=0 ;i<rows;i++)
        {
            for (int j=0 ;j<cols ;j++)
            {
                cout <<matrices[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    double * at (int r , int c)
    {
        int i=r;
        int j=c;
        return &matrices[i][j];
    }
};
int main()
{
    matrix a(2 ,2);
    a.fill(2);
    a.print();
    matrix b=a;
    b.print();
    matrix c= move(a);
    double *ptr=c.transpose();

    

}