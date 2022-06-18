#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>


std::string alphabet[62] = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                            "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                            "S", "T", "U", "V", "W", "X", "Y", "Z", "1",
                            "2", "3", "4", "5", "6", "7", "8", "9", "0",
                            "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
                            "l", "m", "n", "o", "p", "q", "r", "s", "t", "u",
                            "v", "w", "x", "y", "z"};

    /** функция, вызывающая выбор режима работы генерации паролей и исполняемые функции
    
    * @param pass_leng - длина создаваемых паролей 
    
    */
auto generator_txt(int pass_leng) {
   
  
    std::string string_in_txt;
    std::string answer;
    srand(time(nullptr));
    auto max_pass = pow(62, pass_leng);
    auto txt_size = (pass_leng + 2) * max_pass;
    std::cout << "Number of passwords: " << max_pass << "\n";
    std::cout << "Size of text file: " << txt_size << " byte" << "\n";
    std::cout << "proceed?[yes]: ";
    std::cin >> answer;
    if (answer == "yes") {
        FILE *file = fopen("..//dic//rand_pass.txt", "w+");
        for (unsigned int i = 0; i < max_pass; i++) {
            for (unsigned int j = 0; j < pass_leng; j++) {
                string_in_txt += (alphabet[rand() % 62]);
            }
            const char * char_pass = string_in_txt.data();
            fputs(char_pass,file);
            fputs("\n", file);
            string_in_txt = "";

        }

        fclose(file);
    } else {
        std::cout << "May be next time...\n";
    }
}
     /*!
     функция, заменяющая все s в строке на $
     * @param counter_s - количество букв s в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto normal_order_s1_replace(int counter_s,std::string word,std::vector <std::string> &pass_array)  {

    
    if (counter_s == 1) {

        pass_array.push_back(word.replace(word.find('s'), 1, "$"));
    }

    if (counter_s > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 's') + 1; i++) {
            pass_array.push_back(word.replace(word.find('s'), 1, "$"));
        }
    }
    return word;

}
     /*!
     функция, заменяющая все i в строке на 1
     * @param counter_i - количество букв i в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto normal_order_i1_replace(int counter_i,std::string word,std::vector <std::string> &pass_array) {
    
    if (counter_i == 1) {
        pass_array.push_back(word.replace(word.find('i'), 1, "1"));
    }

    if (counter_i > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'i') + 1; i++) {
            pass_array.push_back(word.replace(word.find('i'), 1, "1"));
        }
    }
    return word;

}
     /*!
     функция, заменяющая все o в строке на 0
     * @param counter_o - количество букв o в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto normal_order_o_replace(auto &counter_o,std::string word,std::vector <std::string> &pass_array) {
    
    if (counter_o == 1) {
        pass_array.push_back(word.replace(word.find('o'), 1, "0"));
    }
    if (counter_o > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'o') + 1; i++) {

            pass_array.push_back(word.replace(word.find('o'), 1, "0"));
        }
    }
    return word;

}
     /*!
     функция, заменяющая все a в строке на @
     * @param counter_a - количество букв a в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto normal_order_a_replace(auto &counter_a,std::string word,std::vector <std::string> &pass_array) {
    
    if (counter_a == 1) {

        pass_array.push_back(word.replace(word.find('a'), 1, "@"));
    }

    if (counter_a > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'a') + 1; i++) {
            pass_array.push_back(word.replace(word.find('a'), 1, "@"));
        }
    }
    return word;
}
     /*!
     функция, заменяющая все f в строке на 4
     * @param counter_f - количество букв f в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto normal_order_f_replace(auto &counter_f,std::string word,std::vector <std::string> &pass_array) {
   
    if (counter_f == 1) {
        pass_array.push_back(word.replace(word.find('f'), 1, "4"));
    }
    if (counter_f > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'f') + 1; i++) {

            pass_array.push_back(word.replace(word.find('f'), 1, "4"));
        }
    }
    return word;

}
     /*!
     функция, заменяющая все e в строке на 3
     * @param counter_e - количество букв e в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto normal_order_e_replace(auto &counter_e,std::string word,std::vector <std::string> &pass_array) {
   
    if (counter_e == 1) {
        pass_array.push_back(word.replace(word.find('e'), 1, "3"));
    }

    if (counter_e > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'e') + 1; i++) {
            pass_array.push_back(word.replace(word.find('e'), 1, "3"));
        }
    }
    return word;
}
     /*!
     функция, заменяющая все $ в строке на 5
     * @param counter_s - количество букв $ в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь
     * @return изменный после замены символов пароль
     */
