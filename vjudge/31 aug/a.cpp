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
    	ll n;
    	cin>>n;
    	ll a[n+1]={0};
    	a[1]=0;
    	f(i,2,n+1) cin>>a[i];
    	f(i,1,n+1) a[i]+=a[i-1];
    	//f(i,1,n+1) cout<<a[i]<<" ";
    	//cout<<endl;
    	ll psum[n+1]={0};
    	psum[0]=0;
    	psum[1]=0;

    	f(i,2,n+1)
    	{
    		if(i%2==1) psum[i] = psum[i-1];
    		else psum[i] = psum[i-1] + a[i/2];
    	}
    	ll b[n+1]={0};
    	f(i,1,n+1) b[i] = a[n-i+1];
    	//f(i,1,n+1) cout<<b[i]<<" ";
    	//cout<<endl;
    	ll ssum[n+1]={0};
    	ssum[0]=0;
    	ssum[1]=0;

    	f(i,2,n+1)
    	{
    		if(i%2==1) ssum[i] = ssum[i-1];
    		else ssum[i] = ssum[i-1] + b[i/2];
    	}
    	//f(i,1,n+1) cout<<psum[i]<<" "<<ssum[i]<<endl;

    	f(i,1,n+1)
    	{
    		psum[i]+=psum[i-1];
    		ssum[i]+=ssum[i-1];
    		// cout<<psum[i]<<" sss "<<ssum[i]<<endl;
    		 //continue;
    		if(i!=n) cout<<ssum[i]-psum[i]<<" ";
    		else cout<<ssum[i]-psum[i]<<endl;
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