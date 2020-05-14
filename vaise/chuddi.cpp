#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define f(p,n) for(ll i=p;i<n;i++)

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	ll a[n+1];
    	f(1,n+1) cin>>a[i];

    	ll pre[n+1]={0};
    	f(1,n+1)
    	{
    		pre[i]=pre[i-1]^a[i];
    	}
    	vector<ll> sb[1000001];
    	f(0,n+1)
    	{
    		sb[pre[i]].pb(i);
    	}
    	ll ans=0;
    	
    	f(0,1000001)
    	{
    		ll co = 0;
    		for(ll j=1;j<sb[i].size();j++)
    		{
    			if(sb[i][j-1]==sb[i][j]-1)
    			{
    				ans+=(j-1)*sb[i][j]-co-2*(j-1);
    				if(i==0) ans++;
    			}
    			else
    			{
    				ans+= sb[i][j]-sb[i][j-1]-2;
    				if(i==0) ans++;
    			}

    			co+=sb[i][j-1];
    			ans = ans%mod;
    		}
    	}
    	cout<<ans<<endl;
    }
    
    
return 0;
}
