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
		int n,q;
		cin>>n>>q;
		while(q--){
			string op;
			cin>>op;
			if(op=="->"){
				ll a,b;
				cin>>a>>b;
				int w=n;
				ll ans=1;
				while(w>=1){
					if((a>=1&&a<=(1LL<<(w-1)))&&(b>=1&&b<=(1LL<<(w-1)))){
						ans+=0;
					}else if((a>(1LL<<(w-1))&&a<=(1LL<<w))&&(b>(1LL<<(w-1))&&b<=(1LL<<w))){
						ans+=(1LL<<(2*w-2));
						a=a-(1LL<<(w-1));
						b=b-(1LL<<(w-1));
					}else if((a>(1LL<<(w-1))&&a<=(1LL<<w))&&(b>=1&&b<=(1LL<<(w-1)))){
						ans+=(1LL<<(2*w-1));
						a=a-(1LL<<(w-1));
					}else if((a>=1&&a<=(1LL<<(w-1)))&&(b>(1LL<<(w-1))&&b<=(1LL<<w))){
						ans+=(1LL<<(2*w-2))*3LL;
						b=b-(1LL<<(w-1));
					}
					w--;
				}
				cout<<ans<<"\n";
			}else if(op=="<-"){
				ll a;
				cin>>a;
				int x=1,y=1;
				int w=n;
				while(w>=1){
					if(a>=1&&a<=(1LL<<(2*w-2))){
						x+=0;
						y+=0;
						a-=0;
					}else if((a>(1LL<<(2*w-2)))&&(a<=(1LL<<(2*w-1)))){
						x+=(1LL<<(w-1));
						y+=(1LL<<(w-1));
						a-=(1LL<<(2*w-2));
					}else if((a>(1LL<<(2*w-1)))&&(a<=(1LL<<(2*w-2))*3)){
						x+=(1LL<<(w-1));
						y+=0;
						a-=(1LL<<(2*w-1));
					}else if((a>(1LL<<(2*w-2))*3)&&(a<=(1LL<<(2*w)))){
						x+=0;
						y+=(1LL<<(w-1));
						a-=(1LL<<(2*w-2))*3LL;
					}
					w--;
				}
				cout<<x<<" "<<y<<"\n";
			}
		}
	}
	
	return 0;
}
