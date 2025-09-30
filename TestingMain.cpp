#include "Mediator.h"
#include "Command.h"
#include "Factory.h"
#include <iostream>
#include <vector>
#include <memory>

// Test function declarations
void testUserCreation();
void testChatRoomFunctionality();
void testCommandPattern();
void testMediatorPattern();
void testFactoryPattern();
void testMemoryManagement();
void testErrorConditions();

int main() {
    std::cout << "=== CHAT SYSTEM COMPREHENSIVE TEST SUITE ===" << std::endl;
    
    // Run all test suites
    testUserCreation();
    testChatRoomFunctionality();
    testCommandPattern();
    testMediatorPattern();
    testFactoryPattern();
    testMemoryManagement();
    testErrorConditions();
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}

void testUserCreation() {
    std::cout << "\n--- TEST 1: User Creation ---" << std::endl;
    
    // Create different types of chat room lists
    ChatRoom* dogRoom = new Dogorithm();
    ChatRoom* catRoom = new CtrlCat();
    
    std::list<ChatRoom*> mixedRooms;
    mixedRooms.push_back(dogRoom);
    mixedRooms.push_back(catRoom);
    
    std::list<ChatRoom*> dogOnlyRooms;
    dogOnlyRooms.push_back(dogRoom);
    
    std::list<ChatRoom*> catOnlyRooms;
    catOnlyRooms.push_back(catRoom);
    
    // Test creating different user types
    Cat* catUser = new Cat(catOnlyRooms, "Whiskers");
    Dog* dogUser = new Dog(dogOnlyRooms, "Rex");
    CatnDog* hybridUser = new CatnDog(mixedRooms, "HybridPet");
    
    std::cout << "Created users: " << catUser->getName() << ", " 
              << dogUser->getName() << ", " << hybridUser->getName() << std::endl;
    
    // Test user methods
    std::cout << "Cat user type: " << typeid(*catUser).name() << std::endl;
    std::cout << "Dog user type: " << typeid(*dogUser).name() << std::endl;
    std::cout << "Hybrid user type: " << typeid(*hybridUser).name() << std::endl;
    
    // Cleanup
    delete catUser;
    delete dogUser;
    delete hybridUser;
    delete dogRoom;
    delete catRoom;
}

void testChatRoomFunctionality() {
    std::cout << "\n--- TEST 2: Chat Room Functionality ---" << std::endl;
    
    Dogorithm* dogRoom = new Dogorithm();
    CtrlCat* catRoom = new CtrlCat();
    
    // Test room names/types
    std::cout << "Dog room type: " << typeid(*dogRoom).name() << std::endl;
    std::cout << "Cat room type: " << typeid(*catRoom).name() << std::endl;
    
    // Test user registration
    std::list<ChatRoom*> rooms;
    rooms.push_back(dogRoom);
    
    Users* testUser = new Dog(rooms, "TestDog");
    dogRoom->registerUser(testUser);
    
    std::cout << "Users in dog room: " << dogRoom->getNumUsers() << std::endl;
    
    // Test message sending
    dogRoom->sendMessage("Test message", *testUser);
    
    // Test user removal
    dogRoom->removeUser(testUser);
    std::cout << "Users in dog room after removal: " << dogRoom->getNumUsers() << std::endl;
    
    delete testUser;
    delete dogRoom;
    delete catRoom;
}

void testCommandPattern() {
    std::cout << "\n--- TEST 3: Command Pattern ---" << std::endl;
    
    ChatRoom* dogRoom = new Dogorithm();
    ChatRoom* catRoom = new CtrlCat();
    
    std::list<ChatRoom*> dogRooms;
    dogRooms.push_back(dogRoom);
    
    std::list<ChatRoom*> catRooms;
    catRooms.push_back(catRoom);
    
    Users* dogUser = new Dog(dogRooms, "CommandDog");
    Users* catUser = new Cat(catRooms, "CommandCat");
    
    // Test different command types
    Command* sendCmd = new SendMessageCommand(dogRoom, dogUser, "Hello from command!");
    Command* logCmd = new LogMessageCommand(dogRoom, dogUser, "Log this message");
    
    std::cout << "Executing SendMessageCommand..." << std::endl;
    sendCmd->execute();
    
    std::cout << "Executing LogMessageCommand..." << std::endl;
    logCmd->execute();
    
    // Test command with different rooms
    Command* crossRoomCmd = new SendMessageCommand(catRoom, dogUser, "Cross-room message");
    std::cout << "Executing cross-room command..." << std::endl;
    crossRoomCmd->execute();
    
    delete sendCmd;
    delete logCmd;
    delete crossRoomCmd;
    delete dogUser;
    delete catUser;
    delete dogRoom;
    delete catRoom;
}

void testMediatorPattern() {
    std::cout << "\n--- TEST 4: Mediator Pattern ---" << std::endl;
    
    Dogorithm* dogRoom1 = new Dogorithm();
    Dogorithm* dogRoom2 = new Dogorithm();
    CtrlCat* catRoom1 = new CtrlCat();
    
    // Test multiple users in same room
    std::list<ChatRoom*> dogRooms;
    dogRooms.push_back(dogRoom1);
    
    Users* user1 = new Dog(dogRooms, "MediatorDog1");
    Users* user2 = new Dog(dogRooms, "MediatorDog2");
    Users* user3 = new Cat(dogRooms, "MediatorCat");
    
    dogRoom1->registerUser(user1);
    dogRoom1->registerUser(user2);
    dogRoom1->registerUser(user3);
    
    std::cout << "Multiple users in room: " << dogRoom1->getNumUsers() << std::endl;
    
    // Test message broadcasting
    std::cout << "Testing message broadcast..." << std::endl;
    dogRoom1->sendMessage("Broadcast message to all users", *user1);
    
    // Test user interaction
    std::cout << "Testing user interaction..." << std::endl;
    dogRoom1->sendMessage("User2 to User1", *user2);
    
    // Cleanup
    dogRoom1->removeUser(user1);
    dogRoom1->removeUser(user2);
    dogRoom1->removeUser(user3);
    
    delete user1;
    delete user2;
    delete user3;
    delete dogRoom1;
    delete dogRoom2;
    delete catRoom1;
}

