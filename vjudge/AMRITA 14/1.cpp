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

    string s;
    cin>>s;
    ll n = s.length();
    ll q;
    cin>>q;
    
    ll m,l;

    while(q--)
    {
    	cin>>m>>l;
    	//ll mo[m]={0};

    	ll ar[m]={0};
    	ll ans = 0;
    	f(i,0,n)
    	{
    		ll br[m]={0};
    	//	f(i,0,m) cout<<br[i]<<" s ";
    		//cout<<endl;
    		//cout<<s[i]-'0'<<endl;
    		f(j,0,m) br[(j*10+(s[i]-'0'))%m]+=ar[j];
    		//f(i,0,m) ar[i]=0;
    		//f(i,0,m) ar[(i+(s[i]-'0'))%m]=br[i];
    		f(j,0,m) ar[j]=br[j];
    		ar[(s[i]-'0')%m]++;
    		//f(i,0,m) ar[i]=br[i];

    		//f(j,0,m) cout<<ar[j]<<" ";
    		//cout<<endl;
    		ans+=ar[l];
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