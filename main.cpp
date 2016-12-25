#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
#include <vector>
#include <map>
//JOHN ELSTAD, 12/25/2016- A basic Zuul Game RPG thing
using namespace std;
void noRoom(){
  cout<<"There is no room here"<<endl;
}

int main(){
  cout<<"Welcome to Zuul"<<endl;
  bool running = true;
  vector<item*> inventory;
  //initializes rooms
  room* home = new room("home");
  room* street = new room("Street");
  room* pub = new room("Pub");
  room* store = new room("Store");
  room* lab = new room("Lab");
  room* living = new room("LivingRoom");
  room* upstairs = new room("UpStairs");
  room* kitchen = new room("Kitchen");
  room* patio = new room("Patio");
  room* lawn = new room("Lawn");
  room* gameRoom = new room("GameRoom");
  room* closet = new room("Closet");
  room* bedroom = new room("Bedroom");
  room* bathroom = new room("Bathroom");
  room* bathtub = new room("Bathtub");

  item* sword = new item("Sword");
  item* hat = new item("Hat");
  item* dog = new item("Dog");
  item* cat = new item("Cat");
  item* soap = new item("Soap");
  item* flea = new item("Flea");
  inventory.push_back(flea);
  //sets exits
  home->setExits(street,upstairs,living,kitchen);
  street->setExits(store,pub,home,lab);
  store->setExits(NULL,NULL,street,NULL);
  lab->setExits(NULL,street,NULL,NULL);
  pub->setExits(NULL,NULL,NULL,street);
  kitchen->setExits(NULL,home,NULL,kitchen);
  patio->setExits(NULL,kitchen,NULL,lawn);
  lawn->setExits(NULL,patio,NULL,NULL);
  living->setExits(home,NULL,NULL,gameRoom);
  gameRoom->setExits(NULL,living,NULL,NULL);
  upstairs->setExits(NULL,bedroom,NULL,home);
  bedroom->setExits(closet,bathtub,bathroom,upstairs);
  closet->setExits(NULL,NULL,bedroom,NULL);
  bathtub->setExits(NULL,NULL,NULL,bedroom);
  bathroom->setExits(bedroom,NULL,NULL,NULL);
  
  room* current = home; 
  char input[50];
  while(running){
    cout<<"You are currently in:"<<current->getName()<<endl;
    cout<<"Your exits options are:"<<endl;
    //displays exits
    current->printExits();
    cout<<"Where would you like to go? NORTH, WEST, EAST or SOUTH?"<<endl;
    
    //prints items
    cout<<"items in this room:"<<endl;
    current->printItem();
    cin>>input;
    //does all the player movment between rooms
    if(strcmp(input, "NORTH")==0){
      if((current->getExits(1))!=NULL){
	current=current->getExits(1);
      }
      else{
	noRoom();
      }
    }
    else if(strcmp(input, "WEST")==0){
      if((current->getExits(2))!=NULL){
	  current = current->getExits(2);
	}
      else{
	noRoom();
      }
    }
    else if(strcmp(input, "SOUTH")==0){
      if((current->getExits(3))!=NULL){
	  current=current->getExits(3);
	}
      else{
	noRoom();
      }
    }
    else if(strcmp(input, "EAST")==0){
      if((current->getExits(4))!=NULL){
	  current=current->getExits(4);
	}
      else{
	noRoom();
      }
    }
    //quits program
    else if(strcmp(input, "QUIT")==0){
      running=false;
    }
    //displays inventory on user command
    else if(strcmp(input, "INVENTORY")==0){
      for(vector<item*>::iterator it = inventory.begin(); it != inventory.end();it++){
	cout<<(*it)->getName()<<endl;
      }
    }
    //deals with room inventory
    else if(strcmp(input,"DROP")==0){
      cout<<"What item would you like to drop?"<<endl;
      cin>>input;
      for(vector<item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	if(strcmp((*it)->getName(),input)==0){
	  current->dropItem((*it));
	  *it = inventory.back();
	  inventory.pop_back();
	  break;
	}
      }
    }
    //deals with player inventory
    else if(strcmp(input,"GRAB")==0){
      cout<<"What item would you like to grab?"<<endl;
      cin>>input;
      for(vector<item*>::iterator it = inventory.begin();it != inventory.end();it++){
	
      }
    }
    else{
      cout<<"WEST, EAST, NORTH, SOUTH, QUIT, DROP, GRAB and INVENTORY are the only valid commands"<<endl;
    }
  }
}


