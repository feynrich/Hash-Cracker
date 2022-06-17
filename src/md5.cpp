#include<bitset>
#include<string>
#include<vector>
#include<sstream>
#include <iostream>

/*
Множество функция Fun - функции проводящие операции над битовым потоком
    */
std::bitset<32> FunG(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z) {
    return (x & z) | (~z & y);
}

std::bitset<32> FunF(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z) {
    return (x & y) | (~x & z);
}

std::bitset<32> FunH(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z) {
    return x ^ y ^ z;
}

std::bitset<32> FunI(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z) {
    return y ^ (x | ~z);
}

std::bitset<32> ROTLEFT(std::bitset<32> x, int n) {
    /*
      Циклический сдвиг влево
    */
    for (int i = 0; i < n; i++) {
        int bit = x[31];
        x = x << 1;
        x[0] = bit;
    }
    return x;
}

std::bitset<32> MERGE_MD5(std::bitset<32> x, std::bitset<32> y) {
    int sum0 = x.to_ulong() + y.to_ulong();
    std::bitset<32> sum(sum0);
    return sum;
}

std::vector<std::bitset<32>> begin_var0 = {
        0x67452301,
        0xefcdab89,
        0x98badcfe,
        0x10325476,
};

const std::vector<std::bitset<32>> const_ = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

const std::vector<int> s = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21

};

auto make_little_endian(std::string input) {
    /*
      Функция которая производит запись битовой послед-ти в формате little endian
    */
    std::string litstr;
    for (auto i = input.length() / 8; i > 0; i--) {
        for (auto j = 8 * i - 8; j < 8 * i; j++) {
            litstr += input[j];
        }
    }
    return litstr;
}

std::string strtobin_sec(std::string &message) {
    std::string binstr;

    for (int i = 0; i < message.length(); i++) {
        binstr += std::bitset<8>(message[i]).to_string();
    }
    return binstr;
}

auto tobinsubseq1(std::string &input) {
    /*
      Функция которая выравнивает битовый поток
    */

    std::string input_bin = strtobin_sec(input);

    int bin_len = input_bin.length();

    std::string input_pl = input_bin + "1";

    int input_pl_len = 448 - (input_pl.length() % 512);

    if (bin_len + 1 > 447) {
        input_pl_len = 512 - (input_pl.length() % 448);
    }

    for (int i = 1; i < input_pl_len + 1; i++) {
        input_pl.insert(input_bin.length() + i, "0");
    }

    input_pl += make_little_endian(std::bitset<64>(bin_len).to_string());

    std::vector<bool> binout;

    for (auto j: input_pl)
        binout.push_back(j == '1');

    return binout;

}

auto makesubhash(std::string &input) {
    /*
      Функция проводящая вычисление хеша по блоку в цикле
    */

    std::vector<bool> bitmsg = tobinsubseq1(input);

    int N = bitmsg.size() / 512;
    std::vector<std::bitset<32>> begin_var = begin_var0;

    for (int k = 0; k < N; k++) {
        std::vector<std::bitset<32>> H = begin_var0;

        std::vector<std::bitset<32>> blockset = {};

        for (int i = 0; i < 16; i++) {
            std::string binblock = "";

            for (int j = (i * 32); j < ((i + 1) * 32); j++) {
                if (bitmsg[512 * k + j]) {
                    binblock += "1";
                } else {
                    binblock += "0";
                }
            }

            blockset.push_back(std::bitset<32>(make_little_endian(binblock)));
        }

        for (int j = 0; j < 64; j++) {
            std::bitset<32> F;
            int g;

            if (j < 16) {
                F = FunF(H[1], H[2], H[3]);
                g = j;
            } else if (j < 32) {
                F = FunG(H[1], H[2], H[3]);
                g = (5 * j + 1) % 16;

            } else if (j < 48) {
                F = FunH(H[1], H[2], H[3]);
                g = (3 * j + 5) % 16;

            } else {
                F = FunI(H[1], H[2], H[3]);
                g = (7 * j) % 16;

            }

            F = MERGE_MD5(MERGE_MD5(F, H[0]), MERGE_MD5(const_[j], blockset[g]));
            H[0] = H[3];
            H[3] = H[2];
            H[2] = H[1];
            H[1] = MERGE_MD5(H[1], ROTLEFT(F, s[j]));

        }


        begin_var[0] = MERGE_MD5(begin_var[0], H[0]);
        begin_var[1] = MERGE_MD5(begin_var[1], H[1]);
        begin_var[2] = MERGE_MD5(begin_var[2], H[2]);
        begin_var[3] = MERGE_MD5(begin_var[3], H[3]);

    }


    return begin_var;
}

auto little_endian(std::string input) {
    /*
      запись битовой послед-ти в формате 2 бита
     */
    std::string litstr;
    for (auto i = input.length() / 2; i > 0; i--) {
        for (auto j = 2 * (i - 1); j < 2 * i; j++) {
            litstr += input[j];
        }
    }
    return litstr;

}

auto hash_little_endian(std::bitset<32> buffer) {
    /*
      запись битовой послед-ти в формате little endian в 16-й код
     */
    std::stringstream hash_out;
    std::string hashdigest;
    hash_out << std::hex << buffer.to_ulong();
    if (hash_out.str().length() == 7) {
        std::string hash_out0 = "0" + hash_out.str();
        hashdigest += little_endian(hash_out0);
    } else {
        hashdigest += little_endian(hash_out.str());
    }
    return hashdigest;
}

auto hash1(std::vector<std::bitset<32>> buffer) {
    /*
      соединение хеша из 4-х блоков
     */
    std::string hash_str;
    for (int i = 0; i < 4; i++) {
        hash_str += hash_little_endian(buffer[i]);
    }
    return hash_str;
}

auto md5(std::string input) {
    /*
      вызов функции hash1 - то есть замыкание
     */

    return hash1(makesubhash(input));
}
