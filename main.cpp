#include <iostream>
using namespace std;

int main(){
  int role;
  cout << "Choose a role" << endl;
  cin >> role;
  // if user enters 1, Student. If user enters 2, Admin; If user enters 3, exit.
  if(role < 0  && role > 3)
  {  
    cout << "Invalid, Choose a role" << endl;
  }
    

