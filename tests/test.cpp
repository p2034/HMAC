#include <iostream>
#include <stdexcept>

#include "sha256.h"
#include "hmac.h"



int main() {
  try {
    std::string kstr = "textjkdfhsgasbflsdkfbsadhjkfvasdhjkfvasdhjkfgvsdfvasdfgvkasdhfvasdghkfvgasdvfghkasdvfghasvhf";
    std::string dstr = "sometextdasdjfhbasjhkldfasdfbasdhjlfjkasdhfsdhfbsdhjbfhsdbfhsdfhsdbfhsdb";

    uint8_t* key = new uint8_t[kstr.length()];
    uint8_t* data = new uint8_t[dstr.length()];

    for (int i = 0; i < kstr.length(); i++)
      key[i] = kstr[i];

    for (int i = 0; i < dstr.length(); i++)
      data[i] = dstr[i];

    uint8_t* hash = hmac(sha256, SHA256_HASH_SIZE, SHA256_BLOCK_SIZE, data, dstr.length(), key, kstr.length());

    for (int i = 0; i < SHA256_HASH_SIZE; i++)
      std::cout << std::hex << (int)hash[i] << " ";
    std::cout << std::endl;

    delete[] data;
    delete[] key;
    delete[] hash;

  } catch(const std::exception& excpt) {
    std::cout << excpt.what() << "\n";
  }

	return 0;
}