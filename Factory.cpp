#include "Factory.h"

void Signup::addUser(UserFactory* factory, std::string& type, std::list<ChatRoom*> chatRooms) {
    if (type == "Cat") {
        factory = new CatFactory();
        std::string name;

        std::cout << "Enter name for User: ";
        std::cin >> name;

        Users* user = factory->createUser(name, chatRooms);

        for (auto it = chatRooms.begin(); it != chatRooms.end(); ++it) {
            (*it)->registerUser(user);
        }
    } else if (type == "Dog") {
        factory = new DogFactory();
        std::string name;

        std::cout << "Enter name for User: ";
        std::cin >> name;

        Users* user = factory->createUser(name, chatRooms);
        for (auto it = chatRooms.begin(); it != chatRooms.end(); ++it) {
            (*it)->registerUser(user);
        }
    } else if (type == "CatnDog") {
        factory = new CatnDogFactory();
        std::string name;
        std::cout << "Enter name for User: ";
        std::cin >> name;

        Users* user = factory->createUser(name, chatRooms);
        for (auto it = chatRooms.begin(); it != chatRooms.end(); ++it) {
            (*it)->registerUser(user);
        }
    }
}
