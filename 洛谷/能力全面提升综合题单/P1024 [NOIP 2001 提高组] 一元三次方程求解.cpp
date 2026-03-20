#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double a,b,c,d;

double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout<<fixed<<setprecision(2);
	
	cin>>a>>b>>c>>d;
	
	double p1,p2,p3,p4;
	double x1,x2,x3;
	if(f(-101)<0){
		p1=-101;
		for(double i=-100;i<=101;i++){
			if(f(i)>=0){
				p2=i;
				break;
			}
		}
		for(double i=p2+1;i<=101;i++){
			if(f(i)<=0){
				p3=i;
				break;
			}
		}
		p4=101;
		
		while(p2-p1>0.000000001){
			double mid=(p1+p2)/2;
			if(f(mid)<0) p1=mid;
			else p2=mid;
		}
		x1=p2;
		
		while(p3-p2>0.000000001){
			double mid=(p2+p3)/2;
			if(f(mid)>0) p2=mid;
			else p3=mid;
		}
		x2=p3;
		
		while(p4-p3>0.000000001){
			double mid=(p3+p4)/2;
			if(f(mid)<0) p3=mid;
			else p4=mid;
		}
		x3=p4;
	}else if(f(-101)>0){
		p1=-101;
		for(double i=-100;i<=101;i++){
			if(f(i)<=0){
				p2=i;
				break;
			}
		}
		for(double i=p2+1;i<=101;i++){
			if(f(i)>=0){
				p3=i;
				break;
			}
		}
		p4=101;
		
		while(p2-p1>0.000000001){
			double mid=(p1+p2)/2;
			if(f(mid)>0) p1=mid;
			else p2=mid;
		}
		x1=p2;
		
		while(p3-p2>0.000000001){
			double mid=(p2+p3)/2;
			if(f(mid)<0) p2=mid;
			else p3=mid;
		}
		x2=p3;
		
		while(p4-p3>0.000000001){
			double mid=(p3+p4)/2;
			if(f(mid)>0) p3=mid;
			else p4=mid;
		}
		x3=p4;
	}
	
	cout<<x1<<" "<<x2<<" "<<x3<<"\n";
	
	return 0;
}
