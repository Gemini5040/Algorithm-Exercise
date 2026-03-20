#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline int h(unsigned x){
	return x==0?0:32-__builtin_clz(x);
}

inline int getbit(unsigned x,int k){
	return ((x>>(k-1))&1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		unsigned a,b,c;
		cin>>a>>b>>c;
		
		if(a==0&&b==0){
			cout<<(c>0?"-1":"0")<<"\n";
			continue;
		}
		
		vector<int> op;
		if(h(a)<h(b)){
			op.push_back(3);
			a^=b;
		}
		if(h(a)>h(b)){
			op.push_back(4);
			b^=a;
		}
		if(h(a)>h(c)){
			while(h(b)>h(c)){
				if(h(a)==h(b)){
					op.push_back(3);
					a^=b;
				}
				op.push_back(2);
				b>>=1;
			}
		}
		if(h(a)<h(b)){
			op.push_back(3);
			a^=b;
		}
		while(h(a)<h(c)){
			if(getbit(a,h(b))!=getbit(c,h(c)-h(a)+h(b))){
				op.push_back(3);
				a^=b;
			}
			op.push_back(1);
			a<<=1;
		}
		while(h(b)>0){
			if(getbit(a,h(b))!=getbit(c,h(b))){
				op.push_back(3);
				a^=b;
			}
			op.push_back(2);
			b>>=1;
		}
		op.push_back(4);
		b^=a;
		
		cout<<op.size()<<"\n";
		for(auto x:op){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
