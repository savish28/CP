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
    	ll a,b;
    	cin>>a>>b;

    	
    	ll a1 = min(a,b);
    	ll b1 = max(a,b);

    	ll sq = sqrt(2*(b1-a1));

    	while( (sq*(sq+1))/2 > (b1-a1)) sq--;
    	
    	a1+= (sq*(sq+1))/2;

    	ll d1 = b1-a1;
    	//cout<<d1<<" "<<sq<<b1<<" "<<a1<<endl;
    	ll ans = sq + 2*d1;

    	ll d2 = abs(a1+sq+1-b1);
    	ans = min(ans,sq+1+2*d2);

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
