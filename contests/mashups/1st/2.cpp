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
ll v[400000];
vector<ll> tr[400000];
bool ans=1;
ll v2[400000];
ll od=0;
ll co=0;
void dfs(ll a, ll ko)
{
	if(ans==0) return ;
	if(v[a]==1)
	{
		if(v2[a]!=ko) ans=0;
		return;
	}	
	co++;
	v[a]=1;
	v2[a]=ko;

	if(ko==1) od++;

	f(0,tr[a].size())
	{
		dfs(tr[a][i],1-ko);
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    ll n=0;
    ll m;
    while(t--)
    {
    	od=0;
    	ans=1;
    	f(0,n+1) tr[i].clear();
    	f(0,n+1) v[i] = 0;
    	f(0,n+1) v2[i] = 0;

    	cin>>n>>m;
    	ll x,y;
    	f(0,m)
    	{
    		cin>>x>>y;
    		tr[x].pb(y);
    		tr[y].pb(x);
    	}
    	ll ans2 = 0;
    	ll ans3=1;
    	f(1,n+1) 
    	{
    		if(v[i]==0)
		    	{
		    		ans2=0;
		    		co=0; od=0;
		    			 dfs(i,0);

		    		ans2+= exp(2,od,mod);

    	ans2+= exp(2,co-od,mod);
    		ans3*=ans2;
    		ans3=ans3%mod;
		    	}

    	}

    	//dfs(1,0);
    	if(ans==0)
    	{
    		cout<<0<<endl;
    		continue;
    	}

    	
    	cout<<ans3 <<endl;
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