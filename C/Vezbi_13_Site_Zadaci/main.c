/*
-----Zadaca 1-----
#include <stdio.h>
#include <stdlib.h>

struct listNode {
   char karakter;
   int broj;
   struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *sPtr,int broj, char karakter);
void printListReverse( ListNodePtr currentPtr );
void printlist( ListNodePtr currentPtr );

int main()
{
   ListNodePtr startPtr = NULL;
   int n;
   printf("Vnesi broj na elementi vo listata: ");
   scanf("%d", &n);
   for(int i=0; i<n; i++){
       int broj;
       char karakter;
       printf("Vnesi broj i karakter: ");
       scanf("%d %c", &broj, &karakter);
       insert(&startPtr, broj, karakter);
   }
   printf("Revers: ");
   printListReverse(startPtr);
   printf("\n");
   return 0;
}

// Sekoj nov element se dodava na kraj na listata
void insert( ListNodePtr *sPtr, int broj, char karakter)
{
   ListNodePtr newPtr;
   ListNodePtr currentPtr;

   newPtr = malloc( sizeof( ListNode ) );

   if ( newPtr != NULL ) {
      newPtr->broj = broj;
      newPtr->karakter=karakter;
      newPtr->nextPtr = NULL;

      if((*sPtr)==NULL)
          (*sPtr)=newPtr;
      else{
          currentPtr = *sPtr;
          while (currentPtr->nextPtr!=NULL) {
             currentPtr = currentPtr->nextPtr;
          }
          currentPtr->nextPtr=newPtr;
      }
   }
}

void printListReverse( ListNodePtr currentPtr )
{
    if(currentPtr!=NULL){
        printf(" <-- %d %c", currentPtr->broj, currentPtr->karakter);

        printListReverse(currentPtr->nextPtr);
    }
}
*/

/*
-----Zadaca 2-----
#include <stdio.h>
#include <stdlib.h>

struct listNode {
   int broj;
   struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr,int broj);
void printList(ListNodePtr currentPtr);
void sortOpagjanje(ListNodePtr *sPtr);
void sortRastenje(ListNodePtr *sPtr);
void brisi(ListNodePtr *sPtr, int broj);

int main()
{
   ListNodePtr startPtr = NULL;
   int n;
   printf("Vnesi broj na elementi vo listata: ");
   scanf("%d", &n);
   for(int i=0; i<n; i++){
       int broj;
       char karakter;
       printf("Vnesi broj: ");
       scanf("%d", &broj);
       insert(&startPtr, broj);
   }
   printf("0-sortOpagjanje\n");
   printf("1-sortRastenje\n");
   printf("2-Brisi\n");
   printf("3-Pecati lista\n");
   printf("4-END\n");
   int choice;
   printf("Izberi: ");
   scanf("%d", &choice);
   while(choice!=4){
       switch (choice) {
       case 0:
           sortOpagjanje(&startPtr);
           break;
       case 1:
           sortRastenje(&startPtr);
           break;
       case 2:
           printf("Vnesi broj za brisenje: ");
           int broj;
           scanf("%d", &broj);
           brisi(&startPtr, broj);
           break;
       case 3:
           printList(startPtr);
           printf("\n");
           break;
       default:
           break;
       }
       printf("Izberi: ");
       scanf("%d", &choice);
   }
   return 0;
}

// Sekoj nov element se dodava na kraj na listata
void insert( ListNodePtr *sPtr, int broj)
{
   ListNodePtr newPtr;
   ListNodePtr currentPtr;

   newPtr = malloc( sizeof( ListNode ) );

   if ( newPtr != NULL ) {
      newPtr->broj = broj;
      newPtr->nextPtr = NULL;

      if((*sPtr)==NULL)
          (*sPtr)=newPtr;
      else{
          currentPtr = *sPtr;
          while (currentPtr->nextPtr!=NULL) {
             currentPtr = currentPtr->nextPtr;
          }
          currentPtr->nextPtr=newPtr;
      }
   }
}


void printList( ListNodePtr currentPtr )
{
    if(currentPtr!=NULL){
        printf("%d --> ", currentPtr->broj);
        printList(currentPtr->nextPtr);
    }
}

void sortOpagjanje(ListNodePtr *sPtr){
    ListNodePtr current=*sPtr;
    ListNodePtr next;
    while(current!=NULL){
        next=current->nextPtr;
        while(next!=NULL){
            if(current->broj<next->broj){
                int tmp=current->broj;
                current->broj=next->broj;
                next->broj=tmp;
            }
            next=next->nextPtr;
        }
        current=current->nextPtr;
    }
}

void sortRastenje(ListNodePtr *sPtr){
    ListNodePtr current=*sPtr;
    ListNodePtr next;
    while(current!=NULL){
        next=current->nextPtr;
        while(next!=NULL){
            if(current->broj>next->broj){
                int tmp=current->broj;
                current->broj=next->broj;
                next->broj=tmp;
            }
            next=next->nextPtr;
        }
        current=current->nextPtr;
    }
}

void brisi(ListNodePtr *sPtr, int broj){
    ListNodePtr prev;
    ListNodePtr curr;
    ListNodePtr tmpPtr;
    if((*sPtr)->broj==broj){
        tmpPtr=*sPtr;
        (*sPtr)=(*sPtr)->nextPtr;
        free(tmpPtr);
    }
    else{
        prev=*sPtr;
        curr=(*sPtr)->nextPtr;
        while(curr!=NULL && curr->broj!=broj){
            prev=curr;
            curr=curr->nextPtr;
        }
        if(curr!=NULL){
            tmpPtr=curr;
            prev->nextPtr=curr->nextPtr;
            free(tmpPtr);
        }
        else{
            printf("Node so vrednost %d ne postoi vo listata\n", broj);
        }
    }
}
*/

