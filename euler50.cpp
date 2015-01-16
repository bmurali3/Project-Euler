#include<iostream>
using namespace std;
#include<math.h>
int isprime(int a)
{
    int limit=sqrt(a);
    if((a%2==0)||(a%3==0))
        return(0);
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
    int l=546,temp=5,count=2,a[l],k=2;
    a[0]=2;
    a[1]=3;
    long long sum=5;
    while(count<l)
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
    for(;count>540;count--)
    {
        cout<<"length ="<<count<<endl<<endl;
        for(int i=0;count+i<=l;i++)
        {
            sum=0;
            cout<<a[i]<<"+...+"<<a[i+count-1]<<"=";
            for(int j=i;j<i+count;j++)
            {
                sum+=a[j];
            }
            cout<<sum;
            if(isprime(sum))
            {
                cout<<":prime";
            }
            cout<<endl;
        }
    }
    return(0);
}
