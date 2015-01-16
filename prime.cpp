#include<iostream>
using namespace std;
#include<conio.h>
#include<math.h>
int isprime(int a)
{
    int limit=sqrt(a);
    for(int i=5;i<=limit;i=i+4)
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
    int temp=5,count=2,a[546],k=2;
    a[0]=2;
    a[1]=3;
    long long sum=5;
    while(count<546)
    {
        if(isprime(temp))
        {
            a[k++]=temp;
            sum+=temp;
            count++;
        }
        temp+=2;
        if(isprime(temp))
        {
            a[k++]=temp;
            sum+=temp;
            count++;
        }
        temp+=4;
    }
    cout<<endl<<"sum is:"<<sum<<"count is:"<<count<<" "<<k;
    return(0);
}