/*
-----Zadaca 3-----
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 100

struct stackNode {
   char karakter;
   struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push( StackNodePtr *topPtr, char info );
char pop( StackNodePtr *topPtr );

int main()
{
   StackNodePtr stackPtr = NULL;
   char *str;
   int i;
   str=malloc(MAXSTR);
   gets(str);
   for(i=0; i<(int)strlen(str); i++){
       push(&stackPtr, str[i]);
   }
   free(str);
   while(i>0){
       printf("%c", pop(&stackPtr));
   }
   printf("\n");
   return 0;
}

void push( StackNodePtr *topPtr, char info )
{
   StackNodePtr newPtr;
   newPtr = malloc( sizeof( StackNode ) );
   if ( newPtr != NULL ) {
      newPtr->karakter = info;
      newPtr->nextPtr = *topPtr;
      *topPtr = newPtr;
   }
   else {
      printf( "%d ne e vnesen. Nema dovolno memorija.\n", info );
   }
}

char pop( StackNodePtr *topPtr )
{
   StackNodePtr tempPtr;
   int popValue;

   tempPtr = *topPtr;
   popValue = ( *topPtr )->karakter;
   *topPtr = ( *topPtr )->nextPtr;
   free( tempPtr );

   return popValue;
}
*/

/*
-----Zadaca 4-----
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
   struct treeNode *leftPtr;
   int data;
   int counter;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *treePtr, int value );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );

int main()
{
   int i;
   int item;
   TreeNodePtr rootPtr = NULL;

   srand( time( NULL ) );
   printf( "Broevite koi se stavaat vo drvoto se: ");

   for ( i = 1; i <= 10; i++ ) {
      item = rand() % 15;
      printf( "%3d", item );
      insertNode( &rootPtr, item );
   }

   printf( "\n\nPominuvanjeto vo preOrder dava:\n" );
   preOrder( rootPtr );

   printf( "\n\nPominuvanjeto vo inOrder dava:\n" );
   inOrder( rootPtr );

   printf( "\n\nPominuvanjeto vo postOrder dava:\n" );
   postOrder( rootPtr );

   return 0;
}

void insertNode( TreeNodePtr *treePtr, int value )
{
      if ( *treePtr == NULL ) {
      *treePtr = malloc( sizeof( TreeNode ) );

      if ( *treePtr != NULL ) {
         ( *treePtr )->data = value;
         ( *treePtr )->counter = 1;
         ( *treePtr )->leftPtr = NULL;
         ( *treePtr )->rightPtr = NULL;
      }
      else {
         printf( "%d ne e vneseno. Nema dovolno memorija.\n", value );
      }
   }
   else {
      if ( value < ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->leftPtr ), value );
      }

      else if ( value > ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->rightPtr ), value );
      }
      else {
          (*treePtr)->counter+=1;
      }
   }
}

void inOrder( TreeNodePtr treePtr )
{
   if ( treePtr != NULL ) {
      inOrder( treePtr->leftPtr );
      printf( "%3d(%d)", treePtr->data, treePtr->counter );
      inOrder( treePtr->rightPtr );
   }
}

void preOrder( TreeNodePtr treePtr )
{
   if ( treePtr != NULL ) {
      printf( "%3d(%d)", treePtr->data, treePtr->counter );
      preOrder( treePtr->leftPtr );
      preOrder( treePtr->rightPtr );
   }
}

void postOrder( TreeNodePtr treePtr )
{
   if ( treePtr != NULL ) {
      postOrder( treePtr->leftPtr );
      postOrder( treePtr->rightPtr );
      printf( "%3d(%d)", treePtr->data, treePtr->counter );
   }
}
*/

