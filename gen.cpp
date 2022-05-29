#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>


std::string alphabet[62] = { "A" , "B" , "C" , "D" , "E" , "F" , "G" , "H" , "I" ,
                             "J" , "K" , "L" , "M" , "N" , "O" , "P" , "Q" , "R" ,
                             "S" , "T" , "U" , "V" , "W" , "X" , "Y" , "Z", "1" ,
                             "2", "3", "4", "5","6","7", "8","9","0",
                             "a","b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
                             "l", "m", "n", "o", "p", "q", "r", "s", "t", "u",
                             "v", "w", "x", "y", "z"};



auto generator_txt(int pass_leng){
    std::string string_in_txt;
    long long int max_pass;
    long long int txt_size;
    std::string answer;
    srand(time(NULL));
    FILE * file = fopen("..\\dic\\rand_pass.txt", "w");
    max_pass = pow(62,pass_leng);
    txt_size = (pass_leng+2) * max_pass;
    std::cout << "Number of passwords: " << max_pass << "\n";
    std::cout << "Size of text file: " << txt_size <<  " byte" << "\n";
    std::cout <<  "proceed?[yes]: ";
    std::cin >> answer;
    if(answer == "yes"){
        for (unsigned int i = 0; i < max_pass; i++) {
            for (unsigned int i = 0; i < pass_leng; i++) {
                string_in_txt += (alphabet[rand() % 62]);
            }
            char char_pass[pass_leng];
            strcpy(char_pass, string_in_txt.c_str());
            bool res = fputs(char_pass, file);
            fputs("\n", file);
            string_in_txt = "";

        }

        fclose(file);
    }
    else{
        std::cout <<  "May be next time...\n";
    }
}

//replace in normal order

