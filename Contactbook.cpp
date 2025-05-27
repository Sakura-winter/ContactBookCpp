#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Contact{
    private:
        string name;
        string phoneNumber;
        string email;
        string address;
    public:
        // Default constructor
        Contact(string n, string p, string e = "", string a = "") : name(n), phoneNumber(p), email(e), address(a) {}
        

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
// Save contacts to a file
void saveContacts(vector<Contact> &contacts) {
    ofstream outfile("contacts.txt");
    for(Contact &c : contacts) {
        outfile << c.getName() << "\n"
                << c.getNumber() << "\n"
                << c.getEmail() << "\n"
                << c.getAddress() << "\n"
                << "---\n"; // Separator for each contact

    }
    outfile.close();
}

// Load contacts from a file
void loadContacts(vector<Contact> &contacts) {
    ifstream infile("contacts.txt");
    string name, phoneNumber, email, address, seprator;
    while(getline(infile, name)) {
        getline(infile, phoneNumber);
        getline(infile, email);
        getline(infile, address);
        getline(infile, seprator);
        if(email.empty() && address.empty()) {
            contacts.push_back(Contact(name, phoneNumber));
        } else if(!email.empty() && address.empty()) {
            contacts.push_back(Contact(name, phoneNumber, email));
        } else {
            contacts.push_back(Contact(name, phoneNumber, email, address));
        }

    }
    infile.close();

}
int main() {
    cout << "Hello, World!\n";
    vector<Contact> contacts;
    contacts.push_back(Contact("Test1", "9714043692", "test1email@email.com"));
    contacts.push_back(Contact("Test2", "123234566654"));
    
    // Load contacts from file if it exists
    loadContacts(contacts);

    // Menu for user interaction
    int choice = -1;
    while(choice != 0) {
        cout << "Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Update Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Search Contact \n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the integer input

        //add contact functionality
        if (choice == 1) {
            string name, phoneNumber, email, address;
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Phone Number: ";
            getline(cin, phoneNumber);
            cout << "Enter Email (optional): ";
            getline(cin, email);
            cout << "Enter Address (optional): ";
            getline(cin, address);
            if(email.empty() && address.empty()) {
                contacts.push_back(Contact(name, phoneNumber));
            } else if(!email.empty() && address.empty()) {
                contacts.push_back(Contact(name, phoneNumber, email));
            } else {
                contacts.push_back(Contact(name, phoneNumber, email, address));
            }

        }
        else if (choice == 2) {
            cout << "Displaying Contacts:\n";
            for(Contact &c: contacts) {
                c.displayContact();
                cout << "------------------------" << endl;
            }
        }
        else if(choice == 3 ) {
            string name;
            cout << "Enter the name of the contact to update: ";
            getline(cin, name);
            bool found = false;
            for(Contact &c : contacts) {
                if(c.getName() == name) {
                    found = true;
                    string newName, newPhoneNumber, newEmail, newAddress;
                    cout << "Enter new Name (Leave blank to keep current): ";
                    getline(cin, newName);
                    if(newName.empty()){
                        newName = c.getName();
                    }
                    cout << "Enter new Phone Number (Leave blank to keep current): ";
                    getline(cin, newPhoneNumber);
                    if(newPhoneNumber.empty()){
                        newPhoneNumber = c.getNumber();
                    }
                    cout << "Enter new Email (Leave blank to keep current): ";
                    getline(cin, newEmail);
                    if(newEmail.empty()){
                        newEmail = c.getEmail();
                    }
                    cout << "Enter new Address (Leave blank to keep current): ";
                    getline(cin, newAddress);
                    if(newAddress.empty()){
                        newAddress = c.getAddress();
                    }
                    c.setName(newName);
                    c.setPhoneNumber(newPhoneNumber);
                    c.setEmail(newEmail);
                    c.setAddress(newAddress);
                    cout << "Contact updated successfully.\n";
                                    
                }
            }
        }
        else if(choice == 4) {
            string name;
            cout << "Enter the name of the contact to delete: ";
            getline(cin, name);
            bool found = false;
            for(int i = 0; i < contacts.size();i++){
                if(contacts[i].getName() == name) {
                    found = true;
                    contacts.erase(contacts.begin() + i);
                    cout << "Contact deleted successfully.\n";
                    break;
                }
            }
        }
        else if(choice == 0) {
            cout << "Exiting the program. \n" << endl;
            break;

        }
        else if(choice == 5) {
            string query;
            cout << "Enter the name or the phone number of the contact to search: ";
            getline(cin, query);
            bool found = false;
            for(Contact &c : contacts) {
                if(c.getName() == query || c.getNumber() == query) {
                    found = true;
                    cout << "Contact found: \n";
                    c.displayContact();
                    cout << "------------------------" << endl;
                }
                
            }
            if(!found) {
                cout << "No contact found with the name or phone number: " << query << endl;
            }

        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    // Save contacts to file before exiting
    saveContacts(contacts);
    cout << "Contacts saved to file.\n";


    return 0;


}