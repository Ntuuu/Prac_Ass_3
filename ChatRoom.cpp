#include "ChatRoom.h"

int ChatRoom::incrementNumUsers(){
    numUsers++;
    return numUsers;
}

std::list<Users*>* ChatRoom::getUsers(){
    return users;
}

int ChatRoom::getNumUsers(){
    return numUsers;
}