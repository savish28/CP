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
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
ll exp(ll a,ll b,ll m);
 
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 /*
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 */
    ll n;
    cin>>n;

    ll a[n];

    f(i,0,n) cin>>a[i];

    ll co[3]={0};

    f(i,0,n) co[a[i]-1]++;

    double dp[2][302][302];

    f(i,0,n+1)
    {
    	for(ll j = i;j>=0;j--)
    	{
    		for(ll k = j;k>=0;k--)
    		{
    			ll a = k , b = j-k, c = i-a-b;

    			ll sa = i%2;
    			ll di = 1-sa;
    			if(i==0) dp[0][b][c] = 0;
    			else
    			{
    				double curr = 0;

    				if(a>0) curr += dp[di][b][c]*double(a);
    				if(b>0) curr += dp[sa][b-1][c]*double(b);
    				if(c>0) curr += dp[sa][b+1][c-1]*double(c);
    				curr+=n;
    				dp[sa][b][c] = curr/double(a+b+c);
    			} 
    		}
    	}
    }
    cout<<fixed;
    cout<<setprecision(12);
    cout<<dp[n%2][co[1]][co[2]]<<endl;
    
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
