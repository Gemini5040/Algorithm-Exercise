#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	char s[10];
	fgets(s,sizeof(s),stdin);
	
	int lim=strlen(s);
	int ans=0;
	for(int i=0;i<lim;i++){
		if(s[i]==' '||s[i]=='\n') continue;
		ans++;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
