#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAX 110

int dp[MAX][MAX][MAX]; // dp[i][j][k]: i店、j花后剩k斗酒

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    memset(dp, 0, sizeof(dp));
    dp[0][0][2] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= M; k++) { // 酒量最多为剩余花次数
                if (!dp[i][j][k]) continue;

                // 遇到店：需确保加倍后酒量 ≤ 剩余花次数（即 M-j 次花能喝完）
                if (i < N && k <= M - j) { 
                    int new_k = 2 * k;
                    if (new_k <= M - j) { // 关键剪枝
                        dp[i+1][j][new_k] = (dp[i+1][j][new_k] + dp[i][j][k]) % MOD;
                    }
                }

                // 遇到花：需有酒且未到最后一花
                if (j < M && k > 0) {
                    dp[i][j+1][k-1] = (dp[i][j+1][k-1] + dp[i][j][k]) % MOD;
                }
            }
        }
    }

    // 结果为遇到N店、M-1花后剩1斗酒，再遇一花喝完
    printf("%d", dp[N][M-1][1] % MOD);
    return 0;
}