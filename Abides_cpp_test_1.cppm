// Abides_cpp_test_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// For compiling on visual studio see:
// https://stackoverflow.com/questions/64877559/cant-use-iostream-as-module-in-c20-visual-studio
// DO NOT DO CHANGE THE SETTING ABOUT INTERNAL PARTITION!!!

// #include <iostream>
//import <iostream>;
import Kernel;  // Import Kernel module
import agent;   // Import Agent module
import message; // Import Message module
#include <iostream>

int main() {
    // Create a shared Kernel
    Kernel shared_kernel;
    shared_kernel.name = "Main Kernel";

    // Create two Agent instances, both using the shared Kernel
    Agent agent1(shared_kernel);
    Agent agent2(shared_kernel);

    // Create Messages
    Message msg1(1, 2, "Hello from Agent 1!", 1616161616, 1616161620);
    Message msg2(2, 1, "Hello from Agent 2!", 1616161621, 1616161625);

    // Agent1 sends a message
    std::cout << "Agent 1 is sending a message...\n";
    agent1.send_message(msg1);

    // Agent2 receives the message from the shared Kernel
    std::cout << "Agent 2 is attempting to receive the message...\n";
    agent2.receive_message();

    // Agent2 sends a message
    std::cout << "Agent 2 is sending a message...\n";
    agent2.send_message(msg2);

    // Agent1 receives the message from the shared Kernel
    std::cout << "Agent 1 is attempting to receive the message...\n";
    agent1.receive_message();

    // Check if the shared Kernel still has messages
    if (shared_kernel.has_messages()) {
        std::cout << "Shared Kernel still has messages.\n";
    }
    else {
        std::cout << "Shared Kernel has no more messages.\n";
    }

    return 0;
}
