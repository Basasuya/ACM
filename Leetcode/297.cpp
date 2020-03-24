class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#,";
        string str = to_string(root->val) + ',';
        str += serialize(root->left);
        str += serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data = "") {
        static int i = 0;
        static string str;
        if (!data.empty()) {
            str = data;
            i = 0;
        }
        int j = str.find(',', i);
        string temp = str.substr(i, j - i);
        i = j + 1;
        if (temp == "#")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(temp));
        node->left = deserialize();
        node->right = deserialize();
        return node;
    }
};

/*

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
