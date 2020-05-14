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
 	ll n;
 	string s;
 	for(ll te=1;te<=t;te++)
 	{
    	cin>>n>>s;
    	ll l = s.length();
    	prin(te);
    	if(s[0]=='E' && s[l-1]=='S')
    	{
    		f(0,n-1) cout<<'S';
    		f(0,n-1) cout<<'E';
    	}
    	else if(s[0]=='S' && s[l-1]=='S')
    	{
    		ll co=0;
    		f(1,l)
    		{
    			if(s[i]=='E') co++;
    			if(s[i]=='E' && s[i+1]=='E') break;
    		}
    		f(0,co) cout<<'E';
    		f(0,n-1) cout<<'S';
    		f(co+1,n) cout<<'E';
    	}
    	else if(s[0]=='S' && s[l-1]=='E')
    	{
    		f(0,n-1) cout<<'E';
    		f(0,n-1) cout<<'S';
    	}
    	else
    	{
    		ll co=0;
    		f(1,l)
    		{
    			if(s[i]=='S') co++;
    			if(s[i]=='S' && s[i+1]=='S') break;
    		}
    		f(0,co) cout<<'S';
    		f(0,n-1) cout<<'E';
    		f(co+1,n) cout<<'S';
    	}
    	cout<<endl;
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