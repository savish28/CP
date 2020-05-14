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
    	string p,h;
    	cin>>p>>h;
    	sort(p.begin(),p.end());

    	ll sz = p.length();
    	ll sh = h.length();
    	bool ans = 0;
    	for(ll i = 0; i + sz <= sh;i++)
    	{
    		string ch = h.substr(i,sz);

    		sort(ch.begin(),ch.end());

    		//cout<<p<<" "<<ch<<endl;
    		if(p==ch)
    		{
    			ans = 1;
    			break;
    		}
    	}

    	if(ans)
    	{
    		cout<<"YES"<<endl;
    	}
    	else cout<<"NO"<<endl;
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
