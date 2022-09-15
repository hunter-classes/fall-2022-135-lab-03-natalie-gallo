#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h"
#include "reverseorder.h"

int main(){
  reverse_order("05/29/2018", "06/02/2018");
  return 0;
}

void reverse_order(std::string date1, std::string date2){

  std::string junk;
  std::string Point_time;
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

  while (Point_time.compare(date1) != 0){
    fin >> Point_time;
    fin.ignore(INT_MAX, '\n');
  }

  while (Point_time.compare(date2) != 0){
    fin >> Point_time;
    fin.ignore(INT_MAX, '\n');

    range = range + 1;
  }

  const int SIZE = range;

  std::string dates[SIZE];
  double west_elevation[SIZE];

  while (dates[0].compare(date1) !=0) {
    west_elevation[range] = westEl;
    dates[range] = Point_time;
    range = range + 1;
    fin.ignore(INT_MAX, '\n');
  }

  for (int i = SIZE - 1; i >= 0; i--){
    std::cout << dates[i] << " " << west_elevation[i] << " ft \n";
  }
  
  fin.close();
}
    

  
    

