#include "Mediator.h"

class Command {
    protected:
        ChatRoom* chatRoom;
        Users* fromUser;
        std::string message;
    public:
        virtual ~Command() {}
        virtual void execute() = 0;
};

class SendMessageCommand : public Command {
    public:
        SendMessageCommand(ChatRoom* chatRoom, Users* fromUser, const std::string& message) {
            this->chatRoom = chatRoom;
            this->fromUser = fromUser;
            this->message = message;
        }
        void execute() override {
            chatRoom->sendMessage(*fromUser, message);
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
            chatRoom->saveMessage(*fromUser, message);
        }   
};