#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


struct matriz_a{ //VARIAVEIS LIGADAS A MATRIZ A
    float mat1[50][50];
    int l1;
    int c1;
    int ht1;
    int ht1s;
    int ht1e;
    int mat1check;
};

struct matriz_b{ //VARIAVEIS LIGADAS A MATRIZ B
    float mat2[50][50];
    int l2;
    int c2;
    int ht2;
    int ht2s;
    int ht2e;
    int mat2check;
};

struct matriz_c{ //VARIAVEIS LIGADAS A MATRIZ C
    float mat3[50][50];
    int l3;
    int c3;
};

struct matriz_a mata;
struct matriz_b matb;
struct matriz_c matc;

void menu(){                    //ESTRUTURA BASICA DO MENU DO PROGRAMA
    system("cls");
    printf("\n== MENU PRINCIPAL ==\n\n");
    printf("Escolha a opcao que voce deseja realizar\n"
           "(Definir os parametros das matrizes A e B antes de realizar qualquer outra operacao)\n\n"
           "> 1 - Limpar todas as matrizes\n"
           "> 2 - Definir os parametros da matriz A\n"
           "> 3 - Definir os parametros da matriz B\n"
           "> 4 - Soma          \n"
           "> 5 - Subtracao     \n"
           "> 6 - Multiplicacao \n"
           "> 7 - Sair do programa\n\n");
    printf("Digite a operacao que voce deseja realizar  > ");
}

void matclear(){                //ZERA TODAS AS MATRIZES
    /*Atribue 0 a todos os valores da matriz A*/
    int i, j;
    for(i=0; i<mata.l1; i++){
        for(j=0; j<mata.c1; j++){
            mata.mat1[i][j]=0;
        }
    }
    /*Atribue 0 a todos os valores da matriz B*/
    for(i=0; i<matb.l2; i++){
        for(j=0; j<matb.c2; j++){
            matb.mat2[i][j]=0;
        }
    }
    /*Atribue 0 a todos os valores da matriz resultante C*/
    for(i=0; i<matc.l3; i++){
        for(j=0; j<matc.c3; j++){
            matc.mat3[i][j]=0;
        }
    }
    /*Mostra uma mensagem falando que a operação foi realizada seguida de uma instrução*/
    printf("Todas as matrizes foram zeradas");
    printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
}

void mat1print(){               //FAZ A IMPRESSÃO DA MATRIZ A NA TELA
    printf("==> Matriz A:\n\n");
    int i, j;
    for(i=0; i<mata.l1; i++){
        for(j=0; j<mata.c1; j++){
            printf("%.2f ", mata.mat1[i][j]);
        }
        printf("\n");
    }
}

void mat2print(){               //FAZ A IMPRESSÃO DA MATRIZ B NA TELA
    printf("==> Matriz B:\n\n");
    int i, j;
    for(i=0; i<matb.l2; i++){
        for(j=0; j<matb.c2; j++){
            printf("%.2f ", matb.mat2[i][j]);
        }
        printf("\n");
    }
}

void mat3print(){               //FAZ A IMPRESSÃO DA MATRIZ C NA TELA
    printf("==> Matriz C:\n\n");
    int i, j;
    for(i=0; i<matc.l3; i++){
        for(j=0; j<matc.c3; j++){
            printf("%.2f ", matc.mat3[i][j]);
        }
        printf("\n");
    }
}

