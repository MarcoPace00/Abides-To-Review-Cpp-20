export module message;
import <iostream>;

/***
        INTERFACE
*/
export struct Message {
    int sender_id;
    int recipient_id;
    std::string content;

    int sent_time;
    int received_time;

    Message(int sender_id, int recipient_id, std::string content, int sent_time, int received_time)
        : sender_id(sender_id), recipient_id(recipient_id), content(content), sent_time(sent_time), received_time(received_time) {
    }
};

/***
        IMPLEMENTATION
*/

export void say_hi() {
    std::cout << "Hi\n";
}
