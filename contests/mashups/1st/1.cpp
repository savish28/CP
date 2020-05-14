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

    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll l=1;
    ll tw=0;
    ll th=0;
    ll co=0;
    f(1,n)
    {
    	if(s[i]==s[i-1]) l++;
    	else
    	{
    		if(l>=3) th++;
    		else if(l==2) tw++;
    		l=1;
    		co++;
    	}
    }
    //cout<<l<<" "<<th<<" "<<tw<<endl;
    if(l>=3) th++;
    else if(l==2) tw++;
    co++;

    if(th>0 || tw>=2 ) cout<<co+2<<endl;
    else if(tw==1)  cout<<co+1;
    else cout<<co<<endl;
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