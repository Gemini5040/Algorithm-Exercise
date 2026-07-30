#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

const int OFFSET=400;
const int DIM=810;

int dist[DIM][DIM];
int qx[DIM*DIM];
int qy[DIM*DIM];

void solve(){
    int k;
    cin>>k;

    vector<pair<int,int>> forces;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        forces.push_back({x,y});
    }

    sort(forces.begin(),forces.end());
    forces.erase(unique(forces.begin(),forces.end()),forces.end());

    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            dist[i][j]=-1;
        }
    }

    dist[OFFSET][OFFSET]=0;
    int head=0,tail=0;

    for(auto f:forces){
        int nx=OFFSET+f.first;
        int ny=OFFSET+f.second;

        if(nx==OFFSET&&ny==OFFSET){
            cout<<1<<endl;
            return;
        }

        if(nx>=0&&nx<DIM&&ny>=0&&ny<DIM){
            if(dist[ny][nx]==-1){
                dist[ny][nx]=1;
                qx[tail]=nx;
                qy[tail]=ny;
                tail++;
            }
        }
    }

    while(head<tail){
        int cx=qx[head];
        int cy=qy[head];
        head++;

        int d=dist[cy][cx];

        for(auto f:forces){
            int nx=cx+f.first;
            int ny=cy+f.second;

            if(nx==OFFSET&&ny==OFFSET){
                cout<<d+1<<endl;
                return;
            }

            if(nx>=0&&nx<DIM&&ny>=0&&ny<DIM){
                if(dist[ny][nx]==-1){
                    dist[ny][nx]=d+1;
                    qx[tail]=nx;
                    qy[tail]=ny;
                    tail++;
                }
            }
        }
    }

    cout<<-1<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    cin>>T;

    while(T--){
        solve();
    }

    return 0;
}