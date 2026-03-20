#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int qmi(int m, int k, int p) {
  long long t = m, res = 1;
  while (k ) {
    if (k&1) res = res*t%p;
    t = t*t%p;
    k >>=1;
  }
  return res;
}
int power(int m, int k, int p) {
  int res = 1;
  while (k--)
    res = res * m % p;
  return res;
}
signed main() {
  cout << qmi(2, 1012, MOD) << "\n";
  cout << power(2, 1012, MOD) << "\n";
  return 0;
}