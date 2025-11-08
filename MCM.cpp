#include <iostream>
using namespace std;

void printOptimalParenthesis(int** S, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printOptimalParenthesis(S, i, S[i][j]);
    printOptimalParenthesis(S, S[i][j] + 1, j);
    cout << ")";
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int* p = new int[n + 1];
    cout << "Enter dimensions (p[0] p[1] ... p[n]): ";
    for (int i = 0; i <= n; i++) cin >> p[i];

    int** M = new int*[n + 1];
    int** S = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        M[i] = new int[n + 1];
        S[i] = new int[n + 1];
    }

    for (int i = 1; i <= n; i++)
        M[i][i] = 0;

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            M[i][j] = 999999999;

            for (int k = i; k <= j - 1; k++) {
                int q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    cout << "\nM Table (minimum cost):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i > j) cout << "- ";
            else cout << M[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nS Table (splits):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) cout << "- ";
            else cout << S[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nOptimal Parenthesization: ";
    printOptimalParenthesis(S, 1, n);
    cout << endl;

    cout << "Minimum multiplication cost: " << M[1][n] << endl;

    delete[] p;
    for (int i = 0; i <= n; i++) {
        delete[] M[i];
        delete[] S[i];
    }
    delete[] M;
    delete[] S;

    return 0;
}
