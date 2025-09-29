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
    
    //std::ostream os;
    
    
    std::cout << "User: " << fromUser.getName() << " sent:\n";
    std::cout << message;




}

void ChatRoom::saveMessage(std::string message, Users fromUser){
    
    //std::string* saveMessage = &message;
    std::string messageToSave = fromUser.getName() + " sent " + message;

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


std::string Users::getName(){
    return name;
}


// void Users::send(std::string message, ChatRoom* room){
//     room->sendMessage(message, *this);
//     room->saveMessage(message, *this);
// }

void Users::addCommand(Command* command){
    commandQueue.push_back(command);
}
void Users::executeAll(){
    for(Command* cmd : commandQueue){
        cmd->execute();
    }
    commandQueue.clear();
}

void Users::send(std::string message, ChatRoom* room){
    Command* cmd = new SendMessageCommand(room, this, message);
    addCommand(cmd);
    Command* logCmd = new LogMessageCommand(room, this, message);
    addCommand(logCmd);

    executeAll();
}


void Users::receive(std::string message, Users fromUser, ChatRoom* room){

}


void CtrlCat::registerUser(Users user){
    
    Users* newUser = &user;

    getUsers()->push_back(newUser);
   
    // Users* users = getUsers();
    // Users* newUser = &user;

    // std::list<Users*>* userList = new std::list<Users*>();
    
    // userList->add(newUser);
    
    // users = userList.get(0)




}

void CtrlCat::removeUser(Users user){

    // auto it = getUsers()->begin();
    
    
    //  auto getValueAt = [](const std::list<int>& lst, size_t pos) -> int {
    //     if (pos >= lst.size()) {
    //         throw std::out_of_range("Position out of range");
    //     }
    //     auto it = lst.begin();
    //     std::advance(it, pos);
        
    
    
    // for(int i = 0; i < getNumUsers(); i++){
    //     if(user == it.)


    //     std::advance(it, 1);
}


