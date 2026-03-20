#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isc(char c){
	return !((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
	
	ll ans=0;
	for(int len=8;len<=16;len++){
		for(int l=0;l<(int)s.size()-len+1;l++){
			int f1=0,f2=0;
			for(int p=l;p<l+len;p++){
				if(isdigit(s[p])) f1=1;
				if(isc(s[p])) f2=1;
			}
			if(f1&&f2) ans++;
		}
	}
	
	cout<<ans;
	
	return 0;
}
