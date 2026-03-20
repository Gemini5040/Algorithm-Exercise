#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dis(ll x1,ll y1,ll x2,ll y2){
	return pow(x1-x2,2)+pow(y1-y2,2);
}

bool check(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
	if(a.first==b.first||a.first==c.first){
		return a.first==b.first&&a.first==c.first;
	}
	double k1=(a.second-b.second)*1.0/(a.first-b.first);
	double k2=(a.second-c.second)*1.0/(a.first-c.first);
	return abs(k1-k2)<1e-6;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<pair<ll,ll>> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	
	ll ans=0;
	for(int i=0;i<n;i++){
		map<ll,vector<ll>> m;
		for(int j=0;j<n;j++){
			if(i!=j){
				ll d=dis(arr[i].first,arr[i].second,arr[j].first,arr[j].second);
				m[d].push_back(j);
			}
		}
		
		for(auto& de:m){
			auto e=de.second;
			for(int a=0;a<(int)e.size();a++){
				for(int b=a+1;b<(int)e.size();b++){
					if(!check(arr[i],arr[e[a]],arr[e[b]])){
						ans++;
					}
				}
			}
		}
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
