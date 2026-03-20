#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	
	int s=max(n,m);
	vector<int> stk1(s),stk2(s);
	int top1=0,top2=0;
	int i=0,j=0;
	int ans=0;
	while(i<n&&j<m){
		stk1[top1++]=a[i++];
		stk2[top2++]=b[j++];
		if(stk1[top1-1]==stk2[top2-1]){
			top1--;
			top2--;
			continue;
		}
		while(stk1[top1-1]!=stk2[top2-1]){
			if(stk1[top1-1]>stk2[top2-1]){
				stk2[top2-1]+=b[j++];
			}else if(stk1[top1-1]<stk2[top2-1]){
				stk1[top1-1]+=a[i++];
			}
			ans++;
		}
		top1--;
		top2--;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
