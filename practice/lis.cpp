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

    ll n;
    cin>>n;

    ll a[n];

    f(i,0,n)
    {
    	cin>>a[i];
    }
    
    ll val[n+1]={-mod};
    f(i,1,n+1) val[i] = mod;

    ll L[n]={0};
    ll ma = 0;
    f(i,0,n)
    {
    	ll st = 0 , en = n;
    	while(st<=en)
    	{
    		ll mi = (st+en)/2;

    		if(val[mi]>a[i])
    		{
    			en = mi -1;
    		}
    		else if(val[mi]==a[i])
    		{
    			break;
    		}
    		else 
    		{
    			st = mi+1;
    		}
    	}
    	L[i] = st;
    	val[st] = a[i];
    	ma = max(ma,st);
    }
    ll ba = mod;
    vector<ll> pr;
    for(ll i = n-1;i>=0;i--)
    {
    	if(a[i]<ba && L[i]==ma)
    	{
    		ma--;
    		ba = a[i];
    		pr.pb(a[i]);
    	}
    }

    reverse(pr.begin(),pr.end());

    ll ans = pr.size();
    cout<<ans<<endl;
    f(i,0,ans) cout<<pr[i]<<" ";
    cout<<endl;
    
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
