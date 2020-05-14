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
    ll a[n],b[n];
    f(i,0,n)
    {
    	cin>>a[i];
    }
    f(i,0,n)
    {
    	cin>>b[i];
    }
    
    vector< ll > msm;
    f(i,0,n) msm.pb(a[i]);

    sort(msm.begin(),msm.end());

    vector<ll> ch;
    if(msm.size()>1 && msm[0]==msm[1]) ch.pb(msm[0]);

    f(i,1,n-1)
    {
    	if(msm[i]!=msm[i-1] && msm[i]==msm[i+1]) ch.pb(msm[i]);
    }

    bool anss[n+1]={0};
    ll ans = 0;
    ll sz = ch.size();
   // cout<<sz<<endl;
    f(i,0,n)
    {
    	f(j,0,sz)
    	{
    		if((a[i]|ch[j])<=ch[j])
    		{
    			anss[i]=1;
    			break;
    		}
    	}
    }
   
    f(i,0,n)
    {
    	if(anss[i]==1) ans+=b[i];
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
