/****************************************
*Programmer: Andrew Slade
*Due: 11/28/17
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*header file
*Purpose: Implement a hashing algorithm
*with indirect sorting 
****************************************/

#include "/home/cs340/progs/17f/p9/hTable.h"

//default constructor
HT::HT( const unsigned& hs){
 hTable.resize(hs);
 hsize = hs;
}



//destructor
HT::~HT(){
  for(size_t i = 0; i < hsize; i++){
    hTable[i].clear();
  }
}


//insert function
void HT::insert(const Entry& e){
  int hashV = hash(e.key);
  list<Entry> &l = hTable[hashV];

    auto search =  find_if(l.begin(), l.end(), [e](const Entry &k){return e.key == k.key;});

  if(search != l.end()){
    cout << "not inserted - duplicate key!!\n";
  } 
  else{
    //value is found, then add it on
    l.push_front(e);
    pTable.push_back(&l.front());
    cout << "entry = " << hashV << endl;
  }
  return;
}


//search function
void HT::search(const string& key){
  auto hashVal = hash(key);
  list<Entry> &k = hTable[hashVal];
  auto p =  find_if(k.cbegin(), k.cend(), [key](Entry t){return key == t.key;});
  if(p != k.end()){
    cout << "  ==> number: " << p->num <<" - item: " << p->desc <<  endl;
  } 
  else{
    cout << " not in table!!" << endl ;
  }
  return;
}




//print hash table
void HT::hTable_print(){
  list<Entry> temp;
  string temps;
  for(size_t i = 0; i < hTable.size(); i++){
     temp = hTable[i];
     for(auto l = temp.begin(); l != temp.end(); l++){
       cout << i << ":   "  << l->key << "  -  " << l->num << "  -  " << l->desc << endl;
       //find contents, have index
     }
  }
 return;
}



//print pointer table
void HT::pTable_print(){
  //print everything in pTable
  sort(pTable.begin(), pTable.end(), 
		  [](Entry* p, Entry* q){ return ((p->key < q->key) ? true : false ); });
  for(auto q = pTable.begin(); q != pTable.end(); q++){
    cout << "   " << (*q)->key << " - " << (*q)->num << " - " << "    " << (*q)->desc << endl;
  } 
 return;
}
