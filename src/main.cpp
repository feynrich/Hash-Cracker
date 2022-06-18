#include <iostream>
#include <fstream>
#include <string>
#include "md5.h"
#include "sha.h"
#include "gen.h"

#define UNICODE

#include <windows.h>
    /*!
    * Функция вызывающая хэш-функцию
    *  @param pass - изменяемая строка и func - инициализатор функции
    */
std::string hashfunc(std::string pass, int func) {
    
    switch (func) {
        case 1:
            return sha256(pass);

        case 2:
            return md5(pass) ;
    }

    return nullptr;

}
    /*!
      * Функция которая запускает перебор пароля по словарю
      * @param hash - изменяемая строка и func - инициализатор функции
    */

auto wordlist(std::string hash, int func) {
  
    std::string path;
    std::cout << "Enter file's path: ";
    std::cin >> path;

    std::string s;
    std::string hashes;
    //считывание строк из файла-словаря
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
      /*!
      Функция которая производит численный перебор
      * @param hash - изменяемая строка и func - инициализатор функции
     */
auto numlist(std::string hash, int func) {
   
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
     /*!
      Функция main - рут функция проекта
     */
int main() {
    /*!
      Функция main - рут функция проекта
     */
    int choose;
    SetConsoleOutputCP(CP_UTF8);
    const char8_t* text = u8"██╗░░██╗░█████╗░░██████╗██╗░░██╗░░░░░░░█████╗░██████╗░░█████╗░░█████╗░██╗░░██╗███████╗██████╗░\n"
                    "██║░░██║██╔══██╗██╔════╝██║░░██║░░░░░░██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║░██╔╝██╔════╝██╔══██╗\n"
                    "███████║███████║╚█████╗░███████║█████╗██║░░╚═╝██████╔╝███████║██║░░╚═╝█████═╝░█████╗░░██████╔╝\n"
                    "██╔══██║██╔══██║░╚═══██╗██╔══██║╚════╝██║░░██╗██╔══██╗██╔══██║██║░░██╗██╔═██╗░██╔══╝░░██╔══██╗\n"
                    "██║░░██║██║░░██║██████╔╝██║░░██║░░░░░░╚█████╔╝██║░░██║██║░░██║╚█████╔╝██║░╚██╗███████╗██║░░██║\n"
                    "╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░╚═╝░░╚═╝░░░░░░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n"
                    "project by BAG_student, feynrich, millerocky \n";
    std::cout << reinterpret_cast<const char*>(text); 
    std::cout << "Crack or generate, that is a question:" << std::endl;
    std::cout << "1 - CRACK IT!" << std::endl;
    std::cout << "2 - Generate your own txt" << std::endl;
    std::cin >> choose;
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
