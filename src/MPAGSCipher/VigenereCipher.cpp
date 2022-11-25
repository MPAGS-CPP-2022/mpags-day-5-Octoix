#include "VigenereCipher.hpp"
#include "CipherMode.hpp"
#include "Alphabet.hpp"
#include <algorithm>
#include <string>

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
        return !std::isalpha(c);
    }), std::end(key_));

    // Check if the key is empty, if it is replace with a default key
    if (key_.length() == 0) {
        key_ = "KEY";
    }

    // Empty the map in-case it isn't 
    charLookup_.clear();
    // Loop over the key
    for (const char c : key_) {
        // find the letter position in the alphabet
        if (charLookup_.find(c) != charLookup_.end()) {
            continue;
        }
        const std::size_t charIndex {Alphabet::alphabet.find(c)};
        // create caesarcipher using this position as a key
        const CaesarCipher cipher {charIndex};
        // insert a std::pair of char and cipher into lookup table
        charLookup_.insert(std::make_pair(c, cipher));
    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const {
    // Initially make output text a copy of the input text
    std::string outputText{""};
    // for each letter in the input text
    for (std::size_t i{0}; i < inputText.size(); i++) {
        // find corresponding letter in the key (repeats/truncates as needed)
        // find caesar cipher from lookup
        const CaesarCipher& thisCipher {charLookup_.at(key_[i % key_.size()])};
        // run the encrypt/decrypt and add to the output text
        const std::string cipherInput {inputText[i]};
        outputText += thisCipher.applyCipher(cipherInput, cipherMode);
    }
    return outputText;
}
