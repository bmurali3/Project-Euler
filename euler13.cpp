#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
using namespace std;

int main () {
  string line[100];
  ifstream myfile ("example.txt");
  int k=0;
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line[k]);
      k++;
    }
    myfile.close();
  }
  else cout << "Unable to open file";

  /*for(int i=0;i<100;i++)
  {
      for(int j=0;j<50;j++)
      {
          char ch=line[i][j];
          temp=ch;
          cout<<temp-48<<"";
      }
      cout<<endl;
  }*/

  int digits[50];
  int carry=0,temp;
  int sum;
  for(int i=49;i>=0;i--)
  {
      sum=0;
      for(int j=0;j<100;j++)
      {
          temp=(int)line[j][i];
          temp-=48;
          //cout<<temp<<" ";
          sum+=temp;
      }
      sum+=carry;
      digits[i]=sum%10;
      carry=sum/10;
  }
  cout<<endl<<carry<<",";
  for(int i=0;i<49;i++)
  {
  cout<<digits[i];
  }
  return 0;
}
