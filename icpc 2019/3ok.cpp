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

    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	vector< pair< ll, pair<ll,ll> > > sb;
    	ll x,y,v;

    	f(i,0,n)
    	{
    		cin>>x>>y>>v;

    		sb.pb(mp(v,mp(x,y)));
    	}
    	bool ans = 1;
    	f(i,0,n)
    	{
    		ll col = 0;
    		ll cor = 0;
    		ll l = sb[i].ss.ff, r = sb[i].ss.ss , v1 = sb[i].ff;
    		
    		f(j,0,n)
    		{
    			if(sb[j].ff==v1)
    			{
    				if(l>=sb[j].ss.ff && l<=sb[j].ss.ss) col++;
    				if(r>=sb[j].ss.ff && r<=sb[j].ss.ss) cor++;
    			}
    			if(col>=3 || cor>=3) break;
    		}

    		if(col>=3 || cor>=3)
    		{
    			ans = 0;
    			break;
    		}
    	}

    	if(ans == 1)
    	{
    		cout<<"YES"<<endl;
    	}
    	else cout<<"NO"<<endl;
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
