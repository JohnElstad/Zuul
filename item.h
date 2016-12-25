#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

class item{
  
 public:
  item(const char* name);
  ~item();
  char* getName();
  char* getDescription();
 private:
  char* name;
  char* description;
  
};
#endif
