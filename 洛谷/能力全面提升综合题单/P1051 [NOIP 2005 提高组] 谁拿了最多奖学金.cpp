#include <bits/stdc++.h>
using namespace std;

struct node{
	int id;
	string name;
	int fg;
	int cg;
	string cadre;
	string west;
	int pp;
	int scho;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<node> a(n);
	
	for(int i=0;i<n;i++){
		string t1,t4,t5;
		int t2,t3,t6;
		cin>>t1>>t2>>t3>>t4>>t5>>t6;
		a[i]=(node){i,t1,t2,t3,t4,t5,t6,0};
	}
	
	for(int i=0;i<n;i++){
		if(a[i].fg>80&&a[i].pp>0) a[i].scho+=8000;
		if(a[i].fg>85&&a[i].cg>80) a[i].scho+=4000;
		if(a[i].fg>90) a[i].scho+=2000;
		if(a[i].fg>85&&a[i].west=="Y") a[i].scho+=1000;
		if(a[i].cg>80&&a[i].cadre=="Y") a[i].scho+=850;
	}
	sort(a.begin(),a.end(),[&](node x,node y){
		if(x.scho!=y.scho) return x.scho>y.scho;
		return x.id<y.id;
	});
	
	int total=0;
	for(int i=0;i<n;i++){
		total+=a[i].scho;
	}
	
	cout<<a[0].name<<"\n"<<a[0].scho<<"\n"<<total<<"\n";
	
	return 0;
}
