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
			cout << "Некорректный ввод, попробуйте еще раз" << endl;
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
			cout << "Вы действительно хотите выйти? (Yes|No)" << endl;
			string s;
			cin >> s;
			while (s != "Yes" && s != "No")
			{
				cout << "Некорректный ввод, попробуйте снова." << endl;
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
	cout << "Выберите одну из операций:" << endl
		<< "1. Вывести дерево на экран" << endl
		<< "2. Вывести список узлов дерева" << endl
		<< "3. Добавить узел в дерево" << endl
		<< "4. Удалить узел из дерева" << endl
		<< "5. Сохранить дерево в файл" << endl
		<< "6. Загрузить дерево из файла" << endl
		<< "7. Проверить наличие узла" << endl
		<< "8. Завершить работу программы" << endl;
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
		cout << "Дерево пусто" << endl;
		return;
	}
	tree.print_pine();
}

void Item2(Tree & tree)
{
	if (tree.empty())
	{
		cout << "Дерево пусто" << endl;
		return;
	}
	char op;
	cout << "a. Прямой обход" << endl
		<< "b. Поперечный обход" << endl
		<< "c. Обратный обход" << endl;
	while (!(cin >> op) || op != 'a' && op != 'b'&&op != 'c')
	{
		cout << "Некорректный ввод, попробуйте еще раз" << endl;
		cout << "a. Прямой обход" << endl
			<< "b. Попереный обход" << endl
			<< "c. Обратный обход" << endl;
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
	cout << "Введите значение узла: ";
	int value;
	while (!(cin >> value))
	{
		cout << "Некорректный ввод, попробуйте снова." << endl;
		ClearBuffer();
	}
	if (!tree.insert(value))
		cout << "Узел уже существует." << endl;
}

void Item4(Tree & tree)
{
	cout << "Введите значение узла: ";
	int value;
	while (!(cin >> value))
	{
		cout << "Некорректный ввод, попробуйте снова." << endl;
		ClearBuffer();
	}
	if (tree.remove(value))
		cout << "Узел удален." << endl;
	else
		cout << "Узел не найден." << endl;
}

void Item5(Tree & tree)
{
	string path;
	cout << "Введите путь к файлу: " << endl;
	while (!(cin >> path))
	{
		cout << "Некорректный ввод, попробуйте снова." << endl;
		ClearBuffer();
	}
	if (tree.save(path))
		cout << "Дерево было успешно сохранено." << endl;
	else
		cout << "Файл с заданным путем не существует." << endl;
}

void Item6(Tree & tree)
{
	string path;
	cout << "Введите путь к файлу: " << endl;
	while (!(cin >> path))
	{
		cout << "Некорректный ввод, попробуйте снова." << endl;
		ClearBuffer();
	}
	if (tree.load(path))
		cout << "Дерево было успешно загружено." << endl;
	else
		cout << "Файл с заданным путем не существует." << endl;
}

void Item7(Tree & tree)
{
	cout << "Введите значение узла: ";
	int value;
	while (!(cin >> value))
	{
		cout << "Некорректный ввод, попробуйте снова." << endl;
		ClearBuffer();
	}
	if (tree.exists(value))
		cout << "Узел найден." << endl;
	else
		cout << "Узел не найден." << endl;
}