auto by_word_generator_normal_order(int amount_of_words,std::string *word_array) {

    std::string word;
    std::string word_2;
    std::string word_o;// 0
    std::string word_i;// 1
    std::string word_i_2;// !
    std::string word_s;// $
    std::string word_s_2;// 5
    std::string word_a;// @
    std::string word_f;// 4
    std::string word_e;// 3
    std::vector<std::string> pass_array;


    for (unsigned int i = 0; i <= amount_of_words; i++) {
        word = word_array[i];
        int counter_o = std::count(word.begin(), word.end(), 'o');
        int counter_i = std::count(word.begin(), word.end(), 'i');
        int counter_s = std::count(word.begin(), word.end(), 's');
        int counter_a = std::count(word.begin(), word.end(), 'a');
        int counter_f = std::count(word.begin(), word.end(), 'f');
        int counter_e = std::count(word.begin(), word.end(), 'e');

        //replace s on $

        if (counter_s == 1) {
            word_s = word.replace(word.find("s"), 1, "$");
            //std::cout << word_s << "\n";
            pass_array.push_back(word_s);
        }
        if (counter_s > 1) {
            for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 's') + 1; i++) {
                word_s = word.replace(word.find("s"), 1, "$");
                //std::cout << word_s << "\n";
                pass_array.push_back(word_s);
            }
        }

        //replace i on 1

        if (counter_i == 1) {
            word_i = word.replace(word.find("i"), 1, "1");
            //std::cout << word_i << "\n";
            pass_array.push_back(word_i);
        }
        if (counter_i > 1) {
            for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'i') + 1; i++) {
                word_i = word.replace(word.find("i"), 1, "1");
                //std::cout << word_i << "\n";
                pass_array.push_back(word_i);
            }

        }

        //replace o on 0

        if (counter_o == 1) {
            word_o = word.replace(word.find("o"), 1, "0");
            //std::cout << word_o << "\n";
            pass_array.push_back(word_o);
        }
        if (counter_o > 1) {
            for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'o') + 1; i++) {
                word_o = word.replace(word.find("o"), 1, "0");
                //std::cout << word_o << "\n";
                pass_array.push_back(word_o);
            }
        }

        //replace a on @

        if (counter_a == 1) {
            word_a = word.replace(word.find("a"), 1, "@");
            //std::cout << word_a << "\n";
            pass_array.push_back(word_a);
        }
        if (counter_a > 1) {
            for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'a') + 1; i++) {
                word_a = word.replace(word.find("a"), 1, "@");
                //std::cout << word_a << "\n";
                pass_array.push_back(word_a);
            }
        }

        //replace f on 4

        if (counter_f == 1) {
            word_f = word.replace(word.find("f"), 1, "4");
            //std::cout << word_f << "\n";
            pass_array.push_back(word_f);
        }
        if (counter_f > 1) {
            for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'f') + 1; i++) {
                word_f = word.replace(word.find("f"), 1, "4");
                //std::cout << word_f << "\n";
                pass_array.push_back(word_f);
            }
        }

        //replace e on 3

        if (counter_e == 1) {
            word_e = word.replace(word.find("e"), 1, "3");
            //std::cout << word_e << "\n";
            pass_array.push_back(word_e);
        }
        if (counter_e > 1) {
            for (unsigned int i = 0; i <= std::count(word.begin(), word.end(), 'e') + 1; i++) {
                word_e = word.replace(word.find("e"), 1, "3");
                //std::cout << word_e << "\n";
                pass_array.push_back(word_e);
            }
        }

        //replace s on 5

        word_2 = word;
        if (counter_s == 1) {

            word_s_2 = word_2.replace(word_2.find("$"), 1, "5");
            //std::cout << word_s_2 << "\n";
            pass_array.push_back(word_s_2);
        }
        if (counter_s > 1) {
            for (unsigned int i = 0; i <= std::count(word_2.begin(), word_2.end(), '$') + 1; i++) {

                word_s_2 = word_2.replace(word_2.find("$"), 1, "5");
                //std::cout << word_s_2 << "\n";
                pass_array.push_back(word_s_2);
            }
        }

        //replace 1 on !

        if (counter_i == 1) {
            word_i_2 = word_2.replace(word_2.find("1"), 1, "!");
            //std::cout << word_i_2 << "\n";
            pass_array.push_back(word_i_2);
        }
        if (counter_i > 1) {
            for (unsigned int i = 0; i <= std::count(word_2.begin(), word_2.end(), '1') + 1; i++) {
                word_i_2 = word_2.replace(word_2.find("1"), 1, "!");
                //std::cout << word_i_2 << "\n";
                pass_array.push_back(word_i_2);
            }
        }
    }

    return pass_array;
}

//replace in reverse order

