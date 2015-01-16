# include <iostream>

using namespace std;

int main()
{
    long long a[21][21],i,j;
    a[0][0]=1;
    for(i=0;i<21;i++)
        for(j=0;j<21;j++)
        {
            if((i==0)||(j==0))
                a[i][j]=1;
            else
            {
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
    for(i=0;i<21;i++)
    {
        for(j=0;j<21;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return(0);
}
