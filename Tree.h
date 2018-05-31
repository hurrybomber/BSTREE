#include <initializer_list>
#include <string>
#include <iostream>


struct Node
{
	int data;
	Node* left;
	Node* right;
	Node() = delete;
	Node(int data_) : Node{ data_, nullptr, nullptr } {}
	Node(int data_, Node*left_, Node* right_) : data{ data_ }, left{ left_ }, right{ right_ } {}
};

enum class traversal_order { pre, in, post };

class Tree
{
private:
	Node * root;
	
	void clean(Node* &);
	void direct_print(Node *);
	void reverse_print(Node *);
	void symmetric_print(Node *);
	void pine(Node * cur, int plane, int top);
	void find(Node * cur, int val, bool & res);
public:

	Tree();
	Tree(std::initializer_list<int> list);
	Tree(const Tree& tree);

	bool insert(int value);
	bool exists(int value);
	bool remove(int value);
	bool save(const std::string & path);
	bool load(const std::string & path);
	void print(traversal_order order);
	void swap(Tree & other);

	auto friend operator<<(std::ostream & stream, const Tree &) -> std::ostream &;
	auto operator=(const Tree & ) -> Tree &;

	~Tree();

	bool empty();
	void print_pine();
};