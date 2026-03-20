#include <bits/stdc++.h>
using namespace std;

const int N=1000010;
char s[N],p[N];
int k[N];

void tl(char arr[],int len){
	for(int i=0;i<len;i++){
		if(arr[i]>='A'&&arr[i]<='Z'){
			arr[i]+=32;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	fgets(s+1,sizeof(s),stdin);
	fgets(p+1,sizeof(p),stdin);
	s[0]=' ',p[0]=' ';
	int ls=strlen(s),lp=strlen(p);
	s[ls-1]=' ',p[lp-1]=' ';
	tl(s,ls),tl(p,lp);
	
	k[0]=0;
	int j=0;
	for(int i=1;i<ls;i++){
		while(j&&s[j]!=s[i]) j=k[j-1];
		if(s[j]==s[i]) j++;
		k[i]=j;
	}
	
	j=0;
	int pos=-1,cnt=0;
	for(int i=0;i<lp;i++){
		while(j&&s[j]!=p[i]) j=k[j-1];
		if(s[j]==p[i]) j++;
		if(j==ls){
			if(pos==-1) pos=i-ls+1;
			cnt++;
			j=k[j-1];
		}
	}
	
	if(cnt) cout<<cnt<<" "<<pos<<"\n";
	else cout<<-1<<"\n";
	
//	cout<<"---"<<"\n";
//	for(int i=0;i<ls;i++) cout<<s[i];
//	cout<<"."<<"\n";
//	for(int i=0;i<lp;i++) cout<<p[i];
//	cout<<"."<<"\n";
//	cout<<ls<<" "<<lp;
	
	return 0;
}
