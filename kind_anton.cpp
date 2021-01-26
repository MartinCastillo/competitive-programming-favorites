#include <bits/stdc++.h>
using namespace std;
int main(){
    //tests
    int tests; cin >> tests;
    for(int _ = 0; _<tests;_++){
        //n
        int n; cin >> n;
        vector<int> A;
        vector<int> B;
        int aux;
        bool posible = true;
        for(int i=0; i<n; i++){
            cin >> aux;
            A.push_back(aux);
        }
        for(int i=0; i<n; i++){
            cin >> aux;
            B.push_back(aux);
        }
        //Hacer mapa de A
        map<int,int> set_A = {pair<int,int>(-1,0),pair<int,int>(1,0),pair<int,int>(0,0)};
        for(auto a: A){
            set_A[a]++;
        }
        //Recorrer B inversamente
        for(int i = A.size()-1; i >= 0 ; i--){
            //Descuenta de B, ya lo pasó
            set_A[A[i]]--;
            if(B[i]>A[i]){//Debe sumar (1 en map)
                if(set_A[1]==0){
                    posible = false; break;
                }
            }
            if(B[i]<A[i]){
                if(set_A[-1]==0){
                    posible = false; break;
                }
            }
        }
        if(posible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
