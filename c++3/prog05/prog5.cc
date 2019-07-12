/****************************************
*Programmer: Andrew Slade
*Due: 10/10/2017
*TA: Bhaskara Reddy Devarapalli
*ZID: Z1818810
*Section: 340-0003
*source file
*Purpose: execute process to solve the 
*Josephus problem
****************************************/

//Preprocessors
#include "/home/cs340/progs/17f/p5/prog5.h"
//************



int main(){
  vector<string> soldiers;
  inargs instance;
  unsigned count = 0;
  int i = 0;
  
  init_vals(soldiers,instance);
  
  while(soldiers.size() > 1){
     //eliminates every Nth person
     if(count % instance.K == 0){
        print_vector(soldiers,count); //prints every Kth elimination
      }
     
     i +=instance.M - 1; 
     i %= soldiers.size(); //wraps around
     soldiers.erase(soldiers.begin() +i);
     count++;
   }
  
  print_vector(soldiers,count);//print the soldier that escapes
  
 return 0;
}



//initializes vector and values of N,M, and K
void init_vals(vector<string>& v, inargs& in){
  cin >> in.N >> in.M >> in.K; 
  /*
  reads in values to in args for soldier count,
  index for removal, and the final removal count 
 */

  cout << "Number of people? " << in.N << endl 
       << "Index for elimination? " << in.M << endl
       << "Index for printing? " << in.K << endl;

  v.resize(in.N); //resize vector to N
  generate(v.begin(), v.end(), SEQ(in.N)); //gen soldier names   

 return;
}



//Prints vector initially and then after every removal
void print_vector(const vector<string>& v, const unsigned& cnt){
 //makes sure that the contraction is proper
  string append = "";
  if(cnt == 2){
    append = "nd";
   }
  else if(cnt == 1){
    append = "st";
   }
  else{
     append = "th";
   }
  //***********
 
  if(cnt == 0){
    cout << endl << "Initial group of people" << endl
         << "-----------------------" << endl;
   }
  else{
    cout << endl << "After eliminating "
         << cnt << append << " person" << endl
         << "-----------------------------" << endl;
   }
  
  for(size_t c = 0; c < v.size(); c++){
      //print vector with NO_ITEMS per line
      cout << v.at(c) << " ";
      if(((c + 1)  % NO_ITEMS) == 0){
        cout << endl;
       }  
   }
  cout << endl;
   
 return;
}
