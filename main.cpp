// add your code as appropriate 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  //TASK A TESTS
  get_east_storage("05/20/2018");
  get_east_storage("01/01/2018");
  get_east_storage("12/30/2018");

  std::cout << std::endl;

  //TASK B: Find minimum and maximum storage in 2018
  
  get_min_east();
  
  get_max_east();

  std::cout << std::endl;

  //TASK C TESTS

  std::cout << "09/13/2018 " << compare_basins("09/13/2018");
  std::cout << "09/14/2018 " << compare_basins("09/14/2018");
  std::cout << "09/15/2018 " << compare_basins("09/15/2018");
  std::cout << "09/16/2018 " << compare_basins("09/16/2018");
  std::cout << "09/17/2018 " << compare_basins("09/17/2018");

  std::cout << std::endl;

  //TASK D TEST

  reverse_order("05/29/2018", "06/02/2018");
  
  return 0;
}
