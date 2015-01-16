#include<iostream>
using namespace std;
#include<conio.h>
int ispalin(int a)
{
    int rev=0,str=a,r;
    while(a)
    {
        r=a%10;
        a/=10;
        rev=rev*10+r;
    }
    if(str==rev)
        return(1);
    return(0);
}
int main()
{
    int i,j,k=0,temp,x,y;
    for(i=999;i>99;i--)
    {
        if(i*i<k)
            break;
        for(j=i;j>99;j--)
        {
            temp=i*j;
            if(ispalin(temp))
                if(k<temp){
                    k=temp;x=i,y=j;}
        }
    }
    cout<<"largest="<<k<<"("<<x<<","<<y<<")";
    return(0);
}
