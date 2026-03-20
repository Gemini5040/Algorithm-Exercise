#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string wushiyin[133]={
	"a","i","u","e","o","ya","yu","yo",
	"ka","ki","ku","ke","ko","kya","kyu","kyo",
	"ga","gi","gu","ge","go","gya","gyu","gyo",
	"sa","si","su","se","so","sya","syu","syo",
	"za","zi","zu","ze","zo","zya","zyu","zyo",
	"ta","ti","tu","te","to","tya","tyu","tyo",
	"da","de","do",
	"na","ni","nu","ne","no","nya","nyu","nyo",
	"ha","hi","hu","he","ho","hya","hyu","hyo",
	"ba","bi","bu","be","bo","bya","byu","byo",
	"pa","pi","pu","pe","po","pya","pyu","pyo",
	"ma","mi","mu","me","mo","mya","myu","myo",
	"ra","ri","ru","re","ro","rya","ryu","ryo",
	"wa",
	"nn",
	"ppa","ppi","ppu","ppe","ppo","ppya","ppyu","ppyo",
	"tta","tti","ttu","tte","tto","ttya","ttyu","ttyo",
	"kka","kki","kku","kke","kko","kkya","kkyu","kkyo",
	"ssa","ssi","ssu","sse","sso","ssya","ssyu","ssyo"
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	set<string> wsy1,wsy2;
	for(int i=0;i<101;i++){
		wsy1.insert(wushiyin[i]);
	}
	for(int i=101;i<133;i++){
		wsy2.insert(wushiyin[i]);
	}
	
//	for(auto i:wsy1){
//		cout<<i<<" ";
//	}
//	cout<<"--------------------------\n";
//	for(auto i:wsy2){
//		cout<<i<<" ";
//	}
	
	int T;
	cin>>T;
	
	while(T--){
		string s1,s2;
		cin>>s1>>s2;
		
		int ans1=0,ans2=0;
		
		string ts;
		for(auto s:s1){
			ts.push_back(s);
//			cout<<"ts:"<<ts<<"\n";
			if(wsy1.count(ts)){
//				cout<<ts<<"--\n";
				ans1++;
				ts.clear();
			}else if(wsy2.count(ts)){
//				cout<<ts<<"-*\n";
				ans1+=2;
				ts.clear();
			}
		}
		
		ts.clear();
		for(auto s:s2){
			ts.push_back(s);
			if(wsy1.count(ts)){
//				cout<<ts<<"--\n";
				ans2++;
				ts.clear();
			}else if(wsy2.count(ts)){
//				cout<<ts<<"-*\n";
				ans2+=2;
				ts.clear();
			}
		}
		
		cout<<ans1<<" "<<ans2<<"\n";
	}
	
	return 0;
}
