#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int el)
    {
        this->val = el;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0;
    }
    int getValue()
    {
        return this->val;
    }
};

class Tree
{
private:
    TreeNode *root;
    TreeNode *insert(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            node = new TreeNode(val);
            return node;
        }
        if (node->val > val)
        {
            node->left = insert(node->left, val);
        }
        else if (node->val < val)
        {
            node->right = insert(node->right, val);
        }
        else
        {
            cout << "unable to add node" << endl;
            return node;
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        return node;
    }
    void displayNodeInorder(TreeNode *node)
    {
        if (node->left != nullptr)
        {
            displayNodeInorder(node->left);
        };
        cout << node->val << " ";
        if (node->right != nullptr)
        {
            displayNodeInorder(node->right);
        };
    }
    void displayNodePreorder(TreeNode *node)
    {
        cout << node->val << " ";
        if (node->left != nullptr)
        {
            displayNodePreorder(node->left);
        };
        if (node->right != nullptr)
        {
            displayNodePreorder(node->right);
        };
    }
    void displayNodePostorder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        displayNodePostorder(node->left);
        displayNodePostorder(node->right);
        cout << node->val << " ";
    }
    void prettyDisp(TreeNode *node, int level)
    {
        if (node == nullptr)
        {
            return;
        }

        prettyDisp(node->right, level + 1);

        if (level != 0)
        {
            for (int i = 0; i < level - 1; i++)
            {
                cout << "|\t";
            }
            cout << "|------>" << node->val;
        }
        else
        {
            cout << node->val;
        }
        cout << endl;
        prettyDisp(node->left, level + 1);
    }
    int height(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return node->height;
    }
    bool search(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->getValue() == val)
        {
            return true;
        }
        else if (node->getValue() > val)
        {
            return search(node->left, val);
        }
        else if (node->getValue() < val)
        {
            return search(node->right, val);
        }

        return false;
    }
    TreeNode *deleteNode(TreeNode *node, int key)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (node->getValue() == key)
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else
            {
                if (node->right == nullptr)
                {
                    node = node->left;
                    return node;
                }
                else if (node->left == nullptr)
                {
                    node = node->right;
                    return node;
                }
                TreeNode *min = findMin(node->right);
                node->right = deleteNode(node->right, min->getValue());
                node->val = min->val;
                return node;
            }
        }
        else if (node->getValue() > key)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (node->getValue() < key)
        {
            node->right = deleteNode(node->right, key);
        }
        return node;
    }
    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

public:
    Tree();
    void display();
    void prettyDisplay();
    int height();
    bool isEmpty();
    void insert(int val);
    bool search(int val);
    void delete_Elem(int val);
};

Tree::Tree()
{
    root = nullptr;
}

void Tree::delete_Elem(int val)
{
    if (!search(val))
    {
        cout << "elem not present" << endl;
        return;
    }

    deleteNode(root, val);
    return;
}
void Tree::display(/* args */)
{
    cout << " inorder : ";
    displayNodeInorder(root);
    cout << endl;
    cout << " preorder : ";
    displayNodePreorder(root);
    cout << endl;
    cout << " postorder : ";
    displayNodePostorder(root);
    cout << endl;
}
bool Tree::search(int val)
{
    return search(root, val);
}
bool Tree ::isEmpty()
{
    return root == nullptr;
}
void Tree::prettyDisplay()
{
    prettyDisp(root, 0);
    cout << endl;
}

int Tree::height()
{
    return height(root);
}

void Tree::insert(int val)
{
    if (root == nullptr)
    {
        this->root = new TreeNode(val);
    }
    else
    {
        insert(root, val);
    }
}

int main(int argc, char const *argv[])
{
    int rootVal, numOfElem;
    bool display;
    cout << "Enter number of nodes : ";
    cin >> numOfElem;
    cout << endl;
    Tree x;
    for (int i = 0; i < numOfElem; i++)
    {
        int elem;
        cout << "Enter elem value :";
        cin >> elem;
        x.insert(elem);
    }
    cout << "do you want to display tree (1 / 0) :";
    cin >> display;
    if (display)
    {
        x.display();
        cout << endl;
        x.prettyDisplay();
    }
    cout << "delete elem :";
    cin >> rootVal;
    x.delete_Elem(rootVal);
    x.prettyDisplay();
    return 0;
}