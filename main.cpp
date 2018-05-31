#include "Tree.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[]);

void PrintMenu();
void Init(Tree* &, int, char* []);
void ClearBuffer();

void Item1(Tree & tree);
void Item2(Tree & tree);
void Item3(Tree & tree);
void Item4(Tree & tree);
void Item5(Tree & tree);
void Item6(Tree & tree);
void Item7(Tree & tree);

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "rus");
	Tree * tree = new Tree();
	Init(tree, argc, argv);
	do
	{
		PrintMenu();
		int op;
		while (!(cin >> op) || op<1 || op>8)
		{
			ClearBuffer();
			cout << "������������ ����, ���������� ��� ���" << endl;
		}
		switch (op)
		{
		case 1: Item1(*tree); break;
		case 2:	Item2(*tree); break;
		case 3: Item3(*tree); break;
		case 4: Item4(*tree); break;
		case 5: Item5(*tree); break;
		case 6: Item6(*tree); break;
		case 7: Item7(*tree); break;
		case 8:
		{
			cout << "�� ������������� ������ �����? (Yes|No)" << endl;
			string s;
			cin >> s;
			while (s != "Yes" && s != "No")
			{
				cout << "������������ ����, ���������� �����." << endl;
				ClearBuffer();
				cin >> s;
			}
			if (s == "Yes") return 0;
		}
		}
	} while (true);
}

void PrintMenu()
{
	cout << "�������� ���� �� ��������:" << endl
		<< "1. ������� ������ �� �����" << endl
		<< "2. ������� ������ ����� ������" << endl
		<< "3. �������� ���� � ������" << endl
		<< "4. ������� ���� �� ������" << endl
		<< "5. ��������� ������ � ����" << endl
		<< "6. ��������� ������ �� �����" << endl
		<< "7. ��������� ������� ����" << endl
		<< "8. ��������� ������ ���������" << endl;
}

void Init(Tree* & tree, int argc, char * argv[])
{
	if (argc == 1)
		return;
	for (int i = 1; i < argc; i++)
		tree->insert(atoi(argv[i]));
}

void ClearBuffer()
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}

void Item1(Tree & tree)
{
	if (tree.empty())
	{
		cout << "������ �����" << endl;
		return;
	}
	tree.print_pine();
}

void Item2(Tree & tree)
{
	if (tree.empty())
	{
		cout << "������ �����" << endl;
		return;
	}
	char op;
	cout << "a. ������ �����" << endl
		<< "b. ���������� �����" << endl
		<< "c. �������� �����" << endl;
	while (!(cin >> op) || op != 'a' && op != 'b'&&op != 'c')
	{
		cout << "������������ ����, ���������� ��� ���" << endl;
		cout << "a. ������ �����" << endl
			<< "b. ��������� �����" << endl
			<< "c. �������� �����" << endl;
		ClearBuffer();
	}
	switch (op)
	{
	case 'a': tree.print(traversal_order::pre); break;
	case 'b': tree.print(traversal_order::in); break;
	case 'c': tree.print(traversal_order::post); break;
	}
}

void Item3(Tree & tree)
{
	cout << "������� �������� ����: ";
	int value;
	while (!(cin >> value))
	{
		cout << "������������ ����, ���������� �����." << endl;
		ClearBuffer();
	}
	if (!tree.insert(value))
		cout << "���� ��� ����������." << endl;
}

void Item4(Tree & tree)
{
	cout << "������� �������� ����: ";
	int value;
	while (!(cin >> value))
	{
		cout << "������������ ����, ���������� �����." << endl;
		ClearBuffer();
	}
	if (tree.remove(value))
		cout << "���� ������." << endl;
	else
		cout << "���� �� ������." << endl;
}

void Item5(Tree & tree)
{
	string path;
	cout << "������� ���� � �����: " << endl;
	while (!(cin >> path))
	{
		cout << "������������ ����, ���������� �����." << endl;
		ClearBuffer();
	}
	if (tree.save(path))
		cout << "������ ���� ������� ���������." << endl;
	else
		cout << "���� � �������� ����� �� ����������." << endl;
}

void Item6(Tree & tree)
{
	string path;
	cout << "������� ���� � �����: " << endl;
	while (!(cin >> path))
	{
		cout << "������������ ����, ���������� �����." << endl;
		ClearBuffer();
	}
	if (tree.load(path))
		cout << "������ ���� ������� ���������." << endl;
	else
		cout << "���� � �������� ����� �� ����������." << endl;
}

void Item7(Tree & tree)
{
	cout << "������� �������� ����: ";
	int value;
	while (!(cin >> value))
	{
		cout << "������������ ����, ���������� �����." << endl;
		ClearBuffer();
	}
	if (tree.exists(value))
		cout << "���� ������." << endl;
	else
		cout << "���� �� ������." << endl;
}