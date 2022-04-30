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

void inORDER( node* root ){
  
  if( root != NULL ){
    inORDER( root -> left );
    printf("%d ", root -> data);
    inORDER( root -> right );
  }
                             
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

  }
  
  else
    return true;
  
}  

bool insertion( node* root, int key ){
  
    if( key == root->data )
      return false;
  
    
    if( key < root->data ){
      
      if( root -> left == NULL ){
        
          node* ptr = createNODE ( key );
          root -> left = ptr;
          
          return true;
      }
                           
      else
      insertion ( root->left , key );
    
    }
                                       
                                       
    else {
      
      if( root -> right == NULL ){
        
          node* ptr = createNODE ( key );
          root -> right = ptr;
        
          return true;
      }
                           
      else
      insertion ( root->right , key );
    
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
  
  bool able;

  able = insertion( ptr[0], 2 );
    able = insertion( ptr[0], 4 );
      able = insertion( ptr[0], 10 );
        able = insertion( ptr[0], 13 );
          able = insertion( ptr[0], -1 );
            able = insertion( ptr[0], -5 );

  able = insertion( ptr[0], -6 );
    able = insertion( ptr[0], -7 );
      able = insertion( ptr[0], -8 );
        able = insertion( ptr[0], -9 );
          able = insertion( ptr[0], -10 );
            able = insertion( ptr[0], 4 );
      
      if( able )
          printf("\nthe element was successfully inserted...!\n");
      
      else
          printf("\nthe element is already present...!\n"); 

  bool isit = isitBST( ptr[0] );

      if( isit )
        printf("the given tree is BST...!\n");
      
      else
        printf("no it is not a BST...!\n"); 

  inORDER( ptr[0] );

  return 0;

}