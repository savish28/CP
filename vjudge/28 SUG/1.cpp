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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll d;
    cin>>d;
    ll a[d];
    f(i,0,d) cin>>a[i];
    ll st = 100000;
    ll m = 100;
    ll s = m/a[0];
    ll ind = 0;
    f(i,1,d-1)
    {
    	
    	//s = min(st,s);
    	if(a[i]<=a[ind])
    	{
    		s= m/a[i];
    		ind = i;
    		s = min(st,s);
    		continue;
    	}

    	if(a[i]>a[i+1])
    	{
    		m+= (a[i]-a[ind])*s;
    		s = 0;
    		ind = i+1;
    	}

    }

    if(s>0)
    {
    	m+=(a[d-1]-a[ind])*s;
    }
    
    cout<<m<<endl;
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