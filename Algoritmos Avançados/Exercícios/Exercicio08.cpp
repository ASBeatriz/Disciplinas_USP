#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// int valMaximo(int ini, int fim, vector<int> arr, vector<vector<int>> dp){
//     // caso base
//     if(ini > fim) return 0;

//     // verifica se já foi calculado
//     if(dp[ini][fim] =! -1) return dp[ini][fim];

//     int valMax1 = arr[ini] + min(valMaximo(ini+2, fim, arr, dp), valMaximo(ini+1, fim-1, arr, dp));
//     int valMax2 = arr[fim] + min(valMaximo(ini+1, fim-1, arr, dp), valMaximo(ini, fim-2, arr, dp));

//     return(max(valMax1, valMax2));
// }

// entender o que ta acontecendo aqui (https://www.geeksforgeeks.org/dsa/optimal-strategy-for-a-game-dp-31/)

int valMaximo(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n,0));

    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {

            int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;

            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
}

int main() {
    int c;
    cin >> c;
    for(int i=0; i<c; i++){
        vector<int> arr;

        int n;
        cin >> n;
        for (int j = 0; j < n; j++){
            string s;
            cin >> s;
            auto pos = s.find(',');
            int n1 = stoi(s.substr(1,pos));
            int n2 = stoi(s.substr(pos+1,s.length()-1));
            arr.push_back(n1+n2);
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int res = valMaximo(arr);
        cout << res << endl;
    }
}