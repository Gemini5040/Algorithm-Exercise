#include <bits/stdc++.h>
using namespace std;

int a[110][30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	string s;
	cin>>s;
	
	int r=0,c=0;
	int val=0;
	int ans=0;
	for(auto i=s.begin();i<s.end();i++){
		if((*i)>='A'&&(*i)<='Z'){
			c=(*i)-'A'+1;
		}else if(isdigit((*i))){
			val=(val*10)+(*i)-'0';
		}else{
			r=val;
			val=0;
			ans+=a[r][c];
//			cout<<"a"<<r<<c<<":"<<a[r][c]<<"---"<<" ";
		}
		if(i==s.end()-1){
			r=val;
			val=0;
			ans+=a[r][c];
//			cout<<"a"<<r<<c<<":"<<a[r][c]<<"---"<<" ";
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}