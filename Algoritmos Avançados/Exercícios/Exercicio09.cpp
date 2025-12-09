#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função recursiva com meoização para achar o valor máximo
int valorMaximo(int i, int comprar, vector<int>& arr, vector<vector<int>>& dp) {
    int n = arr.size();

    // Caso base
    if (i >= n) return 0;

    // Se o valor já foi calculado
    if (dp[i][comprar] != -1) return dp[i][comprar];

    // Se pode comprar
    if (comprar) {
        int pega = -arr[i] + valorMaximo(i + 1, 0, arr, dp);
        int passa = valorMaximo(i + 1, 1, arr, dp);
        dp[i][comprar] = max(pega, passa);
    }

    // Se pode vender
    else {
        int vende = arr[i] + valorMaximo(i + 2, 1, arr, dp);
        int passa = valorMaximo(i + 1, 0, arr, dp);
        dp[i][comprar] = max(vende, passa);
    }

    return dp[i][comprar];
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int val, tam;
        cin >> val >> tam;
        vector<int> arr;

        for(int j=0; j<tam; j++){
            int val;
            cin >> val;
            arr.push_back(val);
        }

        vector<vector<int>> dp(tam, vector<int>(2, -1));
        cout << valorMaximo(0, 1, arr, dp) + val << endl;
    }

    return 0;
}
   