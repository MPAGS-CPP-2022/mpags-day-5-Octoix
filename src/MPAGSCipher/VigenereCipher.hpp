#ifndef VIGENERE_HPP
#define VIGENERE_HPP
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "Cipher.hpp"
#include <string>
#include <map>

/**
 * \file VigenereCipher.hpp
 * \brief Contains declaration for VigenereCipher class
*/

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere cipher with the given key
 */
class VigenereCipher : public Cipher {
    public:
        /**
         * \brief Create a new VigenereCipher with the given key
         * 
         * \param key the key to use in the cipher
        */
        explicit VigenereCipher(const std::string& key);

        /**
         * \brief Set the key to be used for encryption/decryption
         * 
         * \param key the key to use in the cipher
        */
        void setKey(const std::string& key);

        /**
         * \brief Apply the cipher to the provided text
         * 
         * \param inputText the text to encrypt/decrypt
         * \param cipherMode whether to encrypt or decrypt the text
         * \return the result of applying the cipher to the input text
        */
        virtual std::string applyCipher(const std::string& inputText, const CipherMode cipherMode) const override;
    private:
        // The cipher key
        std::string key_;
        // Lookup map of Caesar cipher's associated with corresponding char
        std::map<char, CaesarCipher> charLookup_;
};

#endif