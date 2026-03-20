#include <bits/stdc++.h>
using namespace std;

double d,r,x,y;

double cc(double x){
	return (double)sqrt(r*r-x*x)+d;
}

double dd(double x1,double y1,double x2,double y2){
	return (double)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		cin>>d>>r>>x>>y;
		x=(double)abs(x);
		y=(double)abs(y);
		
		double ans=0;
		if(y<=d){
			ans=(double)abs(x-r);
		}else{
			double dis=dd(0,d,x,y);
			double t=(double)abs(r-dis);
			ans=t;
		}
		
		ans=round(ans);
		cout<<ans<<"\n";
	}
	
	return 0;
}
