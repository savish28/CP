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
vector<ll> tr[100001];
int col[100001],sz[100001],he[100001],ans[100001]={0};
map<ll,ll> cnt[100001];
bool big[100001]={0};
vector< pair<ll,ll> > sb[100001];

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
    if(cnt[he[v]][col[v]]==0)
    {
        cnt[he[v]].erase(col[v]);
    }
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
   // cout<<"v = "<<v<<endl;
    for(auto q:sb[v])
    {
     //   cout<<"height = "<<q.ff<<endl;
        if(q.ff>=100001)
        {
            ans[q.ss] = 0; continue;
        }
      //  for(auto p:cnt[q.ff]) cout<<p.ff<<" "<<p.ss<<endl;
       // cout<<"size ="<<cnt[q.ff].size()<<endl;
    	ans[q.ss] = cnt[q.ff].size();
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
    cin>>n;
    string wo[n+1];
    map<string,ll> msm;
    vector<ll> roots;
    f(i,1,n+1)
    {
    	cin>>wo[i]>>x;
        msm[wo[i]]=i;
    	tr[x].pb(i);
        if(x==0) roots.pb(i);
    }
    
    f(i,1,n+1) col[i] = msm[wo[i]];

    cin>>m;
    for(auto po:roots) getsz(po,0,1);
    f(i,0,m)
    {
    	cin>>x>>y;
    	sb[x].pb(mp(he[x]+y,i));
    }
   
    for(auto po:roots) dfs(po,0,0);
    
    f(i,0,m) 
    {
    	cout<<ans[i]<<endl;
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