void testFactoryPattern() {
    std::cout << "\n--- TEST 5: Factory Pattern ---" << std::endl;
    
    Signup signup;
    ChatRoom* dogRoom = new Dogorithm();
    ChatRoom* catRoom = new CtrlCat();
    
    std::list<ChatRoom*> dogRooms;
    dogRooms.push_back(dogRoom);
    
    std::list<ChatRoom*> catRooms;
    catRooms.push_back(catRoom);
    
    std::list<ChatRoom*> mixedRooms;
    mixedRooms.push_back(dogRoom);
    mixedRooms.push_back(catRoom);
    
    // Test factory creation
    CatFactory catFactory;
    DogFactory dogFactory;
    CatnDogFactory hybridFactory;
    
    // Test creating users through factories
    std::cout << "Testing factory creation..." << std::endl;
    
    // Test with different parameters
    std::string factoryCatName = "FactoryCat";
    std::string factoryDogName = "FactoryDog";
    std::string factoryHybridName = "FactoryHybrid";
    Users* factoryCat = catFactory.createUser(factoryCatName, catRooms);
    Users* factoryDog = dogFactory.createUser(factoryDogName, dogRooms);
    Users* factoryHybrid = hybridFactory.createUser(factoryHybridName, mixedRooms);
    
    if (factoryCat) {
        std::cout << "Factory created: " << factoryCat->getName() << std::endl;
        delete factoryCat;
    }
    
    if (factoryDog) {
        std::cout << "Factory created: " << factoryDog->getName() << std::endl;
        delete factoryDog;
    }
    
    if (factoryHybrid) {
        std::cout << "Factory created: " << factoryHybrid->getName() << std::endl;
        delete factoryHybrid;
    }
    
    delete dogRoom;
    delete catRoom;
}

void testMemoryManagement() {
    std::cout << "\n--- TEST 6: Memory Management ---" << std::endl;
    
    // Test creating and deleting multiple objects
    const int NUM_OBJECTS = 5;
    std::vector<ChatRoom*> rooms;
    std::vector<Users*> users;
    std::vector<Command*> commands;
    
    std::cout << "Creating " << NUM_OBJECTS << " of each object type..." << std::endl;
    
    for (int i = 0; i < NUM_OBJECTS; ++i) {
        // Create rooms
        ChatRoom* dogRoom = new Dogorithm();
        ChatRoom* catRoom = new CtrlCat();
        rooms.push_back(dogRoom);
        rooms.push_back(catRoom);
        
        // Create users
        std::list<ChatRoom*> roomList;
        roomList.push_back(dogRoom);
        
        Users* user = new Dog(roomList, "User" + std::to_string(i));
        users.push_back(user);
        
        // Create commands
        Command* cmd = new SendMessageCommand(dogRoom, user, "Message " + std::to_string(i));
        commands.push_back(cmd);
    }
    
    std::cout << "Created " << rooms.size() << " rooms, " 
              << users.size() << " users, " 
              << commands.size() << " commands" << std::endl;
    
    // Execute some commands
    for (int i = 0; i < 3 && i < commands.size(); ++i) {
        commands[i]->execute();
    }
    
    // Cleanup everything
    std::cout << "Cleaning up all objects..." << std::endl;
    for (auto cmd : commands) delete cmd;
    for (auto user : users) delete user;
    for (auto room : rooms) delete room;
    
    std::cout << "Memory management test completed." << std::endl;
}

void testErrorConditions() {
    std::cout << "\n--- TEST 7: Error Conditions ---" << std::endl;
    
    // Test null pointers
    std::cout << "Testing null pointer handling..." << std::endl;
    try {
        Command* nullCmd = new SendMessageCommand(nullptr, nullptr, "Null test");
        // This might crash or should be handled gracefully
        // nullCmd->execute(); // Uncomment to test, but might crash
        delete nullCmd;
    } catch (...) {
        std::cout << "Null pointer exception caught" << std::endl;
    }
    
    // Test empty messages
    ChatRoom* dogRoom = new Dogorithm();
    std::list<ChatRoom*> rooms;
    rooms.push_back(dogRoom);
    
    Users* user = new Dog(rooms, "TestUser");
    
    std::cout << "Testing empty message..." << std::endl;
    Command* emptyMsgCmd = new SendMessageCommand(dogRoom, user, "");
    emptyMsgCmd->execute();
    
    // Test with very long message
    std::cout << "Testing long message..." << std::endl;
    std::string longMsg(1000, 'X'); // 1000 character message
    Command* longMsgCmd = new SendMessageCommand(dogRoom, user, longMsg);
    longMsgCmd->execute();
    
    delete longMsgCmd;
    delete emptyMsgCmd;
    delete user;
    delete dogRoom;
    
    std::cout << "Error condition tests completed." << std::endl;
}