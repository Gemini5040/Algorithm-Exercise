#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
};

int g[10][10];
int st[10];
int vt[10];
node q[100010];
int front,rear;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int ans=0;
	for(int i=1;i<(1<<7);i++){
		fill(&g[0][0],&g[0][0]+100,0);
		fill(st,st+10,0);
		fill(vt,vt+10,0);
		fill(q,q+100010,(node){0,0});
		front=0,rear=0;
		
		int crt=i;
		for(int j=0;j<7;j++){
			if(crt>>j&1){
				switch(j){
					case 0:{
						g[1][2]=1;
						g[2][1]=1;
						break;
					}
					case 1:{
						g[2][3]=1;
						g[3][2]=1;
						break;
					}
					case 2:{
						g[3][4]=1;
						g[4][3]=1;
						break;
					}
					case 3:{
						g[4][5]=1;
						g[5][4]=1;
						break;
					}
					case 4:{
						g[5][6]=1;
						g[6][5]=1;
						break;
					}
					case 5:{
						g[1][6]=1;
						g[6][1]=1;
						break;
					}
					case 6:{
						g[3][6]=1;
						g[6][3]=1;
						break;
					}
					default:{
						break;
					}
				}
			}
		}
		
		for(int i=1;i<=6;i++){
			for(int j=1;j<=6;j++){
				if(g[i][j]){
					st[i]=1;
					st[j]=1;
				}
			}
		}
		
		int stop=0;
		for(int i=1;i<=6;i++){
			for(int j=1;j<=6;j++){
				if(g[i][j]){
					q[rear++]=(node){i,j};
					stop=1;
					break;
				}
			}
			if(stop){
				break;
			}
		}
		
		while(front<rear){
			node c=q[front++];
			vt[c.x]=1,vt[c.y]=1;
			for(int i=1;i<=6;i++){
				if(!vt[i]&&g[c.x][i]){
					q[rear++]=(node){c.x,i};
				}
			}
			for(int i=1;i<=6;i++){
				if(!vt[i]&&g[c.y][i]){
					q[rear++]=(node){c.y,i};
				}
			}
		}
		
		int flag=1;
		for(int i=1;i<=6;i++){
			if(st[i]!=vt[i]){
				flag=0;
				break;
			}
		}
		
		if(flag){
			ans++;
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}