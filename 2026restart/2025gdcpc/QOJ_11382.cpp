#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl "\n"
using namespace std;

//#define int long long
// using ll=long long;
// using ull=unsigned long long;
// using i128=__int128;

// const int inf=0x3f3f3f3f;
// const ll MOD=998244353;
// const ll inv2=(MOD+1)/2;
// const ll P=1e9+7;
// const ull H=1e9+7;
// const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
// const int N=100010;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ull rnd(ull l=0ull,ull r=-1ull){return uniform_int_distribution<ull>(l,r)(rng);}

int obj[100005],cnt[100005],ans[100005];

struct point
{
	int to,w;
};

vector<point>v[100005];
int minntime[100005];
bool vis[100005];

void solve(){
	int n,m,k,cur=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq,getnum;
	cin>>n>>m>>k;
	for (int i=0;i<=n+1;i++)
		minntime[i]=INF,ans[i]=-1;
	for (int i=1;i<=n;i++)
		cin>>obj[i];
	for (int i=1;i<=k;i++)
	{
		int time,num,x;
		cin>>time>>num;
		while (num--)
		{
			cin>>x;
			minntime[x]=min(minntime[x],time);
		}
	}
	for (int i=1;i<=m;i++)
	{
		int from,to,w;
		cin>>from>>to>>w;
		v[from].push_back({to,w});
	}
	for (int i=1;i<=n;i++)
	{
		if (minntime[i]==INF)
			continue;
		getnum.push({minntime[i],i});
	}
	for (int i=1;i<=n;i++)
	{
		if (obj[i]!=0)
			continue;
		for (int j=0;j<v[i].size();j++)
		{
			pq.push({v[i][j].w,v[i][j].to});
		}
		ans[i]=0;
	}
	// cout<<getnum.size();
	while (!pq.empty()||!getnum.empty())
	{
		while (!getnum.empty())
		{
			pair<int,int>curpair = getnum.top();
			// getnum.pop();
			int time=curpair.first,num=curpair.second;
			if (pq.empty()||!pq.empty()&&time<=pq.top().first)
			{
				
				// cout<<"getnum time: "<<time<<" num: "<<num<<endl;
				
				for (int j=0;j<v[num].size()&&!vis[num];j++)
				{
					pq.push({time+v[num][j].w,v[num][j].to});
				}		
				vis[num]=true;
				ans[num]=time;
				getnum.pop();
			}
			else
			{
				break;
			}
		}
		if (pq.empty())
			continue;
		pair<int,int>curpair = pq.top();
		pq.pop();
		int time=curpair.first,num=curpair.second;

		// cout<<"time: "<<time<<" num: "<<num<<endl;

		cur=time;
		cnt[num]++;
		if (cnt[num]==obj[num]&&ans[num]==-1)
		{
			for (int j=0;j<v[num].size()&&!vis[num];j++)
			{
				pq.push({time+v[num][j].w,v[num][j].to});
			}		
			vis[num]=true;
			ans[num]=time;
		}
	}
	for (int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
	// cin>>T;
	
	while(T--){
		solve();
	}
	
	return 0;
}
