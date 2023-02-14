#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> K(n+1, vector<int>(W+1));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main() {
    int w,n; 
    cin>>n;
    vector<int>wt(n); 
    vector<int>val(n); 
    for(int &i: val) cin>>i;
    for(int &i: wt) cin>>i;
    cin>>w;
    cout << knapsack(w, wt, val, n) << endl;
    return 0;
}
