#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

ll BIT[1000005], n;

void update_ftree(ll x, ll delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
ll query_ftree(ll x)
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    cin>>n;
    ll a[n+1];
    f(i,1,n+1) cin>>a[n-i+1];

    set<ll> sb;
    f(i,1,n+1) sb.insert(a[i]);

    map<ll,ll> tr;
    ll y = 0;
    for(auto va:sb)
    {
    	y++;
    	tr[va] = y;
    }
    
    f(i,1,n+1) { a[i] = tr[a[i]]; }

   
    ll li[n+2]={0};
    f(i,1,n+1)
    {
    	li[i] = query_ftree(a[i]-1);
    	update_ftree(a[i],1);
    }
    f(i,1,n+1)
    {
    	BIT[i]=0;
    }
    ll ans = 0;
    f(i,1,n+1)
    {
    	ans += query_ftree(a[i]-1);
    	update_ftree(a[i],li[i]);
    }
    cout<<ans<<endl;
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

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    
    
    
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
