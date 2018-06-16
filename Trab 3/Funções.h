struct celula_tipo{
    float valor;
    int linha_c, coluna_c;
    struct celula_tipo *prox;};
typedef struct celula_tipo celula_tipo;

struct tamanho{
    int linhas, colunas;};
typedef struct tamanho tamanho;
//--------------------------------------------------------------------------------------------------------------------

int Existe_matriz(tamanho matriz){
    if(matriz.linhas>0 || matriz.colunas>0){
        return 1;
    }
    else return 0;
}



celula_tipo* busca(celula_tipo* lista, int linha_busca, int coluna_busca){
    celula_tipo* p;
    p= lista;
    while(p!=NULL){
        if(p->linha_c==linha_busca && p->coluna_c==coluna_busca){
            return p;}
        else p = p->prox;}
    return p;
}

//--------------------------------------------------------------------------------------------------------------------
tamanho Criar_matriz(){
    tamanho matriz;
        do{
            printf("Insira o numero de linhas: "), scanf("%d",&matriz.linhas),fflush(stdin);
            if(matriz.linhas<=0)printf("\nNumero deve ser maior que 0, tente novamente.\n");}while(matriz.linhas<=0);
        do{
            printf("\nInsira o numero de colunas: "), scanf("%d",&matriz.colunas),fflush(stdin);
                if(matriz.colunas<=0)printf("\nNumero deve ser maior que 0, tente novamente.\n");}while(matriz.colunas<=0);
    printf("\nMatriz criada com sucesso!\n"), system("PAUSE");
    return matriz;
}

celula_tipo* Inserir_valor(tamanho matriz){
    int linha_c,coluna_c;
    float valor;
    printf("Insira o Valor: "), scanf("%f",&valor),fflush(stdin);
        do{
            printf("Insira a Linha para o Valor: "), scanf("%d",&linha_c),fflush(stdin);
            if(linha_c>matriz.linhas|| linha_c<=0){
                    printf("\nEsta linha nao existe na matriz, tente novamente.\n"), Sleep(2500);}
        }while(linha_c>matriz.linhas|| linha_c<=0);
        do{
            printf("Insira a Coluna para o Valor: "), scanf("%d",&coluna_c),fflush(stdin);
            if(coluna_c>matriz.colunas || coluna_c<=0){
                    printf("\nEsta coluna nao existe na matriz, tente novamente.\n"), Sleep(2500);}
        }while(coluna_c>matriz.colunas || coluna_c<=0);
    celula_tipo* celula;
    celula= (celula_tipo*)malloc(sizeof(celula_tipo));
    celula->linha_c= linha_c;
    celula->coluna_c= coluna_c;
    celula->valor= valor;
    celula->prox=NULL;
    return celula;
    }

void Consultar_valor(celula_tipo* lista, int coluna_busca, int linha_busca){
    celula_tipo* pqp= busca(lista, linha_busca, coluna_busca);
    system("CLS"),printf("-----------Matrizes Esparsas-----------\n");
    if(pqp==NULL){
        printf("Valor: 0");
        printf("\nLinha: %d",linha_busca);
        printf("\nColuna: %d\n",coluna_busca);}
    else{
    printf("Valor: %.2f",pqp->valor);
    printf("\nLinha: %d",pqp->linha_c);
    printf("\nColuna: %d\n",pqp->coluna_c);}
}

void soma_linha(celula_tipo* lista, tamanho matriz){
    system("CLS");
    printf("-----------Matrizes Esparsas-----------\n");
    int linha_c;
    float sum=0;
    celula_tipo* p=lista;
        do{
            printf("Insira a Linha a ser somada: "), scanf("%d",&linha_c),fflush(stdin);
            if(linha_c>matriz.linhas|| linha_c<=0){
                    printf("\nEsta linha nao existe na matriz, tente novamente.\n"), Sleep(2500);}
        }while(linha_c>matriz.linhas|| linha_c<=0);
    while(p!=NULL){
        if(p->linha_c==linha_c){
            sum+= p->valor;}
            p= p->prox;
    }
    printf("\nA soma dos valores da linha %d e: %.2f\n\n",linha_c,sum),system("PAUSE");
}

void soma_coluna(celula_tipo* lista, tamanho matriz){
    system("CLS");
    printf("-----------Matrizes Esparsas-----------\n");
    int coluna_c;
    float sum=0;
    celula_tipo* p=lista;
        do{
            printf("Insira a Coluna a ser somada: "), scanf("%d",&coluna_c),fflush(stdin);
            if(coluna_c>matriz.colunas|| coluna_c<=0){
                    printf("\nEsta coluna nao existe na matriz, tente novamente.\n"), Sleep(2500);}
        }while(coluna_c>matriz.colunas|| coluna_c<=0);
    while(p!=NULL){
        if(p->coluna_c==coluna_c){
            sum+= p->valor;}
            p= p->prox;
    }
    printf("\nA soma dos valores da coluna %d e: %.2f\n\n",coluna_c,sum),system("PAUSE");
}

tamanho Excluir_matriz(celula_tipo* lista, tamanho matriz){
    celula_tipo *p, *q;
    while(lista!=NULL){
        p= lista;
        q= lista->prox;
        lista=lista->prox;
        free(p);
        p=q;}
    system("CLS");
    printf("-----------Matrizes Esparsas-----------\n");
    matriz.linhas=0,matriz.colunas=0;
    printf("Matriz excluida com successo!"), Sleep(2500);
    return matriz;
}
