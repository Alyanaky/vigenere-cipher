#include "vigenere_cipher.h"
#include <ctype.h>
#include <string.h>

void encrypt(char *text, const char *key) {
    int key_len = strlen(key);
    int key_index = 0;

    while (*text) {
        if (isalpha(*text)) {
            char base = isupper(*text) ? 'A' : 'a';
            int shift = tolower(key[key_index % key_len]) - 'a';
            *text = (char)((*text - base + shift) % ALPHABET_SIZE + base);
            key_index++;
        }
        text++;
    }
}

void decrypt(char *text, const char *key) {
    int key_len = strlen(key);
    int key_index = 0;

    while (*text) {
        if (isalpha(*text)) {
            char base = isupper(*text) ? 'A' : 'a';
            int shift = tolower(key[key_index % key_len]) - 'a';
            *text = (char)((*text - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE + base);
            key_index++;
        }
        text++;
    }
}
