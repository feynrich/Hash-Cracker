#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bitset>
#include "../external/doctest.h"
#include "md5.h"
#include "sha.h"
#include "gen.h"
//ddjdjdjb

TEST_CASE ("Checking MD5 hash") {
    std::string str1 = "smartlms";
    std::string str2 = "va$hpp";
    std::string str3 = "BAG_student";
            REQUIRE(md5(str1) == "7a2e6ee2b4cdb99b1e7f8fc00a719583");
            REQUIRE(md5(str2) == "9c3125bd5b7180fb6779f0705775249a");
            REQUIRE(md5(str3) == "26c55b82886f07ec0316ae012f6674ec");
}

TEST_CASE ("Checking little-endian") {
    std::string str1 = "1234567891011121314";
    std::string str2 = "10101010100000101010101010";
    std::string str3 = "qawsedrftgyhujio";
            REQUIRE(make_little_endian(str1) == "9101112112345678");
            REQUIRE(make_little_endian(str2) == "101010101000001010101010");
            REQUIRE(little_endian(str3) == "ioujyhtgrfedwsqa");
            REQUIRE(little_endian(little_endian(str3)) == "qawsedrftgyhujio");
}

TEST_CASE ("Checking SHA2 hash") {
    std::string str1 = "qwertyuiop123456";
    std::string str2 = "feynrich";
    std::string str3 = "hsepassword";
            REQUIRE(sha256(str1) == "e3f7c6cc5e7dd9f105f4bcd05e1477f108f0d17b0178e1221b1b09a2096dda4e");
            REQUIRE(sha256(str2) == "cacb3a6e529cc578043ad5c7f43775539451d6d05855c01d9ec7b986a858131b");
            REQUIRE(sha256(str3) == "10bf0ee577cd3cf3fa219024e22d67831708b332c99a5ad9f6aa070df73cf9d1");
}

TEST_CASE ("Checking string to binary") {
    std::string str1 = "11111";
    std::string str2 = "hashcracker";
           REQUIRE(strtobin_sec(str1) == "0011000100110001001100010011000100110001");
           REQUIRE(strtobin_sec(str2) ==
                   "0110100001100001011100110110100001100011011100100110000101100011011010110110010101110010");
}

TEST_CASE ("Checking logic operation") {
            std::bitset<32> x = std::bitset<32>("101010101");
            std::bitset<32> y = std::bitset<32>("101010101001010110");
            std::bitset<32> z = std::bitset<32>("10101010101010101");
            REQUIRE(MERGE_MD5(x, y).to_string() == "00000000000000101010101110101011");
            REQUIRE(FunH(x, y, z).to_string() == "00000000000000111111111001010110");
            REQUIRE(FunI(x, y, z).to_string() == "11111111111111000000000110101001");
            REQUIRE(FunG(x, y, z).to_string() == "00000000000000101010101101010111");
            REQUIRE(ROTLEFT(x, 2).to_string() == "00000000000000000000010101010100");
}

TEST_CASE ("Checking replace in normal order") {
    auto counter_i = 1;
    auto counter_s = 1;
    auto str = std::string ("iosafe");
    auto vec = std::vector <std::string> ({"1"});
            REQUIRE(normal_order_s1_replace(counter_s,str,vec) == std::string("io$afe"));
            REQUIRE(normal_order_i1_replace(counter_i, str, vec) == std::string("1osafe"));
}

TEST_CASE ("Checking replace in reverse order") {
    auto counter_i = 1;
    auto counter_s = 1;
    auto str = std::string ("aisoi");
    auto vec = std::vector <std::string> ({"1"});
            REQUIRE(reverse_order_s1_replace(counter_s,str,vec) == std::string("ai$oi"));
            REQUIRE(reverse_order_i1_replace(counter_i, str, vec) == std::string("aiso1"));
}












