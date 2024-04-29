#ifndef HEX_H_
#define HEX_H_

#include <map>
#include <string>

int power(int base, int exp) {
  if (exp == 0) {
    return 1;
  } else {
    return base * power(base, exp - 1);
  }
}

int hex2dec(std::string hex_num) {
  std::map<char, int> hex_digits{{'a', 10}, {'b', 11}, {'c', 12},
                                 {'d', 13}, {'e', 14}, {'f', 15}};
  int dec_num{0};
  for (size_t i{0}; i < hex_num.size(); ++i) {
    dec_num += hex_digits[hex_num[i]] * power(16, hex_num.size() - i - 1);
  }
  return dec_num;
}

#endif // HEX_H_
