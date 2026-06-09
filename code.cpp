#include <iostream>
using namespace std;

int main(){
    int n = 4;
    int matrizBloqueada [n][n], matrizIdentidade [n][n], matrizResposta [n][n], x = 1, mudanca = 0, randI, randJ;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            matrizIdentidade[i][j] = x;
            matrizResposta[i][j] = x;
            cout<<matrizIdentidade[i][j]<<" ";
        }
        x++;
        for(int j = 2; j < 4; j++){
            matrizIdentidade[i][j] = x;
            matrizResposta[i][j] = x;
            cout<<matrizIdentidade[i][j]<<" ";
        }
        x++;
        cout<<endl;
    }

    //Para randomizar os números

    for(int i = 0; i < 4; i ++){
        for(int j = 0; j <4; j++){
            randI = rand() % 3;
            randJ = rand() % 3;
            matrizResposta[randI][randJ] = matrizIdentidade[i][j];
            matrizResposta[i][j] = matrizIdentidade[randI][randJ];
            cout<<matrizResposta[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}