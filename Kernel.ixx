export module Kernel;
import <iostream>;
import <queue>;  // For the queue container
import message;   // Assuming message includes AbidesClasses and OptionalMessage

export struct Kernel {
    std::string name;
    std::queue<Message> message_queue;  // Message queue to hold messages

    // Default constructor
    Kernel() {}

    // Method to add a message to the queue
    void add_message(const Message& msg) {
        message_queue.push(msg);
    }

    // Method to retrieve and remove a message from the queue
    OptionalMessage get_message() {
        if (message_queue.empty()) {
            // Return an OptionalMessage indicating there is no message
            Message emptyMsg(0, 0, "No message", 0, 0, AbidesClasses::BaseMsg);
            return OptionalMessage(false, emptyMsg);
        }

        // Get the message from the front of the queue
        Message msg = message_queue.front();
        message_queue.pop();  // Remove the message from the queue

        // Return the message in an OptionalMessage with `isMsg = true`
        return OptionalMessage(true, msg);
    }

    

    // Method to check if there are messages in the queue
    bool has_messages() const {
        return !message_queue.empty();
    }
};
