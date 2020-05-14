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
string mon[12] ={"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
ll day[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    f(tt,1,t+1)
    {
    	
    	cout<<"Case "<<tt<<": ";
    	string s;
    	cin>>s;

    	ll ye = (s[7]-'0')*1000 + (s[8]-'0')*100 + (s[9]-'0')*10 + (s[10]-'0')*1;

    	string mu = "";
    	mu+=s[3];
    	mu+=s[4];
    	mu+=s[5];

    	ll le = 0;
    	ll mo = 0;
    	f(i,0,12)
    	{
    		if(mon[i]==mu)
    		{
    			mo = i;
    			break;
    		}
    	}

    	if(ye%400==0 || (ye%4==0 && ye%100!=0))
    	{
    		le = 1;
    	}

    	ll da = (s[0]-'0')*10 + s[1]-'0';

    	f(i,0,mo)
    	{
    		da+=day[le][i];
    	}

    	if(da<=300)
    	{
    		cout<<da<<" Hundreds"<<endl;
    	}
    	else if(da<=360)
    	{
    		cout<<da-300<<" Tens"<<endl;
    	}
    	else
    	{
    		cout<<da-360<<" Ones"<<endl;
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
