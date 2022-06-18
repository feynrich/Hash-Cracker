
#include <string>
#include <algorithm>
#ifndef HASH_CRACKER_GEN_H
#define HASH_CRACKER_GEN_H
extern auto normal_order_s1_replace(int counter_s,std::string word,std::vector <std::string> &pass_array) -> std::string;
extern auto normal_order_i1_replace(int counter_i,std::string word,std::vector <std::string> &pass_array) -> std::string;
extern auto reverse_order_s1_replace(int counter_s,std::string word,std::vector <std::string> &pass_array) -> std::string;
extern auto reverse_order_i1_replace(int counter_s,std::string word,std::vector <std::string> &pass_array) -> std::string;
extern int main_generator();
#endif //HASH_CRACKER_GEN_H

