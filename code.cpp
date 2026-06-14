#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    const int n = 4;
    int matrizIdentidade [n][n], matrizResposta [n][n], x = 1, randI, randJ, randIDois, randJDois, temp;
    string matrizBloqueada [n][n]; 

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

    cout<<"----------------------"<<endl;

    //Para randomizar os números

    srand(time(0));

    int totalElementos = n * n;

    for (int k = totalElementos - 1; k > 0; k--){
        randI = k / n;
        randJ = k % n;

        int sorteado = rand() % (k + 1);
        randIDois = sorteado / n;
        randJDois = sorteado % n;

        temp = matrizResposta[randI][randJ];
        matrizResposta[randI][randJ] = matrizResposta[randIDois][randJDois];
        matrizResposta[randIDois][randJDois] = temp;
    }

    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j++){
            cout<<matrizResposta[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j++){
            matrizBloqueada[i][j] = "*";
        }
    }
    

    cout<<"----------- Teste para o jogo em si (O que vai ser revelado) --------------"<<endl;

    cout<<"  | 1 | 2 | 3 | 4 |"<<endl;

    for (int i = 0; i < 4; i ++){
        cout<<(i + 1);
        for (int j = 0; j < 4; j++){
            cout<<"| "<<matrizBloqueada[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }

    int chuteI, chuteJ, chuteIdois, chuteJDois;
    cout<<endl<<"Digite as cordenadas da primeira carta a virar: "<<endl;
    cout<<"Linha: ";
    cin>>chuteI;
    cout<<"Coluna: ";
    cin>>chuteJ;

    matrizBloqueada[chuteI - 1][chuteJ - 1] = matrizResposta[chuteI - 1][chuteJ - 1];

    cout<<"  | 1 | 2 | 3 | 4 |"<<endl;

    for (int i = 0; i < 4; i ++){
        cout<<(i + 1);
        for (int j = 0; j < 4; j++){
            cout<<"| "<<matrizBloqueada[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }    


    cout<<endl<<"Digite as cordenadas da segunta carta a virar: "<<endl;
    cout<<"Linha: ";
    cin>>chuteIdois;
    cout<<"Coluna: ";
    cin>>chuteJDois;

    matrizBloqueada[chuteIdois - 1][chuteJDois - 1] = matrizResposta[chuteIdois - 1][chuteJDois - 1];

    cout<<"  | 1 | 2 | 3 | 4 |"<<endl;

    for (int i = 0; i < 4; i ++){
        cout<<(i + 1);
        for (int j = 0; j < 4; j++){
            cout<<"| "<<matrizBloqueada[i][j]<<" ";
        }
        cout<<"|"<<endl;
    }

    if (matrizBloqueada[chuteI][chuteJ] == matrizBloqueada[chuteIdois][chuteJDois]){
        matrizBloqueada[chuteI][chuteJ] = " ";
        matrizBloqueada[chuteIdois][chuteJDois] = " ";
        cout<<"Parabéns! Você acertou!"<<endl;
    }else{
        matrizBloqueada[chuteI][chuteJ] = "*";
        matrizBloqueada[chuteIdois][chuteJDois] = "*";
        cout<<"Que pena! Parece que você não acertou..."<<endl;
    }

    return 0;
}