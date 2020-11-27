#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int valor;
  struct node* dir;
  struct node* esq;
  //struct node*prox;
}Node;

typedef struct BinaryTree{
  node *Raiz;
}Btree;

Node* inicializaArv(){
    return NULL;
}
Node* AdicionarnaArvore(Node* Raiz){
    Node* item = (Node *)malloc(sizeof(Node));
    printf("Digite um numero:");
    scanf(" %d",&item->valor);
    return item;
}

Node *InserirArvore(Node* Raiz,Node* item){
 if (Raiz == NULL){
 //    return 0;
 // }
      Node* novo = (Node*)malloc(sizeof(Node));
     // if(novo == NULL){
        novo->valor = item->valor;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;

//     if (Raiz == NULL){
//       Raiz = novo;
}
   else{
     if (item->valor > Raiz->valor ) {
      Raiz->dir = InserirArvore(Raiz->dir, item);
     }
     else if (item->valor < Raiz->valor ) {
      Raiz->esq = InserirArvore(Raiz->esq, item);
     }
  //       Node* atual = Raiz;
  //       Node* ant = NULL;
  //   while (atual != NULL){
  //       ant = atual;
  //   if(item->valor == atual->valor){
  //     free(novo);               //o elemento digitado já existe na árvore
  //
  //   if ((item->valor) > (atual->valor)){
  //     atual = atual->dir;
  //   }
  //   else{
  //     atual = atual->esq;
  //   }
  // }
  // if (item->valor > ant->valor){
  //   ant->dir = novo;
  // }else{
  //   ant->esq = novo;
  // }
}
return Raiz;
}
void ImprimiArvore(Node * Raiz){
    // Node* aux = Raiz;
    //while (aux != NULL){
          if (Raiz != NULL){
          printf("%d, ", Raiz->valor);
          ImprimiArvore(Raiz->esq);
          ImprimiArvore(Raiz->dir);

        }
  // }aux = aux->prox;
}

void Treefree(Node* Raiz){  //liberando a memoria alocada da arvore
  if (Raiz!= NULL){
    Treefree(Raiz->dir);
    Treefree(Raiz->esq);
    free(Raiz);
  }
}
int main() {
  Node* Raiz = inicializaArv();
for (int i = 0; i < 7; i++) {
      Raiz = InserirArvore(Raiz,AdicionarnaArvore(Raiz));
    }
    printf("\nARVORE BINÁRIA!!\n");
  ImprimiArvore(Raiz);
  printf("\n");
  Treefree(Raiz);
  return 0;
}
