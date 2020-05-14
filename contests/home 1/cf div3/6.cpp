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

map< ll , vector< pair<ll,ll> > > sb;
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

 	ll n;
 	cin>>n;
 	ll a[n+1]={0};
 	f(1,n+1) cin>>a[i];


 	ll su=0;
 	f(1,n+1)
 	{
 		su=0;
 		for(ll j=i;j<=n;j++)
 		{
 			su+=a[j];
 		//	cout<<su<<" "<<i<<" "<<j<<endl;
 			sb[su].pb(mp(j,i));

 		}
 	}

 	ll ans=0;
 	ll ind=0;
 	map<ll, vector< pair<ll,ll> > > :: iterator ap;
 	for(ap=sb.begin();ap!=sb.end();ap++)
 	{
 		vector< pair<ll,ll> > bt = ap->ss;

 		ll ans1=0;
 		sort(bt.begin(),bt.end());
 		ll en=0;
 		//cout<<"ind = "<<ap->ff<<endl;
 		f(0,bt.size())
 		{
 			//cout<<"hello "<<bt[i].ff<<" "<<bt[i].ss<<endl;
 			if(bt[i].ss>en)
 			{
 				en=bt[i].ff;
 				ans1++;
 			}
 		}

 		if(ans<ans1)
 		{
 			ind=ap->ff;
 			ans=ans1;
 		}
 	}

 	cout<<ans<<endl;
 //	cout<<ind<<endl;

 	vector< pair<ll,ll> > kt = sb[ind];
 	sort(kt.begin(),kt.end());
 	ll end=0;
 	f(0,kt.size())
 	{
 		if(kt[i].ss>end)
 		{
 			end=kt[i].ff;
 			cout<<kt[i].ss<<" "<<kt[i].ff<<endl;
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