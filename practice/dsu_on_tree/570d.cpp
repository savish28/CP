#include<bits/stdc++.h>
#define ll int
#define endl "\n"
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
vector<ll> tr[500001];
int cnt[500001][26],col[500001],sz[500001],he[500001];
bool big[500001]={0},ans[500001]={0};
vector< pair<ll,ll> > sb[500001];

void getsz(int v, int p, int h){
    sz[v] = 1;
    he[v] = h; 
    for(auto u : tr[v])
        if(u != p){
            getsz(u, v,h+1);
            sz[v] += sz[u];
        }
}
void add(int v, int p, int x)
{
    cnt[he[v]][col[v]] += x;
    for(auto u: tr[v])
        if(u != p && !big[u])
            add(u, v, x);
}
void dfs(int v, int p, bool keep)
{
	//cout<<v<<" "<<p<<endl;
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
    
    for(auto q:sb[v])
    {
    	ll od = 0;
    	f(i,0,26) od+= (cnt[q.ff][i]%2==1);
    	if(od>1) ans[q.ss]=0;
    	else ans[q.ss] = 1;
    }
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

    ll n,m,x,y;
    cin>>n>>m;
    f(i,2,n+1)
    {
    	cin>>x;
    	tr[x].pb(i);
    }
    string wo;
    cin>>wo;
    f(i,0,n) col[i+1] = (wo[i]-'a');
   
    f(i,0,m)
    {
    	cin>>x>>y;
    	sb[x].pb(mp(y,i));
    }
    getsz(1,0,1);
    dfs(1,0,1);
    
    f(i,0,m) 
    {
    	if(ans[i]) cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;
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