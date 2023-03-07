#include "iostream"
using namespace std;
bool even(int a)
{
if (a%2==0)
return (true);
else
return (false);
}
int main()
{
int n;
cout<<"Enter the limit :";
cin>>n;
for(int i=1;i<=n;i++)
{
if(even(i))
cout<<i<<" is even."<<endl;
else
cout<<i<<" is odd."<<endl;
}
return 0;
}
