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
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
vector<ll> tr[1001];
ll vis[1001]={0};
ll co = 0;
ll coun = 0;
void dfs(ll a)
{
	if(vis[a]==co) return;
	coun++;
	vis[a] = co;

	f(i,0,tr[a].size()) dfs(tr[a][i]);
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n = 0;
    while(cin>>n)
    {
    	if(n==0) break;

    	f(i,1,n)
    	{
    		vis[i]=0;
    		string s;
    		cin>>s;
    		f(j,0,n-i)
    		{
    			if(s[j]=='1') tr[i].pb(i+j+1);
    			else tr[i+j+1].pb(i);
    		}
    	}
    	vis[n]=0;
    	ll ans = 0;
    	f(i,1,n+1)
    	{
    		co = i;
    		coun = 0;
    		dfs(i);
    		if(coun == n) ans++;
    		//cout<<coun<<endl;
    	}
    	cout<<ans<<endl;

    	f(i,1,n+1) {tr[i].clear();}
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