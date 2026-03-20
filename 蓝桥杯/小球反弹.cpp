#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	long long t=1;
	int x=343720;
	int y=233333;
	
	while(1){
		if((y*15*t)%(x*17)==0) break;
		t++;
	}
	
	double a=y*t;
	double b=(double)(y*t*15/17);
	printf("%.2f",2*sqrt(a*a+b*b));

	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int main(){
//        long long t=1,x=343720,y=233333;
//        while(1){
//            if((15*t)%x==0&&(17*t)%y==0) break;
//            t++;
//        }//往右延长同样的长方形 当走到第t个长方形的左上角 就算是回到了左上角了
//        printf("%.2f",2*sqrt(15*15*t*t+17*17*t*t));//如果小球刚好射向角落，则按入射方向原路返回因此*2
//  return 0;
//}