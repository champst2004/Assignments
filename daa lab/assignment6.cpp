#include <iostream>
using namespace std;

int knapsack(int W, int weights[], int profits[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (weights[i - 1] <= j) dp[i][j] = max(profits[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter no. of objects: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;
    int profits[n], weights[n];

    for(int i = 0; i < n; i++){
        cout << "Enter weight of object " << i + 1 << ": ";
        cin >> weights[i]; 
        cout << "Enter profit of object " << i + 1 << ": ";
        cin >> profits[i]; 
    }

    cout << "Maximum profit: " << knapsack(W, weights, profits, n) << endl;
    return 0;
}