void mat1parameters(){          //RECEBE OS DADOS DA MATRIZ A
    int i, j;
    printf("Defina o tamanho da matriz A (Matriz com tamanho igual ou menor que 50x50):\n\n"
           ">Quantidade de linhas:  ");
    scanf("%d", &mata.l1);                   //RECEBE O NUMERO DE LINHAS DE A
    printf(">Quantidade de colunas: ");
    scanf("%d", &mata.c1);                   //RECEBE O NUMERO DE COLUNAS DE A
    if(mata.l1>0&&mata.l1<51&&mata.c1>0&&mata.c1<51){
    /*CASO O NUMERO DE LINHAS E COLUNAS ESTEJA ENTRE O VALOR MIN~MAX PERMITIDO PROSEGUE
      COM O RECEBIMENTO DE DADOS DA MATRIZ A. SE O USUARIO SELECIONAR PARA GERAR VALORES
      RANDOMICOS PARA A MATRIZ A, ELE TEM QUE DETERMINAR EM SEGUIDA A FAIXA DE VALORES
      ONDE OS NUMEROS RANDOMICOS ESTARÃO, CASO SELECIONE PARA PREENCHER MANUALMENTE, O
      USUARIO TERÁ DE ESPECIFICAR O VALOR DE CADA CÉLULA*/
    printf("\nDe qual forma voce deseja preencher a matriz?\n"
           "> 1 - Randomicamente\n"
           "> 2 - Manualmente (Caractere por caractere)\n");
    scanf("%d", &mata.ht1);
    if(mata.ht1==1){
        printf("Digite a faixa de valores para gerar a os numeros da matriz\n\n");
        printf("Valor inicial:  ");
        scanf("%d", &mata.ht1s);
        printf("Valor final:    ");
        scanf("%d", &mata.ht1e);
        srand(time(NULL));
        for(i=0; i<mata.l1; i++){
            for(j=0; j<mata.c1; j++){
                mata.mat1[i][j] = mata.ht1s + (rand()%(mata.ht1e - mata.ht1s + 1));
            }
        }
    }else{
        if(mata.ht1==2){
            printf("Digite os valores da matriz A, um por um:\n\n");
            for(i=0; i<mata.l1; i++){
                for(j=0; j<mata.c1; j++){
                    printf("Linha [%d], Coluna [%d]:    ", i+1, j+1);
                    scanf("%f", &mata.mat1[i][j]);
                }
            }
        }else{
            printf("voce nao escolheu uma opcao valida");
        }
    }

    printf("\n\n");                 //PRINTA 2 QUEBRAS DE LINHA
    mat1print();                    //MOSTRA A MATRIZ "A" QUE FOI ESPECIFICADA EM MAT1PARAMETERS


    }else{
        printf("por favor atribua valores entre 1 e 50 para o numero de linhas e colunas");
    }
}

void mat2parameters(){          //RECEBE OS DADOS DA MATRIZ B
    int i, j;
    printf("Defina o tamanho da matriz B (Matriz com tamanho igual ou menor que 50x50):\n\n"
           ">Quantidade de linhas:  ");
    scanf("%d", &matb.l2);
    printf(">Quantidade de colunas: ");
    scanf("%d", &matb.c2);
    if(matb.l2>0&&matb.l2<51&&matb.c2>0&&matb.c2<51){
    /*CASO O NUMERO DE LINHAS E COLUNAS ESTEJA ENTRE O VALOR MIN~MAX PERMITIDO PROSEGUE
      COM O RECEBIMENTO DE DADOS DA MATRIZ B. SE O USUARIO SELECIONAR PARA GERAR VALORES
      RANDOMICOS PARA A MATRIZ B, ELE TEM QUE DETERMINAR EM SEGUIDA A FAIXA DE VALORES
      ONDE OS NUMEROS RANDOMICOS ESTARÃO, CASO SELECIONE PARA PREENCHER MANUALMENTE, O
      USUARIO TERÁ DE ESPECIFICAR O VALOR DE CADA CÉLULA*/
    printf("\nDe qual forma voce deseja preencher a matriz?\n"
           "> 1 - Randomicamente\n"
           "> 2 - Manualmente (Caractere por caractere)\n");
    scanf("%d", &matb.ht2);
    if(matb.ht2==1){
        printf("Digite a faixa de valores para gerar a os numeros da matriz\n\n");
        printf("Valor inicial:  ");
        scanf("%d", &matb.ht2s);
        printf("Valor final:    ");
        scanf("%d", &matb.ht2e);
        srand(time(NULL));
        for(i=0; i<matb.l2; i++){
            for(j=0; j<matb.c2; j++){
                matb.mat2[i][j] = matb.ht2s + (rand()%(matb.ht2e - matb.ht2s + 1));
            }
        }
    }else{
        if(matb.ht2==2){
            printf("Digite os valores da matriz B, um por um:\n\n");
            for(i=0; i<matb.l2; i++){
                for(j=0; j<matb.c2; j++){
                    printf("Linha [%d], Coluna [%d]:   ", i+1, j+1);
                    scanf("%f", &matb.mat2[i][j]);
                }
            }
        }else{
            printf("voce nao escolheu uma opcao valida");
        }
    }

    printf("\n\n");                 //PRINTA 2 QUEBRAS DE LINHA
    mat2print();                    //MOSTRA A MATRIZ "B" QUE FOI ESPECIFICADA EM MAT2PARAMETERS

    }else{
        printf("por favor atribua valores entre 1 e 50 para o numero de linhas e colunas");
    }
}

