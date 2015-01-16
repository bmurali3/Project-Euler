#include<iostream>
using namespace std;
#include<math.h>

int isprime(int a)
{
    if((a%2==0)||(a%3==0))
        return(0);
    int limit=sqrt(a);
    for(int i=5; i<=limit; i=i+4)
    {
        if(a%i==0)
            return(0);
        i+=2;
        if(a%i==0)
            return(0);
    }
    return(1);
}
int isSquare(int n)
{
    int root=sqrt(n);
    if (n==root*root)
        return 1;
    else
        return 0;
}
int main()
{
    int x,r,flag,temp;
    for(x=9;x<10000;x+=2)
    {
        if(isprime(x))
            continue;
        cout<<x;
        r=1;
        temp=2;
        flag=0;
        while(1)
        {
            if(temp>=x)
            {
                flag=1;
                break;
            }
            else if(isprime(x-temp))
            {
                cout<<"="<<x-temp<<"+"<<"2*"<<r<<"^2"<<endl;
                break;
            }
            else
            {
                r++;
                temp=2*r*r;
            }
        }
        if(flag==1)
        {
            cout<<" we have our solution...";
            break;
        }
    }
    return(0);
}
