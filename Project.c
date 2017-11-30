#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int opt, l1, l2, l3, c1, c2, c3;
float mat1[50][50], mat2[50][50], mat3[50][50];
int i, j, y, ht1, ht2, ht1s, ht1e, ht2s, ht2e, sm, mm;
int mat1check, mat2check;

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
    for(i=0; i<l1; i++){
        for(j=0; j<c1; j++){
            mat1[i][j]=0;
        }
    }
    /*Atribue 0 a todos os valores da matriz B*/
    for(i=0; i<l2; i++){
        for(j=0; j<c2; j++){
            mat2[i][j]=0;
        }
    }
    /*Atribue 0 a todos os valores da matriz resultante C*/
    for(i=0; i<l3; i++){
        for(j=0; j<c3; j++){
            mat3[i][j]=0;
        }
    }
    /*Mostra uma mensagem falando que a operação foi realizada seguida de uma instrução*/
    printf("Todas as matrizes foram zeradas");
    printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
}

void mat1print(){               //FAZ A IMPRESSÃO DA MATRIZ A NA TELA
    printf("==> Matriz A:\n\n");
    for(i=0; i<l1; i++){
        for(j=0; j<c1; j++){
            printf("%.2f ", mat1[i][j]);
        }
        printf("\n");
    }
}

void mat2print(){               //FAZ A IMPRESSÃO DA MATRIZ B NA TELA
    printf("==> Matriz B:\n\n");
    for(i=0; i<l2; i++){
        for(j=0; j<c2; j++){
            printf("%.2f ", mat2[i][j]);
        }
        printf("\n");
    }
}

void mat3print(){               //FAZ A IMPRESSÃO DA MATRIZ C NA TELA
    printf("==> Matriz C:\n\n");
    for(i=0; i<l3; i++){
        for(j=0; j<c3; j++){
            printf("%.2f ", mat3[i][j]);
        }
        printf("\n");
    }
}

