#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


std::string hashfunc(std::string pass, std::string func) {

}

auto wordlist(std::string hash, std::string func) {
    std::string path;

    std::cin >> path;

    std::string s;
    std::string hashes;

    std::ifstream file(path);

    int i = 1;
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

auto numlist(std::string hash, std::string func) {
    int i = 0;
    std::string hashes;

    while (true) {
        std::string str = std::to_string(i);
        hashes = hashfunc(str, func);

        if (hashes == hash) {
                std::cout << "Success! Password: " << i;
                exit(0);
        }
    }
}


int main(int argc, char *argv[]) {

}


