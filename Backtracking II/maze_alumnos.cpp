#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int min_4(int a, int b, int c, int d){
    return min(a, min(b, min(c, d) ) );
}

int best = 100000000000000;  //poner infinito lol

int BT(vector<vector<bool>>& G, int i,int j,int k){
    if (i >= G[0].size() || j >= G.size() || i < 0 || j < 0 || k > G[0].size()*G.size() || !G[j][i]){
        return 10000000000000000;
    }
    else if (i == G[0].size() -1 && j == G.size()-1){
        return k;
    }
    else{
        int op1 = BT(G, i, j+1, k+1);
        int op2 = BT(G, i+1, j, k+1);
        int op3 = BT(G, i-1, j, k+1);
        int op4 = BT(G, i, j-1, k+1);
        int best_ac = min_4(op1, op2, op3, op4);
        if( best_ac < best){
            best = best_ac;
        }
        return best;
    }
}


int main() {
    vector<vector<bool>> G;

    vector<bool> aux(6,true);
    for(int i =0; i< 3 ; i++){
        for(int j =0;j<6;j++){
            if(j % 4 == 1 && i <2 ){
                aux[j]=false;
            }
            else if(j % 4 ==3 && i>0 ){
                aux[j]=false;
            }
        }
        G.push_back(aux);
    }
    G[2][1]=true;
    G[0][0]=true;
    int N = G.size();
    int M= G[0].size();
    G[N-1][M-1]=true;
    

    for(int i =0;i<N;i++){
        for(int j =0;j<M;j++){
            cout<< G[i][j] << "-";
        }
        cout<< endl;
    }
    
    std::cout <<  BT (G, 0,0,0)<< "\n";
}