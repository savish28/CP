#include<bits/stdc++.h>
using namespace std;
#define pu push_back
#define fi first
#define se second
#define mp make_pair
#define int long long
#define sz 2000005
#define db double
signed main()
{	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

	int t;
	cin>>t;
	int ii=0;
	

	while(t>0)
	{ ii++;
		t--;
	 int n;
	 cin>>n;
	 vector<db > ss;
	 for(int i=0;i<n;i++)
	 {
	 	db a,b;
	 	char c;
	 	cin>>a>>c>>b;
	 	//cout<<a<<" "<<c<<" "<<b<<endl;
	 ss.pu((db(10000)*b)/a);
	 }
	 sort(ss.begin(),ss.end());
	 reverse(ss.begin(),ss.end());
	 int ch=1;
	
	for(int i=1;i<n;i++)
	{   // cout<<ss[i]<<endl;
		db d=10000,sum=0;
		for(int j=0;j<=i;j++)
		{
			db k=ss[j]+(db)10000;
		//	cout<<ss[j]<<endl;
			sum+=d/k;
		}
	//	cout<<i<<" h "<<sum<<endl;
		if(sum<d*(db)10000) ch=i+1;
		else break;
		
	}
//	cout<<ch<<endl;
	
	
		cout<<"Case #"<<ii<<": "<<ch<<endl;
	
	
		
	}
	
}
