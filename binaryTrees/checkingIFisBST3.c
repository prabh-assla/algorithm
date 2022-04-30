#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
            
static node* comparisonWITH = NULL;
            
bool isitBST( node* root ){
  
  if( root != NULL ){
    
    if( !isitBST( root -> left ) ){
      printf("value of error -> %d\n", root -> data);
      return false;
    }
    
    if( ( comparisonWITH != NULL ) && ( root -> data < comparisonWITH -> data ) ){
      printf("value of error -> %d\n", root -> data);
      return false;
    }
    
    comparisonWITH = root;
    
    return isitBST( root -> right ); 
    
    /* i guess we can avoid return; 
    but it would be much better to use it since we have approached the end of the particular process 
    when we enter isitBST( root -> right) */

  }
  
  else
    return true;
  
}        

 
// our tree ->

//         7
//      /     \                         
//     4        10
//   /   \    /   \                    * -> stands for error in a certain value; 2* be replaced by 5 
//  2    5    9    9*                              1* be replaced by 3
// /  \   \  /    \                  & -> stands for final value of COMPARISON WITH...
// 1   3  6 11*&      12
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
  ptr[6] = createNODE( 9 );
  ptr[7] = createNODE( 1 );
  ptr[8] = createNODE( 3 );
  ptr[9] = createNODE( 6 );
  ptr[10] = createNODE( 11 );
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
  
  bool isit = isitBST( ptr[0] );
  
  printf("\nthe final value of comparisonWITH -> %d\n", comparisonWITH -> data);
  
  if( isit )
    printf("the given tree is BST...!\n");
  
  else
    printf("no it is not a BST...!\n");
  
  
  return 0;
  
}
