/*
Purpose: encrypt / decrypt a message using a certain key of the users choice,
the key will always consist of only letters and a length of 5.
Author: EL-Moatasem Ahmed El-Sayed Azzam
Date: 8 Mar 2024
Version : 1.0 */

#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

// this function validates key for length of not any number but 5, and for letters only.
string validate_key(string check_key)
{
    // key to lower case
    for (char &b : check_key)
    {
        b = tolower(b);
    }
    // validate key for letters only.
    while (true)
    {
        bool f = false;
        for (char i : check_key)
        {
            if (!isalpha(i))
            {
                f = true;
                break;
            }
        }
        // validate for letters and size.
        if (f || check_key.size() != 5)
        {
            // get new key.
            cout << "Please enter a key consisting of 5 letters: " << endl;
            getline(cin, check_key);
            // new ket to lowercase.
            for (char &b : check_key)
            {
                b = tolower(b);
            }
        }
        else
        {
            break;
        }
    }
    return check_key;
}

// this function validates message to contain only letters and spaces.
string validate_message(string check_message)
{
    for (char &a : check_message)
    {
        a = tolower(a);
    }
    // validate message for only letters.
    while (true)
    {
        bool f = false;
        for (char j : check_message)
        {
            if (isdigit(j) == 0)
            {
                continue;
            }
            f = true;
            break;
        }
        if (f)
        {
            cout << "Please enter a message with only letters and spaces: " << endl;
            getline(cin, check_message);
            for (char &a : check_message)
            {
                a = tolower(a);
            }
        }
        else
            break;
    }
    return check_message;
}

string encrypt()
{
    string message, cipher_key, alphabet, ciph_alphabet;
    alphabet = "abcdefghijklmnopqrstuvwxyz ";
    cout << "Please enter a key consisting of 5 letters: " << endl;
    getline(cin, cipher_key);
    // validate key
    cipher_key = validate_key(cipher_key);
    // get message
    cout << "Please enter message: " << endl;
    getline(cin, message);
    // validate message
    message = validate_message(message);

    // set cipher_alphabet to the actual alphabet then edit it according to the key.
    ciph_alphabet = alphabet;
    // first reverse cipher key so when we add its letters back they are added in the correct order.
    reverse(cipher_key.begin(), cipher_key.end());
    // generation of cipher alphabet using for loop
    // to remove every letter in the key and add it to the front
    for (char k : cipher_key)
    {
        size_t index = ciph_alphabet.find(k);
        ciph_alphabet.erase(index, 1);
        ciph_alphabet.insert(0, 1, k);
    }
    // finally adding space to the end, so we can handle spaces between words to be encrypted.
    ciph_alphabet += " ";
    string encrypted_message;
    // encryption part
    for (char l : message)
    {
        size_t index = alphabet.find(l);
        encrypted_message += ciph_alphabet[index];
    }
    return encrypted_message;
}

string decrypt()
{
    string message, cipher_key, alphabet, ciph_alphabet;
    alphabet = "abcdefghijklmnopqrstuvwxyz ";
    cout << "Please enter the key you used to encrypt the message: " << endl;
    getline(cin, cipher_key);
    // validate key
    cipher_key = validate_key(cipher_key);
    // get message
    cout << "Please enter encrypted message: " << endl;
    getline(cin, message);
    // validate message
    message = validate_message(message);

    // set cipher_alphabet to the actual alphabet then edit it according to the key.
    ciph_alphabet = alphabet;
    // first reverse cipher key so when we add its letters back they are added in the correct order.
    reverse(cipher_key.begin(), cipher_key.end());
    // generation of cipher alphabet using for loop
    // to remove every letter found in key and add it to the front of the cipher_alphabet
    for (char m : cipher_key)
    {
        size_t index = ciph_alphabet.find(m);
        ciph_alphabet.erase(index, 1);
        ciph_alphabet.insert(0, 1, m);
    }

    // finally adding space to the end, so we can handle spaces between words to be encrypted.
    ciph_alphabet += " ";
    // decryption part
    string decrypted_message;
    for (char n : message)
    {
        size_t index = ciph_alphabet.find(n);
        decrypted_message += alphabet[index];
    }
    return decrypted_message;
}
// main3
int main()
{
    cout << "Welcome to  Simple Substitution Cipher!" << endl;
    cout << "You will always use the same key to encrypt/decrypt the same message" << endl;
    while (true){
        cout << "Menu: " << endl;
        cout << "A) Encrypt a message" << endl;
        cout << "B) Decrypt a message" << endl;
        cout << "C) Exit" << endl;
        string choice;
        cout << "choose operation: " << endl;
        getline(cin, choice);
        choice[0] = tolower(choice[0]);
        // get key
        while (true)
        {
            if (choice == "a")
            {
                string encrypted_message = encrypt();
                cout << "Encrypted message is: " << encrypted_message << endl;
                break;
            }
            else if (choice == "b")
            {
                string decrypted_message = decrypt();
                cout << "Decrypted message is: " << decrypted_message << endl;
                break;
            }
            else if (choice == "c")
            {
                cout << "Exiting Program!" << endl;
                return 0;
            }
            else
            {
                cout << "Invalid choice, Please enter a valid choice" << endl;
                getline(cin, choice);
                choice[0] = tolower(choice[0]);
            }
        }
    }
}