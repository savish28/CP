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
vector<ll> tr[200001];
bool vis[200001]={0};
ll co=0;
void dfs(ll a , ll p)
{
	vis[a]=1;
	co++;

	f(0,tr[a].size())
	{
		if(tr[a][i]==p) continue;

		dfs(tr[a][i],a);
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    
    ll n,k;
    cin>>n>>k;
    ll x,y;
    bool hi;
    f(0,n-1)
    {
    	cin>>x>>y>>hi;
    	if(hi==0)
    	{
    		tr[x].pb(y);
    		tr[y].pb(x);
    	}
    }
    ll ans1 = exp(n,k,mod);
    ll ans2=0;
    f(1,n+1)
    {
    	if(vis[i]==0)
    	{
    		co=0;
    		dfs(i,-1);
    		ans2+=exp(co,k,mod);
    		ans2=ans2%mod;
    	}
    }

    ans1+=mod;
    ans1-=ans2;

    ans1=ans1%mod;

    cout<<ans1<<endl;



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