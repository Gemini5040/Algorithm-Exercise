#include <bits/stdc++.h>
using namespace std;

const int N=10010;
double dz[N];
int jm[N];
int pos1,pos2;

int compare1(const void *a,const void *b){
	return *(double*)a-*(double*)b;
}

int compare2(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout<<fixed<<setprecision(2);
	
	int T;
	cin>>T;
	
	while(T--){
		pos1=1,pos2=1;
		fill(dz,dz+N,0);
		fill(jm,jm+N,0);
		
		double p;
		int n,k;
		cin>>p>>n>>k;
		
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			if(t==0){	
				cin>>dz[pos1++];
			}else if(t==1){
				cin>>jm[pos2++];
			}
		}
		qsort(dz+1,pos1-1,sizeof(double),compare1);
		qsort(jm+1,pos2-1,sizeof(int),compare2);
		
//		cout<<"--------"<<"\n";
//		for(int i=0;i<pos1;i++){
//			cout<<"dz"<<i<<":"<<dz[i]<<" ";
//		}
//		for(int i=0;i<pos2;i++){
//			cout<<"jm"<<i<<":"<<jm[i]<<" ";
//		}
//		cout<<"\n"<<"---------"<<"\n";
		
		dz[0]=1.0;
		for(int i=1;i<pos1;i++){
			dz[i]=(dz[i]/10.0)*dz[i-1];
		}
		for(int i=2;i<pos2;i++){
			jm[i]+=jm[i-1];
		}
		
//		cout<<"--------"<<"\n";
//		for(int i=0;i<pos1;i++){
//			cout<<"dz"<<i<<":"<<dz[i]<<" ";
//		}
//		for(int i=0;i<pos2;i++){
//			cout<<"jm"<<i<<":"<<jm[i]<<" ";
//		}
//		cout<<"\n"<<"---------"<<"\n";
		
		double res=0x3f3f3f3f;
		for(int i=0;i<pos1;i++){
			if(k-i>=0&&k-i<pos2){
				double tmp=p*dz[i]-jm[k-i];
				res=min(res,tmp);
			}
		}
		if(res<0) res=0;
		
		cout<<res<<"\n";
	}
	
	return 0;
}