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
        ll a[n];
        f(0,n) cin>>a[i];

        sort(a,a+n);

        ll ans=0;
        f(0,n) ans+=a[i];
        ll ans1=ans;

        for(int i=n-1;i>0;i--)
        {

        	for(int j=2;j<=sqrt(a[i]);j++)
        	{
        		if(a[i]%j==0)
        		{
        			ans=min(ans,ans1-a[0]-a[i]+a[0]*j+a[i]/j);
//cout<<a[i]<<" "<<j<<" "<<ans<<endl;
        			ans=min(ans,ans1-a[0]-a[i]+a[0]*(a[i]/j)+j);
        			//cout<<a[i]<<" "<<j<<" "<<ans<<endl;
        		}
        	}
        //	cout<<ans<<endl;
        }

        cout<<ans<<endl;
        
    
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