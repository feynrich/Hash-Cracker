#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../external/doctest.h"
#include "md5.h"
#include "sha.h"
#include "gen.h"

TEST_CASE ("Checking MD5 hash") {

            REQUIRE(md5("smartlms") == "7a2e6ee2b4cdb99b1e7f8fc00a719583");
            REQUIRE(md5("BAG_student") == "26c55b82886f07ec0316ae012f6674ec");
            REQUIRE(md5("matanalys") == "d2f3ad262af0a599f800acf6887f2922");
            REQUIRE(md5("va$hpp") == "9c3125bd5b7180fb6779f0705775249a");
            REQUIRE(md5("marina1978") == "86ff49753955d236c77ba551d348f187");
}

TEST_CASE ("Checking little-endian") {
            REQUIRE(make_little_endian("1234567891011121314") == "9101112112345678");
            REQUIRE(make_little_endian("10101010100000101010101010") == "101010101000001010101010");
            REQUIRE(little_endian("110011001010011001010110") == "100101011001101000110011");
            REQUIRE(little_endian("qawsedrftgyhujiol") == "ioujyhtgrfedwsqa");
}

TEST_CASE ("Checking SHA2 hash") {
            REQUIRE(sha256("qwertyuiop123456") == "0485df2c3af8d7cf5c97cb73bf18dd00e78979c88d1488121e01000e36190667");
            REQUIRE(sha256("feynrich") == "845f9b6b65366ce7aa6108353d082f5b22d799fac3cce77d54414d5027ab80ad");
            REQUIRE(sha256("hsepassword") == "fd532ebfec5043ab6ac1c5243dad93b27245dc0ccc2f72a4268f8d9eff6b9162");
            REQUIRE(sha256("pa$$word") == "6a158d9847a80e99511b2a7866233e404b305fdb7c953a30deb65300a57a0655");
}

TEST_CASE ("Checking string to binary") {
            REQUIRE(strtobin_sec("11111") == "0011000100110001001100010011000100110001");
            REQUIRE(strtobin_sec("hashcracker") ==
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
    auto counter_i = 2;
    auto counter_s = 2;
    auto str = std::string ("asisoi");
    auto vec = std::vector <std::string> ({"1"});
            REQUIRE(reverse_order_s1_replace(counter_s,str,vec) == std::string("asi$oi"));
            REQUIRE(reverse_order_i1_replace(counter_i, str, vec) == std::string("asiso1"));
}









