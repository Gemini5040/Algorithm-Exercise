#include <bits/stdc++.h>
using namespace std;

const int N=1010;

struct info{
	long long z;
	int j;
	int k;
}stu[N];

int compare(const void *a,const void *b){
	return ((info*)a)->j-((info*)b)->j;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long z;
		int j,k;
		cin>>z>>j>>k;
		stu[i]=(info){z,j,k};
	}
	qsort(stu,n,sizeof(info),compare);
	
	int w;
	cin>>w;
	while(w--){
		int jj;
		cin>>jj;
		cout<<stu[jj-1].z<<" "<<stu[jj-1].k<<endl;
	}
	
	return 0;
}