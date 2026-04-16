#include <bits/stdc++.h>
using namespace std;


bool canVisitAllNodes(vector<vector<int> >& arr, int X, int n)
{
    queue<int> q;
    vector<int> visited(n, false);
    q.push(X);
    visited[X] = true;
    int count = 0;
    while(q.size() > 0){
        int size = q.size();
        for(int i = 0; i<size; i++){
            auto curr = q.front();
            q.pop();
            count++;
            for(auto j : arr[curr]){
                if (visited[j] == false){
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    return count == n;
}

// Driver code
int main()
{
    vector<vector<int> > arr
        = { { 1, 2 }, { 0, 3, 2 }, { 0, 1 }, { 1 } };
    int N = 4, X = 0;

    // Function Call
    if (canVisitAllNodes(arr, X, N)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
