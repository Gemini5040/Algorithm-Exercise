#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ull=unsigned long long;
using i128=__int128;

const double PI=acos(-1.0);

void fft(vector<complex<double>>& a,bool invert){
    int n=a.size();
    for(int i=1,j=0;i<n;i++){
        int bit=n>>1;
        for(;j&bit;bit>>=1){
            j^=bit;
        }
        j^=bit;
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    for(int len=2;len<=n;len<<=1){
        double ang=2*PI/len*(invert?-1:1);
        complex<double> wlen(cos(ang),sin(ang));
        for(int i=0;i<n;i+=len){
            complex<double> w(1);
            for(int j=0;j<len/2;j++){
                complex<double> u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(invert){
        for(complex<double>& x:a){
            x/=n;
        }
    }
}

vector<ll> convolution_fft(vector<ll>& a,vector<ll>& b){
    vector<complex<double>> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    int len_conv=a.size()+b.size()-1;
    int n=1;
    while(n<len_conv){
        n<<=1;
    }
    fa.resize(n);
    fb.resize(n);

    fft(fa,false);
    fft(fb,false);
    for(int i=0;i<n;i++){
        fa[i]*=fb[i];
    }
    fft(fa,true);

    vector<ll> result(len_conv);
    for(int i=0;i<len_conv;i++){
        result[i]=round(fa[i].real());
    }

    return result;
}

void solve(){
    string A,B;
    cin>>A>>B;

    if(A=="0"||B=="0"){
        cout<<"0"<<"\n";
        return;
    }

    int na=A.size(),nb=B.size();
    vector<ll> a(na),b(nb);
    for(int i=0;i<na;i++){
        a[i]=A[na-1-i]-'0';
    }
    for(int i=0;i<nb;i++){
        b[i]=B[nb-i-1]-'0';
    }

    vector<ll> poly=convolution_fft(a,b);
    ll max_index=na+nb-2;
    if(poly.size()<max_index+3){
        poly.resize(max_index+3,0);
    }

    int i=0;
    while(i<=max_index||i<poly.size()&&poly[i]!=0){
        if(i>=poly.size()){
            poly.resize(i+3,0);
        }
        if(poly[i]==0||poly[i]==1){
            i++;
            continue;
        }
        ll r=poly[i]&1;
        ll q=(poly[i]-r)/2;
        poly[i]=r;
        if(i+2>=poly.size()){
            poly.resize(i+3,0);
        }
        poly[i+2]-=q;
        if(i+2>max_index){
            max_index=i+2;
        }
        i++;
    }

    int hi=-1;
    for(int j=max_index;j>=0;j--){
        if(j<poly.size()&&poly[j]!=0){
            hi=j;
            break;
        }
    }
    if(hi==-1){
        cout<<"0"<<"\n";
    }else{
        string res="";
        for(int j=hi;j>=0;j--){
            if(j<poly.size()){
                res+=('0'+poly[j]);
            }else{
                res+='0';
            }
        }
        cout<<res<<"\n";
    }
}

signed main(){
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