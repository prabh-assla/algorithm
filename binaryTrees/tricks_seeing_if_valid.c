#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node* left;
  int data;
  struct node* right;
} node;

node* createNODE( int val ){
  
  node* ptr = ( node* ) malloc( sizeof( node ) );
  
  ptr -> left = NULL;
  ptr -> data = val;
  ptr -> right = NULL;
  
  return ptr;
  
}


void preORDER( node* root ){
  
  if( root != NULL ){
    printf("%d ", root -> data);
    preORDER( root -> left );
    preORDER( root -> right );
  }
                             
}
            
            
void inORDER( node* root ){
  
  if( root != NULL ){
    inORDER( root -> left );
    printf("%d ", root -> data);
    inORDER( root -> right );
  }

}          


void postORDER( node* root ){
  
  if( root != NULL ){
    postORDER( root -> left );
    postORDER( root -> right );
    printf("%d ", root -> data);
  }
                             
}

 
// our tree ->

//         7
//      /     \
//     4        10
//   /   \    /   \
//  2     5   9    11
// /  \   \   /    \ 
//  1 3   6 8      12
// /
//0
int main(){
  
  node* ptr[13];
  
  
  ptr[0] = createNODE( 7 );
  ptr[1] = createNODE( 4 );
  ptr[2] = createNODE( 10 );
  ptr[3] = createNODE( 2 );
  ptr[4] = createNODE( 5 );
  ptr[5] = createNODE( 9 );
  ptr[6] = createNODE( 11 );
  ptr[7] = createNODE( 1 );
  ptr[8] = createNODE( 3 );
  ptr[9] = createNODE( 6 );
  ptr[10] = createNODE( 8 );
  ptr[11] = createNODE( 12 );
  ptr[12] = createNODE( 0 );
  
  ptr[0] -> left = ptr[1];
  ptr[0] -> right = ptr[2];
  
  ptr[1] -> left = ptr[3];
  ptr[1] -> right = ptr[4];
  
  ptr[2] -> left = ptr[5];
  ptr[2] -> right = ptr[6];
  
  ptr[3] -> left = ptr[7];
  ptr[3] -> right = ptr[8];
  
  ptr[4] -> right = ptr[9];
  
  ptr[5] -> left = ptr[10];
  
  ptr[6] -> right = ptr[11];
  
  ptr[7] -> left = ptr[12];
   
  printf("preORDER -> ");
  preORDER( ptr[0] );
  printf("\n");
  
  printf("postORDER -> ");
  postORDER( ptr[0] );
  printf("\n");
  
  printf("inORDER -> (arranges in ascending order) ");
  inORDER( ptr[0] );
  printf("\n");
  
  
  return 0;
  
}
