#include <bits/stdc++.h>
//#include "testlib.h"
 
using namespace std;
 
int n,m;
vector<vector<int>> a;
vector<int> vis; 
int way[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int jumpL(int x,int y,int z){
	y%=z;
	x-=y;
	if (x<=0){
		x+=z;
	}
	return x;
}

int jumpR(int x,int y,int z){
	y%=z;
	x+=y;
	if (x>z){
		x-=z;
	}
	return x;
}

string to_upper(string s){
	string t="";
	for (int i=0;i<(int)s.size();i++){
		if ('a'<=s[i]&&s[i]<='z')t+=(char)(s[i]-'a'+'A');
		else t+=s[i];
	}
	return t;
}

inline int readAndCheckAnswer(InStream &in) {
    string result = in.readToken("[Yy][Ee][Ss]|[Nn][Oo]","STATE");
    if (to_upper(result)== "NO")
        return -1;
    a.resize(n+1);
    vis.resize(n*m+1);
    for (int i=1;i<=n*m;i++)vis[i]=0;
    for (int i=0;i<=n;i++)a[i].resize(m+1);
    int psx=0,psy=0;
    for (int i=0;i<n;i++){
    	for (int j=0;j<m;j++){
    		int x=in.readInt(1,n*m,"a");
    		if (vis[x])in.quitf(_wa, "Exist duplicated numbers in your construction :(");
			vis[x]=1; 
			a[i+1][j+1]=x;
			if (x==1){
				psx=i+1,psy=j+1;
			}
		}
	}
	for (int i=1;i<n*m;i++){
		bool fl=0;
		for (int j=0;j<4;j++){
			int px=psx,py=psy;
			if (way[j][0]==1){
				px=jumpR(px,i,n);
			}else if (way[j][0]==-1){
				px=jumpL(px,i,n);
			}
			if (way[j][1]==1){
				py=jumpR(py,i,m);
			}else if (way[j][1]==-1){
				py=jumpL(py,i,m);
			}
			if (a[px][py]==i+1){
				fl=1;
				psx=px,psy=py;
				break;
			}
		}
		if (!fl)in.quitf(_wa,"Construction doesn't satisfy the conditions step=%d:(",i);
	}
    return 1;
}
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    n=inf.readInt(0,1000000,"n");
    m=inf.readInt(0,1000000,"m");
    inf.ensuref(n*m<=1000000,"Found n*m>=10^6");
    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);
    if (ja != -1 && pa == -1)
        quitf(_wa, "Jury found an answer but participant didn't :(");
    quitf(_ok, "Wow, Accepted! Did you AK the contest?");
}
