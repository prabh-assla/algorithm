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

bool leafnode( node* root ){

    if( ( root->left == NULL ) && ( root->right == NULL ) )
    return true;

    else
    return false;
}

node* IOS( node* root ){

    root = root->right;

    while( root->left != NULL )
        root = root->left;

return root;

}

node* deletion( node* root, int key ){

    if( root == NULL )
    return NULL;

    if( root->data == key ){

        if( leafnode( root ) ){
        free( root );
        return NULL;
        }

        else{
            node* inorderSUCCESSOR = IOS( root );
            root->data = inorderSUCCESSOR->data;
            root->right = deletion( root->right, root->data );
            
        }

    }

    if( root->data > key )
    root->left = deletion( root->left, key );

    else
    root->right = deletion( root->right, key );

return root;

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

      inORDER( ptr[0] ); printf("\n");
  
  node* isdeleted = deletion( ptr[0], ptr[0] );
  
  isdeleted = deletion( isdeleted, isdeleted->data);
  printf("%d\n", isdeleted->data);

  isdeleted = deletion( isdeleted, isdeleted->data);
  printf("%d\n", isdeleted->data);

  isdeleted = deletion( isdeleted, isdeleted->data); 
  printf("%d\n", isdeleted->data);

  isdeleted = deletion( isdeleted, isdeleted->data); 
  printf("%d\n", isdeleted->data);

  isdeleted = deletion( isdeleted, isdeleted->data); 
  printf("%d\n", isdeleted->data);

  node* newroot = isdeleted; // 12 -> value of new root

  isdeleted = deletion( newroot, 2 );
  isdeleted = deletion( newroot, 2 );

  // isdeleted->data is actually the "new ROOT" after " ROOT deletion " in BST

      inORDER( newroot ); printf("\n");
      
  if( isdeleted==NULL )
    printf("the element isn't present in BST..!\n");
  
  else
    printf("the element has been deleted successfully...!\n");
  
  
  return 0;
  
}
