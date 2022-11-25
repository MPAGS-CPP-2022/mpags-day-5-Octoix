#ifndef VIGENERE_HPP
#define VIGENERE_HPP
#include "CipherMode.hpp"
#include <string>

class VigenereCipher {
    public:
        VigenereCipher(const std::string& key);
        void setKey(const std::string& key);
        std::string applyCipher(const std::string& inputText, const CipherMode /*cipherMode*/) const;
    private:
        std::string key_;
};

#endif