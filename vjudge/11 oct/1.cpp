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

    ll mo = 2147483647;

    ll t;
    cin>>t;
    while(t--)
    {
    	ll n,m;
    	cin>>n>>m;

    	ll a[n+1][m+1];
    	f(i,0,n+1) a[i][m] = mo;
    	f(j,0,m+1) a[n][j] = mo;
    	f(i,0,n)
    	{
    		f(j,0,m) cin>>a[i][j];
    	}

    	ll x=0,y=0;

    	while(a[x+1][y]!=mo || a[x][y+1]!=mo)
    	{
    		bool adk = 0;
    		if(a[x+1][y]>a[x][y+1]) adk = 1;

    		if(adk) y++;
    		else x++;
    	}
    	//cout<<x<<" "<<y<<endl;
    	cout<<x+y<<endl;
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
