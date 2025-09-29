#ifndef CTRLCAT_H
#define CTRLCAT_H

#include <string>
#include "ChatRoom.h"

class CtrlCat : public ChatRoom{

    void registerUser(Users user) override;
};

#endif