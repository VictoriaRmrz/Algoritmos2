#include <iostream>
using namespace std;

string solveLCS(string x, string y) {
    int m = x.length();
    int n = y.length();
    int dp[m + 1][n + 1];

    // Build the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct the LCS
    int index = dp[m][n];
    string lcs(index, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

string findLCS_string(string x, string y) {
    if (x.length() == 0 || y.length() == 0)
        return "";

    if (x.length() == 1) {
        for (int j = 0; j < y.length(); j++) {
            if (y[j] == x[0])
                return x;
        }
        return "";
    } else {
        int m = x.length();
        int mid = m / 2;
        string x1 = x.substr(0, mid);
        string x2 = x.substr(mid, m);

        int n = y.length();
        string y1, y2;

        for (int k = 0; k <= n; k++) {
            y1 = y.substr(0, k);
            y2 = y.substr(k, n);

            if (solveLCS(x1, y1) + solveLCS(x2, y2) == solveLCS(x, y))
                break;
        }

        string sol1 = findLCS_string(x1, y1);
        string sol2 = findLCS_string(x2, y2);

        return sol1 + sol2;
    }
}

int main() {
    string x = "ABCBDAB";
    string y = "BDCAB";

    cout << "LCS: " << findLCS_string(x, y) << endl;

    return 0;
}
