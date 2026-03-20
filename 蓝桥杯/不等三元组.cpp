#include <iostream>
using namespace std;

const int MAX = 100001;

int cnt[MAX] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    long long total = (long long)n * (n - 1) * (n - 2) / 6;
    long long invalid = 0;
    for (int x = 0; x < MAX; ++x) {
        int c = cnt[x];
        if (c >= 3) {
            invalid += (long long)c * (c - 1) * (c - 2) / 6;
        }
        if (c >= 2) {
            long long two = (long long)c * (c - 1) / 2;
            invalid += two * (n - c);
        }
    }
    cout << total - invalid << endl;
    return 0;
}