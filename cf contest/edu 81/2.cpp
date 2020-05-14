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
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

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
    	ll n,x;
    	cin>>n>>x;
    	string s;
    	cin>>s;
    	
    	ll su = 0;
    	ll di[n+1]={0};
    	ll ne[n+1]={0};
    	di[0] = 1;
    	f(i,0,n-1)
    	{
    		if(s[i]=='0') su++;
    		else su--;

    		if(su>=0) di[su]++;
    		else ne[-su]++;
    	}
    	if(s[n-1]=='0') su++;
    	else su--;
    	ll ans = 0;
    	
    	f(i,0,n+1)
    	{
    		if(su==0 && ( (i==x && di[i]>0) || (x==-i && ne[i]>0)))
    		{
    			ans=-1;
    			break;
    		}

    		if(su!=0)
    		{
    			if( (x-i)/su >=0 && (x-i)==((x-i)/su)*su ) ans+=di[i];
    			if( (x+i)/su >=0 && (x+i)==((x+i)/su)*su) ans+=ne[i];
    		}
    		//cout<<i<<" "<<ans<<endl;
    	}
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
