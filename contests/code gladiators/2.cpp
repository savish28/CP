#include<bits/stdc++.h>
#define ll int
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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	/*#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
*/
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	ll a[n];
    	f(0,n) cin>>a[i];
    	ll ma=-mod;
    	f(0,n)
    	{
    		if(a[i]==0) continue;

    		ma=max(ma,a[i]);
    	}

    	if(ma<=0)
    	{
    		if(ma==-mod) ma=0;
    		cout<<ma<<endl;
    		continue;
    	}

    	/*map<ll,ll> maal;

    	ll dp[n+1]={0};
    	dp[n-1]=a[n-1];
    	maal[n-1]=a[n-1];
    	ll kisko[n+1]={0};
    	for(ll j=n-2;j>=0;j--)
    	{
    		dp[j] = a[j]+dp[j+2];

    		if(dp[j]<a[j]) dp[j]=a[j];

    		dp[j]=max(dp[j],dp[j+1]);
    	}

    	cout<<dp[0]<<endl;
    	*/

    	
    	ll sa=0,sb=0;
    	ll ko=0;
    	vector<ll> ans;
    	for(ll j=n-1;j>=0;j--)
    	{
    		vector<ll> b[2];
    		vector<ll> sb;

    		if(a[j]<=0) continue;
    		while(a[j]>0 && j>=0)
    		{
    			sb.pb(a[j]);

    			j--;
    		}
    		j++;
    		ll l=sb.size();

    		if(l==0 ) continue;
    		//j++;
    		ll tw=1,tw2=0;
    		ll b1[2]={0,0};
    		f(0,l)
    		{
    			tw=1-tw;
    			tw2=1-tw2;
    			if(b1[tw]>b1[tw2])
    			{
    				b1[tw2]=b1[tw];
    				b[tw2]=b[tw];
    			}
    			else if(b1[tw]==b1[tw2] && b1[tw]!=0)
    			{
    				if(b[tw][0]>b[tw2][0])
    				{
    					b1[tw2]=b1[tw];
    					b[tw2]=b[tw];
    				}
    			}
    			
    			b[tw].pb(sb[i]);
    			b1[tw]+=sb[i];

    		}

    		ll kiska=0;
    		if(b1[1]>b1[0])
    		{
    			kiska=1;
    		}
    		else if(b1[1]==b1[0] )
    		{
    			f(0,min(b[0].size(),b[1].size()))
    			{
    				if(b[1][i]>b[0][i]) 
    				{
    					kiska=1; break;
    				}
    				else if(b[1][i]<b[0][i]) break;
    			}
    		}

    		f(0,b[kiska].size())
    		{
    			ans.pb(b[kiska][i]);
    		}

    		
    	}

    	f(0,ans.size()) cout<<ans[i];
    	cout<<endl;
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