#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to encrypt a string
string encrypt(string input, int key) {
    string encrypted = input;
    for (int i = 0; i < input.size(); ++i) {
        // Shift each character by the key
        encrypted[i] = input[i] + key;
    }
    return encrypted;
}

// Function to decrypt a string
string decrypt(string input, int key) {
    string decrypted = input;
    for (int i = 0; i < input.size(); ++i) {
        // Shift each character back by the key
        decrypted[i] = input[i] - key;
    }
    return decrypted;
}

void password_generator() {
    cout << "\t====================================" << endl;
    cout << "\t====>>>  Password Generator  <<<====" << endl;
    cout << "\t====================================" << endl;
    char alpha_num[] = "67ghiST5j8^&:*a07WX@1ef9V2tv34d5wxQR14DOIpkJ8LZl2mMNBC9!noqYEruA#6$sy3zPbcU%FGHK";
    int req_length, string_length = (sizeof(alpha_num) - 1);
    cout << "Enter the Length (>10) of Password: ";
    cin >> req_length;
    while (req_length < 10) {
        cout << "Less than 10 is not allowed!!! \nEnter the Length (>10) of Password:";
        cin >> req_length;
    }
    cin.ignore(); // Clear input buffer
    srand(time(0));
    cout << "\n=> Generated Password of Length " << req_length << " is :  ";
    for (int i = 0; i < req_length; i++)
        cout << alpha_num[rand() % string_length];
    string con;
    cout << "\n\nDo you want to continue this tool? (Y/N): ";
    getline(cin, con);
    if (con == "Y" || con == "y") {
        system("CLS");
        password_generator();
    }
}

void password_analyzer() {
    cout << "\t====================================" << endl;
    cout << "\t====>>>   Password Analyzer  <<<====" << endl;
    cout << "\t====================================" << endl;
    int l_case = 0, u_case = 0, digit = 0, special = 0, strength = 100;
    string password;
    cin.ignore(); // Clear input buffer
    cout << "\nEnter your password: ";
    getline(cin, password);
    int len = password.length();
    cout << "\n\t====================================" << endl;
    cout << "\t====>>>      Suggestions     <<<====" << endl;
    cout << "\t====================================" << endl;

    if (len <= 8) {
        cout << "=> Password length is too SHORT" << endl;
        strength -= 50;
    }
    if (len > 8 && len <= 10) {
        cout << "=> Password length could be increased more" << endl;
        strength -= 25;
    }
    if (len > 20) {
        strength += 50;
    }

    for (int i = 0; i < len; i++) {
        if (islower(password[i]))
            l_case++;
        if (isupper(password[i]))
            u_case++;
        if (isdigit(password[i]))
            digit++;
        if (!isalpha(password[i]) && !isdigit(password[i]) && password[i] != ' ')
            special++;
    }
    if (l_case <= 2) {
        cout << "=> Add more LOWERcase characters to increase strength!" << endl;
        strength -= 15;
    }
    if (u_case <= 2) {
        cout << "=> Add more UPPERcase characters to increase strength!" << endl;
        strength -= 15;
    }
    if (digit <= 2) {
        cout << "=> Add more DIGITS to increase strength!" << endl;
        strength -= 15;
    }
    if (special <= 2) {
        cout << "=> Add more SPECIAL characters to increase strength!" << endl;
        strength -= 15;
    }
    cout << "\n\t====================================" << endl;
    cout << "\t====>>>   Password Analyzed  <<<====" << endl;
    cout << "\t====================================" << endl;
    cout << "=> Total Length: " << len << endl
        << "=> Lowercase: " << l_case << endl
        << "=> Uppercase: " << u_case << endl
        << "=> Digits: " << digit << endl
        << "=> Special: " << special << endl;

    cout << "\n\t====================================" << endl;
    cout << "\t====>>>   Password Strength  <<<====" << endl;
    cout << "\t====================================" << endl;
    cout << strength << "% |";
    {
        for (int i = 0; i < int(strength / 2); i++) {
            cout << "=";
        }
        for (int i = 0; i < (100 - (strength)) / 2; i++) {
            cout << ".";
        }
        cout << "|" << endl << endl;
    }
    string con;
    cout << "Do you want to continue this tool? (Y/N): ";
    getline(cin, con);
    if (con == "Y" || con == "y") {
        system("CLS");
        password_analyzer();
    }
}

// Function prototypes for encryption and decryption
void cryptography_tool();
void encryption();
void decryption();

void cryptography_tool() {
    cout << "\t====================================" << endl;
    cout << "\t====>>>  Cryptographic Tool  <<<====" << endl;
    cout << "\t====================================" << endl;
    long what;
    cout << "What do you want to perform? " << endl
        << "1) Encryption " << endl
        << "2) Decryption " << endl
        << "=>";
    cin >> what;
    while (what < 1 && what > 2) {
        cout << "Invalid Option" << endl;
        cin >> what;
    }
    switch (what) {
    case 1:
        encryption();
        break;
    case 2:
        decryption();
        break;
    default:
        cout << "Invalid Option";
    }
    string con;
    cout << "\nDo you want to continue this tool? (Y/N): ";
    cin.ignore(); // Clear input buffer
    getline(cin, con);
    if (con == "Y" || con == "y") {
        system("CLS");
        cryptography_tool();
    }
}

void encryption() {
    string input;
    int key;

    // Input message and key
    cin.ignore(); // Clear input buffer
    cout << "Enter message to encrypt: ";
    getline(cin, input);
    cout << "Enter encryption key: ";
    cin >> key;

    // Encrypt the message
    string encrypted_message = encrypt(input, key);
    cout << "Encrypted message: " << encrypted_message << endl;
}

void decryption() {
    string input;
    int key;

    // Input encrypted message and key
    cin.ignore(); // Clear input buffer
    cout << "Enter encrypted message: ";
    getline(cin, input);
    cout << "Enter decryption key: ";
    cin >> key;

    // Decrypt the message
    string decrypted_message = decrypt(input, key);
    cout << "Decrypted message: " << decrypted_message << endl;
}

int main() {
    cout << "\t========================================" << endl
        << "\t====>>>  Cyber Security Toolkit  <<<====" <<
        endl << "\t========================================\n" << endl;
    int what;
    cout << "1) Cryptography Tool" << endl
        << "2) Password Analyzer" << endl
        << "3) Password Generator" << endl
        << "4) Exit" << endl
        << "=> ";
    cin >> what;
    while (what < 1 || what > 4) {
        cout << "Error!!! Invalid Option Selected" << endl;
        cout << "Please choose a correct option (1-4): ";
        cin >> what;
    }
 
    switch (what) {
    case 1:
        system("CLS");
        cryptography_tool();
        break;
    case 2:
        system("CLS");
        password_analyzer();
        break;
    case 3:
        system("CLS");
        password_generator();
        break;
    case 4:
        cout << "Thanks for using :)" << endl;
        cout << "Exiting......." << endl;
        return 0;
    default:
        cout << "Something Went Wrong!" << endl;
    }
    system("CLS");
    main();
    return 0;
}
