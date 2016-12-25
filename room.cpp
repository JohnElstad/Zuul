
#include "room.h"
#include <iostream>
#include<vector>
#include "item.h"

using namespace std;

room::room(const char* name){
  this->name= strdup(name);
}
room::~room(){

}
char* room::getName(){
  return name;
}
char* room::getDescription(){
  return description;
}
void room::setExits(room* north, room* east, room* south, room* west){
  exits[1]=north;
  exits[2]=east;
  exits[3]=south;
  exits[4]=west;

}
room* room::getEast(){

}
room* room::getExits(int x){
  map<int, room*>::iterator it = exits.find(x);
  if(it != exits.end()){
    return it->second;
  }
}
room* room::getNorth(){
  
}
room* room::getSouth(){
  
}
room* room::getWest(){
  
}
void room::printExits(){
  for(map<int,room*>::iterator it = exits.begin(); it != exits.end();it++){
    if((*it).second!=NULL&&(*it).first==1){
      cout<<"NORTH:"<<(*it).second->getName()<<endl;
    }
    if((*it).second!=NULL&&(*it).first==2){
      cout<<"WEST:"<<(*it).second->getName()<<endl;
    }
    if((*it).second!=NULL&&(*it).first==3){
      cout<<"SOUTH:"<<(*it).second->getName()<<endl;
    }
    if((*it).second!=NULL&&(*it).first==4){
      cout<<"EAST:"<<(*it).second->getName()<<endl;
    }
  }
}
void room::printItem(){

}
void room::dropItem(){

}
void room::grabItem(){

}
