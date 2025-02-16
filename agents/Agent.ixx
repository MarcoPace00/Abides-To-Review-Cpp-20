export module agent;
import <iostream>;
import Kernel;  // Import Kernel module
import message; // Import message module

export class Agent {
public:
    Kernel& kernel;  // Reference to shared Kernel
    // Constructor takes a reference to a shared Kernel
    Agent(Kernel& shared_kernel) : kernel(shared_kernel) {}

    // Method to receive a message
    void receive_message() {
        Message msg(0, 0, "", 0, 0);  // Temporary message to receive

        // Check if there are messages in the kernel's queue
        if (kernel.get_message(msg)) {
            std::cout << "Agent received message: " << msg.content << "\n";
        }
        else {
            std::cout << "No messages in the queue.\n";
        }
    }

    // Method to send a message
    void send_message(const Message& msg) {
        kernel.add_message(msg);
        std::cout << "Agent sent message: " << msg.content << "\n";
    }

    // Method to check if the agent has any messages
    bool has_messages() const {
        return kernel.has_messages();
    }
};
