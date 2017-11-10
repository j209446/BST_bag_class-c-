#include <iostream>
using namespace std;

template <typename T>
class binary_tree_node
{
public:
	binary_tree_node();
	binary_tree_node<T>(const binary_tree_node& copy);
	binary_tree_node<T>(const T& init_data = T(), binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL);
	void set_data(T& entry);
	void set_left(binary_tree_node* link);
	void set_right(binary_tree_node* link);
	binary_tree_node<T>* get_left();
	binary_tree_node<T>* get_right();
	T& get_data();
	const binary_tree_node<T>* get_left() const;
	const binary_tree_node<T>* get_right() const;
	const T& get_data() const;
	bool is_left();
private:
	T data;
	binary_tree_node* left_node;
	binary_tree_node* right_node;
};

template <typename item>
class bag
{
public:
	bag();
	~bag<item>() { delete ptr; }
	void insert(item& entry);
	void print_ptr();
private:
	binary_tree_node<item>* ptr;
};

int main()
{
	bag<int> one;
	int x=9;
	while (x != 0)
	{
		cin >> x;
		one.insert(x);
		system("cls");
		one.print_ptr();
	}
	
}

template<typename T>
binary_tree_node<T>::binary_tree_node()
{
	data = NULL;
	left_node = NULL;
	right_node = NULL;
}

template<typename T>
binary_tree_node<T>::binary_tree_node(const binary_tree_node & copy)
{
	this = copy;
}

template<typename T>
void binary_tree_node<T>::set_data(T& entry)
{
	data = entry;
}

template<typename T>
void binary_tree_node<T>::set_left(binary_tree_node * link)
{
	left_node = link;
}

template<typename T>
void binary_tree_node<T>::set_right(binary_tree_node * link)
{
	right_node = link;
}

		template<typename T>
binary_tree_node<T>* binary_tree_node<T>::get_left()
{
	return left_node;
}

template<typename T>
binary_tree_node<T>* binary_tree_node<T>::get_right()
{
	return right_node;
}

template<typename T>
T& binary_tree_node<T>::get_data()
{
	return data;
}

template<typename T>
const binary_tree_node<T>* binary_tree_node<T>::get_left() const
{
	return left_node;
}

template<typename T>
const binary_tree_node<T>* binary_tree_node<T>::get_right() const
{
	return right_node;
}

template<typename T>
const T& binary_tree_node<T>::get_data() const
{
	return data;
}

template<typename T>
bool binary_tree_node<T>::is_left()
{
	return (left_node==NULL&&right_node==NULL);
}

template<typename item>
bag<item>::bag()
{
	ptr = nullptr;
}

template<typename item>
void bag<item>::insert(item & entry)
{
	if (ptr->get_data() == NULL)
	{
		ptr->set_data(entry);
	}
	else {
		binary_tree_node<item>* node = ptr;
		while (1) {
			if (node->get_data() < entry)
			{
				if (node->get_right() == NULL)
					node->set_right(new binary_tree_node<item>);
				if (node->get_data() == NULL)
				{
					node->set_data(entry);
					break;
				}
				else
					node = node->get_right();

			}
			else if (node->get_data() > entry)
			{
				if (node->get_left() == NULL)
					node->set_left(new binary_tree_node<item>);
				if (node->get_data() == NULL)
				{
					node->set_data(entry);
					break;
				}
				else
					node = node->get_left();
			}
			else
			{
				cout << "Exist equal node" << endl;
				return;
			}
		}
	}
}

template<typename item>
void bag<item>::print_ptr()
{
	print_BST(ptr);
}

template<typename item>
void print_BST(binary_tree_node<item>* BST)
{
	if (BST != NULL)
	{
		cout << BST->get_data() << endl;
		print_BST(BST->get_left());
		print_BST(BST->get_right());
	}
}

template<typename T>
binary_tree_node<T>::binary_tree_node(const T& init_data, binary_tree_node * init_left, binary_tree_node * init_right)
{
	data = init_data;
	left_node = init_left;
	right_node = init_right;
}
