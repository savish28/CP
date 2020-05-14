#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 998244353
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;
    ll a[n];
    f(0,n) cin>>a[i];

    ll ans1 = 0;

    f(0,n)
    {	
    	ll po = 1;
    	ll ans=0;
    	while(a[i])
    	{
    		ll d = a[i]%10;
    		a[i]/=10;
    		ans+= d*po;
    		po*=100;
    		po = po%mod;
    		ans = ans%mod;
    	}

    	ans1+=(11*ans);

    	ans1 = ans1%mod;
    }
    cout<<(ans1*n)%mod<<endl;
    
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