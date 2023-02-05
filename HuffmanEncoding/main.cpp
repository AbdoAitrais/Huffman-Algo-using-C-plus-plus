#include <iostream>
#include "Classes/Huffman.cpp"


int main() {
    std::string text = "this is a test string";
    std::unordered_map<char, int> freq;
    for (auto ch : text) {
        freq[ch]++;
    }
    Huffman huffman(freq);
    auto codes = huffman.getCodes();

    std::string encoded = encode(text, codes);
    std::string decoded = decode(encoded, huffman.root);

    std::cout << "Text: " << text << std::endl;
    std::cout << "Encoded: " << encoded << std::endl;
    std::cout << "Decoded: " << decoded << std::endl;

    return 0;
}
