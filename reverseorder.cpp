#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2) {

  std::string file_date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

  std::ifstream fin("Current_Reservoir_Levels.tsv");

  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }

  std::string junk;   // new string variable
  getline(fin, junk); // read one line from the file

  bool start = false;

  int length;

  std::string dates[365];
  double west_elevation[365];

  while (fin >> file_date >> eastSt >> eastEl >> westSt >> westEl) {
  // this loop reads the file line-by-line
  // extracting 5 values on each iteration

    fin.ignore(INT_MAX, '\n'); // skips to the end of line
    
    if (file_date == date1) {
      start = true;
    }

    if (start){
      dates[length] = file_date;
      west_elevation[length] = westEl;
      length++;
    }

    if (file_date == date2){
      start = false;
    }

  }
  
  for (int i = length - 1; i >= 0; i--){
    std::cout << dates[i] << " " << west_elevation[i] << " ft \n";
  }
  
  fin.close();
}

    

  
    

