#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> // pro to_string - que converte int para string
using namespace std;

int main(){
    const int n = 4;
    int matrizIdentidade [n][n], matrizResposta [n][n], x = 1, randI, randJ, randIDois, randJDois, temp;
    string matrizBloqueada [n][n];
    int tentativas = 0, paresAcertados = 0;

    string cores[9] = {"", "\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[91m", "\033[93m"};
    string corReset = "\033[0m";

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            matrizIdentidade[i][j] = x;
            matrizResposta[i][j] = x;
        }
        x++;
        for(int j = 2; j < 4; j++){
            matrizIdentidade[i][j] = x;
            matrizResposta[i][j] = x;
        }
        x++;
    }

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
            matrizBloqueada[i][j] = "*";
        }
    }

    int chuteI, chuteJ, chuteIdois, chuteJDois;

    while (paresAcertados < 8){
    // Loop principal do jogo, o jogador continua jogando até encontrar todos os pares.
        cout << "\033[33mPares encontrados: " << paresAcertados << "/8\033[0m  |  \033[36mTentativas: " << tentativas << "\033[0m" << endl;

        cout<<"  | 1 | 2 | 3 | 4 |"<<endl;
        for (int i = 0; i < 4; i ++){
            cout<<(i + 1);
            for (int j = 0; j < 4; j++){
                if (matrizBloqueada[i][j] == "*"){
                    cout<<"| "<<matrizBloqueada[i][j]<<" ";
                } else {
                    cout<<"| "<<cores[matrizResposta[i][j]]<<matrizBloqueada[i][j]<<corReset<<" ";
                }
            }
            cout<<"|"<<endl;
        }

        cout<<endl<<"Digite as cordenadas da primeira carta a virar: "<<endl;
        cout<<"Linha: ";
        cin>>chuteI;
        cout<<"Coluna: ";
        cin>>chuteJ;

        matrizBloqueada[chuteI - 1][chuteJ - 1] = to_string(matrizResposta[chuteI - 1][chuteJ - 1]);

        cout<<"  | 1 | 2 | 3 | 4 |"<<endl;
        for (int i = 0; i < 4; i ++){
            cout<<(i + 1);
            for (int j = 0; j < 4; j++){
                if (matrizBloqueada[i][j] == "*"){
                    cout<<"| "<<matrizBloqueada[i][j]<<" ";
                } else {
                    cout<<"| "<<cores[matrizResposta[i][j]]<<matrizBloqueada[i][j]<<corReset<<" ";
                }
            }
            cout<<"|"<<endl;
        }

        cout<<endl<<"Digite as cordenadas da segunta carta a virar: "<<endl;
        cout<<"Linha: ";
        cin>>chuteIdois;
        cout<<"Coluna: ";
        cin>>chuteJDois;

        matrizBloqueada[chuteIdois - 1][chuteJDois - 1] = to_string(matrizResposta[chuteIdois - 1][chuteJDois - 1]);

        cout<<"  | 1 | 2 | 3 | 4 |"<<endl;
        for (int i = 0; i < 4; i ++){
            cout<<(i + 1);
            for (int j = 0; j < 4; j++){
                if (matrizBloqueada[i][j] == "*"){
                    cout<<"| "<<matrizBloqueada[i][j]<<" ";
                } else {
                    cout<<"| "<<cores[matrizResposta[i][j]]<<matrizBloqueada[i][j]<<corReset<<" ";
                }
            }
            cout<<"|"<<endl;
        }

        tentativas++;

        if (matrizResposta[chuteI - 1][chuteJ - 1] == matrizResposta[chuteIdois - 1][chuteJDois - 1]){
            matrizBloqueada[chuteI - 1][chuteJ - 1] = " ";
            matrizBloqueada[chuteIdois - 1][chuteJDois - 1] = " ";
            paresAcertados++;
            cout<<"\033[32mParabéns! Você acertou!\033[0m"<<endl;
        }else{
            matrizBloqueada[chuteI - 1][chuteJ - 1] = "*";
            matrizBloqueada[chuteIdois - 1][chuteJDois - 1] = "*";
            cout<<"\033[31mQue pena! Parece que você não acertou...\033[0m"<<endl;
        }
    }

    cout << endl << "Parabéns! Você encontrou todos os pares em " << tentativas << " tentativas!" << endl;

    return 0;
}