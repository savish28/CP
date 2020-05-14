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
string s;
bool isp(ll l, ll r)
{
	ll le=l+r;
	for(int i=l;i<=r;i++)
	{
		if(s[i]!=s[le-i]) return 0;
	}

	return 1;
}
ll ans=0;

void solve(ll l, ll r)
{
	ll szz=r-l+1;
	if(szz%2==0){ ans++; return;}
	ll sz=(r-l+1)/2;

	ll ls = l+sz-1;
	ll rs= r-sz+1;

	if(isp(l,ls))
	{
		solve(l,ls);
	}
	
	ans+=2;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

        cin>>s;
        ll l=s.length();
        	char ch=s[0];
        	ll co=1;
        f(1,l) 
        {
        	if(s[i]==ch) co++;
        }
        if(l%2==1 && co==l-1)
        {
        	cout<<"Impossible"<<endl;
        	return 0;
        }
        if(co==l || l==1) 
        {
        	cout<<"Impossible"<<endl;
        	return 0;
        }
       

        ll sz=(l)/2;

    	if(l%2==0) ans=1;
    	else 
    	{
    		ans=2;
    		if(isp(0,(l+sz-1))==0) ans+=0;
    		else if((l/2)%2==1) ans+=2;
    		else ans++;
    	}


        if(ans<=l-1) cout<<ans<<endl;
        else cout<<"Impossible"<<endl;
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