#include <iostream>
using namespace std;

class knapSack{
    int n, w, profits[100], weights[100];
    public:
        void accept(){
            cout << "Enter no. of objects: ";
            cin >> n;
            cout << "Enter knapsack capacity: ";
            cin >> w;

            for(int i = 0; i < n; i++){
                cout << "Enter weight of object " << i + 1 << ": ";
                cin >> weights[i];
                cout << "Enter profit of object " << i + 1 << ": ";
                cin >> profits[i];
            }
        }
        int solve(){
            int dp[n + 1][w + 1];
            for(int i = 0; i < n + 1; i++){
                for(int j = 0; j < w + 1; j++){
                    if(i == 0 || j == 0) dp[i][j] = 0;
                    else if(weights[i - 1] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + profits[i - 1]);
                    else dp[i][j] = dp[i - 1][j];
                }
            }
            return dp[n][w];
        }
};

int main(){
    knapSack ks;
    ks.accept();
    cout << "Maximum profit: " << ks.solve() << endl;
    return 0;
}