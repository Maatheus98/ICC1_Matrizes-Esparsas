
tamanho Criar_matriz_menu(tamanho matriz){
    if(Existe_matriz(matriz)==0){
    system("CLS");
    printf("-----------Matrizes Esparsas-----------\n");

    return Criar_matriz();}
    else{
    printf("\nUma matriz ja foi criada.\nPara criar outra, exclua a ja existente.\n\n");
    Sleep(2500);
    return matriz;}
}

void Inserir_valores_menu(celula_tipo **lista,tamanho matriz){
        if(Existe_matriz(matriz)==1){
            int resp2;
            do{
                system("CLS");
                printf("-----------Matrizes Esparsas-----------\n");
                celula_tipo *p = *lista;
                *lista=Inserir_valor(matriz);//Retorna "celula", struct com valor e coordenadas.
                (*lista)->prox=p;
                printf("\n1-Inserir novo valor\n2-Voltar ao Menu Principal\n");
                printf("Opcao desejada: "), scanf("%d",&resp2),fflush(stdin);
                if(resp2>2 || resp2<1){printf("\n\nOpcao invalida, tente novamente."),Sleep(2500);}
            }while(resp2!=2);
    }
        else{printf("\nCrie uma matriz antes de inserir um valor."), Sleep(2500);}
}

void Consulta_soma_menu(celula_tipo* lista, tamanho matriz){
             if(Existe_matriz(matriz)==1){int resp3;
         do{
         system("CLS");
         printf("-----------Matrizes Esparsas-----------\n");
         printf("1-Soma de uma linha\n2-Soma de uma coluna\n3-Voltar\n");
         printf("Opcao desejada: "),scanf("%d",&resp3),fflush(stdin);
         if(resp3==1){soma_linha(lista, matriz);}
         if(resp3==2){soma_coluna(lista,matriz);}
         if(resp3>3 || resp3<1){printf("Opcao invalida, tente novamente."),Sleep(2500);}
        }while(resp3!=3);}
            else{printf("\nCrie uma matriz antes de calcular somas.\n"),Sleep(2500);}
}

void Consulta_valor_menu(celula_tipo* lista,tamanho matriz){
         if(Existe_matriz(matriz)==1){
         system("CLS");
         printf("-----------Matrizes Esparsas-----------\n");
         int resp4;
            do{
                int linha_busca;
                int coluna_busca;
                    do{
                        printf("Insira a Linha: "), scanf("%d",&linha_busca),fflush(stdin);
                        if(linha_busca>matriz.linhas || linha_busca<0){
                            printf("\nEsta linha nao existe na matriz, tente novamente.\n");}
                    }while(linha_busca>matriz.linhas || linha_busca<0);
                    do{
                        printf("Insira a Coluna: "), scanf("%d",&coluna_busca),fflush(stdin);
                        if(coluna_busca>matriz.colunas || coluna_busca<0){
                            printf("\nEsta coluna nao existe na matriz, tente novamente.\n");}
                    }while(coluna_busca>matriz.colunas || coluna_busca<0);
                Consultar_valor(lista,coluna_busca,linha_busca);
                printf("\n1-Consultar outro valor\n2-Voltar ao Menu Principal");
                printf("\nOpcao desejada: "), scanf("%d",&resp4),fflush(stdin);
                }while(resp4!=2);}
        else {printf("\nCrie uma matriz antes de consultar um valor."), Sleep(2500);}
}

tamanho Excluir_menu(celula_tipo* lista, tamanho matriz){
        if(Existe_matriz(matriz)==1){
                system("CLS");
                printf("-----------Matrizes Esparsas-----------\n");
                tamanho temp=Excluir_matriz(lista, matriz);
                matriz.linhas=temp.linhas;
                matriz.colunas=temp.colunas;
                return matriz;}
        else{
                printf("\nNao ha matriz disponivel para exclusao.\n"),Sleep(2500);
                return matriz;}

}
