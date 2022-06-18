#include <string>

#ifndef HASH_CRACKER_MD5_H
#define HASH_CRACKER_MD5_H
extern auto md5(std::string &input) -> std::string;
extern auto make_little_endian(std::string message) -> std::string;
extern auto little_endian(std::string input) -> std::string;
//extern auto is_isogram(std::string const& word) -> bool;
#endif //HASH_CRACKER_MD5_H
