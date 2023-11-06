
#include <iostream>
#include <string>
using namespace std;

// Message class
class Message {
private:
    string header_;
    string txt_;

public:
    void setHeader(string& header) {
        header_ = header;
    }
    void setTXT(string& txt) {
        txt_ = txt;
    }

    void display() {
        cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
        cout << "\t" << header_ << "\n";
        cout << "\t" << txt_ << "\n";
        cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
    }


};

// Message Builder interface
class MessageBuilder {
public:
    virtual void buildHeader() = 0;
    virtual void buildTXT(string& txt) = 0;
    virtual Message* getMessage() = 0;
};

// Concrete Message Builder
class EmailMessageBuilder : public MessageBuilder {
private:
    Message* message_;

public:
    EmailMessageBuilder() {
        message_ = new Message();
    }

    void buildHeader() override {
        string header = "EMail";
        message_->setHeader(header);
    }

    void buildTXT(string& txt) override {
        message_->setTXT(txt);
    }

    Message* getMessage() override {
        return message_;
    }

};

class SMSMessageBuilder : public MessageBuilder {
private:
    Message* message_;

public:
    SMSMessageBuilder() {
        message_ = new Message();
    }

    void buildHeader() override {
        string header = "SMS";
        message_->setHeader(header);
    }

    void buildTXT(string& txt) override {
        message_->setTXT(txt);
    }

    Message* getMessage() override {
        return message_;
    }

};

int main() {
    SMSMessageBuilder SMSMessageBuilder_;
    EmailMessageBuilder EmailMessageBuilder_;

    SMSMessageBuilder_.buildHeader();
    string txt;
    cout << "Input message for SMS:\n";
    getline(cin, txt);
    SMSMessageBuilder_.buildTXT(txt);

    EmailMessageBuilder_.buildHeader();
    cout << "Input message for EMail:\n";
    getline(cin, txt);
    EmailMessageBuilder_.buildTXT(txt);

    Message * SMS =  SMSMessageBuilder_.getMessage();
    Message * EMAIL = EmailMessageBuilder_.getMessage();
    SMS->display();
    cout << endl;
    EMAIL->display();
    

    delete SMS;
    delete EMAIL;

    return 0;
}
