#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class room{
 public:
  room(const char* name);
  ~room();
  void setExits(room* north,room* east, room* south,room* west);
  char* getName();
  char* getDescription();
  void printExits();
  room* getExits(int x);
  room* getWest();
  room* getEast();
  room* getSouth();
  room* getNorth();
  void printItem();
  void dropItem(item* item);
  void grabItem(item* item);
  bool checkItem(item* item);
private:
  char* name;
  char* description;
  map<int,room*> exits;
  vector<item*> roomItems;
};
#endif
