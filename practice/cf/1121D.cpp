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
    	ll h[n],c[n];
    	f(i,0,n) cin>>h[i]>>c[i];

    	ll dp[n][3];
    	dp[0][0]=0;
    	dp[0][1] = c[0];
    	dp[0][2] = 2*c[0];
    	f(i,1,n)
    	{
    		f(j,0,3)
    		{
    			dp[i][j]=mod*n;
    			f(k,0,3)
    			{
    				if(h[i]+j!=h[i-1]+k) dp[i][j] = min(dp[i][j],j*c[i]+dp[i-1][k]);
    			}
    		}
    	}
    	cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<endl;
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
