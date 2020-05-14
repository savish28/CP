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

    ll n;
    ll time[2][2];
   		time[0][0]=12;
   		time[0][1]=30;
   		time[1][0]=9;
   		time[1][1]=30;

   	ll lim[2]={9,8};
   	while(cin>>n)
   	{
   		if(n==0) break;
   		
   		
   		//ll h1,m1,s1,h2,m2,s2;
   		
   		ll ans = 0;
   		while(n--)
   		{
   			bool day = 0;
   			bool galat = 0;
   			string s;
   			cin>>s;
   			ll l = s.length();
   			vector<ll> sb;
   			ll te = 1;
   			ll ac = 0;
   			for(ll i = l-1;i>=1;i--)
   			{
   				if(s[i]==':')
   				{
   					sb.pb(ac);
   					te = 1;
   					ac = 0;
   					
   				}
   				else
   				{
   					ac += (s[i]-'0'+0)*te;
   					te*=10;
   				}
   			}	
   			if(s[0]=='D') day = 1;

   			//f(0,6) cout<<sb[i]<<" ";
   			//cout<<endl;
   			//cout<<time[day][0]<<endl;
   			if(sb[5]>time[day][0] || (sb[5]==time[day][0] && sb[4]>time[day][1]) || (sb[5]==time[day][0] && sb[4]==time[day][1] && sb[3]>0)) galat = 1;
   			if(galat)
   			{
   				ans++;
   				continue;
   			}
   			//cout<<"galat = "<<galat<<endl;
   			if(sb[5]<8 || sb[5]==8 && sb[4]<30) sb[5] = 8,sb[4]=30,sb[3]=0;

   			ll s1 = sb[3]+60*sb[4]+60*60*sb[5];
   			ll s2 = sb[0]+60*sb[1]+60*60*sb[2];

   			ll ts = s2-s1;

   			ts = ts/3600;

   			if(ts<lim[day]) galat = 1;

   			if(galat) ans++;
   			//cout<<"galat2 = "<<galat<<endl;
   		}
   		if(ans==0)
   		{
   			cout<<"All OK"<<endl;
   		}
   		else if(ans>3)
   		{
   			cout<<"Issue Show Cause Letter"<<endl;
   		}
   		else 
   		{
   			cout<<ans<<" Point(s) Deducted"<<endl;
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