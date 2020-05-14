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
ll a,b;
bool bedi(ll x)
{
	if(x>=b && x<a) return 0;
	if(x>=2*b) return 0;
	return 1;
}
ll sb(ll x)
{
	if(x>=a && x<2*b) return 1;
	return 0;
}
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
    	
    	cin>>a>>b;
    	string s;
    	cin>>s;
    	ll co[4]={0};
    	ll le,cu=0;
    	ll l = s.size();
    	f(i,0,l)
    	{
    		if(s[i]=='.') cu++;
    		else
    		{
    			if(cu<b) co[0]++;
    			else if(cu>=b && cu<a) co[1]++;
    			else if(cu>=a && cu<2*b) co[2]++;
    			else
    			{
    				le = cu;
    				co[3]++;
    			}
    			cu=0;
    		}
    	}
    			if(cu<b) co[0]++;
    			else if(cu>=b && cu<a) co[1]++;
    			else if(cu>=a && cu<2*b) co[2]++;
    			else if(cu>=2*b)
    			{
    				le = cu;
    				co[3]++;
    			}

    	if(co[1]>0 || co[3]>=2)
    	{
    		cout<<"NO"<<endl;
    		continue;
    	}
    	ll cou = co[2];

    	if(co[3]==1)
    	{
    		ll n1 =le-a;
    		ll x,y;
    		bool don = 0;
    		f(j,0,n1+1)
    		{
    			x=j;
    			y=n1-j;
    			if(bedi(x) && bedi(y))
    			{
    				ll n2 = cou + sb(x)+sb(y);
    				if(n2 %2==0)
    				{
    					//cout<<x<<" "<<y<<endl;
    					//cou =n2;
    					don=1;
    					break;
    				}
    			}
    		}
    		if(don) cout<<"YES"<<endl;
    		else cout<<"NO"<<endl;
    		continue;
    	}

    	if(cou%2==0) cout<<"NO"<<endl;
    	else cout<<"YES"<<endl;
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
