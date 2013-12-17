#include <iostream>
using namespace std;
template <class T>
class CMatrix
{
public:
       T* pMat;
       CMatrix(int m,int n)
       {
            this->n=n;
            this->m=m;
            pMat=new T[n*m];
            memset(pMat,0,n*m*sizeof(T));
       }
       CMatrix(CMatrix<T>& matrix)
       {
            this->n=matrix.n;
            this->m=matrix.m;
            pMat=new T[matrix.n*matrix.m];
            memcpy(pMat,matrix.pMat,n*m*sizeof(T));
       }
       T& valueOf(int r,int c)
       {
             return pMat[r*n+c];    
       }
       int show()
       {
           for(int i=0;i<m;i++)
           {
                for(int j=0;j<n;j++)
                {
                     cout<<valueOf(i,j)<<' ';
                }
                cout<<endl;
           }
           return 0;
       }
       CMatrix<T> operator*(CMatrix<T>& matrix)
       {
           if(getRowNum()!=matrix.getColNum()) return CMatrix<T>(1,1);
           CMatrix<T> r(getRowNum(),matrix.getColNum());
           for(int i=0;i<getRowNum();i++)
           {
                for(int j=0;j<matrix.getColNum();j++)
                {
                     r.valueOf(i,j)=0;
                     for(int k=0;k<getColNum();k++)
                     {
                          r.valueOf(i,j)=(T)(r.valueOf(i,j)+valueOf(i,k)*matrix.valueOf(k,j));
                     }
                }
           }
           return r;
       }
       int getRowNum()
       {
           return m;
       }
       int getColNum()
       {
           return n;
       }
       ~CMatrix()
       {
            if(pMat!=NULL) delete[] pMat;     
       }
	   bool colIsAllZero(int colNum)
	   {
		   for(int i=0;i<getRowNum();i++)
		   {
			   if(valueOf(i,colNum)!=0)
			   {
				   return 0;
			   }
		   }
		   return 1;
	   }
	   bool setRowZero(int rowNum)
	   {
		   memset(pMat+rowNum*sizeof(T)*getColNum(),0,getColNum()*sizeof(T));
		   return 1;
	   }
private:
       int m;
       int n; 
};
