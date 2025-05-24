#include <iostream>
#include <vector>
using namespace std;
class Contact{
    private:
        string name;
        string phoneNumber;
        string email;
        string address;
    public:
        // Default constructor
        Contact(string n, string p) : name(n), phoneNumber(p), email(""), address("") {}
        //parameterrized constructor with all fields
        Contact(string n, string p, string e, string a) : name(n), phoneNumber(p), email(e), address(a) {}
        //parameterized constructor with email and not address
        Contact(string n, string p, string e) : name(n), phoneNumber(p), email(e), address("") {}

        // Getter methods
        string getName() {return name;}
        string getNumber() {return phoneNumber;}
        string getEmail() {return email;}
        string getAddress() {return address;}


        //setter methods
        void setName(string n) {
            name = n;
        }

        void setPhoneNumber(string p) {
            phoneNumber = p;
        }
        void setEmail(string e) {
            email = e;
        }
        void setAddress(string a){
            address = a;
        }

        // Method to display contact information
        void displayContact() {
            cout << "Name: " << name << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            if (!email.empty()) {
                cout << "Email: " << email << endl;
            }
            if(!address.empty()) {
                cout << "Address: " << address << endl;
            }
        }

};
int main() {
    cout << "Hello, World!\n";
    vector<Contact> contacts;
    contacts.push_back(Contact("Alice", "9714043692"));
    contacts.push_back(Contact("Bob", "123234566654"));
    for(Contact &c: contacts) {
        c.displayContact();
        cout << &c << endl;
        cout << "------------------------" << endl;
    }

    // Menu for user interaction
    int choice;
    while(choice != 0) {
        cout << "Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Update Contact\n";
        cout << "4. Delete Contact\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the integer input
    }
    


    return 0;


}