class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<long long> dp;
    vector<int> last;

    long long solve(int i, string &s) {
        if (i < 0)
            return 1;   // empty subsequence

        if (dp[i] != -1)
            return dp[i];

        // All subsequences from s[0...i-1]
        long long ans = (2 * solve(i - 1, s)) % MOD;

        int ch = s[i] - 'a';

        // If character appeared before, remove duplicates
        if (last[ch] != -1) {
            ans = (ans - solve(last[ch] - 1, s) + MOD) % MOD;
        }

        last[ch] = i;

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        dp.assign(n, -1);
        last.assign(26, -1);

        // solve(n-1) includes empty subsequence
        return (solve(n - 1, s) - 1 + MOD) % MOD;
    }
};