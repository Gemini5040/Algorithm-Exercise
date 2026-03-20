#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

double arr[100010][3];
double answer[100010];
int pos=0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;

	while(T--){
		memset(answer,0,sizeof(answer));
		pos=0;
		
		int n;
        cin>>n;
		
		int flag=0;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
            arr[i][0]=abs((double)(c-b)/a);
            arr[i][1]=abs((double)(c-a)/b);
            arr[i][2]=abs((double)(a-b)/c);
			
            if(n==1){
                for(int w=0;w<3;w++){
                    if((int)arr[0][w]==arr[0][w]){
                        cout<<(int)arr[0][w]<<endl;
                        flag=1;
                        break;
                    }
                }
            }
            else{
                if(i==0) for(int j=0;j<3;j++){
					if((int)arr[i][j]==arr[i][j]){
						answer[pos++]=arr[i][j];
					}
				}
                else if(i>0){
                	int tmp=pos;
                    for(int w=0;w<3;w++){
                        for(int e=0;e<tmp;e++){
                            if(arr[i][w]==answer[e]){
                                answer[pos++]=arr[i][w];
                                break;
                            }
                        }
                    }
                }
            }
            if(flag) break;
		}
		
		if(!flag){
	        int cnt=0;
	        int pp=0;
	        for(int j=0;j<pos;j++){
	        	for(int k=0;k<pos;k++){
	        		if(answer[j]==answer[k]){
	        			cnt++;
					}
				}
				if(cnt>=n){
					pp=j;
					break;
				}
			}
			cout<<answer[pp]<<endl;
		}
	}

	return 0;
}