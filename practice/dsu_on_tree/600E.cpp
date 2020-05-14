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
vector<ll> tr[100001];
int cnt[1000001], col[1000001],sz[1000001];
bool big[100001]={0};
ll sbcount[100001]={0},ans[100002]={0};
int sbmax = 0;
void add(int v, int p, int x)
{
	sbcount[cnt[col[v]]]-=col[v]; 
    cnt[ col[v] ] += x;
    sbcount[cnt[col[v]]]+=col[v];

    while(sbcount[sbmax]==0 && sbmax>0) sbmax--;
    sbmax = max(sbmax,cnt[col[v]]);

    for(auto u: tr[v])
        if(u != p && !big[u])
            add(u, v, x);
}

void getsz(int v, int p){
    sz[v] = 1; 
    for(auto u : tr[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u];
        }
}

void dfs(int v, int p, bool keep)
{
    int mx = -1, bigChild = -1;
    for(auto u : tr[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : tr[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
    add(v, p, 1);
    
    ans[v] = sbcount[sbmax];
    //answer the queries here
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;
    f(i,1,n+1) cin>>col[i];
    ll x,y;
    f(i,1,n)
    {
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    }
    getsz(1,0);

    dfs(1,0,0);
    f(i,1,n+1) cout<<ans[i]<<" ";
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