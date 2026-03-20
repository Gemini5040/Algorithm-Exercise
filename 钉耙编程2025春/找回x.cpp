#include <iostream>
#include <ctype.h>

using namespace std;

long long read_and_sum(){
	long long sum=0;
	int c;
	int negative=0;
	while((c=getchar())!=EOF&&c!='\n'&&isspace(c)) c=getchar();
	if(c==EOF) return 0;
	do{
		long long num=0;
		
		if(c=='-'){
			negative=1;
			c=getchar();
		}else{
			negative=0;
		}
		while(isdigit(c)){
			num=num*10+c-'0';
			c=getchar();
		}
		if(negative) num=-num;
		sum+=num;
		while(c!=EOF&&c!='\n'&&isspace(c)) c=getchar();
	}while(c!=EOF&&c!='\n');
	return sum;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		
		while(getchar()!='\n');
		long long sumA=read_and_sum();
		long long sumB=read_and_sum();
		long long sumC=read_and_sum();
		long long x=(sumC-sumB)/sumA;
		printf("%lld\n",x);
	}
	
	return 0;
}