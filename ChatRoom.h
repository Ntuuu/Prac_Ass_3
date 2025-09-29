#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include "Users.h"
#include <list>


class ChatRoom{

public:

virtual void registerUser(Users user) = 0;
void sendMessage(std::string message, Users fromUser);
void saveMessage(std::string message, Users fromUser);
virtual void removeUser(Users user) = 0;
std::list<Users*>* getUsers();
int incrementNumUsers();
int getNumUsers();

private:

std::list<Users*>* users;
int numUsers = 0;
std::string* chatHistory;


};

#endif