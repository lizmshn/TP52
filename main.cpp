#include <iostream>
#include <string>
using namespace std;

class Price
{
	string product;
	string shop;
	int price;
	int size;
	Price** array;
public:
	~Price() { cout << "Destructor" << endl; delete array; };
	Price(int a)
	{
		string text;
		getline(cin, text);
		Setter_product(text);
		cout << "shop: ";
		getline(cin, text);
		Setter_shop(text);
		cout << "price: ";
		getline(cin, text);
		Setter_price(stoi(text));
	}
	Price()
	{
		price = 0;
	}
	Price(const Price& object)
	{
		
		this->array = new Price * [object.size];
		
		for (int i = 0; i < object.size; i++)
		{
			array[i] = object.array[i];
		}
	}
	void Setter_product(string product) { this->product = product; };
	void Setter_shop(string shop) { this->shop = shop; };
	void Setter_price(int price) { this->price = price; };
	void Setter_size(int size) { this->size = size; };

	string Getter_product() {return product;}
	string Getter_shop() { return shop; };
	int Getter_price() { return price; };
	int Getter_size() { return size; };

	void Show_products()
	{
		string text;
		getline(cin, text);

		for (int i = 0; i < Getter_size(); i++)
		{
			if (text == array[i]->Getter_shop())
			{
				cout << i + 1<<endl;
				array[i]->Show();
			}
		}
	}
	void Show()
	{
		cout << "product: " << Getter_product() << endl;
		cout << "shop: " << Getter_shop() << endl << "price: " << Getter_price() << endl;
	}
	void Show_all()
	{
		for (int i = 0; i < Getter_size(); i++)
		{
			cout << i + 1 << endl;
			cout << "Show all-Show" << endl;
			array[i]->Show();
		}
	}
	Price operator +(int number)
	{
		Price buffer(*this);
		Setter_size(Getter_size() + 1);
		array = new Price * [Getter_size()];
		cout << "First object" << endl << "product: ";
		
		for (int i = 0; i < Getter_size()-1; i++)
		{
			array[i] = buffer.array[i];
		}
		array[Getter_size() - 1] = new Price(1);

		return *this;

	}
	Price operator -(int number)
	{
		Price buffer(*this);
		Setter_size(Getter_size() - 1);
		array = new Price * [Getter_size()];
		for (int i = 0; i < number - 1; i++)
		{
			array[i] = buffer.array[i];
		}
		for (int i = number - 1; i < Getter_size(); i++)
		{
			array[i] = buffer.array[i + 1];
		}

		return *this;

	}

};
int main()
{
	string text;
	Price object;
	getline(cin, text);

	if (stoi(text) == 1)
	{
		object + 1;
	}
	getline(cin, text);
	if (stoi(text) == 1)
	{
		object + 1;
	}
	getline(cin, text);
	if (stoi(text) == 1)
	{
		object + 1;
	}

	getline(cin, text);
	if (stoi(text) == 2)
	{
		object.Show_all();
	}

	getline(cin, text);
	if (stoi(text) == 3)
	{
		object.Show_products();
	}
	//getline(cin, text);
	//if (stoi(text) == 3)
	//{
	//	cout << "VV num" << endl;
	//	getline(cin, text);
	//	object - (stoi(text));
	//}
	//getline(cin, text);
	//if (stoi(text) == 2)
	//{
	//	object.Show_all();
	//}

	return 0;
}