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

    ll n,m;
    cin>>n>>m;

    ll x1=1,y1 = 1;
    ll mu=1;
    m--;
    n--;
    while(m>0)
    {
    	//cout<<m<<endl;
    	for(ll j = n;j>=-n;j--)
    	{
    		
    		x1 = x1 + mu*j;
    		y1= y1 +mu*m;
    		mu*=-1;
    		cout<<x1<<" "<<y1<<endl;
    	}
    	mu*=-1;
    	m--;
    	//cout<<mu<<" ss"<<endl;
    	if(m)
    	{
    		x1 = x1 + mu*n;
    		y1= y1 -mu*m;
    		cout<<x1<<" "<<y1<<endl;
    	}
    	m--;
   	
    }
    
   for(ll j = n;j>0;j--)
    	{
    		
    		x1 = x1 + mu*j;
    		y1= y1 +mu*m;
    		mu*=-1;
    		cout<<x1<<" "<<y1<<endl;
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