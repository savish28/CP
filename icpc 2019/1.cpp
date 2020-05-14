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
    	string s;
    	cin>>s;

    	ll l = s.length();
    	ll ind = l-1;
    	f(i,0,l-1)
    	{
    		ll c1 = s[i]-'0';
    		ll c2 = s[i+1]-'0';

    		if(c1>c2)
    		{
    			ind = i;
    			break;
    		}
    	}

    	string pr = "";
    	f(i,0,l)
    	{
    		if(i!=ind)
    		{
    			pr+=s[i];
    		}
    	}
    	ll st = 0;
    	f(i,0,l-1)
    	{
    		if(pr[i]=='0') st++;
    		else break;
    	}
    	ll pl = pr.size();
    	f(i,st,pl)
    	{
    		cout<<pr[i];
    	}
    	cout<<endl;
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
