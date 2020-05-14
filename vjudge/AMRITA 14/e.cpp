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
void solve()
{
	ll co = 0;
    	ll ans = 0;
    	for(ll j = n-1;j>=0;j--)
    	{
    		ll f1 = exp(10,co,mod);
    		ll f2 = exp(10,l[j],mod)+mod;
    		f2--;
    		f2 = f2%mod;

    		f2 = f2 * exp(9,mod-2,mod);
    		f2 = f2%mod;
    		f2*=f1;
    		f2 = f2%mod;
    		ans += (d[j]*f2)%mod;
    		ans = ans%mod;
    		co+=l[j];
    		co = co%(mod-1);
    	}
}
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
    	ll d[n],l[n];
    	f(i,0,n) cin>>l[i]>>d[i];
    	
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