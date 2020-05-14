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

    ll t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	ll p,q;
    	cin>>p>>q;
    	ll co[26]={0};
    	ll l = s.length();

    	f(i,0,l) co[s[i]-'a']++;
    	f(i,0,26) co[i]*=p;
    	map<ll,char> sb;
    	ll sum = 0;
    	f(i,0,26)
    	{
    		if(co[i]>0)
    		{
    			sum+=co[i];
    			char up = 'a' + i;
    			sb[sum] = up;
    		}
    	}

    	ll x;
    	while(q--)
    	{
    		cin>>x;
    		if(x>sum)
    		{
    			cout<<-1<<endl;
    			continue;
    		}

    		char ans = sb.lower_bound(x)->ss;
    		cout<<ans<<endl;
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
