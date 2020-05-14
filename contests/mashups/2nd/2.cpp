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

    ll n,m;
    cin>>n>>m;
    ll a[n];
    f(0,n) cin>>a[i];
    ll b[m+1]={0};
    f(1,m+1) cin>>b[i];
    
    ll st = 0,en=n-1;
    ll mi;


    while(st<=en)
    {
    	//cout<<"st = "<<st<<" "<<en<<endl;
    	mi=(st+en)/2;
    	//cout<<"mi= "<<mi<<endl;
    	//
    	bool sb[m+1]={0};
    	bool ch=1;

    	ll co=0;
    	
    	ll to = mi+1; ll cut = 0;
    	for(ll j=mi;j>=0;j--)
    	{
    		if(cut>0 && (a[j]==0 || sb[a[j]]==1 )) cut--;
    		else to--;
    		
    		
    		if(a[j]==0) 
    			{
    				continue;
    			}
   

    		if(sb[a[j]]==1) continue;

    		if(to-(m-co-1)>=b[a[j]]) 
    			{
    				to-=b[a[j]];
    				cut+=b[a[j]];

    			}
    		else 
    		{
    			ch=0;
    			break;
    		}

    		co++;
    		sb[a[j]]=1;
    		if(co==m) break;
    	}


    	if(co!=m) ch=0;

    	if(ch==0) st=mi+1;
    	else 
    		{
    			
    			if(en==mi) break;
    			en=mi;
    		}

    	
    }

 	if(st==n) cout<<-1<<endl;
 	else cout<<st+1<<endl;
    
    
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