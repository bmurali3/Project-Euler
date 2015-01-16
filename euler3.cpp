#include<iostream>
using namespace std;
#include<math.h>
int isprime(int a)
{
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

int main()
{
    long long n=600851475143,p=5,flag;
    while(n!=1)
    {
        flag=0;
        while(n%p==0)
        {
            flag=1;
            n/=p;
        }
        if(flag==1)
        {
            cout<<p<<" ";
        }
        p+=2;
        flag=0;
        while(n%p==0)
        {
            flag=1;
            n/=p;
        }
        if(flag==1)
        {
            cout<<p<<" ";
        }
        p+=4;
    }
}
