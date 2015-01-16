#include<iostream>
using namespace std;

int ispalin(unsigned long long& a)
{
    unsigned long long rev=0,str=a;
    int r;
    while(str)
    {
        r=str%10;
        str/=10;
        rev=rev*10+r;
    }
    if(a==rev)
        return(1);
    a+=rev;
    return(0);
}

int isNotLychrel(unsigned long long a)
{
    unsigned long long str=a,rev=0;
    int r;
    while(str)
    {
        r=str%10;
        str/=10;
        rev=rev*10+r;
    }
    a+=rev;
    for(int i=0;i<50;i++)
    {
        if(ispalin(a))
            return(1);
    }
    return(0);
}

int main()
{
    unsigned long long n;
    int count=0;
    for(n=1;n<=10000;n++)
    {
        if(!isNotLychrel(n))
        {
            cout<<n<<endl;
            count++;
        }
    }
    cout<<endl<<"Count="<<count;
    return(0);
}
