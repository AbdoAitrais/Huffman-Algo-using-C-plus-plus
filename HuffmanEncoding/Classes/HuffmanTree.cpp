//
// Created by abdo on 2/5/2023.
//
class HuffmanTree {
public:
    char ch;
    int freq;
    HuffmanTree* left;
    HuffmanTree* right;

    HuffmanTree(char ch, int freq, HuffmanTree *pTree, HuffmanTree *pHuffmanTree) {
        this->ch = ch;
        this->freq = freq;
        left = pTree;
        right = pHuffmanTree;
    }

    ~HuffmanTree() {
        delete left;
        delete right;
    }
};