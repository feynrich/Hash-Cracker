#include <iostream>
#include <fstream>
#include <string>
#include "md5.cpp"
#include "sha.cpp"
#include "gen.cpp"

#define UNICODE

#include <windows.h>

std::string hashfunc(std::string pass, int func) {
    /*
      Функция которая проблема хеширования
    */
    switch (func) {
        case 1:
            return sha256(pass);

        case 2:
            return md5(pass) ;
    }

    return nullptr;

}

//
auto wordlist(std::string hash, int func) {
    /*
      Функция которая запускает перебор пароля по словарю
    */
    std::string path;
    std::cout << "Enter file's path: ";
    std::cin >> path;

    std::string s;
    std::string hashes;

    std::ifstream file(path + ".txt");

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
    /*
      Функция которая производит численный перебор словаря
     */
    int i = 0;
    std::string hashes;

    while (true) {
        std::string str = std::to_string(i);
        std::cout << i << std::endl;
        hashes = hashfunc(str, func);
        std::cout << hashes << std::endl;
        if (hashes == hash) {
            std::cout << "Success! Password: " << i << std::endl;
            return;
        }
        i++;
    }
}

int main() {
    /*
      Функция main - рут функция проекта
     */
    int choose;
    char Buffer[256];
    wchar_t *text = TEXT(
                            "██╗░░██╗░█████╗░░██████╗██╗░░██╗░░░░░░░█████╗░██████╗░░█████╗░░█████╗░██╗░░██╗███████╗██████╗░\n"
                            "██║░░██║██╔══██╗██╔════╝██║░░██║░░░░░░██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║░██╔╝██╔════╝██╔══██╗\n"
                            "███████║███████║╚█████╗░███████║█████╗██║░░╚═╝██████╔╝███████║██║░░╚═╝█████═╝░█████╗░░██████╔╝\n"
                            "██╔══██║██╔══██║░╚═══██╗██╔══██║╚════╝██║░░██╗██╔══██╗██╔══██║██║░░██╗██╔═██╗░██╔══╝░░██╔══██╗\n"
                            "██║░░██║██║░░██║██████╔╝██║░░██║░░░░░░╚█████╔╝██║░░██║██║░░██║╚█████╔╝██║░╚██╗███████╗██║░░██║\n"
                            "╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░╚═╝░░╚═╝░░░░░░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n"
                            "project by BAG_student, feynrich, millerocky \n");
    CharToOemW(text, Buffer);
    std::cout << Buffer;
    std::cout << "Crack or generate, that is a question:" << std::endl;
    std::cout << "1 - CRACK IT!" << std::endl;
    std::cout << "2 - Generate your own txt" << std::endl;
    std::cin >> choose;
    std::cout << little_endian("10101010100000101010101010");
    switch (choose) {
        case 1: {
            int func;
            int mode;
            std::string hashes;
            std::cout << "Choose hash-function:" << std::endl;
            std::cout << "1 - SHA256" << std::endl;
            std::cout << "2 - MD5" << std::endl;
            std::cin >> func;
            std::cout << "Enter hash:" << std::endl;
            std::cin >> hashes;
            std::cout << "Choose crack mode:" << std::endl;
            std::cout << "1 - Wordlist" << std::endl;
            std::cout << "2 - Enumeration of numbers" << std::endl;
            std::cin >> mode;
            if (mode == 1)
                wordlist(hashes, func);
            else if (mode == 2)
                numlist(hashes, func);
            break;
        }
        case 2:
            main_generator();
            break;

    }
    return 0;
}
