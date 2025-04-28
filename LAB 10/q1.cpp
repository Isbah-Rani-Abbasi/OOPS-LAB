#include <iostream>
#include <string>
#include <fstream> // Include the fstream library

using namespace std;

string encryptString(const string& text) {
    string encryptedText = "";
    for (size_t i = 0; i < text.length(); ++i) {
        encryptedText += static_cast<char>(text[i] + i);
    }
    return encryptedText;
}

string decryptString(const string& encryptedText) {
    string decryptedText = "";
    for (size_t i = 0; i < encryptedText.length(); ++i) {
        decryptedText += static_cast<char>(encryptedText[i] - i);
    }
    return decryptedText;
}

void writeToFile(const string& filename, const string& text) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << text;
        outputFile.close();
        cout << "Encrypted text inserted in file" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}

string readFromFile(const string& filename) {
    ifstream inputFile(filename);
    string content = "";
    if (inputFile.is_open()) {
        getline(inputFile, content);
        inputFile.close();
        return content;
    } else {
        cerr << "Error opening file for reading." << endl;
        return "";
    }
}

int main() {
    string inputString = "Hello World";
    cout << "Normal Text:= " << inputString << endl;

    string encryptedText = encryptString(inputString);
    string filename = "encrypted_data.txt";
    writeToFile(filename, encryptedText);

    string readEncryptedText = readFromFile(filename);

    if (!readEncryptedText.empty()) {
        string decryptedText = decryptString(readEncryptedText);
        cout << "Decrypted text Read then decoded from file" << endl;
        cout << decryptedText << endl;
    }

    return 0;
}