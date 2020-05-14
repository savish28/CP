#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 10000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

ll solve(ll a, ll b)
{
	ll ans = 0;

	while(a>0)
	{
		ans+=a/b;
		a/=b;
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

    
  
   int n = 1000000;
vector<char> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
vector<ll> pr;
f(2,n+1) if(is_prime[i]) pr.pb(i);

ll sz = pr.size();
	while(cin>>n)
	{
		if(n==0) break;

		ll ans = 1;
		
		for(ll i = 0;i<sz;i++)
		{
			if(pr[i]>n) break;
			ll co = solve(n,pr[i]);
			
			if(co)
			{
				ans*=(((co+2)*(co+1))/2)%mod;
				ans = ans%mod;
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
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