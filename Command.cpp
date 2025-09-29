#include "Command.h"
#include "Mediator.h"

void Command::execute () {
    // no implementation
}

void SendMessageCommand::execute () {
    chatRoom->sendMessage(message, *fromUser);
}

void LogMessageCommand::execute () {
    chatRoom->saveMessage(message, *fromUser);
}