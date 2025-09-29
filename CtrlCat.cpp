#include "CtrlCat.h"

void CtrlCat::registerUser(Users user){
    
    Users* newUser = &user;

    getUsers()->push_back(newUser);
   
    // Users* users = getUsers();
    // Users* newUser = &user;

    // std::list<Users*>* userList = new std::list<Users*>();
    
    // userList->add(newUser);
    
    // users = userList.get(0)




}