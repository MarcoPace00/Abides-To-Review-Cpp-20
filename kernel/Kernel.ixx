export module Kernel;
import <iostream>;
import <queue>;  // For the queue container
import message;

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
    bool get_message(Message& msg) {
        if (message_queue.empty()) {
            return false;  // Return false if queue is empty
        }
        msg = message_queue.front();  // Copy the front message to msg
        message_queue.pop();  // Remove the message from the queue
        return true;
    }

    // Method to check if there are messages in the queue
    bool has_messages() const {
        return !message_queue.empty();
    }
};
