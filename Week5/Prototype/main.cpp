#include <iostream>
#include <string>
#include <assert.h>

class Node { // Prototype 
public:
    Node() = default;
    virtual ~Node() = default;
    virtual Node *clone() = 0;
    virtual void print(std::ostream &os) = 0;
};

class One : public Node { // Concrete Prototype 1
public:
    One() = default;
    Node *clone() { return new One(); }
    void print(std::ostream &os) { std::cout << "1"; }
};

class Plus : public Node { // Concrete Prototype 2
    Node *m_left, *m_right;
public:
    Plus(Node *left, Node *right) : m_left(left), m_right(right) { }
    Node *clone() { return new Plus(m_left == nullptr ? nullptr : m_left->clone(), m_right == nullptr ? nullptr : m_right->clone()); }
    void print(std::ostream &os) { m_left->print(os); std::cout << "+"; m_right->print(os); }
};

class Subtract : public Node {
    Node *m_left, *m_right;
public:
    Subtract(Node *left, Node *right) : m_left(left), m_right(right) { }
    Node *clone() { return new Subtract(m_left == nullptr ? nullptr : m_left->clone(), m_right == nullptr ? nullptr : m_right->clone()); }
    void print(std::ostream &os) { m_left->print(os); std::cout << "-"; m_right->print(os); }
};

class Multiply : public Node {
    Node *m_left, *m_right;
public:
    Multiply(Node *left, Node *right) : m_left(left), m_right(right) { }
    Node *clone() { return new Multiply(m_left == nullptr ? nullptr : m_left->clone(), m_right == nullptr ? nullptr : m_right->clone()); }
    void print(std::ostream &os) { m_left->print(os); std::cout << "*"; m_right->print(os); }
};

class Divide : public Node {
    Node *m_left, *m_right;
public:
    Divide(Node *left, Node *right) : m_left(left), m_right(right) { }
    Node *clone() { return new Divide(m_left == nullptr ? nullptr : m_left->clone(), m_right == nullptr ? nullptr : m_right->clone()); }
    void print(std::ostream &os) { m_left->print(os); std::cout << "/"; m_right->print(os); }
};

One protoOne; // prototypical One

              // represent a number as a binary tree
Node *createTree(int x) {
    if (x == 1) { // base case I
        return protoOne.clone(); // inductive case 
    }
    else if (x > 1) {
        return new Plus(createTree(x - 1), protoOne.clone());
    }
    else return nullptr; // base case II
}

int main(int argc, char **argv) {
    assert(argc == 2 && "not enough arguments");
    int num = std::stoi(argv[1]);
    Node *tree = createTree(num);
    if (tree != nullptr) {
        // double number
        tree = new Plus(tree->clone(), tree->clone());
        tree->print(std::cout);
        std::cout << std::endl;
    }
}