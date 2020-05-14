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
ll n,m,q;
ll ans = 0;
pair<ll,ll> parent[1001][1001];
ll ar[1001][1001];
bool vis[1001][1001];
ll qe[10000][4];

pair<ll,ll> find_set(pair<ll,ll> v) {
    if (v == parent[v.ff][v.ss])
        return v;
    return parent[v.ff][v.ss] = find_set(parent[v.ff][v.ss]);
}

void make_set(pair<ll,ll> cu , pair<ll,ll> pa)
{
	vis[cu.ff][cu.ss]=1;
	parent[cu.ff][cu.ss] = pa;

	if(cu.ff>0 && ar[cu.ff-1][cu.ss]==0 && vis[cu.ff-1][cu.ss]==0) make_set(mp(cu.ff-1,cu.ss),pa);
	if(cu.ff<n-1 && ar[cu.ff+1][cu.ss]==0 && vis[cu.ff+1][cu.ss]==0) make_set(mp(cu.ff+1,cu.ss),pa);
	if(cu.ss>0 && ar[cu.ff][cu.ss-1]==0 && vis[cu.ff][cu.ss-1]==0) make_set(mp(cu.ff,cu.ss-1),pa);
	if(cu.ss<m-1 && ar[cu.ff][cu.ss+1]==0 && vis[cu.ff][cu.ss+1]==0) make_set(mp(cu.ff,cu.ss+1),pa);

}

void solve(ll i1, ll j1)
{
	parent[i1][j1] = mp(i1,j1);
    				if(i1>0 && ar[i1-1][j1]==0) 
    				{
    					
    					pair<ll,ll> p1 = find_set(mp(i1-1,j1));
    					pair<ll,ll> p2 = find_set(mp(i1,j1));

    					if(p1!=p2)
    					{
    						ans--;
    						parent[p1.ff][p1.ss] = p2;
    					}
    					
    				}
					if(i1<n-1 && ar[i1+1][j1]==0 ) 
    				{
    					pair<ll,ll> p1 = find_set(mp(i1+1,j1));
    					pair<ll,ll> p2 = find_set(mp(i1,j1));

    					if(p1!=p2)
    					{
    						ans--;
    						parent[p1.ff][p1.ss] = p2;
    					}
    				}
    				if(j1>0 && ar[i1][j1-1]==0 ) 
    				{
    					pair<ll,ll> p1 = find_set(mp(i1,j1-1));
    					pair<ll,ll> p2 = find_set(mp(i1,j1));

    					if(p1!=p2)
    					{
    						ans--;
    						parent[p1.ff][p1.ss] = p2;
    					}
    				}
    				if(j1<m-1 && ar[i1][j1+1]==0) 
    				{
    					pair<ll,ll> p1 = find_set(mp(i1,j1+1));
    					pair<ll,ll> p2 = find_set(mp(i1,j1));

    					if(p1!=p2)
    					{
    						ans--;
    						parent[p1.ff][p1.ss] = p2;
    					}
    				}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    cin>>n>>m>>q;

   
    f(i,0,q)
    {
    	cin>>qe[i][0]>>qe[i][1]>>qe[i][2]>>qe[i][3];
    	qe[i][0]--;
    	qe[i][1]--;
    	qe[i][2]--;
    	qe[i][3]--;
    	if(qe[i][0]==qe[i][2])
    	{
    		f(j,qe[i][1],qe[i][3]+1) ar[qe[i][0]][j]++;
    	}
    	else
    	{
    		f(j,qe[i][0],qe[i][2]+1) ar[j][qe[i][1]]++;
    	}
    }
    
    vector<ll> pr;

    f(i,0,n)
    {
    	f(j,0,m)
    	{
    		if(ar[i][j]==0 && vis[i][j]==0)
    		{
    			make_set(mp(i,j),mp(i,j));
    			ans++;
    		}
    	}
    }

    for(ll i = q-1;i>=0;i--)
    {
    	pr.pb(ans);

    	if(qe[i][0]==qe[i][2])
    	{
    		f(j,qe[i][1],qe[i][3]+1) 
    		{
    			ar[qe[i][0]][j]--;
    			if(ar[qe[i][0]][j]==0)
    			{
    				ans++;
    				solve(qe[i][0],j);
    			}
    		}
    	}
    	else
    	{
    		f(j,qe[i][0],qe[i][2]+1) 
    		{
    			ar[j][qe[i][1]]--;
    			if(ar[j][qe[i][1]]==0)
    			{
    				ans++;
    				solve(j,qe[i][1]);
    			}
    		}
    	}
    }

    reverse(pr.begin(),pr.end());

    f(i,0,pr.size()) cout<<pr[i]<<endl;
    
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