#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int,int> pii;
typedef vector<int> vi;
void dijkstra(vector<vector<pii>> adjList,vi &distance, int initialNode){
    priority_queue<pii, vector<pii>, std::greater<pii> > cola;
    //Costo de camino nodo y nodo
    pii nodo = make_pair(0,initialNode);
    distance[initialNode]=0;
    cola.push(nodo);
    while(!cola.empty()){
        nodo = cola.top();
        cola.pop();
        for(auto nodo_costo: adjList[nodo.second]){
            int vecino = nodo_costo.first;
            int costo = nodo_costo.second;
            if(costo+distance[nodo.second] > distance[vecino])continue;
            else{
                distance[vecino] = costo+distance[nodo.second];
                cola.push(make_pair(distance[vecino],vecino));
            }
        }
    }
}

int main(){
    int t;
    cin>>t;//1 a N
    for(int j =0;j<t;j++){
        int N,E,T,M;
        //Cells,Exit,Time,Conections
        cin>>N>>E>>T>>M;
        E--;
        vector<vector<pii>> maze(N,vector<pii>());
        for(int k=0;k<M;k++){
            int a,b,w;
            cin>>a>>b>>w;
            a--;
            b--;
            maze[a].push_back(make_pair(b,w));
            maze[b].push_back(make_pair(a,w));
        }
        int c=0;
        for(int k=0;k<N;k++){
            vi times (N,INF);
            dijkstra(maze,times,k);
            if(times[E] <= T) c++;
        }
        cout << c<<endl;
        if(j!=t-1) cout << endl;
    }
}
