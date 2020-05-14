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

    ll a[n-1];
    f(0,n-1) cin>>a[i];

    ll b[n-1]={0};
    b[0]=a[0];

    f(1,n-1) b[i]=a[i]+b[i-1];

    ll s=0;
    f(0,n-1) s+=b[i];

    ll ans=(n*(n+1))/2 -s;

    bool ok=1;
    vector<ll> pr;
    bool ch[n+1]={0};
    if(ans>0 && ans%n==0 && ans/n<=n)
    {
    	ll pe=ans/n;
    	ch[pe]=1;
    	pr.pb(pe);
    	f(0,n-1)
    	{
    		if(ok==0) break;
    		if(pe+a[i]>=1 && pe+a[i]<=n)
    		{
    			if(ch[pe+a[i]]==0)
    			{
    				pe+=a[i];
    				pr.pb(pe);
    				ch[pe]=1;
    			}
    			else ok=0;
    		}
    		else ok=0;
    	}

    }
    else ok=0;


    if(pr.size()!=n) ok=0;
    if(ok==0)
    {
    	cout<<-1<<endl;
    	return 0;
    }

    f(0,pr.size())
    {
    	cout<<pr[i]<<" ";
    }

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