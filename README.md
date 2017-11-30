# Algoritmos e Lógica de Programação
### Projeto da Terceira Unidade
* Professor:  Agostinho Brito
* Aluno:      Felipe Anderson de Medeiros Araújo
# PROGRAMA MANIPULADOR DE MATRIZES
* O programa recebe dados de matrizes e faz soma, subtração e multiplicação entre elas da forma que o usuário escolher
# INSTALAÇÃO
* Pegue o código em C e execute-o em um compilador em C de sua preferencia
# INSTRUÇÕES DE USO
## 1 - A opção [01] do programa atribuirá o valor zero a todas as células das matrizes A, B e C.
## 2 - Definir os parametros das Matrizez:
    [+] As matrizes A e B deverão ser especificadas pelo usuario antes de fazer qualquer calculo entre elas.
    [+] Após espeficar os dados das matrizes, elas serão mostradas na tela para o usuario saber como ficou a matriz.
### 2.1 - A opção [02] do programa receberá os dados de uma matriz A especificada pelo usuário.
* 2.1.1 - O Usuário terá de informar o números de linhas e colunas da matriz A, respeitando o limite máximo de 50 linhas ou colunas
* 2.1.2 - O usuário terá de escolher de qual forma deseja preencher a matriz, randomicamente ou manualmente
* 2.1.2.1 - Randomicamente:   Os valores dentro da matriz A será feita de forma aleatória, o usuario terá de informar a faixa de valores que os numeros serão gerados
* 2.1.2.2 - Manualmente:      Os valores serão atribuidos pelo usuário célula por célula da matriz, até todos os valores da matriz serem preenchidos
### 2.2 - A opção [03] do programa receberá os dados de uma matriz A especificada pelo usuário.
* 2.2.1 - O Usuário terá de informar o números de linhas e colunas da matriz B, respeitando o limite máximo de 50 linhas ou colunas
* 2.2.2 - O usuário terá de escolher de qual forma deseja preencher a matriz, randomicamente ou manualmente
* 2.2.2.1 - Randomicamente:   Os valores dentro da matriz B será feita de forma aleatória, o usuario terá de informar a faixa de valores que os numeros serão gerados
* 2.2.2.2 - Manualmente:      Os valores serão atribuidos pelo usuário célula por célula da matriz, até todos os valores da matriz serem preenchidos
## 3 - A opção [04] do programa fará, se possivel, a soma entre as matrizes gerando uma nova matriz C.
    [+] Lembre-se que para fazer a soma entre duas matrizes elas devem ter número de linhas e colunas iguais.
        Ex: Com A=3x5 e B=3x5 a soma entre as matrizes será realizada
            Com A=3x5 e B=3x6 a soma entre as matrizes não será realizada
    [+] Após realizar a soma entre as matrizes o programa mostrará as matrizes A e B e uma matriz C resultante
## 4 - A opção [05] do programa fará se possivel, a subtração entre as matrizes gerando uma nova matriz C.
    [+] Lembre-se que para fazer a subtração entre duas matrizes elas devem ter número de linhas e colunas iguais.
        Ex: Com A=3x5 e B=3x5 a subtração entre as matrizes será realizada
            Com A=3x5 e B=3x6 a subtração entre as matrizes não será realizada
    [+] O usuário poderá determinar de qual forma a subtração será feira (A-B) ou (B-A)
    [+] Após realizar a subtração entre as matrizes o programa mostrará as matrizes A e B e uma matriz C resultante
## 5 - A opção [06] do programa fará se possivel, a multiplicação entre as matrizes gerando uma nova matriz C.
    [+] Lembre-se, para fazer uma multiplicação entre matrizes, o número de linhas de uma das matrizes deve ser igual ao número de colunas da outra matriz
    [+] O programa analizará e realizará a multiplicação (A*B) ou (B*A) de forma automática. Se as matrizes forem quadradas e com número de linhas e colunas iguais entre sí o usuário poderá escolher entra uma das duas formas de multiplicação.
## 6 - A opção [07] do programa encerrará o mesmo.
## Observações
    Qualquer valor digitado que não esteja dentro dos valores esperados dentro do programa resultará em uma mensagem informando o que aconteceu e retornará ao menu principal
