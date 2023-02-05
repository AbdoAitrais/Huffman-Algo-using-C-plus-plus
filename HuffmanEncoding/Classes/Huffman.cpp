//
// Created by abdo on 2/5/2023.
//
#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include "HuffmanTree.cpp"
#include <functional>


class Huffman {
public:HuffmanTree* root;
    std::unordered_map<char, std::string> codes;

    void buildHuffmanTree(std::unordered_map<char, int>& freq) {
        std::priority_queue<HuffmanTree*, std::vector<HuffmanTree*>, std::function<bool(HuffmanTree*, HuffmanTree*)>> pq([](HuffmanTree* a, HuffmanTree* b) {
            return a->freq > b->freq;
        });

        for (auto [ch, f] : freq) {
            pq.push(new HuffmanTree(ch, f, nullptr, nullptr));
        }

        while (pq.size() != 1) {
            HuffmanTree* left = pq.top();
            pq.pop();
            HuffmanTree* right = pq.top();
            pq.pop();
            int sum = left->freq + right->freq;
            pq.push(new HuffmanTree('\0', sum, left, right));
        }
        root = pq.top();
    }

    void buildCodes(HuffmanTree* node, std::string code) {
        if (node->left == nullptr && node->right == nullptr) {
            codes[node->ch] = code;
            return;
        }

        buildCodes(node->left, code + "0");
        buildCodes(node->right, code + "1");
    }

public:
    Huffman(std::unordered_map<char, int>& freq) {
        buildHuffmanTree(freq);
        buildCodes(root, "");
    }

    std::unordered_map<char, std::string> getCodes() {
        return codes;
    }

    ~Huffman() {
        delete root;
    }
};

std::string encode(std::string text, std::unordered_map<char, std::string>& codes) {
    std::string encoded = "";
    for (auto ch : text) {
        encoded += codes[ch];
    }
    return encoded;
}

std::string decode(std::string encoded, HuffmanTree* root) {
    std::string decoded = "";
    HuffmanTree* current = root;
    for (auto bit : encoded) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == nullptr && current->right == nullptr) {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}


