#include <iostream>

using namespace std;

template <typename T>
struct default_less
{
    bool is_less(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <typename T, typename LESS = default_less<T>>

class Tree
{

    struct Node
    {
        T elem;
        Node *left;
        Node *right;
    };

    Node *root;
    LESS c;

  public:
    Tree() : root{nullptr}{}

    void add(const T &n)
    {
        add(root, n);
    }

    void print() const
    {
        print(root);
    }

    const T& operator[](const T& e) const
    {
        return find(root, e);
    }

    ~Tree()
    {
        release(root);
    }

  private:
    void add(Node* &node, const T &n)
    {
        if (node == nullptr)
        {
            node = new Node{n, nullptr, nullptr};
            return;
        }

        bool less = c.is_less(n, node->elem);
        if (less)
            add(node->left, n);
        else
            add(node->right, n);
    }

    void print(Node *node) const
    {   
        if (node == nullptr) {
            return;
        }
        print(node->left);
        cout << node->elem << "\n";
        print(node->right);
    }

    void release(Node* node)
    {

        if (node == nullptr)
            return;
        

        release(node->left);
        release(node->right);
        delete node;
    }

    const T& find(const Node *node, const T& e) const
    {
        if (node ==  nullptr)
            throw "Not found";
        
        bool less = c.is_less(e, node->elem);
        if (less)
            return find(node->left, e);
        if (c.is_less(node->elem, e))
            return find(node->right, e);
        
        return node->elem;
    }
    
};

int main(int argc, char const *argv[])
{
    Tree<int> p;
    p.add(14);
    p.add(50);
    p.add(25);
    p.add(15);
   
    Tree<string> s;

    s.add("hola"s);
    s.add("mundo"s);
    s.add("berr"s);
    
    

    p.print();
    s.print();

    auto &q = s["beer"];

    cout << q << "\n";

    return 0;
}
