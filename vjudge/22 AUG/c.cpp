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

    	n=n*2;

    	int sq = sqrt(n);
    	
        bool ans = 0;
    	for(int i = 2;i<=sq;i++)
    	{
    		if(n%i==0)
    		{
    			
    			
    		ll a1 = -1 + (n-i*i)/i;
            if(a1>=0 && a1%2==0) 
                {
                    ll a = a1/2, k = i; 
                     cout<<n/2<<" = ";
                    f(j,0,k)
                    {   if(j==k-1) cout<<a+j+1;
                        else cout<<a+j+1<<" + ";
                    }
                    cout<<endl;
                    ans = 1;
                    break;
                }
    		}
    	}

        if(ans) continue;
     cout<<"IMPOSSIBLE"<<endl;
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