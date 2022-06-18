#include<sstream>
#include<bitset>
#include<string>
#include<vector>
#include<iostream>

std::bitset<32> ROTRIGHT(std::bitset<32> x, int n) {
    /*!
      Циклический сдвиг вправо
      x: битовый массив
      n: порядок сдвига
     */
    for (int i = 0; i < n; i++) {
        int bit = x[0];
        x = x >> 1;
        x[31] = bit;
    }
    return x;
}

std::bitset<32> XOR(std::bitset<32> x, std::bitset<32> y) {
    /*!
      Логическая операция исключающее "или"
      x: битовая строка
      y: битовая строка
     */
    return x ^ y;
}

std::bitset<32> MERGE(std::bitset<32> x, std::bitset<32> y) {
    /*!
      Возвращает рез-тат побитового сложения
      x: битовая строка
      y: битовая строка
     */
    int sum0 = x.to_ulong() + y.to_ulong();
    std::bitset<32> sum(sum0);
    return sum;
}

std::string strtobin(std::string message) {
    /*!
      Преобразование строки в битовую послед-ть
     */
    std::string binstr;

    for (int i = 0; i < message.length(); i++) {
        binstr += std::bitset<8>(message[i]).to_string();
    }
    return binstr;
}


auto tobinsubseq(std::string &input) {
    /*!
      Функция которая выравнивает битовый поток
      input: исходная строка в битовом формате
     */

    std::string input_bin = strtobin(input);
    int bin_len = input_bin.length();

    std::string input_pl = input_bin + "1";

    int input_pl_len = 448 - (input_pl.length() % 512);

    for (int i = 1; i < input_pl_len + 1; i++) {
        input_pl.insert(input_bin.length() + i, "0");
    }
    input_pl += std::bitset<64>(bin_len).to_string();

    std::vector<bool> binout;

    for (auto j: input_pl)
        binout.push_back(j == '1');

    return binout;
}

auto extrawords(std::bitset<512> &message) {
    /*!
     Генерация дополнительных слов для хэша
     message: выровненный битовый поток
    */

    int bin_len = 512;
    int count = bin_len - 1;
    int bit_long = 32;

    std::string subbit;

    std::vector<std::bitset<32>> messagesset = {};


    for (int i = 0; i < 16; i++) {
        for (int j = count; j > (count - bit_long); j--) {

            subbit += to_string(message[j]);
        }
        messagesset.push_back(std::bitset<32>(subbit));
        subbit = "";
        count -= bit_long;
    }

    std::bitset<32> bitmsg;

    for (int i = 16; i < 64; i++) {

        std::bitset<32> s0 = XOR(XOR(ROTRIGHT(messagesset[i - 15], 7), ROTRIGHT(messagesset[i - 15], 18)),
                                 (messagesset[i - 15] >> 3));
        std::bitset<32> s1 = XOR(XOR(ROTRIGHT(messagesset[i - 2], 17), ROTRIGHT(messagesset[i - 2], 19)),
                                 (messagesset[i - 2] >> 10));
        bitmsg = MERGE(MERGE(messagesset[i - 16], s0), MERGE(messagesset[i - 7], s1));
        messagesset.push_back(bitmsg);
    }

    return messagesset;
}

auto initsupvar(std::vector<std::bitset<32>> H, std::vector<std::bitset<32>> sqhash, std::vector<std::bitset<32>> word_64) {
    /*!
     Инициализация вспомогательных переменных
     H: вектор из значений квадратных корней натуральных чисел
     sqhash: вектор из значений кубических корней натуральных чисел
     word_64: блок битового сообщения
     */

    std::bitset<32> T1;
    std::bitset<32> T2;

    std::vector<std::bitset<32>> SUP = H;

    for (int i = 0; i < 64; i++) {
        T1 = MERGE(XOR(XOR(ROTRIGHT(SUP[4], 6), ROTRIGHT(SUP[4], 11)), ROTRIGHT(SUP[4], 25)),
                   MERGE(XOR(SUP[4] & SUP[5], ~SUP[4] & SUP[6]), MERGE(SUP[7], MERGE(sqhash[i], word_64[i]))));
        T2 = MERGE(XOR(XOR(ROTRIGHT(SUP[0], 2), ROTRIGHT(SUP[0], 13)), ROTRIGHT(SUP[0], 22)),
                   (SUP[0] & (SUP[1] | SUP[2])) | (SUP[1] & SUP[2]));

        SUP[7] = SUP[6];
        SUP[6] = SUP[5];
        SUP[5] = SUP[4];
        SUP[4] = MERGE(SUP[3], T1);
        SUP[3] = SUP[2];
        SUP[2] = SUP[1];
        SUP[1] = SUP[0];
        SUP[0] = MERGE(T1, T2);
    }

    return SUP;
}

auto makebinaryhash(std::string pass) {
    /*!
     Создание бинарного хэша
     pass: исходное сообщение
     */

    std::vector<std::bitset<32>> H_vector = {0x6a09e667,
                                      0xbb67ae85,
                                      0x3c6ef372,
                                      0xa54ff53a,
                                      0x510e527f,
                                      0x9b05688c,
                                      0x1f83d9ab,
                                      0x5be0cd19
    };
    //заранее вычисленные кубические корни натуральных чисел
    const std::vector<std::bitset<32>> root_3 = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
                                           0x923f82a4, 0xab1c5ed5,
                                           0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe,
                                           0x9bdc06a7, 0xc19bf174,
                                           0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa,
                                           0x5cb0a9dc, 0x76f988da,
                                           0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
                                           0x06ca6351, 0x14292967,
                                           0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb,
                                           0x81c2c92e, 0x92722c85,
                                           0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624,
                                           0xf40e3585, 0x106aa070,
                                           0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
                                           0x5b9cca4f, 0x682e6ff3,
                                           0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb,
                                           0xbef9a3f7, 0xc67178f2
    };

    std::vector<bool> bitmsg = tobinsubseq(pass);

    int N = bitmsg.size() / 512; //количество блоков на 512 бит

    std::vector<std::bitset<32>> message;
    std::vector<std::bitset<32>> SUP;
    std::vector<std::bitset<32>> hashedblock;

    for (int i = 0; i < N; i++) { //разбиение потока на блоки
        std::string binblock = "";

        for (int j = (i * 512); j < ((i + 1) * 512); j++) {
            if (bitmsg[j]) {
                binblock += "1";
            } else {
                binblock += "0";
            }
        }

        std::bitset<512> msgblock(binblock);

        message = extrawords(msgblock);

        SUP = initsupvar(H_vector, root_3, message);

        for (int i = 0; i < 8; i++) { //логическое слияние побитовых блоков и вычисленных доп слов

            hashedblock.push_back(MERGE(H_vector[i], SUP[i]));

        }

        H_vector = hashedblock;
    }

    return hashedblock;
}

auto outputhash(std::vector<std::bitset<32>> binhash) {
    /*!
     Возвращает из блоков созданную отхэшированную строку
     binhash: ветктор из хэше, разбитого на блоки
    */

    std::string outputhash = "";

    for (int i = 0; i < 8; i++) {
        std::stringstream strhash;
        strhash << std::hex << binhash[i].to_ulong();
        if (strhash.str().length() == 7) {
            outputhash += "0";
        }
        outputhash += strhash.str();
    }
    return outputhash;
}

auto sha256(std::string pass) {
    /*!
     Возвращает итоговый хеш
     */
    return outputhash(makebinaryhash(pass));;
}







