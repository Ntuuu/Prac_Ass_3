#include "Mediator.h"

class UserFactory {
public:
    static Users* createUser(const std::string& name) {
        // if (name == "Cat") {
        //     return new Cat();
        // } else if (name == "Dog") {
        //     return new Dog();
        // } else if (name == "CatnDog") {
        //     return new CatnDog();
        // } else {
        //     return nullptr; // or throw an exception
        // }
    }
};

class CatFactory : public UserFactory {

};

class DogFactory : public UserFactory {

};

class CatnDogFactory : public UserFactory {
    
};