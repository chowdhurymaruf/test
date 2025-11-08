#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciDP(int n, int memo[]) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacciDP(n - 1, memo) + fibonacciDP(n - 2, memo);
    return memo[n];
}

void fibonacciIterative(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << a;
        else if (i == 1) cout << " " << b;
        else {
            int c = a + b;
            cout << " " << c;
            a = b;
            b = c;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    if (n <= 0) {
        cout << "Fibonacci Series (Recursive):" << endl;
        cout << "Fibonacci Series (Dynamic Programming):" << endl;
        cout << "Fibonacci Series (Iterative):" << endl;
        return 0;
    }

    cout << "Fibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << fibonacciRecursive(i);
        else cout << " " << fibonacciRecursive(i);
    }
    cout << endl;

    int* memo = new int[n + 1];   
    for (int i = 0; i <= n; i++) memo[i] = -1;

    cout << "Fibonacci Series (Dynamic Programming): ";
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << fibonacciDP(i, memo);
        else cout << " " << fibonacciDP(i, memo);
    }
    cout << endl;

    delete[] memo;  

    cout << "Fibonacci Series (Iterative): ";
    fibonacciIterative(n);

    return 0;
}