/*
-----Zadaca 5-----
// Objasnuvanje: Pri brisenje na teme kaj BST ima 3 razlicni nacini
// Case 1: ako sakame da izbriseme list vo drvoto togash samo pokazuvacot na negoviot roditel go postavuvae na null i toa teme so free(node) si gi
// vrakjame resursite
// Case 2: ako sakame da izbriseme teme koe ima samo edeno dete leve ili desno togash pri brisenje pokazuvacot na rodetelot koj pokazuva kon temeto
// koe sakame da go izbriseme go menuvame da pokazuva kaj edinstvenoto dete na temeto koe sakame da go izbriseme i potot so free(node) osloboduvame
// zafateni resursi
// Case 3: ako temeto koe sakame da go izbirseme ima 2 deca togash ili go barame temeto so minimalana vrednost vo desnoto poddrvo ili go barame
// temeto so maksimalna vrednost vo levoto pod drvo i vrednosta na temeto koe sakame da go izbriseme ja menuvame so edna od ovie vred. Sega imame vo
// drvoto 2 teminja so ista vrednost rekurzivno ja povikvame pak funkcijata i zavisno od Case-ot kje se izbirse duplikat temeto, odnosno sega probuvame
// da gi izbriseme temeto vo poddrvoto od koe ja kopiravme vrednosta. Vo ovoj kod go naogjam temeto so minimalna vrednost vo desnoto poddrvo i potoa ja
// brisam duplikat vrednosta od toa poddrvo
// Kodot e zemen od sledniot link: https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *treePtr, int value );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );
TreeNodePtr deleteNode(TreeNodePtr root, int key);
TreeNodePtr minValueNode(TreeNodePtr treePtr);

int main()
{
   int i;
   int item;
   TreeNodePtr rootPtr = NULL;

   srand( time( NULL ) );
   printf( "Broevite koi se stavaat vo drvoto se: ");

   for ( i = 1; i <= 10; i++ ) {
      item = rand() % 15;
      printf( "%3d", item );
      insertNode( &rootPtr, item );
   }

   printf( "\nPominuvanjeto vo preOrder dava:\n" );
   preOrder( rootPtr );

   printf("Vnesi node za brisenje: ");
   int broj;
   scanf("%d", &broj);
   rootPtr=deleteNode(rootPtr, broj);

   printf( "\nPominuvanjeto vo preOrder dava:\n" );
   preOrder( rootPtr );

   return 0;
}

void insertNode( TreeNodePtr *treePtr, int value )
{
      if ( *treePtr == NULL ) {
      *treePtr = malloc( sizeof( TreeNode ) );

      if ( *treePtr != NULL ) {
         ( *treePtr )->data = value;
         ( *treePtr )->leftPtr = NULL;
         ( *treePtr )->rightPtr = NULL;
      }
      else {
         printf( "%d ne e vneseno. Nema dovolno memorija.\n", value );
      }
   }
   else {
      if ( value < ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->leftPtr ), value );
      }

      else if ( value > ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->rightPtr ), value );
      }
      else {
          printf("...");
      }
   }
}

void preOrder( TreeNodePtr treePtr )
{
   if ( treePtr != NULL ) {
      printf( "%3d", treePtr->data);
      preOrder( treePtr->leftPtr );
      preOrder( treePtr->rightPtr );
   }
}

TreeNodePtr minValueNode(TreeNodePtr treePtr)
{
    TreeNodePtr current = treePtr;

    while (current && current->leftPtr != NULL)
        current = current->leftPtr;

    return current;
}

TreeNodePtr deleteNode(TreeNodePtr root, int key)
{
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->leftPtr = deleteNode(root->leftPtr, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->rightPtr = deleteNode(root->rightPtr, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->leftPtr == NULL)
        {
            TreeNodePtr temp = root->rightPtr;
            free(root);
            return temp;
        }
        else if (root->rightPtr == NULL)
        {
            TreeNodePtr temp = root->leftPtr;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        TreeNodePtr temp = minValueNode(root->rightPtr);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->rightPtr = deleteNode(root->rightPtr, temp->data);
    }
    return root;
}
*/
