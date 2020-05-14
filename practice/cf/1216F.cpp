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

    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll co[n+2]={0};
    ll on = 1;
   	f(i,0,n)
   	{
   		if(s[i]=='1')
   		{
   			ll mi = max(on,i+1-k);
   			ll ma = min(n,i+1+k);
   			co[mi]++;
   			co[ma+1]--;
   		}
   	}
   
   	f(i,1,n+2)
   	{
   		co[i]+=co[i-1];
   		//cout<<co[i]<<" ";
   	}
  // 	cout<<endl;
   	ll age[n+2]={0};
   	age[n+1]=n+1;
   	for(ll i = n;i>=1;i--)
   	{
   		if(s[i-1]=='1') age[i]=i;
   		else age[i]=age[i+1];
   	}

   //	f(i,1,n+1) cout<<age[i]<<" ";
   //	cout<<endl;
   //	f(i,1,n+1) cout<<co[i]<<" ";
   //	cout<<endl;
   	ll ans = 0;
   	vector<pair<ll,ll> > sb;
   	ll st = 0;
   	f(i,1,n+1)
   	{
   		if(co[i]==0) ans+=i;
   		else if(co[i+1]>0 && co[i-1]==0) st=i;
   		else if(co[i+1]==0)
   		{
   			sb.pb(mp(st,i));
   		}
   	}

   //	cout<<"ss"<<endl;
  
    ll sz = sb.size();
    //cout<<sz<<endl;
   // return 0;
    f(i,0,sz)
    {
    
    	ll l = sb[i].ff,r=sb[i].ss;
    	//cout<<l<<" "<<r<<endl;
    	//break;
    	ll ch;
    	bool ok = 1;
    	while(ok)
    	{
    		ll pop = -(l*(l-1))/2+(r*(r+1))/2;
    		r-=k;
    		if(r<=l) r=l;
    		ch = age[r];
    		
    		if(pop<=ch)
    		{
    			ans+=pop;
    			break;
    		}
    		//cout<<"ch = "<<ch<<endl;
    		ans += ch;
    		if(ch-k<=l) break;
    		r = ch-k-1;
    	}


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
