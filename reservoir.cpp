// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date) {
  
  std::string junk;
  std::string Point_time;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  
  getline(fin, junk); // read one line from the file

  while (Point_time.compare(date) != 0){
    fin >> Point_time;
  }

  fin >> eastSt;
  
  std::cout << date << " " << "East basin storage: " << eastSt << " billion gallons \n";
  
  fin.close();
  
  return 0;
}