auto by_word_generator_reverse_order(int amount_of_words,std::string *word_array){

    std::string word;
    std::string word_2;
    std::string word_o;// 0
    std::string word_i;// 1
    std::string word_i_2;// !
    std::string word_s;// $
    std::string word_s_2;// 5
    std::string word_a;// @
    std::string word_f;// 4
    std::string word_e;// 3
    std::vector<std::string> pass_array1;

    for (unsigned int i = 0; i <= amount_of_words; i++) {

        word = word_array[i];
        std::reverse(word.begin(),word.end());

        int counter_o = std::count(word.begin(), word.end(), 'o');
        int counter_i = std::count(word.begin(), word.end(), 'i');
        int counter_s = std::count(word.begin(), word.end(), 's');
        int counter_a = std::count(word.begin(), word.end(), 'a');
        int counter_f = std::count(word.begin(), word.end(), 'f');
        int counter_e = std::count(word.begin(), word.end(), 'e');

        //replace s on $

        if (counter_s == 1) {

            word_s = word.replace(word.find("s"), 1, "$");
            std::reverse(word_s.begin(),word_s.end());
            //std::cout << word_s << "\n";
            pass_array1.push_back(word_s);
        }
        if (counter_s > 1) {
            for (unsigned int i = 0; i < std::count(word.begin(), word.end(), 's') + 1; i++) {

                word_s = word.replace(word.find("s"), 1, "$");
                std::reverse(word_s.begin(),word_s.end());
                //std::cout << word_s << "\n";
                pass_array1.push_back(word_s);

            }
        }

        //replace i on 1

        if (counter_i == 1) {
            word_i = word.replace(word.find("i"), 1, "1");
            std::reverse(word_i.begin(),word_i.end());
            //std::cout << word_i << "\n";
            pass_array1.push_back(word_i);

        }
        if (counter_i > 1) {
            for (unsigned int i = 0; i < std::count(word.begin(), word.end(), 'i') + 1; i++) {
                word_i = word.replace(word.find("i"), 1, "1");
                std::reverse(word_i.begin(),word_i.end());
                //std::cout << word_i << "\n";
                pass_array1.push_back(word_i);
            }

        }

        //replace a on @

        if (counter_a == 1) {

            word_a = word.replace(word.find("a"), 1, "@");
            std::reverse(word_a.begin(),word_a.end());
            //std::cout << word_a << "\n";
            pass_array1.push_back(word_a);
        }
        if (counter_a > 1) {
            for (unsigned int i = 0; i < std::count(word.begin(), word.end(), 'a') + 1; i++) {
                word_a = word.replace(word.find("a"), 1, "@");
                std::reverse(word_a.begin(),word_a.end());
                //std::cout << word_a << "\n";
                pass_array1.push_back(word_a);
            }
        }

        //replace o on 0

        if (counter_o == 1) {

            word_o = word.replace(word.find("o"), 1, "0");
            std::reverse(word_o.begin(),word_o.end());
            //std::cout << word_o << "\n";
            pass_array1.push_back(word_o);
        }
        if (counter_o > 1) {
            for (unsigned int i = 0; i < std::count(word.begin(), word.end(), 'o') + 1; i++) {

                word_o = word.replace(word.find("o"), 1, "0");
                std::reverse(word_o.begin(),word_o.end());
                //std::cout << word_o << "\n";
                pass_array1.push_back(word_o);
            }
        }

        //replace e on 3

        if (counter_e == 1) {

            word_e = word.replace(word.find("e"), 1, "3");
            std::reverse(word_e.begin(),word_e.end());
            //std::cout << word_e << "\n";
            pass_array1.push_back(word_e);
        }
        if (counter_e > 1) {
            for (unsigned int i = 0; i < std::count(word.begin(), word.end(), 'e') + 1; i++) {

                word_e = word.replace(word.find("e"), 1, "3");
                std::reverse(word_e.begin(),word_e.end());
                //std::cout << word_e << "\n";
                pass_array1.push_back(word_e);
            }
        }

        //replace f on 4

        if (counter_f == 1) {

            word_f = word.replace(word.find("f"), 1, "4");
            std::reverse(word_f.begin(),word_f.end());
            //std::cout << word_f << "\n";
            pass_array1.push_back(word_f);
        }
        if (counter_f > 1) {
            for (unsigned int i = 0; i < std::count(word.begin(), word.end(), 'f') + 1; i++) {

                word_f = word.replace(word.find("f"), 1, "4");
                std::reverse(word_f.begin(),word_f.end());
                //std::cout << word_f << "\n";
                pass_array1.push_back(word_f);
            }
        }



        //replace s on 5

        word_2 = word;
        if (counter_s == 1) {

            word_s_2 = word_2.replace(word_2.find("$"), 1, "5");
            std::reverse(word_s_2.begin(),word_s_2.end());
            //std::cout << word_s_2 << "\n";
            pass_array1.push_back(word_s_2);
        }
        if (counter_s > 1) {
            for (unsigned int i = 0; i < std::count(word_2.begin(), word_2.end(), '$') + 1; i++) {

                word_s_2 = word_2.replace(word_2.find("$"), 1, "5");
                std::reverse(word_s_2.begin(),word_s_2.end());
                //std::cout << word_s_2 << "\n";
                pass_array1.push_back(word_s_2);
            }
        }

        //replace 1 on !

        if (counter_i == 1) {

            word_i_2 = word_2.replace(word_2.find("1"), 1, "!");
            std::reverse(word_i_2.begin(),word_i_2.end());
            //std::cout << word_i_2 << "\n";
            pass_array1.push_back(word_i_2);
        }
        if (counter_i > 1) {
            for (unsigned int i = 0; i < std::count(word_2.begin(), word_2.end(), '1') + 1; i++) {

                word_i_2 = word_2.replace(word_2.find("1"), 1, "!");
                std::reverse(word_i_2.begin(),word_i_2.end());
                //std::cout << word_i_2 << "\n";
                pass_array1.push_back(word_i_2);
            }
        }
    }

    return pass_array1;
}

