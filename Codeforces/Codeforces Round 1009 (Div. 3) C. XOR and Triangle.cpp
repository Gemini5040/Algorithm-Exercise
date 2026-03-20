//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	
//	int T;
//	cin>>T;
//	
//	while(T--){
//		ll n;
//		cin>>n;
//		
//		int flag=0;
//		int d=-1;
//		int pos0=-1,pos1=-1;
//		for(int i=35;i>=0;i--){
//			if(((n>>i)&1)==1){
//				if(flag==0){
//					d=i;
//					flag++;
//				}else if(flag==2){
//					pos1=i;
//					break;
//				}
//			}else{
//				if(flag==1){
//					pos0=i;
//					flag++;
//				}
//			}
//		}
//		
//		if(pos0==-1||pos1==-1){
//			flag=0;
//			pos0=-1,pos1=-1;
//			for(int i=35;i>=0;i--){
//				if(((n>>i)&1)==1){
//					if(flag==0){
//						flag++;
//					}else if(flag==1){
//						pos0=i;
//						flag++;
//					}
//				}else{
//					if(flag==2){
//						pos1=i;
//						break;
//					}
//				}
//			}
//			
//			if(pos0==-1||pos1==-1){
//				cout<<-1<<"\n";
//			}else{
//				ll ans=(1LL<<d)+(1LL<<pos1);
//				cout<<ans<<"\n";
//			}
//			
//			continue;
//		}
//		
//		ll ans=(1LL<<pos0)+(1LL<<pos1);
//		cout<<ans<<"\n";
//	}
//	
//	return 0;
//}

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
		ll x;
		cin>>x;
		
		ll ans=-1;
		for(int i=0;i<30;i++){
			for(int j=0;j<30;j++){
				ll y=(1LL<<i)|(1LL<<j);
				if(y<x&&(x+y)>(x^y)&&(y+(x^y))>x){
					ans=y;
					break;
				}
			}
			if(ans!=-1){
				break;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
