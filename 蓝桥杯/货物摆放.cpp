#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const long long N=2021041820210418;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int64 n;
	cin>>n;
	
	tuple<int64,int64,int64> y;
	set<tuple<int64,int64,int64>> s;
	
	for(int64 i=1;i<=(int64)cbrt(n);i++){
		int64 tmp1=n;
		tmp1/=i;
		for(int64 j=1;j<=(int64)sqrt(tmp1);j++){
			int64 tmp2=tmp1;
			tmp2/=j;
			for(int64 k=1;k<=(int64)tmp2;k++){
				if(i*j*k==n){
					int64 arr[3]={i,j,k};
					for(int p=0;p<3;p++){
						for(int q=2;q>p;q--){
							if(arr[q]<arr[q-1]) swap(arr[q],arr[q-1]);
						}
					}
					y={arr[0],arr[1],arr[2]};
					s.insert(y);
				}
			}
		}
	}
	
	int64 ans=0;
	for(auto yy:s){
		set<int64> ss;
		int64 aa=get<0>(yy);
		int64 bb=get<1>(yy);
		int64 cc=get<2>(yy);
		
		
		//cout<<"------"<<aa<<" "<<bb<<" "<<cc<<" "<<"------"<<endl;
		
		ss.insert(aa);
		ss.insert(bb);
		ss.insert(cc);
		int size=ss.size();
		if(size==1) ans+=1;
		else if(size==2) ans+=3;
		else if(size==3) ans+=6;
	}
	
	cout<<ans<<endl;
	
	return 0;
}