#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherMode.hpp"
#include "catch.hpp"
#include <string>

bool testCipher(const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText) {
    return cipher.applyCipher(inputText, mode) == outputText;
}

TEST_CASE("Generic Cipher encryption", "[ciphers]")
{
    std::string inputText {"ABCDE"};
    CaesarCipher cc{1};
    PlayfairCipher pp{"Hello"};
    VigenereCipher vv{"Hello"};
    REQUIRE(testCipher(cc, CipherMode::Encrypt, inputText, "BCDEF"));
    REQUIRE(testCipher(pp, CipherMode::Encrypt, inputText, "BCDEF")); // TODO: these aren;t actually real tests currently
    REQUIRE(testCipher(vv, CipherMode::Encrypt, inputText, "BCDEF"));
}