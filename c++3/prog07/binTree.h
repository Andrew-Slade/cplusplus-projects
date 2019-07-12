/****************************************
*Programmer: Andrew Slade
*Due: 10/24/17
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*header file
*Purpose: Implement a binary tree structure
****************************************/

#ifndef BINTREE_H
#define BINTREE_H

//Preprocessors
#include "/home/cs340/progs/17f/p7/Node.h"
#include <algorithm>
using namespace std;
//************



//************
typedef enum {left_side, right_side} SIDE;

SIDE rnd() {return rand() % 2 ? right_side : left_side;}
//*************



template<class T> 
class binTree{
 public:
   binTree();                            //default constructor
   unsigned height();              //return height
   unsigned size() const;                //return size
   virtual void insert(const T&);        //insert a node
   void inorder(void (*) (const T&));      //inorder traversal
 private:
   unsigned height(Node<T>*) const;             //private version of height
   unsigned size(Node<T>*) const;
   void insert(Node<T>* &, const T&);            //private version of insert
   void inorder(Node<T>*,void (*) (const T&));  //private version of inorder
 protected:
   Node<T>* root;    //root
};



//constructor
template<class T>
binTree<T>::binTree(){
  root = nullptr;
}



//insert a value into the bin tree
template<class T>
void binTree<T>::insert(Node<T>* &node, const T &tval){
  if(!node){
    node = new Node<T>(tval);
  }
  else{
    //check side then insert value into desired side
    SIDE s = rnd();
    if(s == left_side){
      insert(node->left, tval); //left
    } 
    else{
      insert(node->right, tval); //right
    }
  }
 return;
}



//accessor
template<class T>
void binTree<T>::insert(const T& ptval){
  insert(root, ptval);
 return;
}



//measure bin tree height
template<class T>
unsigned binTree<T>::height(Node<T>* noded) const{
  unsigned total;

  if(!noded){
   total = 0;
  }

  else if(!noded->left && !noded->right){
   total = 1; //return size one if there are no nodes
  }

  else{
   //return the maximum height found 
   return max(height(noded->left), height(noded->right)) + 1;
  }

 return total;
}



//accessor
template<class T>
unsigned binTree<T>::height(){
 unsigned h = height(root); 
 return h;
}


//measure bin tree size 
template<class T>
unsigned binTree<T>::size(Node<T>* noded) const{
  unsigned tot; //temp

  if(!noded){
   tot = 0; //if there is no size
  }

  else{
   //return size
   return (size(noded->left) + 1 + size(noded->right));
  }

 return tot;
}



//accessor
template<class T>
unsigned binTree<T>::size() const{
 unsigned s = size(root); 
 return s;
}



//traverse bin tree inorder
template<class T>
void binTree<T>::inorder(Node<T>* order,void (*p) (const T&)){
  if(order){
    //check to see if node exists then traverse inorder
    inorder(order->left,p); //recursion
    p(order->data); //print data
    inorder(order->right,p); //recursion
  }
  return;
}



//accessor
template<class T>
void binTree<T>::inorder(void (*f) (const T&)){
  inorder(root,f);
 return;
}
#endif

