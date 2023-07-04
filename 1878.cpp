#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    int N;
    cin >> N;

    if (N % 4 == 2 || N == 3) {
        cout << -1 << endl;
        return 0;
    }
    else if (N % 4 == 0 || N % 4 == 1) {
        if (N % 2 == 1) {
            N -= 1;
        }

        vector<int> left, right;
        vector<pair<int, int>> pairs;

        for (int i = 1; i <= N / 2; i++) {
            pairs.push_back(make_pair(i, N + 1 - i));
        }

        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i].first % 4 == 0 || pairs[i].first % 4 == 1) {
                left.push_back(pairs[i].first);
                left.push_back(pairs[i].second);
            }
            else {
                right.push_back(pairs[i].second);
                right.push_back(pairs[i].first);
            }
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end(), greater<int>());

        Node* root1 = NULL;
        for (int i = 0; i < left.size(); i++) {
            root1 = insert(root1, left[i]);
        }

        Node* root2 = NULL;
        for (int i = 0; i < right.size(); i++) {
            root2 = insert(root2, right[i]);
        }

        preOrder(root1);
        cout << endl;

        preOrder(root2);
        cout << endl;

        return 0;
    }
    else if (N % 8 == 7) {
        vector<int> left, right;

        int mid = (N + 1) / 2;

        for (int i = 1; i <= N; i++) {
            if (i < mid) {
                if (i % 4 == 0 || i % 4 == 1) {
                    left.push_back(i);
                }
                else {
                    right.push_back(i);
                }
            }
            else if (i > mid) {
                if (i % 4 == 1 || i % 4 == 2) {
                    left.push_back(i);
                }
                else {
                    right.push_back(i);
                }
            }
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end(), greater<int>());

        Node* root1 = NULL;
        for (int i = 0; i < left.size(); i++) {
            root1 = insert(root1, left[i]);
        }

        Node* root2 = NULL;
        for (int i = 0; i < right.size(); i++) {
            root2 = insert(root2, right[i]);
        }

        preOrder(root1);
        cout << endl;

        preOrder(root2);
        cout << endl;

        return 0;
    }
    else if (N % 4 == 3) {
        int q = N / 8;
        vector<int> left, right;
        vector<int> odd, even;
        for (int i = 1; i <= N; i++) {
            if (i % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }
        for (int i = 0; i < odd.size(); i++) {
            if (odd[i] % 4 == 1) {
                left.push_back(odd[i]);
            }
            else if (odd[i] % 4 == 3) {
                right.push_back(odd[i]);
            }
        }
        auto itr = find(even.begin(), even.end(), q * 4);
        if (itr != even.end()) {
            even.erase(itr);
        }
        for (int i = 0; i < even.size(); i++) {
            if (i % 2 == 0) {
                right.push_back(even[i]);
            }
            else {
                left.push_back(even[i]);
            }
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end(), greater<int>());

        Node* root1 = NULL;
        for (int i = 0; i < left.size(); i++) {
            root1 = insert(root1, left[i]);
        }

        Node* root2 = NULL;
        for (int i = 0; i < right.size(); i++) {
            root2 = insert(root2, right[i]);
        }

        preOrder(root1);
        cout << endl;

        preOrder(root2);
        cout << endl;

        return 0;
    }
}
