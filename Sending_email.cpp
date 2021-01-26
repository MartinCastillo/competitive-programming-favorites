#include<bits/stdc++.h>
using namespace std;
#define INF LONG_MAX
typedef pair<long,long> pii;
typedef vector<long> vi;

void djk(vector<vector<pii>> adjList, vi &dist, int nodoInicial){
    priority_queue<pii,vector<pii>,std::greater<pii>> cola;
    pii nodo = make_pair(0,nodoInicial);
    cola.push(nodo);
    dist[nodoInicial]=0;
    while(!cola.empty()){
        nodo = cola.top();
        cola.pop();
        if(nodo.first > dist[nodo.second]) continue;
        for(int j=0;j<adjList[nodo.second].size();j++){
            int vecino = adjList[nodo.second][j].first;
            int costo = adjList[nodo.second][j].second;
            //La suma(El nuevo camino) supera lo que ya hay
            if(costo + dist[nodo.second] >= dist[vecino]) continue;
            else{
                dist[vecino] = costo + dist[nodo.second];
                cola.push(make_pair(dist[vecino],vecino));
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    for(int j = 0;j<N;j++){
        int n,m,s,t;
        cin >>n>>m>>s>>t;
        vector<vector<pii>> adjList(n,vector<pii>());
        //Leer
        for(int k=0;k<m;k++){
            int s1,s2,w;
            cin>>s1>>s2>>w;
            adjList[s1].push_back(make_pair(s2,w));
            adjList[s2].push_back(make_pair(s1,w));
        }
        vi dist (n,INF);
        //Entre s y t
        djk(adjList,dist,t);
        printf("Case #%d: ",j+1);
        if(dist[s]==INF) cout << "unreachable";
        else cout << dist[s];
        cout << endl;
    }
}
