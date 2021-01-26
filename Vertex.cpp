#include<bits/stdc++.h>
#define NOT_VISITED 0
using namespace std;

void dfs(int nodoA, vector<vector<int>> adjlist, vector<int> &visitado){
    //Toma un vector de bool con los nodos visitados, inicialmente todos false
    visitado[nodoA]++;
    for(int i=0;i<adjlist[nodoA].size();i++){
        int vecino = adjlist[nodoA][i];
        if(visitado[vecino]==NOT_VISITED || (nodoA==vecino && visitado[vecino]==1)){
            dfs(vecino, adjlist, visitado);
        }
    }
}

int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0)break;
        vector<vector<int>> adjList(n,vector<int>());
        while(true){
            int nodo1;
            cin>>nodo1;
            if(nodo1==0)break;
            nodo1--;
            while(true){
                int nodo2;
                cin>>nodo2;
                if(nodo2==0)break;
                nodo2--;
                adjList[nodo1].push_back(nodo2);
            }
        }
        
        int nvertex;
        cin>>nvertex;
        for(int i=0;i<nvertex;i++){
            int vertex;
            cin >> vertex;
            vertex--;
            vector<int> visitados (n,NOT_VISITED);
            dfs(vertex,adjList,visitados);

            vector<int> no_visitados;
            for(int k=0;k<n;k++){
                if(visitados[k]==NOT_VISITED){
                    no_visitados.push_back(k+1);
                }
            }
            cout << no_visitados.size();
            for(auto a:no_visitados){
                cout << " "<<a;
            }cout << endl;
        }    
    }
}