void mat1parameters(){          //RECEBE OS DADOS DA MATRIZ A
    system("cls");
    printf("Defina o tamanho da matriz A (Matriz com tamanho igual ou menor que 50x50):\n\n"
           ">Quantidade de linhas:  ");
    scanf("%d", &l1);                   //RECEBE O NUMERO DE LINHAS DE A
    printf(">Quantidade de colunas: ");
    scanf("%d", &c1);                   //RECEBE O NUMERO DE COLUNAS DE A
    if(l1>0&&l1<51&&c1>0&&c1<51){
    /*CASO O NUMERO DE LINHAS E COLUNAS ESTEJA ENTRE O VALOR MIN~MAX PERMITIDO PROSEGUE
      COM O RECEBIMENTO DE DADOS DA MATRIZ A. SE O USUARIO SELECIONAR PARA GERAR VALORES
      RANDOMICOS PARA A MATRIZ A, ELE TEM QUE DETERMINAR EM SEGUIDA A FAIXA DE VALORES
      ONDE OS NUMEROS RANDOMICOS ESTARÃO, CASO SELECIONE PARA PREENCHER MANUALMENTE, O
      USUARIO TERÁ DE ESPECIFICAR O VALOR DE CADA CÉLULA*/
    printf("\nDe qual forma voce deseja preencher a matriz?\n"
           "> 1 - Randomicamente\n"
           "> 2 - Manualmente (Caractere por caractere)\n");
    scanf("%d", &ht1);
    if(ht1==1){
        printf("Digite a faixa de valores para gerar a os numeros da matriz\n\n");
        printf("Valor inicial:  ");
        scanf("%d", &ht1s);
        printf("Valor final:    ");
        scanf("%d", &ht1e);
        srand(time(NULL));
        for(i=0; i<l1; i++){
            for(j=0; j<c1; j++){
                mat1[i][j] = ht1s + (rand()%(ht1e - ht1s + 1));
            }
        }
    }else{
        if(ht1==2){
            printf("Digite os valores da matriz A, um por um:\n\n");
            for(i=0; i<l1; i++){
                for(j=0; j<c1; j++){
                    printf("Linha [%d], Coluna [%d]:    ", i+1, j+1);
                    scanf("%f", &mat1[i][j]);
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
    printf("Defina o tamanho da matriz B (Matriz com tamanho igual ou menor que 50x50):\n\n"
           ">Quantidade de linhas:  ");
    scanf("%d", &l2);
    printf(">Quantidade de colunas: ");
    scanf("%d", &c2);
    if(l1>0&&l1<51&&c2>0&&c2<51){
    /*CASO O NUMERO DE LINHAS E COLUNAS ESTEJA ENTRE O VALOR MIN~MAX PERMITIDO PROSEGUE
      COM O RECEBIMENTO DE DADOS DA MATRIZ B. SE O USUARIO SELECIONAR PARA GERAR VALORES
      RANDOMICOS PARA A MATRIZ B, ELE TEM QUE DETERMINAR EM SEGUIDA A FAIXA DE VALORES
      ONDE OS NUMEROS RANDOMICOS ESTARÃO, CASO SELECIONE PARA PREENCHER MANUALMENTE, O
      USUARIO TERÁ DE ESPECIFICAR O VALOR DE CADA CÉLULA*/
    printf("\nDe qual forma voce deseja preencher a matriz?\n"
           "> 1 - Randomicamente\n"
           "> 2 - Manualmente (Caractere por caractere)\n");
    scanf("%d", &ht2);
    if(ht2==1){
        printf("Digite a faixa de valores para gerar a os numeros da matriz\n\n");
        printf("Valor inicial:  ");
        scanf("%d", &ht2s);
        printf("Valor final:    ");
        scanf("%d", &ht2e);
        srand(time(NULL));
        for(i=0; i<l2; i++){
            for(j=0; j<c2; j++){
                mat2[i][j] = ht2s + (rand()%(ht2e - ht2s + 1));
            }
        }
    }else{
        if(ht2==2){
            printf("Digite os valores da matriz B, um por um:\n\n");
            for(i=0; i<l2; i++){
                for(j=0; j<c2; j++){
                    printf("Linha [%d], Coluna [%d]:   ", i+1, j+1);
                    scanf("%f", &mat2[i][j]);
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
    if((l1==l2)&&(c1==c2)){
        l3=l1;
        c3=c1;
        for(i=0; i<l1; i++){
            for(j=0; j<c1; j++){
                mat3[i][j] = mat1[i][j] + mat2[i][j];
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
    if((l1==l2)&&(c1==c2)){
        printf("De qual forma voce deseja realizar a subtracao?\n"
               "> 1 - (A - B)\n"
               "> 2 - (B - A)\n");
        scanf("%d", &sm);
        if(sm==1){
            for(i=0; i<l1; i++){
                for(j=0; j<c1; j++){
                    mat3[i][j] = mat1[i][j] - mat2[i][j];
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
                for(i=0; i<l1; i++){
                    for(j=0; j<c1; j++){
                        mat3[i][j] = mat2[i][j] - mat1[i][j];
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
    l3=l1;
    c3=c1;
}

void multab(){                  //FAZ A MULTIPLICAÇÃO DE A * B
    float multabresult;

    for (i=0; i<l1; i++) {
        for (j=0; j<c2; j++) {
            multabresult=0;
            for (y=0; y<c1; y++) {
                multabresult=multabresult+(mat1[i][y]*mat2[y][j]);
            }
            mat3[i][j]= multabresult;
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

    for (i=0; i<l2; i++) {
        for (j=0; j<c1; j++) {
            multbaresult=0;
            for (y=0; y<c2; y++) {
                multbaresult=multbaresult+(mat2[i][y]*mat1[y][j]);
            }
            mat3[i][j]= multbaresult;
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
    if((l1==c2)||(c1==l2)){
        if((c1==l2)&&(c2!=l1)){
            printf("Com as especificacoes de A e B so eh possivel realizar uma multiplicacao do formato C = A * B\n\n");
            l3=l1;
            c3=c2;
            multab();
        }else{
            if((c1!=l2)&&(c2==l1)){
                printf("Com as especificacoes de A e B so eh possivel realizar uma multiplicação do formato C = B * A\n\n");
                l3=l2;
                c3=c1;
                multba();
            }else{
                printf("De qual forma voce deseja realizar a multiplicacao?\n"
                       "> 1 - A * B\n"
                       "> 2 - B * A\n");
                scanf("%d", &mm);
                if(mm==1){
                    l3=l1;
                    c3=c2;
                    printf("\n\n");
                    multab();
                }else{
                    if(mm==2){
                        l3=l2;
                        c3=c1;
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
    do{
        menu();
        scanf("%d", &opt);
        switch(opt){
            case 1:
                system("cls");                  //LIMPA A TELA
                matclear();                     //EXECUTA A FUNÇÃO MATCLEAR
                mat1check = mat2check = 0;      //ATRIBUE VALOR ZERO A VARIAVEL INTEIRA MAT1CHECK E MAT2CHECK
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 2:
                system("cls");                  //LIMPA A TELA
                mat1parameters();               //EXECUTA A FUNÇÃO MAT1PARAMETERS
                mat1check = 1;                  //ATRIBUE VALOR 1 A VARIAVEL INTEIRA MAT1CHECK
                printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 3:
                system("cls");                  //LIMPA A TERA
                mat2parameters();               //EXECUTA A FUNÇÃO MAT2PARAMETERS
                mat2check = 1;                  //ATRIBUE VALOR 1 A VARIAVEL INTEIRA MAT2CHECK
                printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 4:
                system("cls");                  //LIMPA A TERA
                if((mat1check!=1)||(mat2check!=1)){         //SE AS VARIAVEIS MAT1CHECK OU MAT2CHECK FOREM DIFERENTES DE 1 MOSTRA UMA MENSAGEM DE INSTRUÇÃO
                    printf("Preencha as matrizes A e B antes de realizar uma operacao");
                    printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                }else{                                      //SE AMBAS FOREM IGUAIS A 1 REALIZA A FUNÇÃO MATSOMA
                matsoma();                      //EXECUTA A FUNÇÃO MATSOMA
                }
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 5:
                system("cls");                  //LIMPA A TERA
                if((mat1check!=1)||(mat2check!=1)){         //SE AS VARIAVEIS MAT1CHECK OU MAT2CHECK FOREM DIFERENTES DE 1 MOSTRA UMA MENSAGEM DE INSTRUÇÃO
                    printf("Preencha as matrizes A e B antes de realizar uma operacao");
                    printf("\n\nPressione uma tecla qualquer para voltar ao menu principal");
                }else{                                      //SE AMBAS FOREM IGUAIS A 1 REALIZA A FUNÇÃO MATSUBTRACAO
                matsubtracao();                 //EXECUTA A FUNÇÃO MATSUBTRACAO
                }
                getch();                        //COMANDO PARA VOLTAR AO MENU PRINCIPAL
                break;
            case 6:
                system("cls");                  //LIMPA A TERA
                if((mat1check!=1)||(mat2check!=1)){         //SE AS VARIAVEIS MAT1CHECK OU MAT2CHECK FOREM DIFERENTES DE 1 MOSTRA UMA MENSAGEM DE INSTRUÇÃO
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
