#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		string s;
		cin>>n>>s;
		
		vector<int> a,b;
		int card=1;
		for(auto ss:s){
			if(ss=='A') a.push_back(card);
			else if(ss=='B') b.push_back(card);
			card++;
		}
		
		int sa=a.size(),sb=b.size();
		if(sa>=2&&sb>=2){
			if(a[0]==1&&a[sa-1]==n){
				cout<<"Alice"<<"\n";
			}else if(a[0]==1&&b[sb-1]==n){
				cout<<"Bob"<<"\n";
			}else if(b[0]==1&&b[sb-1]==n){
				cout<<"Bob"<<"\n";
			}else if(b[0]==1&&a[sa-1]==n){
				int ma=a[sa-2],mb=b[sb-1];
				if(ma>mb){
					cout<<"Alice"<<"\n";
				}else if(ma<mb){
					cout<<"Bob"<<"\n";
				}
			}
		}else if(sa==1&&sb==1){
			if(a[0]==1) cout<<"Alice"<<"\n";
			else if(b[0]==1) cout<<"Bob"<<"\n";
		}else if(sa==1&&sb>1){
			cout<<"Bob"<<"\n";
		}else if(sa>1&&sb==1){
			cout<<"Alice"<<"\n";
		}
	}
	
	return 0;
}
