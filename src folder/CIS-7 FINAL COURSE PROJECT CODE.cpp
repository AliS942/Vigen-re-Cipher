#include <iostream>
#include <string>
using namespace std;

// Function to generate the repeated key
string generateKey(const string &text, const string &key) {
    string extendedKey = key;
    while (extendedKey.size() < text.size()) {
        extendedKey += key;
    }
    return extendedKey.substr(0, text.size());
}

// Function to encrypt the plaintext
string encrypt(const string &plaintext, const string &key) {
    string ciphertext = "";
    string extendedKey = generateKey(plaintext, key);

    for (size_t i = 0; i < plaintext.size(); i++) {
        char plainChar = plaintext[i];
        char keyChar = extendedKey[i];

        // Convert characters to indices (A=0, B=1, ..., Z=25)
        int plainIndex = plainChar - 'A';
        int keyIndex = keyChar - 'A';

        // Perform encryption using modular arithmetic
        int cipherIndex = (plainIndex + keyIndex) % 26;

        // Convert index back to character
        char cipherChar = 'A' + cipherIndex;
        ciphertext += cipherChar;
    }

    return ciphertext;
}

// Function to decrypt the ciphertext
string decrypt(const string &ciphertext, const string &key) {
    string plaintext = "";
    string extendedKey = generateKey(ciphertext, key);

    for (size_t i = 0; i < ciphertext.size(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = extendedKey[i];

        // Convert characters to indices (A=0, B=1, ..., Z=25)
        int cipherIndex = cipherChar - 'A';
        int keyIndex = keyChar - 'A';

        // Perform decryption using modular arithmetic
        int plainIndex = (cipherIndex - keyIndex + 26) % 26;

        // Convert index back to character
        char plainChar = 'A' + plainIndex;
        plaintext += plainChar;
    }

    return plaintext;
}

// Main function
int main() {
    string plaintext, keyword, ciphertext;
    int choice;

    cout << "Welcome to the Vigenère Cipher Program!" << endl;
    cout << "1. Encrypt a message" << endl;
    cout << "2. Decrypt a message" << endl;
    cout << "3. Exit" << endl;

    do {
        cout << "\nEnter your choice (1/2/3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter plaintext (UPPERCASE only): ";
                cin >> plaintext;
                cout << "Enter keyword (UPPERCASE only): ";
                cin >> keyword;

                ciphertext = encrypt(plaintext, keyword);
                cout << "Encrypted text: " << ciphertext << endl;
                break;

            case 2:
                cout << "Enter ciphertext (UPPERCASE only): ";
                cin >> ciphertext;
                cout << "Enter keyword (UPPERCASE only): ";
                cin >> keyword;

                plaintext = decrypt(ciphertext, keyword);
                cout << "Decrypted text: " << plaintext << endl;
                break;

            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}