auto normal_order_s2_replace(auto &counter_s,std::string word,std::vector <std::string> &pass_array) {
    
    if (counter_s == 1) {

        pass_array.push_back(word.replace(word.find('$'), 1, "5"));
    }
    if (counter_s > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), '$') + 1; i++) {
            pass_array.push_back(word.replace(word.find('$'), 1, "5"));
        }
    }
    return word;
}
    /*!
     функция, заменяющая все 1 в строке на !
     * @param counter_i - количество букв 1 в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto normal_order_i2_replace(auto &counter_i,std::string word,std::vector <std::string> &pass_array) {
    if (counter_i == 1) {

        pass_array.push_back(word.replace(word.find('1'), 1, "!"));
    }
    if (counter_i > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), '1') + 1; i++) {
            pass_array.push_back(word.replace(word.find('1'), 1, "!"));
        }
    }
    return word;
}
     /*!
     функция, заменяющая все s в строке на $ в обратном порядке
     * @param counter_s - количество букв s в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto reverse_order_s1_replace(int counter_s,std::string word,std::vector <std::string> &pass_array) {

    if (counter_s == 1) {
        std::reverse(word.begin(),word.end());
        word = word.replace(word.find('s'), 1, "$");
        std::reverse(word.begin(),word.end());
        pass_array.push_back(word);
    }

    if (counter_s > 1) {
        for (unsigned int i = word.size(); i <= std::count(word.begin(), word.end(), 's') + 1; i++) {
            std::reverse(word.begin(),word.end());
            word = word.replace(word.find('s'), 1, "$");
            std::reverse(word.begin(),word.end());
            pass_array.push_back(word);
        }
    }
    return word;
}

     /*!
     функция, заменяющая все i в строке на 1 в обратном порядке
     * @param counter_i - количество букв i в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */

auto reverse_order_i1_replace(int counter_i,std::string word,std::vector <std::string> &pass_array) {
   
    if (counter_i == 1) {
        std::reverse(word.begin(),word.end());
        word = word.replace(word.find('i'), 1, "1");
        std::reverse(word.begin(),word.end());
        pass_array.push_back(word);
    }

    if (counter_i > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'i') + 1; i++) {
            std::reverse(word.begin(),word.end());
            word = word.replace(word.find('i'), 1, "1");
            std::reverse(word.begin(),word.end());
            pass_array.push_back(word);
        }
    }
    return word;
}
      /*!
     функция, заменяющая все o в строке на 0 в обратном порядке
     * @param counter_o - количество букв o в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto reverse_order_o_replace(auto  &counter_o,std::string word,std::vector <std::string> &pass_array) {
    if (counter_o == 1) {
        std::reverse(word.begin(),word.end());
        word = word.replace(word.find('o'), 1, "0");
        std::reverse(word.begin(),word.end());
        pass_array.push_back(word);
    }

    if (counter_o > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'o') + 1; i++) {
            std::reverse(word.begin(),word.end());
            word = word.replace(word.find('o'), 1, "0");
            std::reverse(word.begin(),word.end());
            pass_array.push_back(word);
        }
    }
    return word;
}
    /*!
     функция, заменяющая все a в строке на @ в обратном порядке
     * @param counter_a - количество букв a в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto reverse_order_a_replace(auto &counter_a,std::string word,std::vector <std::string> &pass_array) {
   
    if (counter_a == 1) {
        std::reverse(word.begin(),word.end());
        word = word.replace(word.find('a'), 1, "@");
        std::reverse(word.begin(),word.end());
        pass_array.push_back(word);

    }

    if (counter_a > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'a') + 1; i++) {
            std::reverse(word.begin(),word.end());
            word = word.replace(word.find('a'), 1, "@");
            std::reverse(word.begin(),word.end());
            pass_array.push_back(word);
        }
    }

    return word;

}
    /*!
     функция, заменяющая все f в строке на 4 в обратном порядке
     * @param counter_f - количество букв f в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto reverse_order_f_replace(auto  &counter_f,std::string word,std::vector <std::string> &pass_array) {
    
    if (counter_f == 1) {
        std::reverse(word.begin(),word.end());
        word = word.replace(word.find('f'), 1, "4");
        std::reverse(word.begin(),word.end());
        pass_array.push_back(word);

    }

    if (counter_f > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'f') + 1; i++) {
            std::reverse(word.begin(),word.end());
            word = word.replace(word.find('f'), 1, "4");
            std::reverse(word.begin(),word.end());
            pass_array.push_back(word);
        }
    }

    return word;
}
     /*!
     функция, заменяющая все e в строке на 3 в обратном порядке
     * @param counter_e - количество букв e в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto reverse_order_e_replace(auto &counter_e,std::string word,std::vector <std::string> &pass_array) {
    
    if (counter_e == 1) {
        std::reverse(word.begin(),word.end());
        word = word.replace(word.find('e'), 1, "3");
        std::reverse(word.begin(),word.end());
        pass_array.push_back(word);

    }

    if (counter_e > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'e') + 1; i++) {
            std::reverse(word.begin(),word.end());
            word = word.replace(word.find('e'), 1, "3");
            std::reverse(word.begin(),word.end());
            pass_array.push_back(word);
        }
    }

    return word;
}
    /*!
     функция, заменяющая все $ в строке на 5 в обратном порядке
     * @param counter_s - количество букв $ в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto reverse_order_s2_replace(auto &counter_s,std::string word,std::vector <std::string> &pass_array) {
   
    if (counter_s == 1) {
        std::reverse(word.begin(),word.end());
        word = word.replace(word.find('$'), 1, "5");
        std::reverse(word.begin(),word.end());
        pass_array.push_back(word);

    }

    if (counter_s > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), '$') + 1; i++) {
            std::reverse(word.begin(),word.end());
            word = word.replace(word.find('$'), 1, "5");
            std::reverse(word.begin(),word.end());
            pass_array.push_back(word);
        }
    }
    return word;
}
     /*!
     функция, заменяющая все 1 в строке на ! в обратном порядке
     * @param counter_i - количество букв 1 в пароле
     * @param pass_array - массив с создаными паролями
     * @param word - изменяемое слово которое ввел пользователь 
     * @return изменный после замены символов пароль
     */
