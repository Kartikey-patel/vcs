#include"Hasher.h"

#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

std::string Hasher::sha1(const std::string& data)
{
    std::string digest;

    CryptoPP::SHA1 hash;

    CryptoPP::StringSource(
        data,
        true,
        new CryptoPP::HashFilter(
            hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest),
                false
            )
        )
    );

    return digest;
}