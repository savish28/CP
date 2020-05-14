#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
map<ll,ll> o,e;
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

     ll n;
     cin>>n;
     ll a[n];
     f(0,n) cin>>a[i];

     ll xo=0;

     f(0,n)
     {
     	xo^=a[i];

     	if(i%2==0) o[xo]++;
     	else e[xo]++;

     	//cout<<xo<<endl;
     }
     e[0]++;
     map<ll,ll> :: iterator it;
     ll ans=0;
     for(it=o.begin();it!=o.end();it++)
     {
     	ll va= it-> ss;
     	ans+=(va*(va-1))/2;
     }
     for(it=e.begin();it!=e.end();it++)
     {
     	ll va= it-> ss;
     	ans+=(va*(va-1))/2;
     }

     cout<<ans<<endl;
    
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