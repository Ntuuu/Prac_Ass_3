#pragma once
#include <string>

// Forward declarations to avoid circular include
class ChatRoom;
class Users;

class Command {
    protected:
        ChatRoom* chatRoom;
        Users* fromUser;
        std::string message;
    public:
        virtual ~Command() {}
        virtual void execute();
};

class SendMessageCommand : public Command {
    public:
        SendMessageCommand(ChatRoom* chatRoom, Users* fromUser, const std::string& message) {
            this->chatRoom = chatRoom;
            this->fromUser = fromUser;
            this->message = message;
        }
        void execute() override {
            chatRoom->sendMessage(message, *fromUser);
        }
};

class LogMessageCommand : public Command {
    public:
        LogMessageCommand(ChatRoom* chatRoom, Users* fromUser, const std::string& message) {
            this->chatRoom = chatRoom;
            this->fromUser = fromUser;
            this->message = message;
        }
        void execute() override {
            chatRoom->saveMessage(message, *fromUser);
        }   
};