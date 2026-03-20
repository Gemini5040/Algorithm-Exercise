#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int x,y;
	cin>>x>>y;
	
	tuple<double,double,double> line;
	set<tuple<double,double,double>> s;
	
	for(int x1=0;x1<x;x1++){
		for(int y1=0;y1<y;y1++){
			for(int x2=0;x2<x;x2++){
				for(int y2=0;y2<y;y2++){
					if(x1==x2&&y1==y2) continue;
					double A=x2-x1;
					double B=y1-y2;
					double C=x1*y2-x2*y1;
					if(A==0){
						line={0,1,C/B};
					}else if(B==0){
						line={1,0,C/A};
					}else if(A!=0&&B!=0){
						line={1,B/A,C/A};
					}
					s.insert(line);
				}
			}
		}
	}
	
	cout<<s.size()<<endl;
	
	return 0;
}