#include <iostream>
using namespace std;

class nQueen {
public:
    bool place(int k, int i, int x[]) {
        for(int j = 1; j < k; j++){
            if(x[j] == i || abs(x[j] - i) == abs(j - k)) return false;
        }
        return true;
    }   

    void nqueen(int k, int n, int x[]) {
        for(int i = 1; i <= n; i++){
            if(place(k, i, x)){
                x[k] = i;
                if(k == n){
                    for(int j = 1; j <= n; j++){
                        cout << x[j] << " ";
                    }
                    cout << endl;
                }
                else nqueen(k+1, n, x);
            }
        }
    }
};

int main() {
    nQueen a;
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[11] = {0};
    a.nqueen(1, n , arr);
    return 0;
}