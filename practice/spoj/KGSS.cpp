#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll exp(ll a,ll b,ll m);
pair<int,int> sgtr[400005];
ll a[100005];
void build(int node, int start, int end)
{
    if(start == end)
    {
        sgtr[node].ff = a[start];
        sgtr[node].ss = -mod;
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        
        // Internal node will have the sum of both of its children
        sgtr[node].ff = max(sgtr[2*node].ff , sgtr[2*node+1].ff);
        sgtr[node].ss = max(sgtr[2*node].ff + sgtr[2*node+1].ff - sgtr[node].ff, max(sgtr[2*node].ss , sgtr[2*node+1].ss));
    }
}

void update(int node, int start, int end, int idx, ll val)
{
    if(start == end)
    {
        sgtr[node].ff = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        
        sgtr[node].ff = max(sgtr[2*node].ff , sgtr[2*node+1].ff);
        sgtr[node].ss = max(sgtr[2*node].ff + sgtr[2*node+1].ff - sgtr[node].ff, max(sgtr[2*node].ss , sgtr[2*node+1].ss));

    }
}

pair<ll,ll> query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return mp(-mod,-mod);
    }
    if(l <= start and end <= r)
    {
        return sgtr[node];
    }
    
    int mid = (start + end) / 2;
    pair<ll,ll> p1 = query(2*node, start, mid, l, r);
    pair<ll,ll> p2 = query(2*node+1, mid+1, end, l, r);

    ll f1 = max(p1.ff , p2.ff);
    ll f2 = max(p1.ff + p2.ff - f1, max(p1.ss , p2.ss));
    return mp(f1,f2);
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	/*#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif*/

    ll n;
    cin>>n;

    f(i,1,n+1) cin>>a[i];

    build(1,1,n);
    ll q;
    cin>>q;
    char qc;
    ll x,y;
    while(q--)
    {
    	cin>>qc>>x>>y;

    	if(qc=='U') update(1,1,n,x,y);
    	else 
    	{
    		pair<ll,ll> msm = query(1,1,n,x,y);
    		cout<<msm.ff+msm.ss<<endl;
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


