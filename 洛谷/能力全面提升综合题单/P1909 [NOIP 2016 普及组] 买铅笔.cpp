#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,c1,p1,c2,p2,c3,p3;
	cin>>n>>c1>>p1>>c2>>p2>>c3>>p3;
	int cost1=(n+c1-1)/c1*p1;
	int cost2=(n+c2-1)/c2*p2;
	int cost3=(n+c3-1)/c3*p3;
	cout<<min(min(cost1,cost2),cost3)<<"\n";
	
	return 0;
}
