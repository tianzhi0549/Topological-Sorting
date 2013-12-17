#include "Matrix.h"
#include <iostream>
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
	int* p=new int[m.getColNum()];
	int nowPos=0;
	memset(p,0,m.getColNum()*sizeof(int));
	int i=0;
	while(1)
	{
		for(i=0;i<m.getColNum();i++)
		{
			if(m.colIsAllZero(i)&&!isContainer(p,nowPos,i))
			{
				m.setRowZero(i);
				p[nowPos++]=i;
				break;
			}
		}
		if(i==m.getColNum())
		{
			break;
		}
	}
	if(nowPos==m.getColNum())
	{
		cout<<"拓扑排序结果:"<<endl;
		for(i=0;i<m.getColNum();i++)
		{
			cout<<map[p[i]]<<' ';
		}
		cout<<endl;
	}else
	{
		cout<<"出现回路。"<<endl;
	}
	cout<<"----------------------------------------------------"<<endl;
	delete[] p;
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
