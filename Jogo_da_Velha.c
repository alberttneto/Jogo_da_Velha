#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função imprimi jogo
void imprimiJogo(char jogo[][3]){

    int i,j;

    printf("    [1][2][3]\n");
    for(i = 0; i < 3; i++){
        printf("[%d] ", i+1);
        for(j = 0; j < 3; j++){
            printf("[%c]", jogo[i][j]);
        }
        printf("\n");
    }
}

// Função decidi jogada de acordo com valor que está no centro
int verificaCentro(char jogo[][3], char letra){

    if((jogo[0][0] == letra) && jogo[2][2] == ' '){
        jogo[2][2] = 'O';
        return 1;
    } else if((jogo[0][1] == letra) && jogo[2][1] == ' '){
        jogo[2][1] = 'O';
        return 1;
    } else if((jogo[0][2] == letra) && jogo[2][0] == ' '){
        jogo[2][0] = 'O';
        return 1;
    } else if((jogo[1][0] == letra) && jogo[1][2] == ' '){
        jogo[1][2] = 'O';
        return 1;
    } else if((jogo[1][2] == letra) && jogo[1][0] == ' '){
        jogo[1][0] = 'O';
        return 1;
    } else if((jogo[2][0] == letra) && jogo[0][2] == ' '){
        jogo[0][2] = 'O';
        return 1;
    } else if((jogo[2][1] == letra) && jogo[0][1] == ' '){
        jogo[0][1] = 'O';
        return 1;
    } else if((jogo[2][2] == letra) && jogo[0][0] == ' '){
        jogo[0][0] = 'O';
        return 1;
    } else{
        return 0;
    }
}

// Função decide jogada de acordo com lados
int verificaLados(char jogo[][3]){

    if(jogo[0][1] != ' ' && jogo[0][0] == jogo[0][1] && jogo[0][2] == ' '){
        jogo[0][2] = 'O';
        return 1;
    } else if (jogo[0][1] != ' ' && jogo[0][2] == jogo[0][1] && jogo[0][0] == ' '){
        jogo[0][0] = 'O';
        return 1;
    } else if (jogo[1][0] != ' ' && jogo[0][0] == jogo[1][0] && jogo[2][0] == ' '){
        jogo[2][0] = 'O';
        return 1;
    } else if (jogo[1][0] != ' ' && jogo[2][0] == jogo[1][0] && jogo[0][0] == ' '){
        jogo[0][0] = 'O';
        return 1;
    } else if (jogo[1][2] != ' ' && jogo[0][2] == jogo[1][2] && jogo[2][2] == ' '){
        jogo[2][2] = 'O';
        return 1;
    } else if (jogo[1][2] != ' ' && jogo[2][2] == jogo[1][2] && jogo[0][2] == ' '){
        jogo[0][2] = 'O';
        return 1;
    } else if (jogo[2][1] != ' ' && jogo[2][0] == jogo[2][1] && jogo[2][2] == ' '){
        jogo[2][2] = 'O';
        return 1;
    } else if (jogo[2][1] != ' ' && jogo[2][2] == jogo[2][1] && jogo[2][0] == ' '){
        jogo[2][0] = 'O';
        return 1;
    } else if (jogo[0][1] == ' ' && jogo[0][0] == jogo[0][2] && jogo[0][0] != ' '){
        jogo[0][1] = 'O';
        return 1;
    } else if (jogo[1][0] == ' ' && jogo[0][0] == jogo[2][0] && jogo[0][0] != ' '){
        jogo[1][0] = 'O';
        return 1;
    } else if (jogo[1][2] == ' ' && jogo[0][2] == jogo[2][2] && jogo[0][2] != ' '){
        jogo[1][2] = 'O';
        return 1;
    } else if (jogo[2][1] == ' ' && jogo[2][0] == jogo[2][2] && jogo[2][0] != ' '){
        jogo[2][1] = 'O';
        return 1;
    } else{
        return 0;
    }

}

// Função decide jogada de acordo com as pontas.
int verificaPontas(char jogo[][3]){

    if(jogo[2][0] == 'O' && jogo[0][2] == 'O'){
        jogo[1][1] = 'O';
        return 1;

    } else if(jogo[0][0] == 'O' && jogo[2][2] == 'O'){
        jogo[1][1] = 'O';
        return 1;

    }else if(jogo[2][0] == 'X' && jogo[0][2] == 'X'){
        jogo[1][1] = 'O';
        return 1;

    } else if(jogo[0][0] == 'X' && jogo[2][2] == 'X'){
        jogo[1][1] = 'O';
        return 1;
    }else {
        return 0;
    }
}


