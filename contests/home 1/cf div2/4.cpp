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
ll calc(ll a)
{
	ll sq=sqrt(a);
	ll an=0;
	for(ll j=2;j<=sq;j++)
	{
		if(a%j==0) {an+=2;

		if(a/j==j) an--;}
	}

	return an%mod;

}

ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll m;
    cin>>m;

    ll di[m+1]={0};
    //f(2,m+1) di[i]=calc(i);
 //   f(0,m+1) cout<<di[i]<<" ";
  // cout<<endl;
    ll ans = exp(m,mod-2,mod);
    ll ans1;
    f(2,m+1)
    {
    	ll d = m/i;
    	//ll de=(m-i+1-d);
    	ll de=1;
    	//de+= (i-1-di[i]);
    	for(ll j=2;j<=m;j++)
    	{
    		if(gcd(j,i)==1) de++;
    	}
    	ans1=de;
    	ans1*=m;
    	ans1=ans1%mod;

    	ll c1=exp((m-d),mod-2,mod);
    	ll c2 = exp(m-d+1,mod-2,mod);

    	if(d!=1)
    	{
    	c1*=c1;
    	c1=c1%mod;
    	c2*=c2;
    	c2=c2%mod;
    	c1+=mod;
    	c1-=c2;
    	c1=c1%mod;
    	}
    	else
    	{
    		c1*=c1;
    		c1=c1%mod;
    		c1+=(mod-1);
    		c1=c1%mod;
    	}
    	ans1=ans1*c1;
    	ans1=ans1%mod;

    	ans+=ans1;
    	ans=ans%mod;

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