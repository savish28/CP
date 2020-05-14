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
    	ll n,k;
    	cin>>n>>k;

    	ll a[n];
    	f(i,0,n) cin>>a[i];
    	vector<ll> pr;
    	ll ans = 0;
    	ll co = 0;
    	f(i,0,n)
    	{
    		if((ans>0 && ans+a[i]<0) && pr.size()!=k-1)
    		{
    			pr.pb(co);
    			ans=a[i];
    			co++;
    		}
    		else
    		{
    			ans+=a[i];
    			co++;
    		}
    	}
    	pr.pb(co);
    	if(ans<0)
    	{
    		cout<<"NO"<<endl;
    	}
    	else
    	{
    		cout<<"YES"<<endl;
    		f(i,0,k)
    		{
    			cout<<pr[i]<<" ";
    		}
    		cout<<endl;
    	}

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
