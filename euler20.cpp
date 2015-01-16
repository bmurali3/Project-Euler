#include<iostream>
using namespace std;
int digit_sum(int n)
{
    int r,sum=0;
    while(n!=0)
    {
        r=n%10;
        sum+=r;
        n/=10;
    }
    return(sum);
}
int main()
{
    int n;
    long long pro=1,temp=0;
    for(n=1;n<=100;n++)
    {
        pro*=n;
        //if(temp==digit_sum(pro))
        //    pro/=n;
        while(pro%10==0)
        {
            pro/=10;
        }
        //temp=digit_sum(pro);
        cout<<pro<<endl;
    }
    cout<<digit_sum(pro);
}
