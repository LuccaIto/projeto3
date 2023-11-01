#include "projeto_3.h"
#include <stdio.h>
#include <string.h>

int *Contador_Tarefas;
int indice = 0;

// int menu(){
//     printf("Selecione a tarefa desejada abaixo: \n");
//     printf("1. Criar tarefa; \n");
//     printf("2. Remover tarefa; \n");
//     printf("3. Listar tarefa; \n");
//     printf("4. ; \n");
//     printf("5. ; \n");
//     printf("6. ; \n");
//     printf("7. ; \n");
//     printf("8. ; \n");
// }

//Essa função cria uma tarefa na lista
int Criar_Tarefa( Lista_Tarefas Lista[], int *Contador_Tarefas){    

    if (*Contador_Tarefas <= 100) {
        printf("\n Digite a descricao da tarefa: ");
        scanf(" %[^\n]", Lista[*Contador_Tarefas].descricao);
        Clear_buffer();

        printf("\n Digite o conteudo da tarefa: ");
        scanf(" %[^\n]", Lista[*Contador_Tarefas].conteudo);
        Clear_buffer();

        printf("\n Digite a prioridade desejada(de 0 a 10): ");
        scanf("%d", &Lista[*Contador_Tarefas].prioridade);
        Clear_buffer();

        printf("\n Lista realizada com sucesso!! \n");
        

        *Contador_Tarefas = *Contador_Tarefas + 1;
        printf("%d", *Contador_Tarefas);
        return 1;
    }
    else{
        printf("A lista infelizmente esta cheia. Remova outra tarefa para poder acrescentar outra. \n");
        return 0; // Falha.
    }
}

//Essa função remove tarefa/s da lista
void Remove_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){
    char remove_descricao;


    if (*Contador_Tarefas > 0 && indice > 0 && indice <= *Contador_Tarefas){
        printf("digite a descricao da tarefa: ");
        scanf("%s", &remove_descricao);

        for (int i = indice ; i < *Contador_Tarefas ; ++i) {
            if(strcmp(remove_descricao,Lista[*Contador_Tarefas].descricao) == 0){
            Lista[i] = Lista[i + 1];
            }
        }
        (*Contador_Tarefas --);
        printf("Remoção realizada com sucesso!! \n");
        return 1; // Sucesso.
    }
    else{
        printf("Erro na remoção da tarefa desejada. Tente novamente.. \n");
        return 0; // Erro.
    }
}

//Essa função lista as tarefas ja criadas
void Listar_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){

    if (*Contador_Tarefas > 0){
        printf("Lista de tarefas: \n");

        for (int i = 0; i < *Contador_Tarefas; ++i) {
            printf("Tarefa: \n", i + 1);
            printf(" -->   Descrição: \n", Lista[i].descricao);
            printf(" -->   Conteudo: \n", Lista[i].conteudo);
            printf(" -->   Prioridade: \n", Lista[i].prioridade);
        }
    } else{
        printf("A lista esta vazia! ");
        return 0; //Erro
}
}

void Clear_buffer(){  //evita erros com a funcao scanf
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
