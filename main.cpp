// add your code as appropriate 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

int main()
{
  get_east_storage("05/20/2018");
  
  get_min_east();
  
  get_max_east();

  compare_basins("09/13/2018");
  
  return 0;
}
