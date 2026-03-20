#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100010;

struct node{
	int num,cnt;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		vector<int> v(n,0);
		for(auto &x:v){
			cin>>x;
		}
		sort(v.begin(),v.end(),[&](int x,int y){return x<y;});
		
		vector<node> a;
		int cnt=1;
		for(int i=1;i<n;i++){
			if(v[i]==v[i-1]){
				cnt++;
			}else{
				a.push_back((node){v[i-1],cnt});
				cnt=1;
			}
		}
		a.push_back((node){v[n-1],cnt});
		
		int flag=0;
		int lim=a.size();
		int st=0;
		for(int i=0;i<lim;i++){
			if(a[i].cnt>=4){
				flag=1;
				break;
			}
			if(!i&&a[i].cnt>=2){
				st++;
			}
			if(i&&a[i].num==a[i-1].num+1){
				if(a[i].cnt>=2){
					st++;
				}
				if(st==2){
					flag=1;
					break;
				}
			}else if(i&&a[i].num!=a[i-1].num+1&&a[i].cnt>=2){
				st=1;
			}else if(i&&a[i].num!=a[i-1].num+1&&a[i].cnt<2){
				st=0;
			}
		}
		
		if(flag) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
	
	return 0;
}
