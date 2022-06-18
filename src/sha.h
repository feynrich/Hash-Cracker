
#ifndef HASH_CRACKER_SHA_H
#define HASH_CRACKER_SHA_H
#include <string>
#include <vector>
extern auto sha256(std::string pass) -> std::string;
extern auto strtobin(std::string input) -> std::string;
extern auto makebinaryhash(std::string pass) -> std::vector<std::bitset<32>>;
extern auto extrawords(std::bitset<512> &message) -> std::vector<std::bitset<32>>;
#endif //HASH_CRACKER_SHA_H