void matsoma(){                 //FAZ A SOMA DAS MATRIZES
    /*COMPARA AS LINHAS E COLUNAS DE A E B, SE FOREM IGUAIS A SOMA EH FEITA, CASO NÃO SEJA MOSTRA UMA MENSAGEM DE ERRO*/
    int i, j;
    if((mata.l1==matb.l2)&&(mata.c1==matb.c2)){
        matc.l3=mata.l1;
        matc.c3=mata.c1;
        for(i=0; i<mata.l1; i++){
            for(j=0; j<mata.c1; j++){
                matc.mat3[i][j] = mata.mat1[i][j] + matb.mat2[i][j];
            }
        }
        printf("SOMA DA FORMA (A + B) RESULTANDO UMA MATRIZ C");
        printf("\n\n");
        mat1print();
        printf("\n");
        mat2print();
        printf("\n");
        mat3print();
    }else{
        printf("Nao e possivel realizar a soma de matrizes com numero de linhas ou colunas diferentes");
    }
}

void matsubtracao(){            //FAZ A SUBTRAÇÃO DAS MATRIZES
    /*COMPARA O TAMANHO DAS MATRIZES A E B, CASO SEJAM IGUAIS SERÁ PERGUNTADO DE QUAL FORMA SESEJA REALIZAR A OPERAÇÃO
    A-B=C OU B-A=C*/
    int sm;
    int i, j;

    if((mata.l1==matb.l2)&&(mata.c1==matb.c2)){
        printf("De qual forma voce deseja realizar a subtracao?\n"
               "> 1 - (A - B)\n"
               "> 2 - (B - A)\n");
        scanf("%d", &sm);
        if(sm==1){
            for(i=0; i<mata.l1; i++){
                for(j=0; j<mata.c1; j++){
                    matc.mat3[i][j] = mata.mat1[i][j] - matb.mat2[i][j];
                }
            }
            printf("SUBTRACAO DA FORMA (A - B) RESULTANDO EM C");
            printf("\n\n");
            mat1print();
            printf("\n");
            mat2print();
            printf("\n");
            mat3print();
        }else{
            if(sm==2){
                for(i=0; i<mata.l1; i++){
                    for(j=0; j<mata.c1; j++){
                        matc.mat3[i][j] = matb.mat2[i][j] - mata.mat1[i][j];
                    }
                }
                printf("SUBTRACAO DA FORMA (B - A) RESULTANDO EM C");
                printf("\n\n");
                mat2print();
                printf("\n");
                mat1print();
                printf("\n");
                mat3print();
            }else{
                printf("Voce nao escolheu uma opcao valida!");
            }
        }
    }else{
        printf("Nao e possivel realizar a subtracao de matrizes com numero de linhas e colunas diferentes");
    }
    matc.l3=mata.l1;
    matc.c3=mata.c1;
}

