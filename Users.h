#ifndef USERS_H
#define USERS_H

#include <string>
// #include "Users.h"

class ChatRoom;

class Users{

public:

void send(std::string message, ChatRoom room);
void receive(std::string message, Users fromUser, ChatRoom room);
void addCommand(Command command);
void executeAll();

protected:

ChatRoom* chatRooms;
std::string name;
Command* commandQueue;


};

#endif