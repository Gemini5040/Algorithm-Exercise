#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200010;
vector<int> t(N);

ll merge_sort(vector<int> &a,int l,int r){
	if(l>=r) return 0;
	
	int mid=(l+r)>>1;
	ll res=merge_sort(a,l,mid)+merge_sort(a,mid+1,r);
	
	int i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]) t[k++]=a[i++];
		else{
			t[k++]=a[j++];
			res+=mid-i+1;
		}
	}
	while(i<=mid) t[k++]=a[i++];
	while(j<=r) t[k++]=a[j++];
	
	for(int i=l,j=0;i<=r;i++,j++) a[i]=t[j];
	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		
		int lo=(n+1)>>1,le=n-lo;
		vector<int> a(n),odd(lo),even(le);
		
		int po=0,pe=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if((i&1)==0) odd[po++]=a[i];
			else even[pe++]=a[i];
		}
		int cnt1=merge_sort(odd,0,lo-1);
		int cnt2=merge_sort(even,0,le-1);
		
		if((cnt1+cnt2)&1){
			if(lo==le){
				swap(even[le-1],even[le-2]);
			}else if(lo>le){
				swap(odd[lo-1],odd[lo-2]);
			}
		}
		
		po=0,pe=0;
		for(int i=0;i<n;i++){
			if((i&1)==0) cout<<odd[po++];
			else cout<<even[pe++];
			cout<<" \n"[i==n-1];
		}
	}
	
	return 0;
}
