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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

        ll n,m;
        cin>>n>>m;
        ll di = m-(n-1);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    if(n==4 || di<2) 
    {
    	cout<<-1<<endl;
    	return 0;
    }

    vector<ll> r;
    f(1,n+1)
    {
    	if(i!=a && i!=b && i!=c && i!=d) r.pb(i);
    }

    cout<<a<<" "<<c<<" ";
    f(0,r.size()) cout<<r[i]<<" ";
    cout<<d<<" "<<b<<endl;

    cout<<c<<" "<<a<<" ";
    f(0,r.size()) cout<<r[i]<<" ";
    cout<<b<<" "<<d<<endl;
    
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