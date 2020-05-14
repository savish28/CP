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

ll solve(ll a)
{
	ll ans = a;

	if(a%2==0)
	{
		ans/=2;

		while(a%2==0) a/=2;
	}

	for(ll j = 3; j<=sqrt(a);j+=2)
	{
		if(a%j==0)
		{
			ans *= (j-1);
			ans/=j;
			while(a%j==0) a/=j;
		}
	}

	if(a>1)
	{
		ans *= (a-1);
		ans/=a;
	}

	return ans;
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

   	ll n,m;
   	cin>>n>>m;

   	if(m==1)
   	{
   		cout<<0<<endl;
   		return 0;
   	}
   	
   	if(n==1)
   	{
   		cout<<1<<endl;
   		return 0;
   	}
   	
   	//cout<<solve(n)<<endl;
   	vector<ll> phi;
   	phi.pb(m);


   	while(phi.back()>1)
   	{
   		//cout<<phi.back()<<endl;
   		phi.pb(solve(phi.back()));
   	}

   //f(i,0,phi.size()) cout<<phi[i]<<" ";
  // cout<<endl;
   	ll le = phi.size();
   	ll sz = min(le-1,n-1);

   	ll po = n-sz;
    ll p = 1;

    //cout<<po<<endl;
   // return 0;
    for(ll j = po;j<=n;j++)
    {
    	if(j<5)
    	{
    		p = pow(j,p);
    		continue;
    	}
    	else if(j==5) 
    	{
    		p = exp(j%phi[n-j],p,phi[n-j]);
    		continue;
    	}
    	p = exp(j%phi[n-j],p,phi[n-j]) + phi[n-j];
    	//cout<<p<<endl;
    }

    cout<<(p)%m<<endl;
return 0;
}

ll exp(ll a,ll b,ll m)
{
	if(a==0) return 0;
	a = a%m;
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