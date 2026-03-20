#include <bits/stdc++.h>
using namespace std;

const int N=10010;
int a[N];
struct node{
	int a,h,id;
}s[N];

bool cmp(node x,node y){
	if(x.h!=y.h) return x.h<y.h;
	if(x.a!=y.a) return x.a<y.a;
	return x.id<y.id;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n,u,k,hp;
		cin>>n>>u>>k>>hp;
		
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].h;
			s[i].id=i;
		}
		sort(s+1,s+1+n,cmp);
		
		a[n+1]=0;
		for(int i=n;i>=1;i--){
			a[i]=max(a[i+1],s[i].a);
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			if(hp<=0){
				break;
			}
			
			if(s[i].h<=u){
				ans++;
				hp-=a[i+1];
				continue;
			}else{
				hp-=a[i];
				s[i].h-=u;
			}
			
			if(hp<=0){
				break;
			}
			
			int time=min(k-1,(s[i].h+(u>>1)-1)/(u>>1));
			if(time>1){
				if((time-1)*a[i]>=hp){
					break;
				}
				hp-=(time-1)*a[i];
				s[i].h-=min((time-1)*(u>>1),s[i].h);
			}
			
			if(time>0&&s[i].h<=(u>>1)){
				ans++;
				hp-=a[i+1];
			}else{
				break;
			}
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
}