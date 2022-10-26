#include <iostream>
#include <unordered_map>
using namespace std;

#define MOD 1000000007

long long tear(char paper[][10], int l, int r, int u, int d, int k, unordered_map<int, long long>& dp, int comb[][101]) {
    if (l == r && u == d && k != 0) return 0;
    if (k == 0) return 1;

    // state compression: l | r | u | d | k
    int state = (l << 18) | (r << 14) | (u << 10) | (d << 6) | k;
    if (dp.find(state) != dp.end()) return dp[state];

    long long ret = 0;
    if (l != r) {
        for (int j = l; j <= r; ++j) {
            bool cut = true;
            for (int i = u; i <= d && cut; ++i)
                if (paper[i][j] == 'X')
                    cut = false;
            if (cut) {  // tear column j
                if (j == l) ret = (ret + tear(paper, j + 1, r, u, d, k - 1, dp, comb)) % MOD;
                else if (j == r) ret = (ret + tear(paper, l, j - 1, u, d, k - 1, dp, comb)) % MOD;
                else
                    for (int ka = 0; ka < k; ++ka)
                        ret = (ret + comb[k - 1][ka] *\
                                tear(paper, l, j - 1, u, d, ka, dp, comb) % MOD *\
                                tear(paper, j + 1, r, u, d, k - 1 - ka, dp, comb) % MOD) % MOD;
            }
        }
    }

    if (u != d) {
        for (int i = u; i <= d; ++i) {
            bool cut = true;
            for (int j = l; j <= r && cut; ++j)
                if (paper[i][j] == 'X')
                    cut = false;
            if (cut) {  // tear row i
                if (i == u) ret = (ret + tear(paper, l, r, i + 1, d, k - 1, dp, comb)) % MOD;
                else if (i == d) ret = (ret + tear(paper, l, r, u, i - 1, k - 1, dp, comb)) % MOD;
                else
                    for (int ka = 0; ka < k; ++ka)
                        ret = (ret + comb[k - 1][ka] *\
                                tear(paper, l, r, u, i - 1, ka, dp, comb) % MOD *\
                                tear(paper, l, r, i + 1, d, k - 1 - ka, dp, comb) % MOD) % MOD;
            }
        }
    }
    
    return dp[state] = ret;
}


int main(void) {
    // Combination C(i, j).
    int comb[101][101];
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j || j == 0) comb[i][j] = 1;
            else comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    char paper[10][10];
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> paper[i][j];

    int k = 0; // Number of tears.
    long long ret = 0, way;
    unordered_map<int, long long> dp;
    // Increase k until we can not do k tears on the input.
    do {
        way = tear(paper, 0, M - 1, 0, N - 1, k, dp, comb);
        ret = (ret + way) % MOD;
        ++k;
    } while (way != 0);
    cout << ret;

    return 0;
}
