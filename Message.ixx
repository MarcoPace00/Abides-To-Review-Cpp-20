export module message;
import <iostream>;
import enumclass;


/***
        INTERFACE
*/
export struct Message {
    int sender_id;
    int recipient_id;
    std::string content;
    int sent_time;
    int received_time;
    AbidesClasses type;

    // Default constructor with default values for all fields
    Message(int sender_id = 0, int recipient_id = 0, std::string content = "No message",
        int sent_time = 0, int received_time = 0, AbidesClasses type = AbidesClasses::BaseMsg)
        : sender_id(sender_id), recipient_id(recipient_id), content(content),
        sent_time(sent_time), received_time(received_time), type(type) {
    }
};

/***
*/
export struct OptionalMessage {
    bool isMsg;   // Flag to indicate if the message is valid
    Message msg;  // The actual Message object

    // Constructor that initializes both isMsg and msg
    OptionalMessage(bool isMsg, const Message msg) : isMsg(isMsg), msg(msg) {}
};
export struct Reshedule : Message {
    int frequence;

    Reshedule(int sender_id, int recipient_id, std::string content, int sent_time, int received_time, int frequence)
        : Message(sender_id, recipient_id, std::move(content), sent_time, received_time), frequence(frequence) {
    }
};



/***
        IMPLEMENTATION
*/

export void say_hi() {
    std::cout << "Hi\n";
}
