#include<bits/stdc++.h>
using namespace std;
#define NOT_VISITED false
#define VISITED true
vector<vector<int>> adjlist;
vector<bool> visitado;
void dfs(int nodoA){
    visitado[nodoA]=VISITED;
    for(int i=0;i<adjlist[nodoA].size();i++){
        int vecino = adjlist[nodoA][i];
        if(visitado[vecino]==NOT_VISITED){
            dfs(vecino);
        }
    }
}
int main(){
    int t,n;
    string val;
    char max;
    cin >> t;
    cin.ignore();
    cin.ignore();
    for(int i = 0; i<t; i++){
        while(getline(cin,val)){
            if(val.size()==0 || val=="quit")break;
            if(val.size()==1){
                n = (int)val[0]-64;
                adjlist.assign(n,vector<int>());
                visitado.assign(n,false);
            }
            if(val.size()==2){
                int x,y;
                x = (int)val[0]-65;
                y = (int)val[1]-65;
                adjlist[x].push_back(y);
                adjlist[y].push_back(x);
            }
        }
        int c=0;
        for(int iter=0;iter<n;iter++){
            if(visitado[iter]==NOT_VISITED){
                c++;
                dfs(iter);
            }
        }
        cout << c << endl;
        if(i!=t-1)cout<<endl;
    }
}
