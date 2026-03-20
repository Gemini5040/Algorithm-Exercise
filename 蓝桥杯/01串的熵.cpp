#include <bits/stdc++.h>

using namespace std;

const int N=23333333;

int main(){
	for(int i=11027417;i<=11027424;i++){
		double p=(double)i/N;
		//printf("%.10f\n",p);
		double hs=-(p*p*log2(p)+(1-p)*(1-p)*log2(1-p))*N;
		//printf("%.4f\n",hs);
		int num=p*N;
		//if((int)hs==11625907) printf("%d\n",num);
		printf("%.5f\n",hs);
	}
	
	return 0;
}