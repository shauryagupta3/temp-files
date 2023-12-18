#include <iostream>
using namespace std;
struct Node
{
    int val;
    int height;
    Node *right;
    Node *left;
    Node() : val(0), height(1), left(nullptr), right(nullptr) {}
    Node(int el) : val(el), height(1), left(nullptr), right(nullptr) {}
    Node(int el, Node *l, Node *r) : val(el), height(0), left(l), right(r) {}
    void setVal(int el)
    {
        this->val = el;
    }
    void setHeight(int el)
    {
        this->height = el;
    }
    int getVal()
    {
        return this->val;
    }
    int getHeight()
    {
        return this->height;
    }
};

class avlTree
{
private:
    Node *root;
    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->getHeight();
    }
    void prettyDisp(Node *node, int level)
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
            cout << "|------>" << node->getVal() << " h-" << node->getHeight();
        }
        else
        {
            cout << node->getVal() << " h-" << node->getHeight();
        }
        cout << endl;
        prettyDisp(node->left, level + 1);
    }
    Node *insert(Node *&node, int val)
    {
        if (node == nullptr)
        {
            node = new Node(val);
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
        node->height = 1 + max(height(node->left), height(node->right));
        // return rotate(node);
        node = rotate(node);
        return node;
    }

    Node *rotate(Node *&node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (height(node->left) - height(node->right) > 1) // left heavy
        {
            if (height(node->left->left) - height(node->left->right) > 0) // left
            {
                return rightRotate(node);
            }
            if (height(node->left->left) - height(node->left->right) < 0) // left right
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        if (height(node->left) - height(node->right) < -1) // right heavy
        {
            if (height(node->right->right) - height(node->right->left) > 0) // right right
            {
                return leftRotate(node);
            }
            if (height(node->right->right) - height(node->right->left) < 0) // right left
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    Node *leftRotate(Node *node)
    {
        Node *child = node->right;
        Node *childchild = child->left;

        child->left = node;
        node->right = childchild;

        node->height = max(height(node->left), height(node->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
    }

    Node *rightRotate(Node *node)
    {
        Node *child = node->left;
        Node *childchild = child->right;

        child->right = node;
        node->left = childchild;

        node->height = max(height(node->left), height(node->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
    }
    void inorderTraversal(Node *node)
    {
        if (node)
        {
            inorderTraversal(node->left);
            cout << node->getVal() << " ";
            inorderTraversal(node->right);
        }
    }
    bool search(Node *node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (val == node->getVal())
        {
            return true;
        }
        else if (val < node->getVal())
        {
            return search(node->left, val);
        }
        else
        {
            return search(node->right, val);
        }
    }
    Node *deleteNode(Node *node, int key)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (node->getVal() == key)
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
                Node *min = findMin(node->right);
                node->right = deleteNode(node->right, min->getVal());
                node->val = min->val;
                return node;
            }
        }
        else if (node->getVal() > key)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (node->getVal() < key)
        {
            node->right = deleteNode(node->right, key);
        }
        return node;
    }
    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

public:
    avlTree() : root(nullptr) {}
    ~avlTree() {}
    void inorderTraversal()
    {
        inorderTraversal(root);
        cout << endl;
    }
    bool search(int el)
    {
        return search(root, el);
    }
    void deleteNode(int val)
    {
        if (!search(val))
        {
            cout << "elem not present" << endl;
            return;
        }

        deleteNode(root, val);
        return;
    }
    bool isEmpty() const
    {
        return root == nullptr;
    }
    void insert(int el)
    {
        if (root == nullptr)
        {
            root = new Node(el);
            return;
        }
        insert(root, el);
    }
    void display()
    {
        this->prettyDisp(root, 0);
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    avlTree x;
    x.insert(10);
    x.insert(20);
    x.display();
    x.insert(30);
    x.display();
    x.insert(40);
    x.display();
    x.insert(50);
    x.display();
    x.insert(60);
    x.deleteNode(40);
    x.insert(70);
    cout << x.search(70) << " ";
    cout << x.search(170) << " ";
    cout << x.search(10) << " ";
    x.display();
    x.inorderTraversal();
    return 0;
}
