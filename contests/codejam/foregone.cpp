#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define prin(t) cout<<"Case #"<<t<<": "
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	ll t;
 	cin>>t;
 	string s;
 	for(ll te=1;te<=t;te++)
 	{
 		
 		cin>>s;
 		ll l=s.length();
 		string b="";
 		ll ind=l;
 		prin(te);
 		f(0,l)
 		{
 			if(s[i]=='4')
 			{
 				ind=i;
 				break;
 			}

 			cout<<s[i];
 		}

 		f(ind,l)
 		{
 			if(s[i]=='4')
 			{
 				b+='2';
 				cout<<2;
 			}
 			else 
 				{
 					b+='0';
 					cout<<s[i];
 				}
 		}
 		cout<<" "<<b<<endl;

 	}

    
    
    
return 0;
}

ll exp(ll a,ll b,ll m)
{
	if(b==0)
	{
		return 1;
	}
	ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp;
}