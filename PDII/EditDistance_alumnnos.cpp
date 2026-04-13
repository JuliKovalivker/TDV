#include <bits/stdc++.h>
using namespace std;

bool yaCompute(int a){
	return a != -1;
}

int editDistance(string &s, string &t, int i, int j, vector<vector<int>> &memoizacion){
    // casos base
    if(i == 0) return j;
    if(j == 0) return i;

    if(yaCompute(memoizacion[i][j])){
        return memoizacion[i][j];
    }

    int sustituir = editDistance(s, t, i-1, j-1, memoizacion) + (s[i-1] != t[j-1]);
    int eliminar = editDistance(s, t, i-1, j, memoizacion) + 1;
    int agregar = editDistance(s, t, i, j-1, memoizacion) + 1;

    memoizacion[i][j] = min({sustituir, eliminar, agregar});
    return memoizacion[i][j];
}

char deDondeVine(int i, int j, vector <vector <int>> &memoizacion){
	if(i == 0){
		return '-';
	}
	else if(j == 0){
		return '|';
	}
	else{
		int eliminar = memoizacion[i-1][j] + 1;
		int agregar = memoizacion[i][j-1] + 1;
		if(memoizacion[i][j] == eliminar){
			return '|';
		}
		else if(memoizacion[i][j] == agregar){
			return '-';
		}
		else{
			return '\\';
		}
	}
}

// vector <char> recuperarSolucion(string &s, string &t, vector <vector <int>> &memoizacion, int i, int j){
	
	
// }

vector<char> recuperarSolucion(string &s, string &t, vector<vector<int>> &memoizacion){
    int i = s.size();
    int j = t.size();

    vector<char> res;

    while(i > 0 || j > 0){
        char mov = deDondeVine(i, j, memoizacion);
        res.push_back(mov);

        if(mov == '\\'){
            i--;
            j--;
        }
        else if(mov == '|'){
            i--;
        }
        else if(mov == '-'){
            j--;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}


int main(){
	string s,t;
	cin>>s>>t; // Lee dos strings por consola
	int n = s.size();
	int m = t.size();
	vector <vector <int > > memoizacion(n+1, vector <int> (m+1,-1)); // Creo una matriz de (m + 1) x (n + 1) inicializada en -1.
	int distance = editDistance(s, t, n, m, memoizacion);
	
	auto solucion = recuperarSolucion(s, t, memoizacion);
	for(int i = 0 ; i <= n; i++){
		for(int j = 0 ; j <= m; j++){
			cout<<editDistance(s,t,i,j,memoizacion)<<" ";
		}
		cout<<endl;
	}
	for(auto x: solucion){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<distance<<endl;
	return 0;
}