void multab(){                  //FAZ A MULTIPLICAÇÃO DE A * B
    float multabresult;
    int i, j, y;

    for (i=0; i<mata.l1; i++) {
        for (j=0; j<matb.c2; j++) {
            multabresult=0;
            for (y=0; y<mata.c1; y++) {
                multabresult=multabresult+(mata.mat1[i][y]*matb.mat2[y][j]);
            }
            matc.mat3[i][j]= multabresult;
        }
    }
    mat1print();
    printf("\n\n");
    mat2print();
    printf("\n\n");
    mat3print();
}

void multba(){                  //FAZ A MULTIPLICAÇÃO DE B * A
    float multbaresult;
    int i, j, y;

    for (i=0; i<matb.l2; i++) {
        for (j=0; j<mata.c1; j++) {
            multbaresult=0;
            for (y=0; y<matb.c2; y++) {
                multbaresult=multbaresult+(matb.mat2[i][y]*mata.mat1[y][j]);
            }
            matc.mat3[i][j]= multbaresult;
        }
    }

    mat2print();
    printf("\n\n");
    mat1print();
    printf("\n\n");
    mat3print();
}

void matmultiplicacao(){        //ANALIZA AS MATRIZES A E B, EM SEGUIDA DETERMINA DE QUE FORMA PODE SER FEITA A MULTIPLICAÇÃO
    /*ANALIZA O FORMATO DAS MATRIZES A E B, SE FOREM COMPATIVEIS PARA REALIZAR A MULTIPLICAÇÃO DE ALGUMA FORMA
     O PROGRAMA DARA ESSA OPÇÃO.
     1º CASO - SE O NUMERO COLUNA DE A E O NUMERO DE LINHAS DE B FOREM IGUAIS E O NUMERO DE LINHAS DE A FOR
     DIFERENTE DO NUMERO DE COLUNAS DE B O PROGRAMA FAZ A MULTIPLICAÇÃO A*B DE FORMA DIRETA
     2º CASO - SE O NUMERO COLUNA DE B E O NUMERO DE LINHAS DE A FOREM IGUAIS E O NUMERO DE LINHAS DE B FOR
     DIFERENTE DO NUMERO DE COLUNAS DE A O PROGRAMA FAZ A MULTIPLICAÇÃO B*A DE FORMA DIRETA
     3º CASO - CASO AS MATRIZES SEJAM AMBAS QUADRADAS COM NUMEROS DE LINHAS E COLUNAS IGUAIS OFERECE AO USUARIO
    A OPÇÃO DE FAZER A MULTIPLICAÇÃO A*B OU B*A */
    int mm;

    if((mata.l1==matb.c2)||(mata.c1==matb.l2)){
        if((mata.c1==matb.l2)&&(matb.c2!=mata.l1)){
            printf("Com as especificacoes de A e B so eh possivel realizar uma multiplicacao do formato C = A * B\n\n");
            matc.l3=mata.l1;
            matc.c3=matb.c2;
            multab();
        }else{
            if((mata.c1!=matb.l2)&&(matb.c2==mata.l1)){
                printf("Com as especificacoes de A e B so eh possivel realizar uma multiplicação do formato C = B * A\n\n");
                matc.l3=matb.l2;
                matc.c3=mata.c1;
                multba();
            }else{
                printf("De qual forma voce deseja realizar a multiplicacao?\n"
                       "> 1 - A * B\n"
                       "> 2 - B * A\n");
                scanf("%d", &mm);
                if(mm==1){
                    matc.l3=mata.l1;
                    matc.c3=matb.c2;
                    printf("\n\n");
                    multab();
                }else{
                    if(mm==2){
                        matc.l3=matb.l2;
                        matc.c3=mata.c1;
                        printf("\n\n");
                        multba();
                    }else{
                        printf("Voce nao escolheu uma opcao valida!");
                    }
                }
            }
        }
    }else{
        printf("As matrizes nao sao compativeis para realizar a multiplicacao!\n\n"
               "Lembre-se que para realizar uma multiplicacao entre duas matrizes,\n"
               "o numero de culunas de uma das matrizes deve ser igual ao numero de\n"
               "linhas da outra");

    }
}

