#include <bits/stdc++.h>
using namespace std;

bool isConnected(int n,vector<vector<int>>& adj){
	if(n==0)return true;
	vector<bool> visited(n,false);
	queue<int> q;
	
	q.push(0);
	visited[0]=true;
	
	while(!q.empty()){
		int current=q.front();
		q.pop();
		for(int neighbor:adj[current]){
			if(!visited[neighbor]){
				visited[neighbor]=true;
				q.push(neighbor);
			}
		}
	}
	
	for(bool v:visited){
		if(!v) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> adj(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if(isConnected(n,adj)){
		cout<<"Yes"<<"\n";
	}else{
		cout<<"No"<<"\n";
	}
	
	return 0;
}