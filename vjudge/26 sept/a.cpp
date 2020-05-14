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

    ll t;
    cin>>t;
    while(t--)
    {
    	ll n,m;
    	cin>>n>>m;
    	ll a[n+1]={-1};
    	ll ind = 0;
    	bool right = 0;
    	f(i,1,n+1) 
    	{
    		cin>>a[i];
    		if(a[i]==2 || a[i]==3) ind = i;
    		if(a[i]==2) right = 1; 
    	}
    	ll b[n+1]={-1};
    	f(i,1,n+1)
    	{
    		if(right)
    		{
    			b[i] = a[i];
    		}
    		else b[i]=a[n-i+1];
    	}
    	if(right==0) ind = n-ind +1;

    	ll pre[n+2]={0};
    	pre[0]=0;
    	f(i,1,n+1) pre[i] = pre[i-1] + (b[i]==0);

    	if(ind == 0 )
    	{
    		cout<<0<<endl;
    		continue;
    	}
    	ll ans = 0;
    	ll bd = (a[n]==0) + (a[1]==0) + 2*(pre[n-1]-pre[ind] + pre[ind]-pre[1]);
    	ans += (m/(2*n-2)) * bd;

    	m -= (m/(2*n-2))*(2*n-2);
    	//cout<<"ans1 = "<<ans<<endl;
    	if(m>=(n-ind))
    	{
    		m-=(n-ind);
    		ans += pre[n]-pre[ind];
    	}
    	else if(m>0)
    	{
    		ans+= pre[ind+m]-pre[ind];
    		m = 0;
    	}

    	//cout<<m<<" "<<ans<<endl;
    	if(m>=(n-1))
    	{
    		m-=(n-1);
    		ans += pre[n-1];
    	}
    	else if(m>0)
    	{
    		ans+= -pre[n-m-1]+pre[n-1];
    		m = 0;
    	}

    	if(m>0)
    	{
    		ans+= pre[1+m]-pre[1];
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