auto combine(std::vector<std::string> pass_array,int amount_of_words){
    std::string s;
    int n=pass_array.size();
    FILE * file = fopen("..\\dic\\word_pass.txt", "w");
    s = "";
    std::cout << "pustoy" << std::endl;
    for (int i = 0;i <= pass_array.size(); i++ ) {
        if (pass_array[i].empty()){
            pass_array.erase(pass_array.begin()+i);
        }
        std::cout << i << " " << pass_array[i] << ' ';
    }
    int count = 0;

    for (int i = 0;i <= pass_array.size(); i++ ) {
        if (!pass_array[i].empty()){
            count++;
        }
    }
    std::cout << count;
    std::cout << "\n";
    std::cout << "------------------------";
    for (int i =0; i < count;i++) {
        std::cout << "\n" << i << " " ;
        std::cout << pass_array.size() << " ";
        for (int i = 0; i < count ; i++) {

            s = pass_array[i];
            pass_array[i] = pass_array[i + 1];
            pass_array[i + 1] = s;
            std::cout << pass_array[i] << " ";
        }
        if (!pass_array[0].empty() && !pass_array[1].empty()) {
            s = pass_array[0] + pass_array[1];
            std::cout << s << std::endl;
            std::cout << "------------------------";
            char char_pass[amount_of_words];
            strcpy(char_pass, s.c_str());
            bool res = fputs(char_pass, file);
            fputs("\n", file);

        }

        s = "";
    }
    return 0;

}
int main_generator () {
    int choose;
    std::cout << "Choose type of password generation:"
                 "\n1 - random generation"
                 "\n2 - by word generation\n";

    std::cin >> choose;
    switch(choose){
        case 1:
            int pass_leng;
            std::cout << "Enter the amount of symbols in passwords:";
            std::cin >> pass_leng;
            generator_txt(pass_leng);
        case 2:
            int amount_of_words;
            std::cout << "Enter the amount of words in passwords:";
            std::cin >> amount_of_words;
            std::string word_array[amount_of_words];
            for (unsigned int i = 0; i < amount_of_words; i++) {
                std::cout << "enter your word(-s):\n";
                std::cin >> word_array[i];
            }

            std::vector<std::string> pass_array1 = by_word_generator_normal_order(amount_of_words, word_array);
            std::vector<std::string> pass_array2 = by_word_generator_reverse_order(amount_of_words, word_array);
            std::reverse(pass_array2.begin(), pass_array2.end());
            int n = int(pass_array1.size()) + int(pass_array2.size());
            std::vector<std::string> pass_array_sum(n);
            int a = 0;
            int b = 1;
            if (amount_of_words > 1) {

                for (int i = 0; i < pass_array1.size(); i++) {
                    pass_array_sum.insert(pass_array_sum.begin() + a, pass_array1[i]);
                    a = a + 2;

                }

                for (int i = 0; i < pass_array2.size(); i++) {
                    pass_array_sum.insert(pass_array_sum.begin() + b, pass_array2[i]);
                    b = b + 2;
                }
                combine(pass_array_sum, amount_of_words);
            }
    }
    return 0;


}