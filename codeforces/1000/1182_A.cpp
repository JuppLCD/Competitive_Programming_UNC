// https://codeforces.com/problemset/problem/1182/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

int f(uint i, vector<int> &dp) {
    if (i == 0u) {
        return 1u;
    }
    else if (i == 1u) {
        return 0u;
    }


    if (dp[i] != -1) {
        return dp[i];
    }

    dp[i] = 2 * f(i - 2u, dp);

    return dp[i];
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N;
    cin >> N;

    vector<int> dp(N + 1u, -1);

    cout << f(N, dp) << endl;

    return EXIT_SUCCESS;
}