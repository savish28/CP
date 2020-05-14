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

    ll t;
    cin>>t;
    while(t--)
    {
    	ll k,n;
    	cin>>k>>n;
    	vector< pair<ll,ll> > ev;
    	ll x,y;
    	f(i,0,k) 
    	{
    		cin>>x>>y;
    		ev.pb(mp(x,y));
    	}
    	ll co[k]={0};
    	map<ll,ll> sb;

    	f(i,0,m)
    	{
    		ll d;
    		cin>>d;

    		f(i,0,d)
    		{
    			cin>>x>>y;
    			co[x-1]+=y;
    		}
    	}

    	

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
