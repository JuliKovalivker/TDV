#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>

using namespace std;




int cast_to_int(vector<int>& M){
    int res=0;
    for(int i =0; i<M.size();i++){
        res+= M[M.size()-1-i] * pow(10, i) ;
    }
    return res;
}

int FB(vector<int>& A, int c){
	
}

vector<int> min_max_pos(vector<int> A, vector<bool> used){
    int min = 0;
    int max = 0;
    bool found = false;
    for(int i = 0; i < A.size() && !found; i++){
        if(used[i]){
            min = i;
            max = i;
            found = true;
        }
    }
    for(int i = 0; i < A.size(); i++){
        if(used[i]){
            if(A[min] > A[i]){
                min = i;
            }
            if(A[max] < A[i]){
                max = i;
            }
        }
    }
    return {min, max};
}

int BT_rec(vector<int> &A, int c, vector<bool> used){
	if (c <= 0){
        return cast_to_int(A);
    }
    vector<int> min_max = min_max_pos(A, used);
    int min = min_max[0];
    int max = min_max[1];
    swap(A[max], A[min]);
    used[min] = false;
    used[max] = false;
    return BT_rec(A, c-1, used);
}

int BT(vector<int>& A, int c){
    vector<bool> used(A.size(), true);
    return BT_rec(A, c, used);
}


int main() {
    vector<int> M;
    int k=3;
    for(int i =0; i< 9; i++){
        M.push_back(9-i);
        cout<< M[i] << "-";
    }
    cout<< endl;

    
    auto start = chrono::steady_clock::now();
    
    std::cout <<  FB (M,k)<< "\n";

    auto end = chrono::steady_clock::now();

    cout << "Elapsed time FB: "<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " µs" << endl;

    start = chrono::steady_clock::now();
    
    std::cout <<  BT (M,k)<< "\n";

    end = chrono::steady_clock::now();

    cout << "Elapsed time BT: "<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " µs" << endl;
    
}