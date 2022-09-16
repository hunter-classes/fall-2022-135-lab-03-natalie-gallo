#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h"
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2){

  std::string junk;
  std::string file_date;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;
  int range; 
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }

  getline(fin, junk); // read one line from the file

  while (fin >> file_date){
    fin.ignore(INT_MAX, '\n');
    if (file_date == date1){
      fin >> date1;
    }
  }

  while (fin >> file_date){
    fin.ignore(INT_MAX, '\n');

    if (file_date == date2){
      fin >> date2;
    }

    range = range + 1;
  }

  const int SIZE = range;

  std::string dates[SIZE];
  double west_elevation[SIZE];

  while (fin >> file_date >> eastSt >> eastEl >> westSt >> westEl) {
    fin.ignore(INT_MAX, '\n');
    
    if (dates[SIZE] <= date1){
    west_elevation[range] = westEl;
    dates[range] = file_date;
    range = range + 1;
    }
  }

  for (int i = SIZE - 1; i >= 0; i--){
    std::cout << dates[i] << " " << west_elevation[i] << " ft \n";
  }
  
  fin.close();
}
    

  
    

