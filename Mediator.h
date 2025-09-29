#include <string>
#include <vector>
#include <map>
#include <list>
#include <iostream>

#include "Command.h"

/**
 * @file
 * @brief Defines the ChatRoom and Users classes along with specific implementations.
 */

/**
 * @brief Abstract base class representing a chat room mediator.
 * 
 * The ChatRoom defines the communication interface for users to interact.
 * Derived classes must implement user registration and removal.
 */
class ChatRoom {

public:

    /**
     * @brief Registers a user into the chat room.
     * 
     * @param user The user to be registered.
     */
    virtual void registerUser(Users user) = 0;

    /**
     * @brief Sends a message from one user to all others in the chat room.
     * 
     * @param message  The message content.
     * @param fromUser The sender of the message.
     */
    void sendMessage(std::string message, Users fromUser);

    /**
     * @brief Saves a message into the chat history.
     * 
     * @param message  The message content.
     * @param fromUser The sender of the message.
     */
    void saveMessage(std::string message, Users fromUser);

    /**
     * @brief Removes a user from the chat room.
     * 
     * @param user The user to be removed.
     */
    virtual void removeUser(Users user) = 0;

    /**
     * @brief Retrieves the list of users in the chat room.
     * 
     * @return Pointer to a list of user pointers.
     */
    std::list<Users*>* getUsers();

    /**
     * @brief Increments the total number of users.
     * 
     * @return The new number of users after increment.
     */
    int incrementNumUsers();

    /**
     * @brief Gets the current number of users in the chat room.
     * 
     * @return The number of users.
     */
    int getNumUsers();

    std::list<Users*>* getChatHistory();

    friend std::ostream& operator<<(std::ostream& os, const Users& userName) {
        os << userName;
        return os;
    }

     std::string toString() const {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }


private:

    std::list<Users*>* users;    /**< List of users in the chat room. */
    int numUsers = 0;            /**< Number of registered users. */
    std::list<std::string*>* chatHistory;    /**< Storage for chat history. */
};

/**
 * @brief Represents a user that participates in a chat room.
 * 
 * A user can send messages, receive messages, and maintain a queue of commands.
 */
class Users {

public:

    /**
     * @brief Sends a message to a chat room.
     * 
     * @param message The message content.
     * @param room    The chat room where the message will be sent.
     */
    void send(std::string message, ChatRoom room);

    /**
     * @brief Receives a message from another user via the chat room.
     * 
     * @param message  The message content.
     * @param fromUser The user who sent the message.
     * @param room     The chat room through which the message was sent.
     */
    void receive(std::string message, Users fromUser, ChatRoom room);

    /**
     * @brief Adds a command to the user's command queue.
     * 
     * @param command The command to be added.
     */
    void addCommand(Command command);

    /**
     * @brief Executes all commands in the user's command queue.
     */
    void executeAll();

protected:

    ChatRoom* chatRooms;   /**< Reference to the chat room(s) the user is part of. */
    std::string name;      /**< The user’s display name. */
    Command* commandQueue; /**< Queue of commands for this user. */
};

/**
 * @brief A specific chat room implementation: Dogorithm.
 * 
 * Currently inherits ChatRoom without custom behavior.
 */
class Dogorithm : public ChatRoom {

};

/**
 * @brief A specific chat room implementation: CtrlCat.
 * 
 * Provides a custom implementation of user registration.
 */
class CtrlCat : public ChatRoom {

    /**
     * @brief Registers a user into the CtrlCat chat room.
     * 
     * @param user The user to be registered.
     */
    void registerUser(Users user) override;
};

/**
 * @brief Example user subclass: Name1.
 * 
 * Demonstrates how custom user types can be defined.
 */
class Name1 : public Users {

};

/**
 * @brief Example user subclass: Name2.
 * 
 * Demonstrates how custom user types can be defined.
 */
class Name2 : public Users {

};

/**
 * @brief Example user subclass: Name3.
 * 
 * Demonstrates how custom user types can be defined.
 */
class Name3 : public Users {

};