// Função inicia jogada da maquina
void iniciaM(char jogo[][3]){

    int i, j, vazio = 0, entrou = 0;

    for(i = 0 ; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(jogo[i][j] == ' '){
                vazio++;
            }
        }
    }

    // Variavel vazio determina que o usuario iniciou o jogo
    if(vazio == 8 && jogo[1][1] == ' '){
        jogo[1][1] = 'O';
        entrou = 1;
    }

    // Se a maquina não usou nenhuma das opções de jogo, joga no proximo campo vazio
    if(entrou == 0){

        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){

                if(jogo[i][j] == ' '){
                    jogo[i][j] = 'O';
                    entrou = 1;
                    break;
                }
            }
            if(entrou == 1){
                break;
            }
        }
    }
}

// Função verificar quem ganhou ou se deu velha
int verificaGanhador(char *venc, char jogo[][3]){

    int i, j, k, cont1, cont2, cont3, stop = 0, velha = 0;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){

            // Variaveis cont usadas para determina a sequencia igual de 3 resultados
            cont1 = cont2 = cont3 = 0;

            if(jogo[i][j] != ' '){
                velha++;
            }

            for(k = 0; k < 3; k++){
                if(jogo[i][j] == jogo[i][k] && k != j && jogo[i][j] != ' '){
                    cont1++;
                }
                if(jogo[i][j] == jogo[k][j] && k != i && jogo[i][j] != ' '){
                    cont2++;
                }
                if(jogo[i][j] == jogo[k][k] && k != i && k != j && jogo[i][j] != ' '){
                    cont3++;
                }
            }

            if(cont1 == 2 || cont2 == 2 || cont3 == 2){
                stop = 1;
                // Variavel venc recebe a letra do vencedor X ou O
                *venc = jogo[i][j];
                return 1;
                break;
            }
        }

         if(stop == 1){
            break;
        }
    }

    if(velha == 9){
        return 1;
    } else{
        return 0;
    }

}


char iniciaJogo( char jogo[][3], int joga, char nome[25]){

    char venc = 'V';
    int linha, coluna, termina = 0, entra;

    imprimiJogo(jogo);

    while(termina != 1){

       if(joga == 1){
            printf("\n");
            printf("Informe linha: ");
            scanf("%d",&linha);
            printf("Informe coluna: ");
            scanf("%d",&coluna);

            jogo[linha-1][coluna-1] = 'X';

            joga = 0;
            printf("== Jogada %s ==\n", nome);
            imprimiJogo(jogo);
            termina = verificaGanhador(&venc, jogo);
        }else{

            entra = 0;
            if(jogo[1][1] == 'X' || jogo[1][1] == 'O'){
                entra = verificaCentro(jogo, jogo[1][1]);
            } else if(jogo[1][1] == ' '){
                entra = verificaPontas(jogo);
            }

            if(entra == 0){
                entra = verificaLados(jogo);
            }
            if(entra == 0){
                iniciaM(jogo);
            }
            printf("== Jogada Robocop ==\n");
            imprimiJogo(jogo);
            termina = verificaGanhador(&venc, jogo);
            joga = 1;
        }
    }

    return venc;
}

int Quemcomeca(char nome[25]){

    int opcaoU, opcaoM, numU, numM, vence;
    srand(time(NULL));

    printf("Informe seu nome: ");
    gets(nome);


    numM = rand() % 10;
    printf("Escolha opcao: \n"
           "1 - Impar\n"
           "2 - Par\n");
    scanf("%d", &opcaoU);

    if(opcaoU == 1){
        printf("%s eh impar e Robocop eh par!\n", nome);
    }else{
        printf("%s eh par e Robocop eh impar!\n", nome);
        opcaoM = 2;
    }

    printf("Informe um numero de 0 a 10: ");
    scanf("%d", &numU);
    printf("Robocop escolheu %d\n", numM);

    if((numU + numM)%2 == 0){
        vence = 2;
    }else{
        vence = 1;
    }

    if(vence == opcaoU){
        printf("%s comeca!\n", nome);
        return 1;
    }else{
        printf("Robocop comeca!\n");
        return 0;
    }
}


int main(){

    char jogo[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, venc = ' ', nome[25];
    int joga;

    printf("====================================\n"
            "  ____________                      |\n"
            " /         ___| ################### |\n"
            "|_________//  | # EU SOU ROBOCOP ## |\n"
            " |_--__--_||| | ### VAMOS JOGAR? ## |\n"
            " /  ==       | |################### |\n"
            "|__________---| ################### |\n"
            " |   ----) | /  ################### |\n"
            "   ____-____/   ################### |\n"
            "_____|____|___                      |\n"
           "/ __________                        |\n"
           "  ##### #####                       |\n"
         "  ###    ###                        |\n"
         "==================================== \n");

    joga = Quemcomeca(nome);
    venc = iniciaJogo(jogo, joga, nome);

    if(venc == 'X'){
        printf("\n%s ganhou!!!!!!", nome);
    } else if( venc == 'O'){
        printf("\nRobocop ganhou!!!!");
    } else{
        printf("%c", venc);
        printf("\nDeu velha!");
    }

    return 0;
}

