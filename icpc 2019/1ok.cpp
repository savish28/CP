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

    	vector<ll> nu;
    	ll n1 = n;
    	while(n1>0)
    	{
    		nu.pb(n1%10);

    		n1/=10;
    	}
    	vector<ll> sb;

    	ll le = nu.size();

    	f(i,0,le)
    	{
    		ll te = 1;
    		ll np = 0;
    		f(j,0,le)
    		{
    			if(i==j) continue;

    			np+= nu[j]*te;

    			te*=10;
    		}

    		sb.pb(np);
    	}

    	sort(sb.begin(),sb.end());

    	cout<<sb[0]<<endl;
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
