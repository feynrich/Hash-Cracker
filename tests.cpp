#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "src/md5.h"
#include "src/sha.h"
#include "src/gen.h"
TEST_CASE ("Checking MD5 hash") {

            REQUIRE(md5("smartlms") == "7a2e6ee2b4cdb99b1e7f8fc00a719583");
            REQUIRE(md5("BAG_student") == "26c55b82886f07ec0316ae012f6674ec");
            REQUIRE(md5("matanalys") == "d2f3ad262af0a599f800acf6887f2922");
            REQUIRE(md5("va$hpp") == "9c3125bd5b7180fb6779f0705775249a");
            REQUIRE(md5("marina1978") == "86ff49753955d236c77ba551d348f187");
}

TEST_CASE ("Checking SHA2 hash") {
            REQUIRE(sha256("qwertyuiop123456") == "0485df2c3af8d7cf5c97cb73bf18dd00e78979c88d1488121e01000e36190667");
            REQUIRE(sha256("feynrich") == "845f9b6b65366ce7aa6108353d082f5b22d799fac3cce77d54414d5027ab80ad");
            REQUIRE(sha256("hsepassword") == "fd532ebfec5043ab6ac1c5243dad93b27245dc0ccc2f72a4268f8d9eff6b9162");
            REQUIRE(sha256("pa$$word") == "6a158d9847a80e99511b2a7866233e404b305fdb7c953a30deb65300a57a0655");
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





