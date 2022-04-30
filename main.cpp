#include <iostream>
#include <fstream>
#include <string>
#include "sha.cpp"
#include "md5(1.0).cpp"

std::string hashfunc(std::string pass, int func) {

    if (func == 1) {

        return sha256(pass);
    }
    else if (func == 2) {

        return md52(pass);
    }

}

auto wordlist(std::string hash, int func) {
    std::string path;
    std::cout << "Enter file's path: ";
    std::cin >> path;

    std::string s;
    std::string hashes;

    std::ifstream file(path+".txt");

    while (std::getline(file, s)) {
        hashes = hashfunc(s, func);
        if (hashes == hash) {
            std::cout << "Success! Password: " << s;
            exit(0);
        }
    }
    std::cout << "No match found.";
    exit(0);
}

auto numlist(std::string hash, int func) {
    int i = 0;
    std::string hashes;

    while (true) {
        std::string str = std::to_string(i);
        std::cout << i << std::endl;
        hashes = hashfunc(str, func);
        std::cout << hashes << std::endl;

        if (hashes == hash) {
                std::cout << "Success! Password: " << i;
                exit(0);
        }
        i++;
    }
}


int main() {
    std::string hashes;
    int func;
    int mode;
    int i = 12;

    std::cout << "Choose crack mode:" << std::endl;
    std::cout << "1 - Wordlist" << std::endl;
    std::cout << "2 - Enumeration of numbers" << std::endl;
    std::cout << "3 - Random enumeration" << std::endl;

    std::cin >> mode;

    std::cout << "Choose hash-function:" << std::endl;
    std::cout << "1 - SHA256" << std::endl;
    std::cout << "2 - MD5" << std::endl;

    std::cin >> func;

    std::cout << "Enter hash:" << std::endl;

    std::cin >> hashes;




    switch(mode) {
        case 1:
            wordlist(hashes, func);

        case 2:
            numlist(hashes, func);
    }

    return 0;
}


