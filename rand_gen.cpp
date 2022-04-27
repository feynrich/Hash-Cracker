#include <iostream>
#include <cstdlib>
#include <string>
#include "md5/md5.h"
std::string alphabet[62] = { "A" , "B" , "C" , "D" , "E" , "F" , "G" , "H" , "I" ,
                             "J" , "K" , "L" , "M" , "N" , "O" , "P" , "Q" , "R" ,
                             "S" , "T" , "U" , "V" , "W" , "X" , "Y" , "Z", "1" ,
                             "2", "3", "4", "5","6","7", "8","9","0",
                             "a","b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
                             "l", "m", "n", "o", "p", "q", "r", "s", "t", "u",
                             "v", "w", "x", "y", "z"};


auto generator_txt_random(int pass_leng, std::string hash){
    std::string array_rand[pass_leng];
    std::string string_rand;
    while(true) {
        for (unsigned int i = 0; i <= pass_leng; i++) {
            string_rand += *(alphabet + rand() % 62 + 1);
        }
        std::cout << "hash :";
        std::cout <<"\n";
        std::cout << string_rand;
        std::cout <<"\n";
        std::cout << md5(string_rand);

        if (md5(string_rand) == hash ){
            std::cout <<"\nnu vrode ono ya hz";
            break;
        }
        string_rand = "";
    }

}

int main (){
    int pass_leng;
    std::string hash;
    pass_leng = 10;
    std::cout << "vvedi hash ebaniy clown";
    std::cin >> hash;
    std::cout << "eblan-vvedi-pzh-blyat-kolichestvo-simvolov-v-parole-alo-alo-alo";
    std::cin >> pass_leng;
    generator_txt_random(pass_leng, hash);

}


