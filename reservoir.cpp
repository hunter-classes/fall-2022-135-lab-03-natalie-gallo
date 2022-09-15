// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
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
  std::string Point_time;
  double eastSt;
  double min_eastSt;
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  
  getline(fin, junk); // read one line from the file
  
  while (fin >> Point_time) {
    fin >> eastSt;
    fin.ignore(INT_MAX, '\n'); //ignores remaining columns
    
    if (eastSt < min_eastSt) {
      min_eastSt = eastSt;
    }
  }
   
  std::cout << "Minimum storage in East basin: " << min_eastSt << " billion gallons \n";
  
  fin.close();

  return min_eastSt;
}

double get_max_east(){
  std::string junk;
  std::string Point_time;
  double eastSt;
  double max_eastSt;
    
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  
  getline(fin, junk); // read one line from the file
  
  while (fin >> Point_time) {
    fin >> eastSt;
    fin.ignore(INT_MAX, '\n'); //ignores remaining columns

    if (eastSt > max_eastSt) {
      max_eastSt = eastSt;
    }
  }
  
  std::cout << "Maximum storage in East basin: " << max_eastSt << " billion gallons \n";
  
  fin.close();

  return max_eastSt;
}

//TASK C

std::string compare_basins(std::string date){
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
  //fin >> eastEl;
  fin >> westSt;
  //fin >> westEl;

  if (eastSt > westSt){
    std::cout << date << " East \n";
  } else if (eastSt < westSt){
    std::cout << date << " West \n";
  } else if (eastSt == westSt){
    std::cout << date << " Equal \n";
  }
  
   fin.close();
   return 0;
}

    
    
