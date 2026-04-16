#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU
{
    vector<int> id;
    DSU(int n)
    {
        id.resize(n);
        for (int i = 0; i < n; i++)
        {
            id[i] = i;
        }
    }

    void conectar_nodos(int v, int w)
    {
        v = representante(v);
        w = representante(w);
        if (v == w)
            return;
        id[w] = v;
    }

    bool estan_en_la_misma_componente(int v, int w)
    {
        return representante(v) == representante(w);
    }
    int representante(int v)
    {
        if (id[v] == v)
            return v;
        id[v] = representante(id[v]);
        return id[v];
    }
};

struct Arista
{
    int v, w, costo;
    bool operator<(Arista b)
    {
        return costo < b.costo;
    }
};

int distribucion_de_agua(int n, vector<int> p, vector<vector<int>> c)
{
    /*
     * n es la cantidad de casas
     * p[i] es el costo de contruir un pozo en la casa i
     * c[i][j] es el costo de construir una cañeria entre i y j
    */

    vector<Arista> aristas = {};
    DSU AGM = DSU(n + 1);

    for(int i = 0; i < c.size(); i++){
        for(int j = i; j < c[0].size(); j++){
            Arista arista = Arista();
            arista.v = i;
            arista.w = j;
            arista.costo = c[i][j];
            aristas.push_back(arista);
        }
    }

    for(int i = 0; i < c.size(); i++){
        Arista arista = Arista();
        arista.v = i;
        arista.w = c.size();
        arista.costo = p[i];
        aristas.push_back(arista);
    }

    sort(aristas.begin(), aristas.end()); 

    int counter = 0;
    int i = 0;
    int peso = 0;
    while (counter < n && i < aristas.size()){
        if (!AGM.estan_en_la_misma_componente(aristas[i].v, aristas[i].w)){
            AGM.conectar_nodos(aristas[i].v, aristas[i].w);
            counter++;
            peso += aristas[i].costo;
        }
        i++;
    }
    return peso;
}

int main()
{
    // Ejemplo
    cout << distribucion_de_agua(3, {1, 2, 2}, {{0, 1, 2}, {1, 0, 3}, {2, 3, 0}}) << endl;
}
