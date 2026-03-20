#include<iostream>
#include<queue>
#include<vector>
#define int long long

using namespace std;

const int N=1e6+3;

string s[N];
int n,m,k;
int dx[3]={1,-1,0};
int dy[3]={0,0,1};
int dx2[4]={1,-1,0,0};
int dy2[4]={0,0,-1,1};
bool fl;

void dfs(int sy,int x,int y)
{
	if(y-sy+1>=k)fl=1;
	s[x][y]='1';
	for(int i=0;i<3;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=n||ny>=m||nx<0||ny<0)continue;
		if(s[nx][ny]=='1')continue;
		dfs(sy,nx,ny);
	}
}

void solve()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>s[i];
	
//	for(int i=0;i<n;i++){
//		for(int j=0;i<m;j++){
//			cout<<s[i][j]<<" \n"[j==m-1];
//		}
//	}
	
	vector<vector<int>>vis(n,vector<int>(m,0));
	queue<pair<int,int>>q;
	q.push({0,0});
	vis[0][0]=1;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<3;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=n||ny>=m||nx<0||ny<0)continue;
			if(s[nx][ny]=='1'||vis[nx][ny])continue;
			vis[nx][ny]++;
			q.push({nx,ny});
		}
	}
	
	q.push({0,m-1});
	vis[0][m-1]=3;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<3;i++)
		{
			int nx=x+dx[i],ny=y-dy[i];
			if(nx>=n||ny>=m||nx<0||ny<0)continue;
			if(s[nx][ny]=='1'||vis[nx][ny]==3||vis[nx][ny]==2)continue;
			vis[nx][ny]+=2;
			q.push({nx,ny});
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vis[i][j]==1) s[i][j]='0';
			else s[i][j]='1';
		}
	}
	
//	cout<<"\n";
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<s[i][j]<<" \n"[j==m-1];
//		}
//	}
	
	fl=0;
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i][j]=='0')
			{
				dfs(j,i,j);
				if(fl)
				{
					cout<<"YES"<<"\n";
//					cout<<n<<" "<<m<<" "<<k<<"\n";
					return;
				}
			}
		}
	}
	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<s[i][j];
//		}
//		cout<<"\n";
//	}
	
	cout<<"NO"<<"\n";
//	cout<<n<<" "<<m<<" "<<k<<"\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while (t--){
//		cout<<t<<" ";
		solve();
	}
	
	return 0;
}
