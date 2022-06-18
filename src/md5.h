#include <string>
#include <bitset>
#include <vector>
//ert
#ifndef HASH_CRACKER_MD5_H
#define HASH_CRACKER_MD5_H
extern auto md5(std::string &input) -> std::string;
extern auto make_little_endian(std::string const &message) -> std::string;
extern auto little_endian(std::string const &input) -> std::string;
extern auto FunG(std::bitset<32> &x, std::bitset<32> &y, std::bitset<32> &z) -> std::bitset<32>;
extern auto FunF(std::bitset<32> &x, std::bitset<32> &y, std::bitset<32> &z) -> std::bitset<32>;
extern auto FunH(std::bitset<32> &x, std::bitset<32> &y, std::bitset<32> &z) -> std::bitset<32>;
extern auto FunI(std::bitset<32> &x, std::bitset<32> &y, std::bitset<32> &z) -> std::bitset<32>;
extern auto ROTLEFT(std::bitset<32> &x, int n) -> std::bitset<32>;
extern auto MERGE_MD5(std::bitset<32> x, std::bitset<32> y) -> std::bitset<32>;
extern auto strtobin_sec(std::string const &message) -> std::string;
#endif //HASH_CRACKER_MD5_H
