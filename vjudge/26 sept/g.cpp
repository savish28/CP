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
ll pp = 37;
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    int n;

    while(cin>>n)
    {
    	if(n==0) break;

    	int a[n+1],b[n+1];
    	f(i,1,n+1) cin>>a[i];
    	f(i,1,n+1) cin>>b[i];

    	ll ans = 0;
    	ll psb[n+1]={0};
    	f(i,1,n+1) psb[b[i]]=i;
    	ll l,r;
    	f(i,1,n+1)
    	{
    		l = r = psb[a[i]];

    		f(j,i+1,n+1)
    		{
    			l = min(l,psb[a[j]]);
    			r = max(r,psb[a[j]]);
    			if(r-l == j-i) ans++;
    		}
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