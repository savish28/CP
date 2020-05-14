#include<bits/stdc++.h>
#define ll long long int
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

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,k;
    cin>>n>>k;
    ll a[n];
    f(i,0,n) cin>>a[i];

    map< ll , vector< pair<ll,ll> > > sb;
    map< vector< pair<ll,ll> > , ll> co;
    f(i,0,n)
    {
    	vector< pair<ll,ll> > ok;
    	ll nu = a[i];
    	for(ll j = 2; j*j<=a[i];j++)
    	{
    		ll cou = 0;
    		while(nu%j==0) {cou++; nu/=j;}
    		cou = cou%k;
    		if(cou>0) ok.pb(mp(j,cou));
    	}
    	if(nu>1) ok.pb(mp(nu,1));

    	sb[a[i]] = ok;
    	co[ok]++;
    }
    ll ans = 0;
    f(i,0,n)
    {
    	vector< pair<ll,ll> > ok = sb[a[i]];

    	vector< pair<ll,ll> > ok2;

    	for(auto j: ok)
    	{
    		ok2.pb(mp(j.ff,k-j.ss));
    	}

    	if(ok2 == ok) ans+= co[ok]-1;
    	else if(co.find(ok2)!=co.end())
    	{
    		ans+= co[ok2];
    	}
    }
    

    cout<<ans/2<<endl;
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
