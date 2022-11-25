#ifndef MPAGS_CIPHER_CIPHER_HPP
#define MPAGS_CIPHER_CIPHER_HPP
#include "CipherMode.hpp"
#include <string>

/**
 * \file Cipher.hpp
 * \brief Contains the purely abstract Cipher base class
*/
class Cipher {
    public:
        Cipher() = default;
        Cipher(const Cipher& rhs) = default;
        Cipher(Cipher&& rhs) = default;
        Cipher& operator=(const Cipher& rhs) = default;
        Cipher& operator=(Cipher&& rhs) = default;
        virtual ~Cipher() = default;
        virtual std::string applyCipher(const std::string& inputText, const CipherMode cipherMode) const = 0;
        // Equals zero used to tell the compiler that the function is pure virtual i.e. no implementation
        // is provided for the method
};

#endif