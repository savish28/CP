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
ll ans=0;
void sol(ll a[6])
{
	ll nu = a[2];
	while(a[4] && a[0])
	{

		ans+=2*nu-1;

		nu=nu-1;
		if(a[1]>0)
		{
			ans++;
			nu++;
			a[1]--;
		}
		else a[0]--;
		if(a[3]>0)
		{
			ans++;
			nu++;
			a[3]--;
		}
		else a[4]--;

		//cout<<ans<<endl;

		//f(0,6) cout<<a[i]<<" ";
		//cout<<endl;
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll a1[6];

    f(0,6) cin>>a1[i];

    sol(a1);
    
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