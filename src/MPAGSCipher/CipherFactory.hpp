#ifndef CIPHER_FACTORY_HPP
#define CIPHER_FACTORY_HPP

#include "Cipher.hpp"
#include "CipherType.hpp"
#include <memory>

namespace CipherFactory {
    std::unique_ptr<Cipher> makeCipher(const CipherType type, const std::string& key);
}

#endif