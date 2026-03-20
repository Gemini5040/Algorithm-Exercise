#include <bits/stdc++.h>
using namespace std;

const int N=200010;
struct node{
	int v,num;
};
node a[N],b[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		fill(a,a+N,(node){0,0});
		fill(b,b+N,(node){0,0});
		
		string s1,s2;
		cin>>s1>>s2;
		
		int sz1=s1.size();
		int sz2=s2.size();
		
		int p1=1,p2=1;
		int l=0;
		for(int r=0;r<sz1;r++){
			if(s1[r]!=s1[l]){
				if(s1[l]=='L'){
					a[p1++]=(node){0,r-l};
				}else if(s1[l]=='R'){
					a[p1++]=(node){1,r-l};
				}
				l=r;
			}
			if(r==sz1-1){
				if(s1[l]=='L'){
					a[p1++]=(node){0,r-l+1};
				}else if(s1[l]=='R'){
					a[p1++]=(node){1,r-l+1};
				}
			}
		}
		l=0;
		for(int r=0;r<sz2;r++){
			if(s2[r]!=s2[l]){
				if(s2[l]=='L'){
					b[p2++]=(node){0,r-l};
				}else if(s2[l]=='R'){
					b[p2++]=(node){1,r-l};
				}
				l=r;
			}
			if(r==sz2-1){
				if(s2[l]=='L'){
					b[p2++]=(node){0,r-l+1};
				}else if(s2[l]=='R'){
					b[p2++]=(node){1,r-l+1};
				}
			}
		}
		
//		for(int i=1;i<p1;i++){
//			cout<<a[i].v<<"--"<<a[i].num<<" ";
//		}
//		cout<<"\n";
//		for(int i=1;i<p2;i++){
//			cout<<b[i].v<<"--"<<b[i].num<<" ";
//		}
//		cout<<"\n"<<"-------"<<"\n";

		int flag=1;
		if(p1!=p2){
			flag=0;
		}else{
			for(int i=1;i<p1;i++){
				if(!((a[i].v==b[i].v)&&(b[i].num>=a[i].num)&&(b[i].num<=a[i].num*2))){
					flag=0;
					break;
				}
			}
		}
		
		if(flag) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
	
	return 0;
}