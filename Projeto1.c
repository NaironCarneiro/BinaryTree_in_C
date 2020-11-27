#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int idade;
  int id;
  char nome[30];
  char sexo[10];
  char tipo[15];
  struct node* dir;
  struct node* esq;
}Node;

typedef struct BinaryTree{
  Node *Raiz;
}Btree;

Node* inicializaArv(){ //INICIALIZANDO A ARVORE
    return NULL;
}

Node* AdicionarnaArvore(Node* Raiz){
    Node* item = (Node *)malloc(sizeof(Node));
    printf("Informe o CÓDIGO(ID) do ingresso:");
    scanf(" %d",&item->id);
    printf("Informe o NOME do cliente:");
    scanf(" %[^\n]",item->nome);
    printf("Informe a IDADE do cliente:");
    scanf(" %d",&item->idade);
    printf("Informe o SEXO do cliente [masculino/feminino]:");
    scanf(" %[^\n]",item->sexo);
    printf("Informe o TIPO de ingresso [Ex.Pista, Front, Lounge,etc]:");
    scanf(" %[^\n]",item->tipo);

    return item;
}

Node *InserirArvore(Node* Raiz,Node* item){
 if (Raiz == NULL){                                     //QUANDO UM NÓ FOR REGISTRADO, A DIREITA E ESQUERDA DA RAIZ SERÁ NULL
        Raiz = item;
        Raiz->dir = NULL;
        Raiz->esq = NULL;
        printf("\nVENDA EFETUADA COM SUCESSO\n");
         return Raiz;
}
   else{
     if (item->id > Raiz->id){
       if (Raiz->dir == NULL){
         Raiz->dir = item;
         printf("\nVENDA EFETUADA COM SUCESSO\n");
       }else{
         InserirArvore(Raiz->dir, item);
     }
   }
     else if (item->id < Raiz->id ){
       if (Raiz->esq == NULL){
         Raiz->esq = item;
         printf("\nVENDA EFETUADA COM SUCESSO\n");
       }else{
       InserirArvore(Raiz->esq, item);
    }
  }else if(item->id == Raiz->id){
        Raiz->esq = item;
  }
}
return Raiz;
}
void ImprimiArvore(Node* Raiz){
  int a =1, b=1;            //IMPRESSÃO EM ORDEM, POIS A RAIZ SERA O PRIMEIRO VALOR DIGITADO E FICARÁ NO CENTRO
        if (Raiz != NULL){
        printf("(");
        printf("[ ID: %d -> NOME: %s -> IDADE: %d -> SEXO: %s -> TIPO: %s ]\n", Raiz->id, Raiz->nome, Raiz->idade, Raiz->sexo, Raiz->tipo);
        ImprimiArvore(Raiz->esq);
        ImprimiArvore(Raiz->dir);
      }
  }

Node* BuscarId(Node* Raiz,int idBusca){
  Node*aux = Raiz;
  if (aux!= NULL){
		if(aux->id == idBusca){
    printf("[ ID: %d -> NOME: %s -> IDADE: %d -> SEXO: %s -> TIPO: %s ]\n", aux->id, aux->nome, aux->idade, aux->sexo, aux->tipo);
    return aux;
		}else{
      if (idBusca > aux->id){
            return BuscarId(aux->dir,idBusca);
      }else{
            return BuscarId(aux->esq,idBusca);
      }
    }
  }
	printf("O INGRESSO NÃO ENCONTRADO!!!");
	return NULL;
}

Node* RemoverTree(Node* Raiz,int id1){
  Node* item = Raiz;
if (Raiz != NULL){
if (id1 > item->id){
Raiz->dir = RemoverTree(Raiz->dir,id1);
          }
else if (id1 < item->id){
      Raiz->esq = RemoverTree(Raiz->esq,id1);
        }
        else{                     //SE CAIR NO ELSE, O ELEMENTO A SER EXCLUIDO FOI ENCONTRADO
        if(Raiz->esq == NULL && Raiz->dir == NULL){
          free(Raiz);
          printf("INGRESSO EXCLUIDO COM SUCESSO!!!");
          return NULL;
          }else if(Raiz->esq == NULL && Raiz->dir != NULL){
            Node*aux = Raiz->dir;
            free(Raiz);
            printf("INGRESSO EXCLUIDO COM SUCESSO!!!");
            return aux;
            }else if(Raiz->esq != NULL && Raiz->dir == NULL) {
              Node*aux = Raiz->esq;
              free(Raiz);
              printf("INGRESSO EXCLUIDO COM SUCESSO!!!");
                return aux;
              }
                else{
                  Node*aux = Raiz->dir;
                  while(aux->esq!=NULL){
                    aux = aux->esq;
                    }
                  Raiz->id = aux->id;                             // NO CASO DA MINHA ARVORE QUANDO EU FOR EXCLUIR O NÓ RAIZ
                  aux->id = id1;                                  //MINHA NOVA RAIZ SERÁ O MENOR FOLHA DA SUBÁRVORE DIREITA, POIS
                  Raiz->dir = RemoverTree(Raiz->dir,id1);         //DESSE MESMO MINHA ÁRVORE AINDA CONTINUARÁ BINÁRIA, OU SEJA, NORMAL
                  }
              }
            return Raiz;
        }else{
        return NULL;
  }
}

void Treefree(Node* Raiz){  //LIBERA TODA A MEMÓRIA DA ARVORE, QUANDO O USUÁRIO SAIR DO PROGRAMA
  if (Raiz!= NULL){
    Treefree(Raiz->dir);
    Treefree(Raiz->esq);
    free(Raiz);
  }
}
int main() {
  system(" clear");
  int id1,idBusca;
  Node* Raiz = inicializaArv();
  int opt = 1;
  	while (opt != 0){
  		printf("\n");
      printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>CYBER INGRESSOS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
  		printf("|=======================HOME====================|\n");
  		printf("|\t1-Registrar venda de ingresso\t\t|\n");
      printf("|\t2-Imprimir Todos os ingressos vendidos\t|\n");
  		printf("|\t3-Buscar ingresso vendido\t\t|\n");
  		printf("|\t4-Excluir ingresso vendido\t\t|\n");
  		printf("|\t0-Sair\t\t\t\t\t|\n");
  		printf("|===============================================|\n");
  		printf("Digite a opcao desejada: ");
  		scanf("%d", & opt);

  		switch (opt) {
  		case 1:
        printf("\nPREENCHA OS DADOS DO CLIENTE:\n");
      	Raiz = InserirArvore(Raiz,AdicionarnaArvore(Raiz));
  			break;
  		case 2:
        printf("RELAÇÃO DE TODOS OS INGRESSOS VENDIDOS\n");
        ImprimiArvore(Raiz);
        break;
      case 3:
        printf("Informe o código do ingresso a ser buscado: ");
        scanf(" %d",&idBusca);
        Raiz = BuscarId(Raiz,idBusca);
        break;
      case 4:
        printf("Informe o código do ingresso que deseja remover: ");
        scanf(" %d", &id1);
        Raiz = RemoverTree(Raiz,id1);
        break;
      case 0:
        printf("PROGRAMA ENCERRADO COM SUCESSO!!!!!!!!!\n");
        Treefree(Raiz);
        break;
      default:
        printf("POR FAVOR, DIGITE UMA OPÇÃO ACIMA\n");
        break;
}
}
return 0;
}
