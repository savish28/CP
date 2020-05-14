#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{


	int n;
	cin>>n;
	int ans=0;
	int temp = n;
	while(temp != 0)
	{
      temp = temp/5;
      ans = ans + temp;
	}
     cout<<ans<<endl;
	}
	return 0;
}