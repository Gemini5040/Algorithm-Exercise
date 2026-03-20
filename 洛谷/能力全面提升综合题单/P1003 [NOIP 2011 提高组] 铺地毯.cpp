#include <bits/stdc++.h>
using namespace std;

const int N=10010;
struct node{
	int x1,x2,y1,y2;
};
vector<node> v(N);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int a,b,g,k;
		cin>>a>>b>>g>>k;
		v[i]=(node){a,a+g-1,b,b+k-1};
	}
	
	int x,y;
	cin>>x>>y;
	
	int ans=-1;
	for(int i=n-1;i>=0;i--){
		int x1=v[i].x1,x2=v[i].x2,y1=v[i].y1,y2=v[i].y2;
		if(x>=x1&&x<=x2&&y>=y1&&y<=y2){
			ans=i+1;
			break;
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
