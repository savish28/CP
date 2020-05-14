#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
/*
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
*/
    ll n,m;
    cin>>n>>m;

    if(n==1)
    {
    	cout<<0<<endl;
    	return 0;
    }
  //  n = n%mod;
    ll nu = (n)%mod;
    //m =m%mod;
    f(i,1,m+1)
    {
    	nu*=(i%mod);
    	nu = nu%mod;
    }
    nu = nu*(((m*(n%mod))%mod-1+mod)%mod);
    nu = nu%mod;

    ll de = 1;

    f(i,0,m) 
    {
    	de*=((((n%mod)*m)%mod-i+mod)%mod);
    	de = de%mod;
    }
    
    de*=((m+1)%mod);
    de = de%mod;

    ll up = 1;
    f(i,1,m)
    {
    	up*=((((n%mod)*m)%mod-2-i+1+mod)%mod);
    	up = up%mod;

    	up = up*exp(i,mod-2,mod);
    	up = up%mod;
    }

    nu = nu*up;
    nu = nu%mod;
    ////if(de==0) nu = 0;
   de = exp(de,mod-2,mod);

    up = up%mod; de = de%mod;
    nu = nu * de;

    nu = nu%mod;

    cout<<nu<<endl;
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
