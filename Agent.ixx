export module agent;
import <iostream>;
import Kernel;  // Import Kernel module
import message; // Import message module
import enumclass;   

export class Agent {
public:
    Kernel& kernel;  // Reference to shared Kernel

    // Constructor takes a reference to a shared Kernel
    Agent(Kernel& shared_kernel) : kernel(shared_kernel) {}

    // Method to receive a message
    void receive_message(Message& msg) {
        std::cout << "Received message: " << msg.content << "\n";
    }

    // Method to send a message
    void send_message(const Message& msg) {
        kernel.add_message(msg);
        std::cout << "Agent sent message: " << msg.content << "\n";
    }
};
