#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl "\n"
#define int long long
#define double long double

double cos_angle(double ax,double ay,double bx,double by){
	return (ax*bx+ay*by)/sqrtl(ax*ax+ay*ay)/sqrtl(bx*bx+by*by);
}

double sin_angle(double ax,double ay,double bx,double by){
	double cos_A=cos_angle(ax,ay,bx,by);
	return sqrtl(1-cos_A*cos_A);
}

void solve(){
	double sx,sy,ax,ay,bx,by;
	cin>>sx>>sy>>ax>>ay>>bx>>by;

	if(sx>0){
		sx=-sx;
		ax=-ax;
		bx=-bx;
		swap(ax,bx);
		swap(ay,by);
	}

	double r=sqrtl(ax*ax+ay*ay);
	double msun=sx/sy,moa=ax/ay,mob=bx/by;
	double mi=0,ma=0;

	double sin_alpha=sin_angle(sx,sy,-1,0);
	double sin_thetaA=sin_angle(-ax,-ay,-sx,-sy);
	double sin_thetaB=sin_angle(-bx,-by,-sx,-sy);
	double sd1=r/sin_alpha;
	double sd2=r*sin_thetaB/sin_alpha;
	double sd3=r*sin_thetaA/sin_alpha;

	if(fabs(msun)<1e-10){
		if(mob<=msun&&moa>=msun){
			mi=0;
			ma=max(sd2,sd3);
		}else if(moa<=msun){
			mi=sd3;
			ma=sd2;
		}else if(mob>=msun){
			mi=sd2;
			ma=sd3;
		}
	}else{
		double mmax=-1/msun;

		if(mob<=msun&&moa>=mmax){
			mi=0;
			ma=sd1;
		}else if(mob>=msun&&mob<=mmax&&moa>=mmax){
			mi=min(sd2,sd3);
			ma=sd1;
		}else if(mob<=msun&&moa>=msun&&moa<=mmax){
			mi=0;
			ma=max(sd2,sd3);
		}else if(mob>=msun&&mob<=mmax&&moa>=msun&&moa<=mmax){
			mi=sd2;
			ma=sd3;
		}else if(mob>=mmax){
			mi=sd3;
			ma=sd2;
		}else if(moa<=msun){
			mi=sd3;
			ma=sd2;
		}
	}

	cout<<fixed<<setprecision(20)<<mi<<" "<<ma<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T=1;
	cin>>T;

	while(T--){
		solve();
	}

	return 0;
}