int main(void){                 //PROGRAMA PARA O GERENCIAMENTO DAS FUNÇÕES
    int opt;
    do{
        menu();
        scanf("%d", &opt);
        switch(opt){
            case 1:
                system("cls");                  //LIMPA A TELA
                matclear();                     //EXECUTA A FUNÇÃO MATCLEAR
                mata.mat1check = matb.mat2check = 0;      //ATRIBUE VALOR ZERO A VARIAVEL INTEIRA mata.mat1check E matb.mat2check
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 2:
                system("cls");                  //LIMPA A TELA
                mat1parameters();               //EXECUTA A FUNÇÃO MAT1PARAMETERS
                mata.mat1check = 1;                  //ATRIBUE VALOR 1 A VARIAVEL INTEIRA mata.mat1check
                printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 3:
                system("cls");                  //LIMPA A TERA
                mat2parameters();               //EXECUTA A FUNÇÃO MAT2PARAMETERS
                matb.mat2check = 1;                  //ATRIBUE VALOR 1 A VARIAVEL INTEIRA matb.mat2check
                printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 4:
                system("cls");                  //LIMPA A TERA
                if((mata.mat1check!=1)||(matb.mat2check!=1)){         //SE AS VARIAVEIS mata.mat1check OU matb.mat2check FOREM DIFERENTES DE 1 MOSTRA UMA MENSAGEM DE INSTRUÇÃO
                    printf("Preencha as matrizes A e B antes de realizar uma operacao");
                    printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                }else{                                      //SE AMBAS FOREM IGUAIS A 1 REALIZA A FUNÇÃO MATSOMA
                matsoma();                      //EXECUTA A FUNÇÃO MATSOMA
                }
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 5:
                system("cls");                  //LIMPA A TERA
                if((mata.mat1check!=1)||(matb.mat2check!=1)){         //SE AS VARIAVEIS mata.mat1check OU matb.mat2check FOREM DIFERENTES DE 1 MOSTRA UMA MENSAGEM DE INSTRUÇÃO
                    printf("Preencha as matrizes A e B antes de realizar uma operacao");
                    printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                }else{                                      //SE AMBAS FOREM IGUAIS A 1 REALIZA A FUNÇÃO MATSUBTRACAO
                matsubtracao();                 //EXECUTA A FUNÇÃO MATSUBTRACAO
                }
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 6:
                system("cls");                  //LIMPA A TERA
                if((mata.mat1check!=1)||(matb.mat2check!=1)){         //SE AS VARIAVEIS mata.mat1check OU matb.mat2check FOREM DIFERENTES DE 1 MOSTRA UMA MENSAGEM DE INSTRUÇÃO
                    printf("Preencha as matrizes A e B antes de realizar uma operacao");
                }else{                                      //SE AMBAS FOREM IGUAIS A 1 REALIZA A FUNÇÃO MATMULTIPLICACAO
                matmultiplicacao();             //EXECUTA A FUNCAO MATMULTIPLICAÇÃO
                }
                printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
            case 7:
                system("cls");                  //LIMPA A TELA
                printf("Voce saiu do programa!\n\n\n");
                break;
            default:    //CASO A ESCOLHA DA TAREFA(1~7) ESTEJA COM UM VALOR FORA DA FAIXA ESPECIFICADA APARECE UMA MENSAGEM DE ERRO E VOLTA AO MENU PRINCIPAL
                system("cls");
                printf("Voce nao escolheu uma opcao valida!");
                printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                getch();
                break;
        }
    }while(opt!=7);
}
