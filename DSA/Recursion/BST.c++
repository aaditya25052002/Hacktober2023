#include <iostream>
#include "bst.h"

/* ------- Search in BST -------*/
BinaryTreeNode<int>* SearchInBST(BinaryTreeNode<int>* root , int k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == k){
        return root ;
    }
    if(root->data > k){
        return SearchInBST(root->left , k);
    }
    else{
        return SearchInBST(root->right , k);
    }

}

/* -------- Element in Between k1 & k2 ---------*/

void elementsInRangek1k2(BinarySearchNode <int>* root , int k1 , int k2){
    if(root == NULL){
        return ;
    }
    if(root->data > k1){
        return elementsInRangek1k2(root->left ,k1,k2);
    }
    if(root->data <= k2){
        return elementsInRangek1k2(root->right ,k1,k2)
    }
    if(k1 <= root->data && k2 >= root->data){
        cout<<root->data<<" ";
    }
}

/* --------- TO CHECK BST ---------*/

int maximum (BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN ;
    }
    return max(root->data ,max(maximum(root->left) ,maximum(root->right))) ;
}
int minimum (BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX ;
    }
    return min(root->data ,min(minimum(root->left) ,minimum(root->right))) ;
}

bool IsBST (BinaryTreeNode<int>* root){
    if(root == NULL){
        return true ;
    }
    int leftmax = maximum(root->left);
    int rihgtmin = minimum(root->right);
    bool output = (root->data > leftmax) && (root->data <= rihgtmin) && IsBST(root->left) && IsBST(root->right){
        return output ;
    }
}

/* -------- BST FROM  A SORTED ARRAY -------*/
BinaryTreeNode<int>* tree(int *input , int start , int end){
    if(start>end){
        return NULL;
    }
    int mid =  (start + end ) / 2 ;
    BinaryTreeNode<int>* root = new BinaryTreeNode <int>(input[mid]);
    root->left = tree (input , start , mid-1);
    root->right = tree (input , mid+1 , end);
    return root ;
}
BinaryTreeNode<int>* constructTree(int *input , int n){
    int start = 0;
    int end = n - 1 ;
    tree(input ,start , end);
}

/* ---- BST TO SORTED LINKED LIST -----*/

class base{
    public:
    Node<int>*head;
    Node<int>*tail;
};

base abc(BinaryTreeNode<int>* root){
    if(root == NULL){
        base b;
        b.head = NULL;
        b.tail = NULL;
        return b;
    }
    base l = abc(root->left);
    base r = abc(root->right);
    Node<int> *n = new Node <int>(root->data);

    if(tail != NULL){
        l.tail ->next = n;
        n->next = r.head ;
        base b;   
    }
    if(head != NULL){
    b.head = l.head ;
    }
    else{
    b.head = n ; 
    }
    if(r.tail != NULL){
    b.tail = r.tail ;
    }
    else {
    b.tail = n;
    }
    return b;
   
}

/*------ 


int main(){



    return 0;
}
