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
ll n,l,r,le; string s;
ll a[1000001];
ll tree[4000001][3];

void build(ll node, ll start, ll end)
{
	
    if(start == end)
    {
    	tree[node][0]=0;
    	tree[node][1]=0;
    	tree[node][2]=0;

        if(s[start-1]=='(') tree[node][1]++;
         if(s[start-1]==')') tree[node][2]++;
    }
    else
    {
        ll mid = (start + end) / 2;
        
        build(2*node, start, mid);
     
        build(2*node+1, mid+1, end);
       
       	ll ex = min(tree[2*node][1] , tree[2*node+1][2]);
        tree[node][0] = tree[2*node][0] + tree[2*node+1][0]  + ex;
         tree[node][1] = tree[2*node][1] + tree[2*node+1][1]  - ex;
         tree[node][2] = tree[2*node][2] + tree[2*node+1][2]  - ex;
    }
}

pair<ll,pair<ll,ll> >  query(ll node, ll start, ll end)
{
	//cout<<node<<" "<<start<<" "<<end<<endl;
   
   if(r < start or end < l)
    {
        return mp(0,mp(0,0));
    }
    if(l <= start and end <= r)
    {
        return mp(tree[node][0],mp(tree[node][1],tree[node][2]));
    }
    
    ll mid = (start + end) / 2;
    pair<ll,pair<ll,ll> >  p1 = query(2*node, start, mid);
    pair<ll,pair<ll,ll> >  p2 = query(2*node+1, mid+1, end);
   
   pair<ll,pair<ll,ll> > ans;

   ll ex = min( p1.ss.ff,p2.ss.ss);
   ans.ff = p1.ff + p2.ff + ex;
   ans.ss.ff = p1.ss.ff + p2.ss.ff -ex;
   ans.ss.ss = p1.ss.ss + p2.ss.ss -ex;
    return ans;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

   
    cin>>s;
    le=s.size();
    build(1,1,le);
    cin>>n;
    while(n--)
    {
    	cin>>l>>r;
    	pair<ll,pair<ll,ll> > res = query(1,1,le);
    	cout<<2*res.ff<<endl;
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