auto reverse_order_i2_replace(auto  &counter_i,std::string word,std::vector <std::string> &pass_array) {
    
    if (counter_i == 1) {
        std::reverse(word.begin(),word.end());
        word = word.replace(word.find('1'), 1, "!");
        std::reverse(word.begin(),word.end());
        pass_array.push_back(word);

    }
    if (counter_i > 1) {
        for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), '1') + 1; i++) {
            std::reverse(word.begin(),word.end());
            word = word.replace(word.find('1'), 1, "!");
            std::reverse(word.begin(),word.end());
            pass_array.push_back(word);
        }
    }
    return word;

}
      /*!
     функция, заменящая символы в строке на соответсвенные эквивалентные символы
     * @param amount_of_words - количество слов введенных пользователей
     * @param word_array - слова введеннные пользователем
     * @param word - изменяемое слово которое ввел пользователь 
     * @return pass_array - массив изменных слов
     */
auto by_word_generator_normal_order(int amount_of_words, std::string *word_array) {
    /**
    
    */
    std::string word;
    std::string word_2;
    std::vector<std::string> pass_array;
    for (unsigned int i = 0; i < amount_of_words; i++) {

        word = word_array[i];

        auto counter_o = std::count(word.begin(), word.end(), 'o');
        auto counter_i = std::count(word.begin(), word.end(), 'i');
        auto counter_s = std::count(word.begin(), word.end(), 's');
        auto counter_a = std::count(word.begin(), word.end(), 'a');
        auto counter_f = std::count(word.begin(), word.end(), 'f');
        auto counter_e = std::count(word.begin(), word.end(), 'e');

        word = normal_order_s1_replace(counter_s, word, pass_array);
        word = normal_order_i1_replace(counter_i, word, pass_array);
        word = normal_order_o_replace(counter_o, word, pass_array);
        word = normal_order_a_replace(counter_a, word, pass_array);
        word = normal_order_f_replace(counter_f, word, pass_array);
        word = normal_order_e_replace(counter_e, word, pass_array);

        word_2 = word;

        word_2 = normal_order_s2_replace(counter_s,word_2, pass_array);
        word_2 = normal_order_i2_replace(counter_i,word_2, pass_array);
    }

    return pass_array;

}
     /*!
     функция, заменящая символы в строке на соответсвующие им эквивалентные символы в обратном порядке
     * @param amount_of_words - количество слов введенных пользователей
     * @param word_array - слова введеннные пользователем
     * @param word - изменяемое слово которое ввел пользователь 
     * @return pass_array1 - массив изменных слов
     */
