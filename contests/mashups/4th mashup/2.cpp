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

    ll k;
    cin>>k;
    string s;
    cin>>s;

    ll a[26]={0};
    ll l=s.length();
    ll co=0;
    ll pr[l]={0};
    f(0,l)
    {

    	if(a[s[i]-'a'+0]==0)
    	{
    		co++;
    		pr[i]=1;
    		a[s[i]-'a'+0]++;
    	}

    	if(co==k) break;
    }

    if(co<k) cout<<"NO"<<endl;
    else
    {
    	cout<<"YES"<<endl;

    	f(0,l)
    	{
    		cout<<s[i];
    		if(pr[i+1]==1) cout<<endl;
    	}
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