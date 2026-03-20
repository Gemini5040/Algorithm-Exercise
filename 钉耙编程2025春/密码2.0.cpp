#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		unordered_set<int> candidates;
		
		for(int i=0;i<n;i++){
			int u,v,w;
			cin>>u>>v>>w;
			unordered_set<int> current;
			
			int coeff[6][3]={
				{u,v,w},{u,w,v},
				{v,u,w},{v,w,u},
				{w,u,v},{w,v,u}
			};
			
			for(auto &coeff:coeff){
				int a=coeff[0],b=coeff[1],c=coeff[2];
				if(a==0) continue;
				int numerator=c-b;
				if(numerator%a==0){
					int x=numerator/a;
					if(x>=0){
						current.insert(x);
					}
				}
			}
			
			if(i==0){
				candidates=current;
			}else{
				unordered_set<int> temp;
				for(auto x:current){
					if(candidates.count(x)){
						temp.insert(x);
					}
				}
				candidates.swap(temp);
			}
			
			if(candidates.size()==1){
				for(int j=i+1;j<n;j++){
					cin>>u>>v>>w;
				}
				break;
			}
		}
		
		cout<<*candidates.begin()<<"\n";
	}
	
	return 0;
}