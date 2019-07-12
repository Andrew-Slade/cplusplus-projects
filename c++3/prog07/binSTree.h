/****************************************
*Programmer: Andrew Slade
*Due: 11/02/17
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*header file
*Purpose: Implement a binary search 
*tree structure
****************************************/

#ifndef BINSTREE_H
#define BINSTREE_H

//Preprocessors
#include "binTree.h"
//************

template <class T>
class binSTree : public binTree<T>{
 public:
   void insert(const T& x);  //public accessor
   void remove(const T& x);  //public accessor
 private:
   void insert(Node<T>*&, const T&); //insert function private
   void remove(Node<T>*&, const T&); //remove function private
   Node<T>* pred(Node<T>*);          //find predecessor function
};



//insert into binary tree
template<class T>
void binSTree<T>::insert(Node<T>* &anode, const T &atval){
  if(!anode){
    anode = new Node<T>(atval); //create new node
  }
  else{
    //check side then insert value into desired side
    if(atval > anode->data){
      insert(anode->right, atval); //right
    } 
    else{
      insert(anode->left, atval); //left
    }
  }
 return;
}



//public accessor
template<class T>
void binSTree<T>::insert(const T& x){
   insert(this->root, x);
 return;	
}



//remove from binary search tree
template<class T>
void binSTree<T>::remove(Node<T>* &aroot, const T& antval){
  Node<T>* temp; //temp
  Node<T>* pre; //predecessor
 
  if(!aroot){
    return;
  }


  else if(aroot->data == antval){
  
    if(!aroot->right && !aroot->left){
     //case such that there is only a leaf
     aroot = nullptr; //delete node
     delete aroot; //clear memory
    }
    

    else if(!aroot->right && aroot->left){
      //case such that there is only the left child
      temp = aroot; //hold the value for aroot
      aroot = aroot->left; //assign child to parent
      temp = nullptr; //delete parent
      delete temp; //clear memory
    }
  
    else if(aroot->right && !aroot->left){
      //case such taht there is only the right child
      temp = aroot;
      aroot = aroot->right;
      temp = nullptr;
      delete temp;
    }
  

    else if(aroot->right && aroot->left){
      //case such that there are two children
      pre = pred(aroot); //find predecessor
      temp = aroot; //hold aroot value
      remove(aroot, pre->data); //remove predecessor
      temp = nullptr; //get rid of node to remove
      delete temp; //destroy temp memory
    }
   }
  

  else{
    if(aroot->data < antval){
      //if aroot is smaller than antval, then go to the right
      remove(aroot->right,antval);
    }


    else if(aroot->data > antval){
      //if aroot is bigger, then go to the left
      remove(aroot->left,antval); 
    } 
  }
  
 return;
}


//public accessor
template<class T>
void binSTree<T>::remove(const T& r){
   remove(this->root,r);
 return;
}


//find predecessor
template<class T>
Node<T>* binSTree<T>::pred(Node<T>* toor){
   Node<T>* pr = toor->left;

   // while the right node exists, go right
   while(pr->right){
     pr = pr->right;//get predecessor
   }

  return pr;
}
#endif
