#include<iostream>
using namespace std;
#include<stack>
void binary(long temp,char str[],int& l)
{
    stack<char> s;
    while(temp!=0)
    {
        if(temp%2==0)
        {
            s.push('0');
            temp/=2;
        }
        else
        {
            s.push('1');
            temp/=2;
        }
    }
    int i=0;
    while(!s.empty())
    {
        str[i++]=s.top();
        s.pop();
    }
    l=i;
}
int ispalin(char str[],int l)
{
    int p=l/2;
    for(int i=0;i<p;i++)
    {
        if(str[i]!=str[l-i-1])
            return(0);
    }
    return(1);
}
int ispalin(int x)
{
    int temp=x,rev=0,r;
    while(temp)
    {
        r=temp%10;
        rev=rev*10+r;
        temp/=10;
    }
    if(x==rev)
        return(1);
    else
        return(0);
}
int main()
{
    long long sum=0;
    int l,i,x;
    for(x=1;x<1000000;x++)
    {
        char str[20];
        binary(x,str,l);
        if((ispalin(x))&&(ispalin(str,l)))
        {
            cout<<x<<endl;
            sum+=x;
        }
    }
    cout<<"sum="<<sum;
    return(0);
}
