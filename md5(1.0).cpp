#include<bitset>
#include<string>
#include<vector>

std::bitset<32> FunG(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z) {
    return (x & z)|(~z & y);
}

std::bitset<32> FunF(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z) {
    return (x & y)|(~x & z);
}

std::bitset<32> FunH(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z) {
    return x^y^z;
}

std::bitset<32> FunI(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z) {
    return y ^ (x | ~z);
}

std::bitset<32> ROTLEFT(std::bitset<32> x, int n){
    for (int i = 0; i < n; i++){
        int bit = x[31];
        x = x << 1;
        x[0] = bit;
    }
    return x;
}

std::vector<std::bitset<32>> begin_var0 = {
        0x67452301,
        0xefcdab89,
        0x98badcfe,
        0x10325476,
};

std::vector<std::bitset<32>> const_ = {
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

std::vector<int> s = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21

};

std::string little_endian2(std::string input) {
    std::string litstr = "";
   if (input.length() == 64) {
       for (int i = 56; i < 64; i++) {
           litstr += input[i];
       }

       for (int i = 48; i < 56; i++) {
           litstr += input[i];

       }

       for (int i = 40; i < 48; i++) {
           litstr += input[i];
       }

       for (int i = 32; i < 40; i++) {
           litstr += input[i];

       }
   }

    for (int i = 24; i < 32; i++) {
        litstr += input[i];

    }

    for (int i = 16; i < 24; i++) {
        litstr += input[i];
    }

    for (int i = 8; i < 16; i++) {
        litstr += input[i];
    }

    for (int i = 0; i < 8; i++) {
        litstr += input[i];
    }

    return litstr;
}

std::vector<bool> tobinsubseq1(std::string input) {

    std::string input_bin = strtobin(input);

    int bin_len = input_bin.length();

    std::cout << bin_len << std::endl;

    std::string input_pl = input_bin + "1";

    int input_pl_len = 448 - (input_pl.length() % 512);

    if (bin_len + 1 > 447)  {
        input_pl_len = 512 - (input_pl.length() % 448);
    }



    for (int i = 1; i < input_pl_len + 1; i++) {
        input_pl.insert(input_bin.length() + i, "0");
    }

    input_pl += little_endian2(std::bitset<64>(bin_len).to_string());

    //std::cout << input_pl << std::endl;

    std::vector<bool> binout;

    for(auto j: input_pl)
        binout.push_back(j == '1');

    return binout;

}

std::vector<std::bitset<32>> makesubhash(std::string input) {

    std::vector<bool> bitmsg = tobinsubseq1(input);

    int N = bitmsg.size()/512;
    std::cout << N << std::endl;
    std::vector<std::bitset<32>> begin_var = begin_var0;

    for (int k = 0; k < N; k++) {
        std::vector<std::bitset<32>> H = begin_var0;

        std::vector<std::bitset<32>> blockset = {};

        for (int i = 0; i < 16; i++) {
            std::string binblock = "";

            for (int j = (i * 32); j < ((i + 1) * 32); j++) {
                if (bitmsg[512*k + j]) {
                    binblock += "1";
                } else {
                    binblock += "0";
                }
            }

            blockset.push_back(std::bitset<32>(little_endian2(binblock)));
            //std::cout << std::bitset<32>(little_endian2(binblock)) << std::endl;

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

            F = MERGE(MERGE(F, H[0]), MERGE(const_[j], blockset[g]));
            H[0] = H[3];
            H[3] = H[2];
            H[2] = H[1];
            H[1] = MERGE(H[1], ROTLEFT(F, s[j]));

            //std::cout << blockset[g] << std::endl;

        }


        std::cout << std::bitset<32>(H[0]) << std::endl;
        std::cout << std::bitset<32>(H[1]) << std::endl;
        std::cout << std::bitset<32>(H[2]) << std::endl;
        std::cout << std::bitset<32>(H[3]) << std::endl;


        begin_var[0] = MERGE(begin_var[0], H[0]);
        begin_var[1] = MERGE(begin_var[1], H[1]);
        begin_var[2] = MERGE(begin_var[2], H[2]);
        begin_var[3] = MERGE(begin_var[3], H[3]);

        /*std::cout << std::bitset<32>(begin_var[0]) << std::endl;
        std::cout << std::bitset<32>(begin_var[1]) << std::endl;
        std::cout << std::bitset<32>(begin_var[2]) << std::endl;
        std::cout << std::bitset<32>(begin_var[3]) << std::endl;*/

        /*begin_var[0] = MERGE(begin_var[0], std::bitset<32>("10001100101010010101111111001001"));
        begin_var[1] = MERGE(begin_var[1], H[1]);
        begin_var[2] = MERGE(begin_var[2], H[2]);
        begin_var[3] = MERGE(begin_var[3], H[3]);
*/
    }

    return begin_var;
    };

std::string little_endian(std::string input) {
    std::string litstr = "";
    for (int i = 6; i < 8; i++) {
        litstr += input[i];
    }

    for (int i = 4; i < 6; i++) {
        litstr += input[i];
    }

    for (int i = 2; i < 4; i++) {
        litstr += input[i];
    }

    for (int i = 0; i < 2; i++) {
        litstr += input[i];
    }

    return litstr;
}

std::string hash1(std::vector<std::bitset<32>> buffer) {
    std::stringstream hash_out;
    std::stringstream hash_out1;
    std::stringstream hash_out2;
    std::stringstream hash_out3;
    std::string hashdigest = "";

    hash_out << std::hex << buffer[0].to_ulong();
    if (hash_out.str().length() == 7) {
        std::string hash_out0 = "0" + hash_out.str();
        hashdigest += little_endian(hash_out0);
    }
    else {
        hashdigest += little_endian(hash_out.str());
    }


    hash_out1 << std::hex << buffer[1].to_ulong();
    if (hash_out1.str().length() == 7) {
        std::string hash_out11 = "0" + hash_out1.str();
        hashdigest += little_endian(hash_out11);
    }
    else {
        hashdigest += little_endian(hash_out1.str());
    }


    hash_out2 << std::hex << buffer[2].to_ulong();
    if (hash_out2.str().length() == 7) {
        std::string hash_out22 = "0" + hash_out2.str();
        hashdigest += little_endian(hash_out22);
    }
    else {
        hashdigest += little_endian(hash_out2.str());
    }


    hash_out3 << std::hex << buffer[3].to_ulong();
    if (hash_out3.str().length() == 7) {
        std::string hash_out33 = "0" + hash_out3.str();
        hashdigest += little_endian(hash_out33);
    }
    else {
        hashdigest += little_endian(hash_out3.str());
    }

    return hashdigest;
}

std::string md52(std::string input) {

    return hash1(makesubhash(input));
}
