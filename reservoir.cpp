// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h"

//TASK A

double get_east_storage(std::string date) {
  
  std::string junk;
  std::string Point_time;
  double eastSt;
  
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

//TASK B

double get_min_east(){
  std::string junk;
  std::string date;
  double eastSt;
  double min = INT_MAX;
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  
  getline(fin, junk); // read one line from the file
  
  while (fin >> date >> eastSt) {
    fin.ignore(INT_MAX, '\n'); //ignores remaining columns
    
    if (eastSt < min) {
      min = eastSt;
    }
  }
   
  std::cout << "Minimum storage in East basin: " << min << " billion gallons \n";
  
  fin.close();

  return min;
}

double get_max_east(){
  std::string junk;
  std::string date;
  double eastSt;
  double max = INT_MIN;
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  
  getline(fin, junk); // read one line from the file
  
  while (fin >> date >> eastSt) {
    fin.ignore(INT_MAX, '\n'); //ignores remaining columns
    
    if (eastSt > max) {
      max = eastSt;
    }
  }
   
  std::cout << "Maximum storage in East basin: " << max << " billion gallons \n";
  
  fin.close();

  return max;
}


//TASK C

std::string compare_basins(std::string date){
  std::string junk;
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
  
  getline(fin, junk); // read one line from the file

  while (fin >> file_date >> eastSt >> eastEl >> westSt >> westEl){
    fin.ignore(INT_MAX, '\n'); //ignores remaining column;

    if (file_date == date){
      if (eastEl > westEl){
	std::cout << date << " East \n";
      } else if (eastEl < westEl){
	std::cout << date << " West \n";
      } else if (eastEl == westEl){
       std::cout << date << " Equal \n";
      }
    }
  }
  
   fin.close();
   return 0;
}

    
