#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// Function declarations for encoding and decoding
void bro_menu(); // Declare bro_menu() function before main
void ask_continue(); // Declare ask_continue function
string encode(string text, int key); // Declare encode function
string decode(string text, int key); // Declare decode function

#define CHARSET_SIZE 95  // Printable ASCII characters from 32 to 126


int main(void)
{
    printf("Content-Type: text/plain\n\n");
    printf("Welcome to the BRO Zone!\n");
    return 0;
    
    // Ask User for Gender
    string gender = get_string("ARE YOU A BRO (Y/N)? ");

    // Disapprove Usage if User is Not a Bro
    if (gender[0] == 'Y' || gender[0] == 'y')
    {
        // Proceed with the rest of the program
        printf("Welcome, Bro!\n");

        // Ask User For Password to use software
        string password = get_string("Enter the Bro Code password: ");

        // Validate Password
        if (strcmp(password, "A BRO IS NO BRO WITHOUT A BRO") == 0)
        {
            printf("Password accepted. Welcome to the Bro Zone!\n");

            bro_menu(); // Call bro_menu() here

            // After operation ends, ask if they want to continue
            ask_continue();
        }
        else
        {
            // Tell user Wrong password
            printf("Wrong password! X Access denied.\n");
            return 0; // Stop the program if wrong password
        }
    }
    else
    {
        // Stop the program if not a Bro
        printf("Sorry, this zone is only for Bros!\n");
        return 0;
    }
}

// Menu for Bro Options
void bro_menu()
{
    // Ask User Decode/Encode OR Bro code Rules
    string choice = get_string("Do you want to (1) View Bro Code Rules or (2) Encode/Decode Text?: ");

    if (strcmp(choice, "1") == 0)
    {
        // Print out random Bro code rules
        printf("Bro Code Rule #1: Bros before anything else.\n");
        printf("Bro Code Rule #2: Never leave a Bro hanging.\n");
        printf("Bro Code Rule #3: A Bro must always have a Bro's back.\n");
        // Skip to goodbye
        printf("Stay Loyal To The BRO ZONE!!!\n");
    }
    else if (strcmp(choice, "2") == 0)
    {
        // Request For Text
        string text = get_string("Enter the text to Encode/Decode: ");

        // Decode or Encode choice
        string action = get_string("Do you want to (1) Encode or (2) Decode?_ ");

        // Input Secret Key
        int key;
        do {
            key = get_int("Enter a key (number) for encoding/decoding: ");
            // Ensure that the key is in the valid range (0 to 94)
            if (key < 0 || key >= CHARSET_SIZE) {
                printf("Invalid key! Please choose a key between 0 and 94.\n");
            }
        } while (key < 0 || key >= CHARSET_SIZE); // Repeat until a valid key is provided

        if (strcmp(action, "1") == 0)
        {
            // Encode and display encoded text
            string encoded_text = encode(text, key);
            printf("Encoded Text: %s\n", encoded_text);
        }
        else if (strcmp(action, "2") == 0)
        {
            // Decode and display decoded text
            string decoded_text = decode(text, key);
            printf("Decoded Text: %s\n", decoded_text);
        }
    }
}

// Function to ask if the user wants to continue or exit
void ask_continue()
{
    string continue_choice = get_string("Do you want to perform another operation? (Y/N): ");

    if (continue_choice[0] == 'Y' || continue_choice[0] == 'y')
    {
        bro_menu(); // Call bro_menu() again for another action
    }
    else
    {
        // If user chooses no, exit the program
        printf("PEACE OUT BRO\n");
        return; // Exit the program
    }
}

// Function to encode text by shifting each character within the printable ASCII range
string encode(string text, int key)
{
    int i;
    string encoded = text; // Assuming 'text' is a mutable string for simplicity

    // Encode text with the key
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 32 && text[i] <= 126) {  // Check if the character is within the printable ASCII range
            encoded[i] = 32 + (text[i] - 32 + key) % CHARSET_SIZE;
        } else {
            encoded[i] = text[i];  // Preserve non-printable characters (though there shouldn't be any in this case)
        }
    }
    return encoded;
}

// Function to decode the text by shifting each character within the printable ASCII range
string decode(string text, int key)
{
    int i;
    string decoded = text; // Assuming 'text' is a mutable string for simplicity

    // Decode the text using the provided key
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 32 && text[i] <= 126) {  // Check if the character is within the printable ASCII range
            decoded[i] = 32 + (text[i] - 32 - key + CHARSET_SIZE) % CHARSET_SIZE;
        } else {
            decoded[i] = text[i];  // Preserve non-printable characters (though there shouldn't be any in this case)
        }
    }
    return decoded;
}
