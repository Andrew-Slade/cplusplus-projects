/****************************************
*Programmer: Andrew Slade
*Due: 121/06/17
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*header file
*Purpose: Implement a digraph
****************************************/
#include "/home/cs340/progs/17f/p10/wdigraph.h"



//depth first search
void::wdigraph::depth_first(int u) const{
  vector<bool> visit(size,false);//vector initialized by default to false 
  stack<int> traverse;  
  bool search = false;

  traverse.push(u);
  while(!traverse.empty()){
   search = false; //make sure search is false
   u = traverse.top(); //assign u to top of stack

   if(!visit[u]){
     cout << label[u]; // if not visited, print 
   }
   
   visit[u] = true; //mark visited

    for(size_t c = 0; c < adj_matrix[u].size(); c++){

      if(adj_matrix[u][c] != 0 && !visit[c]){ 
	//when values is found, print the label, add it to list of visited locals, and mark as found
        traverse.push(c); 
	search = true;
        cout << "->";   
 	break;
      }

    }  

    if(!search){
      traverse.pop(); //if not found, pop
    }

   }

    cout << endl;

 return;
}



//print the graph
void wdigraph::print_graph()const{
  cout << endl << "No of Nodes = " << size << endl; //header

  cout << endl << "Adjacency Matrix" << endl << endl; // header


  //print labels
  cout << "  |";
  for(int t = 0; t < size; t++){
    cout << "  " << label[t];
  }
  cout << endl;


  //cosntruct weight factored graph
  cout << "--|";
  for(int f = 0; f < size; f++){
    cout << "---";
  }  
  cout << endl;



  for(int q = 0; q < size; q++){
    cout << label[q] << " |";
    for(int b = 0; b < size; b++){
      if(adj_matrix[q][b] != 0){
        cout << " " << setw(2) << right << adj_matrix[q][b];
      }
      else{
        cout << "  -";
      }
    }

      cout << endl;

      if(q != size - 1){
        cout << "  |" << endl;
      }
  }
  cout << endl;

 return;
}
