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

	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	set<string> sb[n+1];

	f(0,n)
	{
		string s1 = "";
		for(ll j=i;j<n;j++)
		{
			s1+=s[j];
			sb[s1.size()].insert(s1);
		}
	}

	ll ans=0;
	ll ans1;
	ll co = k;
	for(ll j=n;j>0;j--)
	{

		ans1 = n-j;
		ll sz = sb[j].size();
		for(auto p:sb[j]) cout<<p<<" ";
			cout<<endl;
		if(co>=sz)
		{
			ans+=ans1*sz;
			co-=sz;
		}
		else if(co)
		{
			ans += co*ans1;
			co=0;
		}
		else break;

		cout<<j<<" "<<co<<sz<<endl;
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