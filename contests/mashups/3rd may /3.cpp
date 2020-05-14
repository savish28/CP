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
    ll cu=0;
    ll ma=0;
    pair<ll,ll> k[n];
    f(0,n) cin>>k[i].ff>>k[i].ss;

    sort(k,k+n);
   f(0,n)
    {
    	ll ok = k[i].ss*4;
    	if(cu-ok>=0) cu-=ok;
    	else cu=0;

    	cu+=k[i].ss;
    }

    //cout<<cu<<endl;
    ll co=1;
    ll ans=4;
    while(ans<cu)
    {
    	co++;
    	ans*=4;
    }
  //  cout<<co<<" "<<k[n-1].ff<<endl;

    cout<<k[n-1].ff + co<<endl;
    
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