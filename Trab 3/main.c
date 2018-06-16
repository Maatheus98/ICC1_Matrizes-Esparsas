#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include "Funções.h"
#include "Menus.h"


int main(){
tamanho matriz;
celula_tipo*lista=NULL;
matriz.colunas=0, matriz.linhas=0;
int resp;
printf("////      ////      ////   //////////   //////////    //    //////////    //////////    ///////// \n");
printf("// //    // //     //  //      //       //      //    //           //     //            //         \n");
printf("//  //  //  //    //   //      //       //      //    //          //      //            //          \n");
printf("//   ////   //   //    //      //       //////////    //         //       //////        /////////    \n");
printf("//    //    //  //////////     //       // //         //        //        //                   //     \n");
printf("//          // //       //     //       //   //       //       //         //                   //      \n");
printf("//          ////        //     //       //     //     //      //////////  //////////    /////////       \n\n\n");
printf("//////////  /////////   //////////       ////    //////////   /////////         ////    ///////// \n");
printf("//          //          //      //      //  //   //      //   //               //  //   //         \n");
printf("//          //          //      //     //   //   //      //   //              //   //   //          \n");
printf("//////      /////////   //////////    //    //   //////////   /////////      //    //   /////////    \n");
printf("//                 //   //           //////////  // //               //     //////////         //     \n");
printf("//                 //   //          //       //  //   //             //    //       //         //      \n");
printf("//////////  /////////   //         //        //  //     //    /////////   //        //  /////////       \n");

Sleep(5000);
    do{
        system("CLS");
        printf("-----------Matrizes Esparsas-----------\n\n");
        printf("1-Criar Matriz\n2-Inserir Valores\n3-Consultar Soma\n4-Consultar Valor\n5-Excluir Matriz\n6-Sair\n");
        printf("Opcao desejada: "), scanf("%d",&resp),fflush(stdin);
        if(resp==1){
                (matriz=Criar_matriz_menu(matriz));}
        if(resp==2){
            Inserir_valores_menu(&lista,matriz);}
        if(resp==3){
            Consulta_soma_menu(lista,matriz);}
        if(resp==4){
            Consulta_valor_menu(lista,matriz);}
        if(resp==5){
            tamanho temp=Excluir_menu(lista,matriz);
            matriz.linhas=temp.linhas, matriz.colunas=temp.colunas;}
        if(resp>6 || resp<1){
            printf("\nOpcao invalida, tente novamente.");
            Sleep(2000);}
}while(resp!=6);
exit(0);
}