auto by_word_generator_reverse_order(int amount_of_words, std::string  *word_array) {
    
    std::string word;
    std::string word_2;
    std::vector <std::string> pass_array1;


    for (unsigned int i = 0; i < amount_of_words; i++) {

        word = word_array[i];

        auto counter_o = std::count(word.begin(), word.end(), 'o');
        auto counter_i = std::count(word.begin(), word.end(), 'i');
        auto counter_s = std::count(word.begin(), word.end(), 's');
        auto counter_a = std::count(word.begin(), word.end(), 'a');
        auto counter_f = std::count(word.begin(), word.end(), 'f');
        auto counter_e = std::count(word.begin(), word.end(), 'e');

        word = reverse_order_s1_replace(counter_s, word, pass_array1);
        word = reverse_order_i1_replace(counter_i, word, pass_array1);
        word = reverse_order_o_replace(counter_o, word, pass_array1);
        word = reverse_order_a_replace(counter_a, word, pass_array1);
        word = reverse_order_f_replace(counter_f, word, pass_array1);
        word = reverse_order_e_replace(counter_e, word, pass_array1);

        word_2 = word;

        word_2 = reverse_order_s2_replace(counter_s, word_2, pass_array1);
        word_2 = reverse_order_i2_replace(counter_i, word_2, pass_array1);

    }
    return pass_array1;
}
     /*!
     функция, комбинирующая ключевые слова в один пароль
     * @param pass_array - массив со всеми измененными словами
     * @return word_pass.txt - словарь в текстовом виде со всеми измененными словами
     */
auto combine(std::vector<std::string> pass_array) {
    
    std::string str;
    FILE *file = fopen("..//dic//word_pass.txt", "w+");
    for (int i = 0; i <= pass_array.size(); i++) {
        if (pass_array[i].empty()) {
            pass_array.erase(pass_array.begin() + i);
        }
    }
    int count = 0;

    for (int i = 0; i <= pass_array.size(); i++) {
        if (!pass_array[i].empty()) {
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {

            str = pass_array[j];
            pass_array[j] = pass_array[j + 1];
            pass_array[j + 1] = str;
        }
        auto str = pass_array[0] + pass_array[1];
        const char * char_pass = str.data();
        fputs(char_pass,file);
        fputs("\n", file);

    }
    fclose(file);
    std::cout << "Your file is ready!?";
    return 0;

}
  /*!
     Главная функция, для выбора режима работы программы
  */
int main_generator() {
    int choose;
    std::cout << "Choose type of password generation:"
                 "\n1 - random generation"
                 "\n2 - by word generation\n";
    std::cin >> choose;
    switch (choose) {
        case 1:
            int pass_leng;
            std::cout << "Enter the amount of symbols in passwords:";
            std::cin >> pass_leng;
            generator_txt(pass_leng);
            break;
        case 2:
            int amount_of_words;
            std::cout << "Enter the amount of words in passwords:";
            std::cin >> amount_of_words;
            std::string word_array[amount_of_words];
            std::string str;
            for (unsigned int i = 0; i < amount_of_words; i++) {
                std::cout << "enter your word(-s):\n";
                std::cin >> str;
                word_array[i] = str;
            }

            std::vector<std::string> pass_array1 = by_word_generator_normal_order(amount_of_words, word_array);

            std::vector<std::string> pass_array2 = by_word_generator_reverse_order(amount_of_words, word_array);

            std::reverse(pass_array2.begin(), pass_array2.end());
            int n = int(pass_array1.size()) + int(pass_array2.size());
            std::vector<std::string> pass_array_sum(n);

            int a = 0;
            int b = 1;
            for (int i = 0; i < pass_array1.size(); i++) {
                pass_array_sum.insert(pass_array_sum.begin() + a, pass_array1[i]);
                a = a + 2;

            }
            for (int i = 0; i < pass_array2.size(); i++) {
                pass_array_sum.insert(pass_array_sum.begin() + b, pass_array2[i]);
                b = b + 2;
            }
            if (amount_of_words == 1){
                for (int i = 0; i <= pass_array_sum.size(); i++) {
                    if (pass_array_sum[i].empty()) {
                        pass_array_sum.erase(pass_array_sum.begin() + i);
                    }
                }
                int count = 0;


                FILE *file = fopen("..//dic//word_pass.txt", "w+");
                for (int i = 0; i <= pass_array_sum.size(); i++){
                    const char * char_pass = pass_array_sum[i].data();
                    fputs(char_pass, file);
                    fputs("\n", file);
                }
                fclose(file);
                std::cout << "Your file is ready!?";
            }
            if(amount_of_words >  1){
                combine(pass_array_sum);
            }

            break;

    }

    return 0;

}
