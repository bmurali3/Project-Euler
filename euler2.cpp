#include<iostream>
using namespace std;
int main()
{
    long sum=0;
    int n1=0,n2=1,temp;
    while(n2<4000000)
    {
        temp=n1+n2;
        n1=n2;
        n2=temp;
        if(n2%2==0)
            sum+=n2;
    }
    cout<<sum;
}
