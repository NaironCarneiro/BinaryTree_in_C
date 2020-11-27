#include<stdio.h>
#include<stdlib.h>
// void liberaNo(struct BinaryNode* no){
//   if (no == NULL){
//     return;
//     liberaNo(no->esq);
//     liberaNo(no->dir);
//     free(no);
//     no = NULL;
//   }
// }
// BinaryTree* LiberaArvore(CriarArvore*Raiz){
//   if (Raiz == NULL){
//     return;
//     liberaNo(*Raiz);
//     free(Raiz);
//   }
// }
typedef struct BinaryNode {
int dado;
struct BinaryNode *esq;
struct BinaryNode *dir;
} BNode;
typedef struct BinaryTree {
BinaryNode *raiz;
int quant;
} BTree;

BinaryNode *CriarArvore(){
  BNode* raiz = (BNode*)malloc(sizeof(BNode));
  if (raiz != NULL){
     raiz = NULL;
  }
  return raiz;
}

BinaryNode* inicializaItem(BinaryTree* raiz){
    BinaryNode* item = (BinaryNode*)malloc(sizeof(BinaryNode));
    printf("digite um numero:");
    scanf(" %d",&item->dado);
    return item;
}


BinaryNode *InserirArvore(BinaryNode* raiz,struct BinaryNode* item){
  if (raiz == NULL){
    return 0;
 }
  struct BinaryNode* novo = (BinaryNode*)malloc(sizeof(BinaryNode));
    if(novo == NULL){
      printf("arvore vazia\n");
    }
    novo->raiz = item;
    novo->dir = NULL;
    novo->esq = NULL;

    if (*raiz == NULL){
      *raiz = novo;
    }
  else{
   struct BinaryNode* atual = *raiz;
   struct BinaryNode* ant = NULL;
    while (atual != NULL){
        ant = atual;
    if(item->dado == atual->dado){
      free(novo);
      //o elemento digitado já existe na árvore
    if ((item->dado) > (atual->dado)){
      atual = atual->dir;
    }
    else{
      atual = atual->esq;
    }
  }
  if (item->dado > ant->dado){
    ant->dir = novo;
  }else{
    ant->esq = novo;
  }
}
//return Raiz;
}
}

// void ImprimiArvore(BinaryTree* Raiz){
//   BinaryNode* aux = novo->Raiz;
//   while (aux != NULL){
//         ImprimiArvore(aux->esq);
//         printf("\n%d", aux->dado);
//         ImprimiArvore(aux->dir);
//       }
// }
  int main(){
      BinaryTree* raiz = NULL;
        printf("OLA MUNDO\n" );
  raiz = InserirArvore(raiz,inicializaItem(raiz));


}
