#include "item.h"
#include <iostream>

using namespace std;

item::item(const char* name){
  this->name=strdup(name);
  
}

item::~item(){

}
char* item::getDescription(){
  return description;
}
char* item::getName(){
  return name;
}
