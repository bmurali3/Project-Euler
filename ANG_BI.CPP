#include<iostream>
using namespace std;
#include<conio.h>
int main()
{
	cout<<"wtf"<<endl;
	long long a,b,c;
	long long count=0;
	for(a=1;a<33333333;a++)
	{
		for(b=a;b<3*a;b++)
		{
			int flag=0;
			for(c=b;c<a+b;c++)
			{
				if(a+b+c>100000000)
				{
					flag=1;
					break;
				}
				if(((a+c)*(a+b))%(b*c)==0)
				{
					cout<<"("<<a<<","<<b<<","<<c<<")"<<endl;
					count++;
				}
			}
			if(flag==1)
				break;
		}
	}
	cout<<endl<<"count="<<count;
	getch();
	return(0);
}
