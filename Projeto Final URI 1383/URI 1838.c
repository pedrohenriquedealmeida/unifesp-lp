#include <stdio.h>

int test3x3 (int *);

int main(){

    int cel[9][9];
    int valorInst[1000];
    int testLin=1, testCol=1, testReg=1;
    int provaLin=1, provaCol=1, provaReg=1;

    int n, i, j, k, x, y;   //FOR Loops
    int LinhaInicial, ColunaInicial; //Para teste 3x3

    scanf("%d", &n);

    for(k=0;k<n;k++) valorInst[k]=1;

    for(k=0;k<n;k++){

        testLin=1; testCol=1; testReg=1;
        provaLin=1; provaCol=1; provaReg=1;

        //ENTRADA DE DADOS
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(i==8&&j==8) scanf("%d", &cel[i][j]);
                else scanf("%d ", &cel[i][j]);
                if(cel[i][j]==0) valorInst[k] = 0;
            }
        }

        //TESTANDO AS LINHAS
    
        for(x=0;x<9;x++){
            for(y=0;y<9;y++){
                for(j=0;j<9;j++) {if(y!=j&&cel[x][y]==cel[x][j]) testLin=0;
                                 if(testLin==0) provaLin=0;}
            }
        }

        //TESTANDO AS COLUNAS
         for(x=0;x<9;x++){
            for(y=0;y<9;y++){
                for(j=0;j<9;j++) {if(y!=j&&cel[y][x]==cel[j][x]) testCol=0;
                                 if(testCol==0) provaCol=0;}
            }
        }


        //TESTANDO 3X3
        for(LinhaInicial=0;LinhaInicial<=6;LinhaInicial+=3){
            for(ColunaInicial=0;ColunaInicial<=6;ColunaInicial+=3){
                testReg=test3x3(&cel[LinhaInicial][ColunaInicial]);
                if(testReg==0) provaReg=0;
                }
        }

        if(provaCol==0||provaLin==0||provaReg==0) valorInst[k]=0;
    }

    //IMPRESSAO
    for(k=0;k<n;k++){
        printf("Instancia %d\n", k+1);
        if(valorInst[k]==0) printf("NAO\n\n");
        if(valorInst[k]==1) printf("SIM\n\n");
    }
        
    return 0;
}

int test3x3(int* add){
    int b,c,resposta = 1;
    int array[9]={*add, *(add+ 1), *(add+ 2), *(add+ 9), *(add+ 10), *(add+ 11), *(add+ 18), *(add+ 19), *(add+ 20)};
    
    for (b=0;b<9;b++){
        for(c=0;c<9;c++) if(b!=c&&array[b]==array[c]) resposta=0;
    }
    
    return resposta;
}
