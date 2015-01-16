#include<iostream>
using namespace std;
#include<conio.h>
#include<math.h>
int main()
{
    long long n=pow(2,1000);
    cout<<n<<endl;
    int r,sum=0;
    while(n!=0)
    {
        r=n%10;
        sum+=r;
        n/=10;
    }
    cout<<sum;
    return(0);
}
