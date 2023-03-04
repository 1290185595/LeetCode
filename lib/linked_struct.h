#ifndef LEETCODE_LINKED_STRUCT_H
#define LEETCODE_LINKED_STRUCT_H

template<class T>
ostream &operator<<(ostream &out, vector<T> const &v) {
    out << "[";
    if (v.empty()){
        out << ",";
    } else {
        for (auto i: v) out << i << ",";
    }
    out << "\b]";
    return out;
}

template<class T>
class LinkedStruct {
private:
    T *root;
public:
    explicit LinkedStruct(string &data) {
        this->root = data == "[]" ? nullptr : new T(data);
    }
    explicit LinkedStruct(vector<int> const &data) {
        stringstream s;
        s << data;
        new(this)LinkedStruct(s.str());
    }
    operator T *() {
        return root;
    }
};

struct ListNode {
    int val{};
    ListNode *next{};

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    friend ostream &operator<<(ostream &out, ListNode const *root) {
        out << "[";
        if (root == nullptr) {
            out << ",";
        } else {
            while (root != nullptr) {
                cout << root->val << ",";
                root = root->next;
            }
        }
        out << "\b]";
        return out;
    }

    ListNode(vector<int>::const_iterator begin, vector<int>::const_iterator end) {
        new(this)ListNode(*begin++, begin == end ? nullptr : new ListNode(begin, end));
    }

    explicit ListNode(vector<int> const &vec) {
        new(this)ListNode(vec.begin(), vec.end());
    }

    explicit ListNode(string const &s) {
        vector<int> vec;
        stringstream ss(s.substr(1, s.size() - 2));
        for (string temp; getline(ss, temp, ',');) {
            vec.emplace_back(stoi(temp));
        }
        new(this)ListNode(vec);
    }
};

template<>
Data<ListNode*>::Data(string & s) {
    data = LinkedStruct<ListNode>(s);
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    friend ostream &operator<<(ostream &out, TreeNode const *root) {
        out << "[";
        if (root == nullptr) {
            out << ",";
        } else {
            deque<const TreeNode *> deque = {root};
            for (int n = 1; n > 0;) {
                const TreeNode *node = deque.front();
                deque.pop_front();
                if (node == nullptr) {
                    out << "null,";
                } else {
                    out << node->val << ",";
                    deque.push_back(node->left);
                    deque.push_back(node->right);
                    n += (node->left != nullptr) + (node->right != nullptr) - 1;
                }
            }
        }
        out << "\b]";
        return out;
    }

    explicit TreeNode(vector<NumType<int>> const &vec) {
        queue<TreeNode *> q;
        bool writen = false;
        auto p = vec.begin();
        for (TreeNode *node = new(this)TreeNode(**p++); p != vec.end(); ++p) {
            TreeNode *next = *p == nullptr ? nullptr : new TreeNode(**p);
            if (next != nullptr) q.push(next);
            if (writen) {
                node->right = next;
                node = q.front();
                q.pop();
            } else {
                node->left = next;
            }
            writen = !writen;
        }
    }

    explicit TreeNode(string const &s) {
        vector<NumType<int>> vec;
        stringstream ss(s.substr(1, s.size() - 2));
        for (string temp; getline(ss, temp, ',');) {
            vec.emplace_back(temp);
        }
        new(this)TreeNode(vec);
    }
};

template<>
Data<TreeNode*>::Data(string &s) {
    data = LinkedStruct<TreeNode>(s);
}


#endif //LEETCODE_LINKED_STRUCT_H
