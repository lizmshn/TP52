#include "Price.h"

Price::Price(int a)
{
	string text;
	cout << "product: ";
	getline(cin, text);
	Setter_product(text);
	cout << "shop: ";
	getline(cin, text);
	Setter_shop(text);
	cout << "price: ";
	getline(cin, text);
	try
	{
		Setter_price(stoi(text));
	}
	catch (const invalid_argument& ex)
	{
		cout << "You did not enter a number: " << ex.what() << endl;
		Setter_price(0);
	}
	catch (const exception&)
	{
		std::cout << "Something wrong" << std::endl;
	}

}
Price::Price()
{
	price = 0;
	size = 0;
	array = nullptr;
}
Price::Price(const Price& object)
{

	this->array = new Price * [object.size];

	for (int i = 0; i < object.size; i++)
	{
		array[i] = object.array[i];
	}
}
Price::~Price() { delete array; };
void Price::Setter_product(string product) { this->product = product; };
void Price::Setter_shop(string shop) { this->shop = shop; };
void Price::Setter_price(int price) { this->price = price; };
void Price::Setter_size(int size) { this->size = size; };

string Price::Getter_product() { return product; }
string Price::Getter_shop() { return shop; };
int Price::Getter_price() { return price; };
int Price::Getter_size() { return size; };

void Price::Show_products()
{
	cout << "FIND SHOP: ";
	string text;
	getline(cin, text);

	for (int i = 0; i < Getter_size(); i++)
	{
		if (text == array[i]->Getter_shop())
		{
			cout << i + 1 << endl;
			array[i]->Show();
		}
	}
}
void Price::Show()
{
	cout << "product: " << Getter_product() << endl;
	cout << "shop: " << Getter_shop() << endl << "price: " << Getter_price() << endl;
}
void Price::Show_all()
{
	cout << "ALL SHOPS:" << endl;
	for (int i = 0; i < Getter_size(); i++)
	{
		cout << i + 1 << ".";

		array[i]->Show();
	}
}
Price Price::operator +(int number)
{
	Price buffer(*this);
	Setter_size(Getter_size() + 1);
	array = new Price * [Getter_size()];
	for (int i = 0; i < Getter_size() - 1; i++)
	{
		array[i] = buffer.array[i];
	}
	array[Getter_size() - 1] = new Price(1);
	return *this;
}
Price Price::operator -(int number)
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
void Price::Insertion_sort() {
	for (int i = 1; i < Getter_size(); i++)
	{
		Price* temp = array[i];
		string temp_shop = temp->Getter_shop();
		int j = i - 1;

		while (j >= 0 && array[j]->Getter_shop() > temp_shop) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}