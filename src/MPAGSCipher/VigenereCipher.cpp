#include "VigenereCipher.hpp"
#include "CipherMode.hpp"
#include "Alphabet.hpp"
#include <algorithm>

VigenereCipher::VigenereCipher(const std::string& key) {
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key) {
    // Store the key
    key_ = key;

    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_), ::toupper);

    // Remove non-alphabetic characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_), [&] (char c) {
        if (Alphabet::alphabet.find(c) == std::string::npos) {
            // The character was not found inside the alphabet
            return true;
        } else {
            return false;
        }
    }), std::end(key_));

    // Check if the key is empty, if it is replace with a default key
    if (key_.length() == 0) {
        key_ = "KEY";
    }

    // Loop over the key
    for (char& c : key_) {
        // find the letter position in the alphabet
        const std::size_t charIndex {Alphabet::alphabet.find(c)};
        // create caesarcipher using this position as a key
        const CaesarCipher cipher {charIndex};
        // insert a std::pair of char and cipher into lookup table
        charLookup_.insert(std::make_pair(c, cipher));
    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText, const CipherMode /*cipherMode*/) const {
    return inputText;
}
