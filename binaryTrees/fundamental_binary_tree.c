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

int main(){
  
  node* ptr[3];
  
  
  ptr[0] = createNODE ( 1 );
  ptr[1] = createNODE( 5 );
  ptr[2] = createNODE( 7 );
  
  ptr[1] -> left = ptr[0];
  ptr[1] -> right = ptr[2];
  
  
  return 0;
  
}
