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

    ll n,m;
    cin>>n>>m;
    ll ans = 0,ans1;

    ll fac[n+2]={0};
    fac[0]=1;
    fac[1]=1;

    f(i,2,n+1)
    {
    	fac[i]=(fac[i-1]*i)%m;
    }
    f(i,0,n)
    {

    	ans1 = ((n-i)*(n-i))%m;
    	ans1*= fac[i+1];
    	ans1 = ans1%m;
    	ans1*=fac[n-i-1];
    	ans1 = ans1%m;

    	ans+=ans1;
    	ans = ans%m;
    	//cout<<ans1<<endl;
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
