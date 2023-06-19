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
    long shift = 5;

    std::cout << "Enter a string: ";
    std::getline(std::cin, message);

    // Encrypt
    std::string encrypted = encrypt(message, shift);
    std::cout << "Encrypted string: " << encrypted << std::endl;

    // Decrypt
    std::string decrypted = decrypt(encrypted, shift);
    std::cout << "Decrypted string: " << decrypted << std::endl;

    return 0;
}