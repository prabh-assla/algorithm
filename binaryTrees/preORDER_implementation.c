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


// preORDER ---> root, left, right
 

// our tree ->

//        6
//      /   \
//     5     7
//   /   \ /   \
//  2     81    9

int main(){
  
  node* ptr[7];
  
  
  ptr[0] = createNODE( 6 );
  ptr[1] = createNODE( 5 );
  ptr[2] = createNODE( 7 );
  ptr[3] = createNODE( 2 );
  ptr[4] = createNODE( 8 );
  ptr[5] = createNODE( 1 );
  ptr[6] = createNODE( 9 );
  
  
  ptr[0] -> left = ptr[1];
  ptr[0] -> right = ptr[2];
  
  ptr[1] -> left = ptr[3];
  ptr[1] -> right = ptr[4];
  
  ptr[2] -> left = ptr[5];
  ptr[2] -> right = ptr[6];
  
  preORDER( ptr[0] );
  
  
  return 0;
  
}
