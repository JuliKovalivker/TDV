#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<bool>> memo = {};
int m = 3;
int n = 3;

int camino_unico(vector<vector<int>> mapa, int m, int n, int i, int j){
    if (i <= 0 || j <= 0 || i >= m || j >= n || mapa[i][j] == 1){
        return 0;
    }
    else if (i == m-1 && j == n-1){
        return 1;
    }
    else if(!memo[i][j]){
        memo[i][j] = true;
        int op1 = camino_unico(mapa, m, n, i+1, j);
        int op2 = camino_unico(mapa, m, n, i, j+1);
        return op1 + op2;
    }
}

int main(){

    for (int i=0; i<m, i++){
        vector<bool> fila;
        for (int j=0; j<n; j++){
            fila.push_back(false)
        }
        memo.push_back(fila);
    }

    vector<vector<int>> mapa = [{0, 0, 0},
                                {0, 1, 0},
                                {0, 0, 0}];

    camino = camino_unico(mapa, m, n, 0, 0);
    cout << camino << endl;
}