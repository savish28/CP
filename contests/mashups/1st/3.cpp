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
    ll a[n+1];
    f(1,n+1) cin>>a[i];
    ll co=0;
    
    f(1,n+1)
    {
    	if(a[a[i]]!=a[i])
    	{
    		cout<<-1<<endl;
    		return 0;
    	}
    }
    

    set<ll> kon;
    vector<ll> sb[n+1];

    f(1,n+1)
    {
    	kon.insert(a[i]);
    	sb[a[i]].pb(i);
    }

    ll sz=kon.size();
    cout<<sz<<endl;

    ll g[n+1]={0};
    ll h[sz+1]={0};
    ll ind=0;
    for(auto hi: kon)
    {
    	ind++;
    	h[ind] = hi;

    	f(0,sb[hi].size())
    	{
    		g[sb[hi][i]]=ind;
    	}
    }

    f(1,n+1) cout<<g[i]<<" ";
    cout<<endl;

    f(1,sz+1) cout<<h[i]<<" ";
    cout<<endl;
    
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