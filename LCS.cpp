#include <iostream>
#include <set>
#include <string>
using namespace std;

int** buildLCSTable(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    int** dp = new int*[m + 1];
    for (int i = 0; i <= m; i++)
        dp[i] = new int[n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp;
}

void findAllLCS(int** dp, const string& X, const string& Y, int i, int j, string current, set<string>& result) {
    if (i == 0 || j == 0) {
        if (!current.empty()) {
            string rev = string(current.rbegin(), current.rend());
            result.insert(rev);
        }
        return;
    }

    if (X[i - 1] == Y[j - 1]) {
        findAllLCS(dp, X, Y, i - 1, j - 1, current + X[i - 1], result);
    } else {
        if (dp[i - 1][j] == dp[i][j])
            findAllLCS(dp, X, Y, i - 1, j, current, result);
        if (dp[i][j - 1] == dp[i][j])
            findAllLCS(dp, X, Y, i, j - 1, current, result);
    }
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    int** dp = buildLCSTable(X, Y);

    cout << "\nDP Table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLength of LCS: " << dp[m][n] << endl;

    set<string> allLCS;
    findAllLCS(dp, X, Y, m, n, "", allLCS);

    cout << "All possible LCS:\n";
    for (auto& seq : allLCS)
        cout << seq << endl;

    for (int i = 0; i <= m; i++)
        delete[] dp[i];
    delete[] dp;

    return 0;
}
