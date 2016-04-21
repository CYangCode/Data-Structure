#include <iostream>
#include <hash_map>
#include <queue>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

struct TreeNode
{
    char ch;//字符名
    int num;//出现的次数
    char code;//二进制编码对应的字符
    TreeNode * lchild, * rchild;
    TreeNode(char _ch, int _num):ch(_ch), num(_num), lchild(nullptr), rchild(nullptr) {}
    TreeNode(TreeNode * lc, TreeNode * rc): ch('$'), lchild(lc), rchild(rc) {if (lchild && rchild) num = lc->num + rc->num;}
};

class Comparer
{
public:
    bool operator()(const TreeNode * first, const TreeNode * second) { return first->num > second->num;}
};

string itoa(int num, int radix)
{
    string str = "0123456789ABCDEFGHI";
    if (num / radix == 0) return string("") + str[num];
    return itoa(num / radix, radix) + str[num % radix];
}

TreeNode * CreateHuffman(const hash_map<char, int> & char_map)
{
    priority_queue<TreeNode*, vector<TreeNode *>, Comparer> min_heap;
    for (auto elem: char_map) min_heap.push(new TreeNode(elem.first, elem.second));
    //遍历最小堆，生成Huffman树
    TreeNode * head = nullptr;
    while (min_heap.size() != 1)
    {
        TreeNode * first_min_node = min_heap.top();
        min_heap.pop();
        TreeNode * second_min_node = min_heap.top();
        min_heap.pop();
        head = new TreeNode(first_min_node, second_min_node);
        min_heap.push(head);
    }
    return head;
}


void Coding(TreeNode * head, int code, hash_map<char, char> & code_map)
{
    if (!head) return;
    head->code = code;
    if (!head->rchild) code_map[head->ch] = code;
    Coding(head->lchild, code * 2, code_map);
    Coding(head->rchild, code * 2 + 1, code_map);
}

hash_map<char, char> GetCodeMap(hash_map<char, int> char_map)
{
    TreeNode * rhead = CreateHuffman(char_map);
    hash_map<char, char> code_map;
    //二进制01和1对应的字符相同,所以将整棵树变成右子树
    TreeNode * head = new TreeNode(nullptr, rhead);
    Coding(head, 0, code_map);
    return code_map;
}

int main()
{
    hash_map<char, int> char_map;
    string str;
    getline(cin, str);
    for (char ch: str) ++char_map[ch];
    const hash_map<char, char> & code_map = GetCodeMap(char_map);
    for (auto elem: code_map) cout << elem.first << " " << itoa(elem.second, 2) << endl;
    return 0;
}

/*//测试数据
    char_map['a'] = 5;
    char_map['b'] = 29;
    char_map['c'] = 7;
    char_map['d'] = 8;
    char_map['e'] = 14;
    char_map['f'] = 23;
    char_map['g'] = 3;
    char_map['h'] = 11;*/
