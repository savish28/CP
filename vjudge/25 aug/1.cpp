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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    ll ti = 0;
    while(t--)
    {
    	ti++;
    	ll n,k;
    	cin>>n>>k;
    	multiset<ll, greater<ll> > sb;
    	sb.insert(0);
    	ll x;
    	f(i,0,n)
    	{
    		cin>>x;
    		sb.insert(x);
    	}
    	ll ans = 0;
    	//cout<<"sz "<<sb.size()<<endl;
    	while(sb.size()>k)
    	{
    		auto f = sb.begin();
    		sb.erase(f);
    		ll co =1;
    		ll val = *f;

    		while(*sb.lower_bound(val/2)!=0)
    		{
    			//cout<<val<<"ssd"<<endl;
    			f = sb.lower_bound(val/2);
    			co++;
    			val = *f;
    			sb.erase(f);
    			if(co==k) break;
    		}

    		
    		if(co==k) ans++;
    		else break;


    	}
    	cout<<"Case #"<<ti<<": ";
    	cout<<ans<<endl;
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