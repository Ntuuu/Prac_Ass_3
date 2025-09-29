#include <string>
#include <vector>
#include <map>
#include <list>
#include <iostream>

#include "Command.h"

/**
 * @file
 * @brief Defines the ChatRoom and Users classes along with specific implementations.
 *
 * @details
 * This file declares:
 * - The abstract ChatRoom mediator
 * - The Users participant class
 * - Concrete chat room types (Dogorithm, CtrlCat)
 * - Example user subclasses (Name1, Name2, Name3)
 *
 * @uml
 * @startuml
 * 
 * class ChatRoom {
 *   +registerUser(user: Users) : void
 *   +sendMessage(message: string, fromUser: Users) : void
 *   +saveMessage(message: string, fromUser: Users) : void
 *   +removeUser(user: Users) : void
 *   +getUsers() : list<Users*>
 *   +incrementNumUsers() : int
 *   +getNumUsers() : int
 *   -users : list<Users*>
 *   -numUsers : int
 *   -chatHistory : string*
 * }
 *
 * class Users {
 *   +send(message: string, room: ChatRoom) : void
 *   +receive(message: string, fromUser: Users, room: ChatRoom) : void
 *   +addCommand(command: Command) : void
 *   +executeAll() : void
 *   -chatRooms : ChatRoom*
 *   -name : string
 *   -commandQueue : list<Command*>
 * }
 *
 * class Dogorithm
 * class CtrlCat
 * class Name1
 * class Name2
 * class Name3
 *
 * ChatRoom <|-- Dogorithm
 * ChatRoom <|-- CtrlCat
 * Users <|-- Name1
 * Users <|-- Name2
 * Users <|-- Name3
 * Users --> ChatRoom : "participates in"
 * ChatRoom --> Users : "manages *"
 *
 * @enduml
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
    virtual void registerUser(Users user);

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
    virtual void removeUser(Users user);

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

private:

    std::list<Users*>* users;    /**< List of users in the chat room. */
    int numUsers = 0;            /**< Number of registered users. */
    std::string* chatHistory;    /**< Storage for chat history. */
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

    Users(std::list<ChatRoom*> chatRooms, std::string name) {
        this->chatRooms = chatRooms;
        this->name = name;
    }

protected:

    std::list<ChatRoom*> chatRooms;   /**< Reference to the chat room(s) the user is part of. */
    std::string name;      /**< The user’s display name. */
    std::list<Command*> commandQueue; /**< Queue of commands for this user. */
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
class Cat : public Users {
    public:
    Cat(std::list<ChatRoom*> chatRooms, std::string name) : Users(chatRooms, name) {}
};

/**
 * @brief Example user subclass: Name2.
 * 
 * Demonstrates how custom user types can be defined.
 */
class Dog : public Users {
    public:
    Dog(std::list<ChatRoom*> chatRooms, std::string name) : Users(chatRooms, name) {}
};

/**
 * @brief Example user subclass: Name3.
 * 
 * Demonstrates how custom user types can be defined.
 */
class CatnDog : public Users {
    public:
    CatnDog(std::list<ChatRoom*> chatRooms, std::string name) : Users(chatRooms, name) {}
};
