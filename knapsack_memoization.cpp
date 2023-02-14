#include <bits/stdc++.h>
using namespace std;
int max(int x, int y) {
   return (x > y) ? x : y;
}
int knapSack(int W, vector<int>w, vector<int>v, int n) {
   int i, wt;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= W; wt++) {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (w[i - 1] <= wt)
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
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
    cout << knapSack(w, wt, val, n);
   return 0;
}