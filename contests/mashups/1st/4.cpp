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

    ll n,k;
    cin>>n>>k;

    ll a[n];
    f(0,n) cin>>a[i];
    map<ll,ll> sb;
    f(0,n) sb[-a[i]]=1;
    ll ma=0;
    sb[0]=1;
    f(0,n) ma=max(a[i],ma);

    ll ans=0;

    while(2*k<ma)
    {	
    	ll lb = sb.lower_bound(-2*k) -> ff;
    	lb=-lb;

    	if(lb>k)
    	{
    		k=lb;
    		continue;
    	}
    	k*=2;
    	ans++;
    }
    
    	cout<<ans<<endl;
    
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