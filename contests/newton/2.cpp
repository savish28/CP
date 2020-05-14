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

    string s1,s2;
    cin>>s1>>s2;
    ll x;
    cin>>x;

    ll n = s1.length();
    ll sa =0 , di = 0;
    f(i,0,n)
    {
    	if(s1[i]==s2[i]) sa++;
    	else di++;
    }

    if(x<di)
    {
    	cout<<0<<endl;
    	return 0;
    }

    x-=di;

    ll ans = 0;

    ans+= exp(2,di,mod);

    if(x==0)
    {
    	cout<<ans<<endl;
    	return 0;
    }

   
    ll up[sa+1]={1};
    ll upd[di+1]={1};
    f(i,1,sa+1)
    {
    	up[i] = up[i-1];

    	up[i] = up[i]*(sa-i+1);
    	up[i] = up[i]*mod;
    	up[i] = up[i]*exp(i,mod-2,mod);
    	up[i] = up[i]%mod;
    }

     f(i,1,di+1)
    {
    	upd[i] = upd[i-1];

    	upd[i] = upd[i]*(di-i+1);
    	upd[i] = upd[i]*mod;
    	upd[i] = upd[i]*exp(i,mod-2,mod);
    	upd[i] = upd[i]%mod;
    }
    ll ha = x/2;
    ha = min(ha,sa);

    ll p1[x+1]={0} , p2[x+1]={0};
    p1[0] = 1;
    p2[0] = ans;
    ans = 0;
    f(i,1,x+1)
    {
    	if(i<=sa) {p1[i] = p1[i-1] + up[i]*exp(25,i,mod);
    	p1[i] = p1[i]%mod;}
    	
    	if(i<=di){ p2[i] = p2[i-1];
    	p2[i] += (exp(2,di-i,mod)*(upd[i]*exp(24,i,mod))%mod)%mod;
    	p2[i] = p2[i]%mod;}
    }
    f(i,0,ha+1)
    {
    	ll ans1 = up[i]*exp(25,i,mod);
    	ll kit = min(di,x-2*i);
    	ll ans2 = upd[kit]*exp(24,kit,mod);

    	ans2*=exp(2,di-kit,mod);

    	ans2 = ans2%mod;
    	ans1 = ans1%mod;

    	ans += (ans1*p2[kit])%mod;
    	ans = ans%mod;
    	ans += (p1[i]*ans2)%mod;
    	ans = ans%mod;
    	ans+=mod;
    	ans-= (ans1*ans2)%mod;
    	ans = ans%mod;
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
