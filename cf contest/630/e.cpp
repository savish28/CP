#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 998244353
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

    ll n,m,l,r;
    cin>>n>>m>>l>>r;

    ll pl = r-l+1;
    ll di = 0;

    if((r-l)%2==0) di++;
    
    ll nm = (n%(mod-1)) * (m%(mod-1));
    nm = nm%(mod-1);


    ll ans1 = exp(pl,n,mod);

    ans1 = exp(ans1,m,mod);
    if(n%2==1 && m%2==1)
    {
    	cout<<ans1<<endl;
    	return 0;
    }

    ll ans2 = ans1;

    ans2-=di;

    ans2+=mod;
    ans2 = ans2%mod;

    ans2 = ans2*exp(2,mod-2,mod);
    ans2 = ans2%mod;

    ans1-=ans2;
    ans1+=mod;
    ans1 = ans1%mod;

    cout<<ans1<<endl;
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
