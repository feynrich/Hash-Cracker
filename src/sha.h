#include <string>
#ifndef HASH_CRACKER_SHA_H
#define HASH_CRACKER_SHA_H
extern auto sha256(std::string input) -> std::string;
extern auto strtobin(std::string input) -> std::string;
extern auto little_endian(std::string input) -> std::string;
#endif //HASH_CRACKER_SHA_H
