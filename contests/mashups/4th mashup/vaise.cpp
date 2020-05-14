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
ll b[1000001]={0};
 ll dp[1000001]={0};
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;
    ll x,y;

    f(0,n)
    {
    	cin>>x>>y;

    	b[x]=y;
    }

   

    ll o=0;
    ll coo[1000001]={0};
    ll cou=0;
    dp[0]=0;
    f(1,1000001)
    {
    	if(b[i]==0)
    	{
    		dp[i]=dp[i-1];
    			coo[i]=cou;
    		continue;
    	}

    	ll mit = max(i-1-b[i],o);
    	
    		dp[i]= coo[i-1]-coo[mit] + dp[mit];
    	

    	cou++;
    	coo[i]=cou;

    }
    // f(0,8) cout<<coo[i]<<" ";
    //f(0,8) cout<<dp[i]<<" ";
   // cout<<endl;
    ll mi=mod;
    ll ind = 0;
    ll co =0;
   for(ll i=1000000;i>=0;i--)
    {

    	if(b[i]==0) continue;
    	if(dp[i] + co <=mi)
    	{
    		mi = dp[i]+co;
    		ind=co;
    	}
    	co++;
    }


    cout<<mi<<endl;
    
    
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