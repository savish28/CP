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

    	sort(sb.begin(),sb.end());

    

    	
    	bool ans = 1;
    	f(i,0,n)
    	{
    		if(i+2<n)
    		{
    			
    			if(sb[i].ff == sb[i+1].ff && sb[i+1].ff == sb[i+2].ff)
    			{
    				ll mr = min(sb[i].ss.ss, min(sb[i+1].ss.ss,sb[i+2].ss.ss));
    				ll ml = max(sb[i].ss.ff, max(sb[i+1].ss.ff,sb[i+2].ss.ff));

    				if(ml<=mr)
    				{
    					ans = 0;
    					break;
    				}
    			}
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
