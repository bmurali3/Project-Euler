#include<iostream>
using namespace std;
#include<conio.h>
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
    int n,div,count,max=0;
    long long num=0,temp=0,max_num=0,max_n=0;
    for(n=1; max<500; n++)
    {
        num=n*(n+1)/2;
        temp=num;
        div=1;
        cout<<"n:"<<n<<", number:"<<num<<"=";

        count=1;                //power of 2
        while(num!=1)
        {
            if(num%2==0)
            {
                num/=2;
                count++;
            }
            else
                break;
        }
        div*=count;
        if(count>1)
            cout<<"2^"<<count-1;
        if(num==1)
        {
            if(max<div)
            {
                max=div;
                max_num=temp;
                max_n=n;
            }
            cout<<"   factors:"<<div<<endl;
            continue;
        }

        count=1;                   //power of 3
        while(num!=1)
        {
            if(num%3==0)
            {
                num/=3;
                count++;
            }
            else
                break;
        }
        div*=count;
        if(count>1)
            cout<<"*3^"<<count-1;
        if(num==1)
        {
            if(max<div)
            {
                max=div;
                max_num=temp;
                max_n=n;
            }
            cout<<"   factors:"<<div<<endl;
            continue;
        }

        int i=5;
        while(num!=1)
        {
            if(isprime(i))
            {
                count=1;                   //power of other primes
                while(num!=1)
                {
                    if(num%i==0)
                    {
                        num/=i;
                        count++;
                    }
                    else
                        break;
                }
                if(count>1)
                {
                    div*=count;
                    cout<<"*"<<i<<"^"<<count-1;
                    if(num==1)
                    {
                        if(max<div)
                        {
                            max=div;
                            max_num=temp;
                            max_n=n;
                        }
                        cout<<"   factors:"<<div<<endl;
                        break;
                    }
                    else if(isprime(num))
                    {
                        div*=2;
                        cout<<"*"<<num<<"^"<<1;
                        if(max<div)
                        {
                            max=div;
                            max_num=temp;
                            max_n=n;
                        }
                        cout<<"   factors:"<<div<<endl;
                        break;
                    }
                }
            }
            i+=2;
            if(isprime(i))
            {
                count=1;
                while(num!=1)
                {
                    if(num%i==0)
                    {
                        num/=i;
                        count++;
                    }
                    else
                        break;
                }
                if(count>1)
                {
                    div*=count;
                    cout<<"*"<<i<<"^"<<count-1;
                    if(num==1)
                    {
                        if(max<div)
                        {
                            max=div;
                            max_num=temp;
                            max_n=n;
                        }
                        cout<<"   factors:"<<div<<endl;
                        break;
                    }
                    else if(isprime(num))
                    {
                        div*=2;
                        cout<<"*"<<num<<"^"<<1;
                        if(max<div)
                        {
                            max=div;
                            max_num=temp;
                            max_n=n;
                        }
                        cout<<"   factors:"<<div<<endl;
                        break;
                    }
                }
            }
            i+=4;
        }
        cout<<endl;

    }
    cout<<endl<<"n:"<<max_n<<", number:"<<max_num<<", factors:"<<max;
    return(0);
}
