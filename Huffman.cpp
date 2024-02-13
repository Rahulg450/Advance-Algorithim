#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node {
  char data;
  int freq;
  Node* left, *right;

  Node(char data, int freq) : data(data), freq(freq), left(NULL), right(NULL) {}
};

struct Compare {
  bool operator()(Node* a, Node* b) { return a->freq > b->freq; }
};

Node* buildTree(vector<char> S, vector<int> f) {
  priority_queue<Node*, vector<Node*>, Compare> pq;
  for (int i = 0; i < S.size(); i++) {
    pq.push(new Node(S[i], f[i]));
  }

  while (pq.size() != 1) {
    Node* left = pq.top();
    pq.pop();
    Node* right = pq.top();
    pq.pop();

    Node* parent = new Node('$', left->freq + right->freq);
    parent->left = left;
    parent->right = right;

    pq.push(parent);
  }

  return pq.top();
}

void printCodes(Node* root, string code) {
  if (!root) return;

  if (root->left == NULL && root->right == NULL) { // Leaf node
    cout << root->data << " : " << code << endl;
  }

  printCodes(root->left, code + "0");
  printCodes(root->right, code + "1");
}

int main() {
  int n;
  cout << "Enter the number of characters: ";
  cin >> n;

  vector<char> S(n);
  vector<int> f(n);

  cout << "Enter the characters and their frequencies separated by spaces:\n";
  for (int i = 0; i < n; i++) {
    cin >> S[i] >> f[i];
  }

  Node* root = buildTree(S, f);
  cout << "Huffman Codes:\n";
  printCodes(root, "");

  return 0;
}
