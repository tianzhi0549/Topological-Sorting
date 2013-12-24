#include "Matrix.h"
#include <iostream>
#include <queue>
using namespace std;
char* map[]={"编译原理","C","C++","数据结构","离散数学","初等数学"};
bool isContainer(int* p,int n,int element)
{
	for(int i=0;i<n;i++)
	{
		if(p[i]==element)
		{
			return 1;
		}
	}
	return 0;
}
void sort(CMatrix<bool>& m)
{
	int* pInDegree=new int[m.getColNum()];
	queue<int> out;
	memset(pInDegree,0,m.getColNum()*sizeof(int));
	for(int i=0;i<m.getColNum();i++)
	{
		pInDegree[i]=m.getColNotZeroCount(i);
		if(m.colIsAllZero(i))
		{
			out.push(i);
		}
	}
	while(!out.empty())
	{
		cout<<map[out.front()]<<endl;
		for(int i=0;i<m.getColNum();i++)
		{
			if(m.valueOf(out.front(),i)==1)
			{
				pInDegree[i]--;
				if(pInDegree[i]==0)
				{
					out.push(i);
				}
			}
		}
		out.pop();
	}
	delete[] pInDegree;
}
int main()
{
	CMatrix<bool> a(6,6);
	a.valueOf(5,1)=1;
	a.valueOf(5,2)=1;
	a.valueOf(1,3)=1;
	a.valueOf(2,3)=1;
	a.valueOf(1,4)=1;
	a.valueOf(2,4)=1;
	a.valueOf(3,0)=1;
	a.valueOf(4,0)=1;
	a.show();
	sort(a);
	a.show();
	getchar();
	return 0;
}
