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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

 	ll n;
 	cin>>n;
 	string s,s1;
 	cin>>s>>s1;

 	vector<ll> a[27],b[27];

 	f(0,n)
 	{
 		if(s[i]=='?') a[26].pb(i);
 		else a[s[i]-'a'].pb(i);

 		if(s1[i]=='?') b[26].pb(i);
 		else b[s1[i]-'a'].pb(i);
 	}
    
    vector<pair<ll,ll> >  pr;

    f(0,26)
    {
    	ll co=min(a[i].size(),b[i].size());

    	while(co--)
    	{
    		ll f1=a[i].back(),f2=b[i].back();
    		a[i].pop_back();
    		b[i].pop_back();
    		pr.pb(mp(f1,f2));
    	}
    }

    ll ans=a[26].size();

    f(0,27)
    {
    	ll co=b[i].size();
    	while(ans>=1 && co>=1)
    	{
    		ans--;
    		co--;


    		ll f1=a[26].back(),f2=b[i].back();
    		a[26].pop_back();
    		b[i].pop_back();
    		pr.pb(mp(f1,f2));
    	}
    }

    ans=b[26].size();

    f(0,27)
    {
    	ll co=a[i].size();
    	while(ans>=1 && co>=1)
    	{
    		ans--;
    		co--;


    		ll f1=a[i].back(),f2=b[26].back();
    		a[i].pop_back();
    		b[26].pop_back();
    		pr.pb(mp(f1,f2));
    	}
    }

    cout<<pr.size()<<endl;
   
    f(0,pr.size())
    {
    	cout<<pr[i].ff + 1 <<" "<<pr[i].ss +1 <<endl;
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