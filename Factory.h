#include "Mediator.h"


class Users;
class Cat;
class Dog;
class CatnDog;
class UserFactory {
public:
    virtual Users* createUser(std::string& name, std::list<ChatRoom*> chatRooms) = 0;
};

class CatFactory : public UserFactory {
    public:
    Users* createUser(std::string& name, std::list<ChatRoom*> chatRooms) override {
        return new Cat(chatRooms, name);
    }
};

class DogFactory : public UserFactory {
    public:
    Users* createUser(std::string& name, std::list<ChatRoom*> chatRooms) override {
        return new Dog(chatRooms, name);
    }
};


class CatnDogFactory : public UserFactory {
    public:
    Users* createUser(std::string& name, std::list<ChatRoom*> chatRooms) override {
        return new CatnDog(chatRooms, name);
    }
};