#include "Tree.h"
#include <iostream>
#include <fstream>

Tree::Tree(): root{nullptr} {
}

Tree::Tree(std::initializer_list<int> list) : Tree{}
{	
	for (auto it : list) this->insert(it);
}

void copy(Tree * root, Node * cur)
{
	if (cur == nullptr) return;
	root->insert(cur->data);
	if (cur->left != nullptr) copy(root, cur->left);
	if (cur->right != nullptr) copy(root, cur->right);
}

Tree::Tree(const Tree & tree) : Tree{}
{
	copy(this, tree.root);
}

void Tree::clean(Node*& cur)
{
	if (cur == nullptr) return;
	clean(cur->left);
	clean(cur->right);
	delete cur;
	cur = nullptr;
}

auto Tree::operator=(const Tree & tree) -> Tree &
{
	Tree{ tree }.swap(*this);
	return *this;
}

Tree::~Tree()
{
	clean(root);
}

bool Tree::empty()
{
	return root==nullptr;
}

bool Tree::insert(int value)
{
	if (root == nullptr)
	{
		root = new Node(value);
		return true;
	}
	Node*cur = root;
	while (true)
	{
		if (cur->data == value) return false;
		if (cur->data < value)
		{
			if (cur->right == nullptr)
			{
				Node*temp = new Node(value);
				cur->right = temp;
				return true;
			}
			else
				cur = cur->right;
		}
		else
		{
			if (cur->left == nullptr)
			{
				Node*temp = new Node(value);
				cur->left = temp;
				return true;
			}
			else
				cur = cur->left;
		}
	}
}

bool Tree::exists(int value)
{
	bool res = false;
	find(root, value, res);
	return res;
}

bool Tree::remove(int value)
{
	Node ** q = &root;
	Node *z = root;
	//поиск удаляемого элемента
	while(true)
	{
		if (z == nullptr) 
			return 0;
		else 
			if (value == z->data) break;
				else 
					if (value > z->data)
					{
						q = &z->right;
						z = z->right;
					}
					else
					{
						q = &z->left;
						z = z->left;
					}
	}
	// непосредственное удаление элемента
	if (z->right == nullptr) 
		*q = z->left;
	else
	{
		Node * y = z->right;
		if (y->left == nullptr)
		{
			y->left = z->left;
		}
		else
		{
			Node * x = y->left;
			while (x->left != nullptr)
			{
				y = x;
				x = y->left;
			}
			y->left = x->right;
			x->left = z->left;
			x->right = z->right;
			*q = x;
		}
	}

	delete z;
	return 1;
}  //???

void dfs(Node* cur, std::ostream & stream)
{
	if (cur != nullptr) {
		stream << cur->data << " ";
		dfs(cur->left, stream);
		dfs(cur->right, stream);
	}
	else return;
}

bool Tree::save(const std::string & path)
{
	std::ofstream fout(path);
	dfs(root, fout);
	return true;
}

bool Tree::load(const std::string & path)
{
	std::ifstream fin(path);
	if (fin) 
	{
		Tree tree;
		int val;
		fin >> val;
		while (fin) 
		{
			tree.insert(val);
			fin >> val;
		}
		this->swap(tree);
		return true;
	}
	else 
		return false;
}

void Tree::print(traversal_order order)
{
	switch (order)
	{
	case traversal_order::pre: direct_print(root); break;
	case traversal_order::in: symmetric_print(root); break;
	case traversal_order::post: reverse_print(root); break;
	}
	std::cout << std::endl;
}

void Tree::swap(Tree & other)
{
	std::swap(root, other.root);
}

void Tree::direct_print(Node* node)
{
	if (node == nullptr) return;
	std::cout << node->data << ' ';
	direct_print(node->left);
	direct_print(node->right);
}

void Tree::reverse_print(Node* node)
{
	if (node == nullptr) return;
	reverse_print(node->left);
	reverse_print(node->right);
	std::cout << node->data << ' ';
}

void Tree::symmetric_print(Node* node)
{
	if (node == nullptr) return;
	symmetric_print(node->left);
	std::cout << node->data << ' ';
	symmetric_print(node->right);
}

void Tree::print_pine()
{
	pine(root, 0, root->data);
}

void Tree::pine(Node * cur, int plane, int top)
{
	if (cur == nullptr) return;

	if (cur->right != nullptr)
		pine(cur->right, plane + 1, top);

	for (int i = 0; i < plane; i++) std::cout << "   ";
	if (cur->data == top)
		std::cout << cur->data << std::endl;
	else
		std::cout << "--" << cur->data << std::endl;

	if (cur->left != nullptr)
		pine(cur->left, plane + 1, top);
}

void Tree::find(Node * cur, int val, bool & res)
{
	if (cur == nullptr) return;
	if (cur->data == val) res = true;
	if (!res)  find(cur->left, val, res);
	if (!res) find(cur->right, val, res);
}

auto operator<<(std::ostream & stream, const Tree & tree) -> std::ostream &
{
	Node* cur = tree.root;
	dfs(cur, stream);
	return stream;
}
