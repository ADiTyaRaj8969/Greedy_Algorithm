// Huffman Coding
// Greedy strategy: Always merge the two nodes with the lowest frequencies first (using a min-heap).
// Task: Given a set of characters and their frequencies, build the Huffman Tree and generate
// the Huffman codes for each character (lossless data compression).

#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct Node
{
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : ch('\0'), freq(l->freq + r->freq), left(l), right(r) {}
};

struct Cmp
{
    bool operator()(Node* a, Node* b) const { return a->freq > b->freq; }
};

void buildCodes(Node* root, const string& path, unordered_map<char, string>& codes)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        codes[root->ch] = path.empty() ? "0" : path;
        return;
    }
    buildCodes(root->left, path + "0", codes);
    buildCodes(root->right, path + "1", codes);
}

unordered_map<char, string> huffmanCodes(const vector<char>& chars, const vector<int>& freq)
{
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (size_t i = 0; i < chars.size(); ++i) pq.push(new Node(chars[i], freq[i]));
    while (pq.size() > 1)
    {
        Node* a = pq.top();
        pq.pop();
        Node* b = pq.top();
        pq.pop();
        pq.push(new Node(a, b));
    }
    Node* root = pq.top();
    unordered_map<char, string> codes;
    buildCodes(root, "", codes);
    return codes;
}

int main()
{
    vector<char> c = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> f = {5, 9, 12, 13, 16, 45};
    auto codes = huffmanCodes(c, f);
    for (auto& p : codes) cout << p.first << ": " << p.second << '\n';
    return 0;
}

/*
Time Complexity: O(k log k) — building the heap and merging nodes (k distinct chars).
Space Complexity: O(k) — priority queue and tree nodes.
*/
