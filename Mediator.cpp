#include "Mediator.h"

int ChatRoom::incrementNumUsers(){
    numUsers++;
    return numUsers;
}

std::list<Users*>* ChatRoom::getUsers(){
    return users;
}

std::list<std::string*>* ChatRoom::getChatHistory(){
    return chatHistory;
}


int ChatRoom::getNumUsers(){
    return numUsers;
}

void ChatRoom::sendMessage(std::string message, Users fromUser){
    std::cout << "User: " << fromUser.toString() << " sent:\n";
    std::cout << message;

}

void ChatRoom::saveMessage(std::string message, Users fromUser){
    
    //std::string* saveMessage = &message;
    std::string messageToSave = fromUser + " sent " + message;

    getChatHistory()->push_back(&messageToSave);
    
}

// void ChatRoom::sendMessage(std::string message, Users fromUser){
//     for(Users* user : *users){
//         if(user->name != fromUser.name){
//             user->receive(message, fromUser, *this);
//         }
//     }
// }
// void ChatRoom::saveMessage(std::string message, Users fromUser){
//     *chatHistory += fromUser.name + ": " + message + "\n";
// }

void CtrlCat::registerUser(Users user){
    
    Users* newUser = &user;

    getUsers()->push_back(newUser);
   
    // Users* users = getUsers();
    // Users* newUser = &user;

    // std::list<Users*>* userList = new std::list<Users*>();
    
    // userList->add(newUser);
    
    // users = userList.get(0)




}