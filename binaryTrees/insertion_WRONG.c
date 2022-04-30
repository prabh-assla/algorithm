#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
  struct node* left;
  int data;
  struct node* right;
} node;

void inORDER( node* root ){
  
  if( root != NULL ){
    inORDER( root -> left );
    printf("%d ", root -> data);
    inORDER( root -> right );
  }
                             
}

node* createNODE( int val ){
  
  node* ptr = ( node* ) malloc( sizeof( node ) );
  
  ptr -> left = NULL;
  ptr -> data = val;
  ptr -> right = NULL;
  
  return ptr;
  
}

bool insertion( node* root, int key ){
  
  if( root == NULL ){
    
    node* ptr = createNODE ( key );
    root = ptr;
    
  }
  
  else{
    
    if( key == root->data )
      return false;
    
    else if( key < root->data )
      insertion ( root->left , key );
    
    else
      insertion( root->right, key );
    
  }
                                       
}
 

// our tree ->

//         7
//       /   \
//      3     11
//    /  \   /   \
//   1    5 8     12
//         \        
//          6   


int main(){
  
  node* ptr[8];
  
  
  ptr[0] = createNODE( 7 );
  ptr[1] = createNODE( 3 );
  ptr[2] = createNODE( 11 );
  ptr[3] = createNODE( 1 );
  ptr[4] = createNODE( 5 );
  ptr[5] = createNODE( 8 );
  ptr[6] = createNODE( 12 );
  ptr[7] = createNODE( 6 );
  
  
  ptr[0] -> left = ptr[1];
  ptr[0] -> right = ptr[2];
  
  ptr[1] -> left = ptr[3];
  ptr[1] -> right = ptr[4];
  
  ptr[2] -> left = ptr[5];
  ptr[2] -> right = ptr[6];
  
  ptr[4] -> right = ptr[7];
  
  inORDER ( ptr[0] );
  
  bool able = insertion( ptr[0], 9 );
  
  if( able )
      printf("\nthe element was successfully inserted...!\n");
  
  else
      printf("\nthe element is already present...!\n"); 
  
   inORDER ( ptr[0] );
  return 0;
  
}
