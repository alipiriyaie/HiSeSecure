#include <iostream>
#include <string>

std::string encrypt(const std::string& message, int shift) {
    std::string encryptedMessage = message;
    for (char& c : encryptedMessage) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return encryptedMessage;
}

std::string decrypt(const std::string& encryptedMessage, int shift) {
    return encrypt(encryptedMessage, 26 - shift);  // Decrypting is the same as encrypting with the opposite shift
}

int main() {
    std::string message;
    auto shift = 5;
    while (true) {
        
        std::cout << "Enter encoded string (or 'exit' to quit): ";
        std::getline(std::cin, message);

        if (message == "exit") {
            break;
        }
        // Decrypt
        std::string decrypted = decrypt(message, shift);
        std::cout << "Decrypted string: " << decrypted << std::endl;
    }
    return 0;
}