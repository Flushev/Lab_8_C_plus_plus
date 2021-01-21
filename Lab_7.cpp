// Lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

#include <cstdlib>

#include <stdio.h>

#include<malloc.h>

#include<string.h>

#include "locale.h"

#include "windows.h"

#pragma warning(disable:4996)



#define LEN 20
#define st_art "_Арт_"
#define st_type "_Вид_"
#define st_name "_Бренд_"
#define st_season "__Сезон__"
#define st_price = 0;
#define pr 0.24


using namespace std;

class shoes
{
public:
	shoes()
	{
		name = st_name;
		type = st_type;
		art = st_art;
		price = 0;
	}

	shoes(string name, string type, string art, double price)
	{
		// 	Работа с исключениями
		if (price < 0) throw 1;
		else
		{
			this->name = name;
			this->type = type;
			this->art = art;
			this->price = price;
		}
	}

	shoes(char* s, double price)
	{
		int k = strlen(s) + 1;
		season = new char[k];
		strcpy(season, s);
		if (price < 0) 
			throw 1;
		else
			this->price = price;
	}

	shoes(shoes& s)
	{
		season = new char[20];
		strcpy (this->season, s.season);
		this->price = s.price;
	}



	shoes(double price)
	{
		name = st_name;
		type = st_type;
		art = st_art;
		if (price < 0) 
			throw 1;
		else
			this->price = price;
	}

	void set_season(char* s)
	{
		strcpy(season, s);
	}

	void set_name(string name)
	{
		this->name = name;
	}

	void set_type(char type[LEN])
	{
		this->type = type;
	}

	void set_art(char art[LEN])
	{
		this->art =  art;
	}

	void set_price(double price)
	{
		this->price = price;
	}

	string get_name()
	{
		cout << "Название бренда: " << name << endl;
	}

	string get_type()
	{
		cout << "Вид обуви: " << type << endl;
	}

	char get_art()
	{
		cout << "Артикул: " << art << endl;
	}

	double get_price()
	{
		return this->price;
	}

	void read()
	{
		
		int f = 0;
		double temp;
		cout << "Введите бренд\n";
		rewind(stdin); cin >> name;
		cout << "Введите вид обуви\n";
		rewind(stdin); cin >> type;
		cout << "Введите артикул\n";
		rewind(stdin); cin >> art;
		// Работа с исключениями
		while (f == 0)
		{
			cout << "Введите стоимость\n";
			cin >> temp;
			try
			{
				if (temp > 0)
				{
					f = 1;
					price = temp;
				}
				else
				{
					throw 2;
				}
			}
			catch (int a)
			{
				cout << "Ошибка ввода! Цена не может быть отрицательной!" << endl;
				f = 0;
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}


	void display()
	{

		cout << "Бренд: " << name << endl;
		cout << "Вид обуви: " << type << endl;
		cout << "Артикул: " << art << endl;
		cout << "Стоимость: " << price << endl;
		cout << "" << endl;
	}

	void display_copy()
	{
		cout << "Сезон:" << season << endl;
		cout << "Стоимость: " << price << endl;
		cout << "" << endl;
	}


	friend double add(double sum, shoes* x);



private:
	string name;
	string type;
	string art;
	double price;
	char* season;



};

double add(double sum, shoes* x)
{
	sum += (*x).price;
	cout << "Общая стоимость товаров:" << sum << endl;
	return sum;
}


class store
{
public:


	store()
	{
		kol = 0;
		profit = 0;
		sale_count = 0;
		*para = new shoes();
	}
	store(int kol, double profit, int sale_count, shoes* para[LEN])
	{
		this->kol = kol;
		this->profit = profit;
		this->sale_count = sale_count;
		for (int i = 0; i < kol; i++)
		{
			this->para[i] = para[i];
		}
	}



	store(int kol, double profit, int sale_count, shoes* para)
	{
		this->kol = kol;
		this->profit = profit;
		this->sale_count = sale_count;
		for (int i = 0; i < kol; i++)
		{
			this->para[i] = para;
		}
	}
	// Конструктор для склада обуви
	store(int box, int k_box, shoes para[10][LEN])
	{
		this->kol = box * k_box;
		this->box = box;
		this->k_box = k_box;
		for (int i = 0; i < box; i++) // Формирует количество коробок
		{
			for (int j = 0; j < k_box; j++) // Формирует количество пар в каждой коробке
			{
				this->para_1[i][j] = para[i][j];
			}
		}
	}
	//Конструтор для коробки с обувью
	store(int box, shoes para[LEN])
	{
		this->kol = box;
		this->box = box;
		for (int i = 0; i < box; i++) // Формирует Количество пар в коробке
			this->para_2[i] = para[i];
	}
	shoes* get_shoes(store st)
	{
		return *para;
	}

	int get_kol()
	{
		return kol;
	}

	void set_kol(int kol)
	{
		this->kol = kol;
	}

	double get_profit()
	{
		return profit;
	}

	void set_profit(double profit)
	{
		this->profit = profit;
	}
	int get_sale()
	{
		return sale_count;
	}

	void set_sale(int sale_count)
	{
		this->sale_count = sale_count;
	}

	void read()
	{
		cout << "Количество пар: " << kol << endl;
		cout << "Выручка: " << profit << endl;
		cout << "Количество продаж: " << sale_count << endl;
	}


	void display()
	{
		cout << "Количество пар: " << kol << endl;
		cout << "Выручка: " << profit << endl;
		cout << "Количество продаж: " << sale_count << endl;
		for (int i = 0; i < kol; i++)
		{
			para[i]->display();
		}
	}


	void sale()
	{
		for (int i = 0; i < kol; i++)
		{
			profit += para[i]->get_price();
			sale_count++;
			kol -= 1;
		}
		cout << "\nПродажа прошла успешно\n";
	}

	void back()
	{
		for (int i = 0; i < 1; i++)
		{
			profit -= para[i]->get_price();
			sale_count--;
			kol += 1;
		}
		cout << "\nВозврат прошел успешно\n";
	}


	void tax(double* taxa)
	{
		*taxa = profit * pr;
		cout << "Налог на прибыль составит:" << *taxa << endl;
		return;
	}

	store& operator++ ()
	{
		this->sale_count++;
		return *this;
	}

	store operator++ (int)
	{
		store tmp = *this;
		++ *this;
		return tmp;
	}
	
	static int rent(int kol)
	{
		static int stavka = 300;
		int renta = 0;
		if (kol < 2)
			stavka += 20;
		else stavka -= 20;
		renta = kol * stavka;
		return renta;
	}

	double cost_sklad()
	{
		double cost = 0;
		for (int i = 0; i < box; i++)
			for (int j = 0; j < k_box; j++)
				cost += para_1[i][j].get_price();
		return cost;
	}

	double cost_box()
	{
		double cost = 0;
		for (int i = 0; i < box; i++)
			cost += para_2[i].get_price();
		return cost;
	}

	void display_sklad()
	{
		cout << "Количество коробок на складе " << k_box << endl;
		cout << "Количество пар в коробке " << box << endl;
		cout << "Общее количесво пар на складе " << kol << endl;
		cout << "Общая стоимость товаров на складе " << cost_sklad() << endl;
		for (int i = 0; i < box; i++)
		{
			for (int j = 0; j < k_box; j++)
				para_1[i][j].display();
			cout << "\n" << endl;
		}
		
	}

	void display_box()
	{
		cout << "Количество пар в коробке " << box << endl;
		cout << "Общая стоимость товаров в коробке " << cost_box() << endl;
		for (int i = 0; i < box; i++)
			para_2[i].display();
	}

private:
	int kol;
	double profit;
	int sale_count;
	int box;
	int k_box;
	shoes* para[LEN];
	shoes para_1 [10][LEN];
	shoes para_2[LEN];

};


int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int kol = 1;
	string standart_name = "__Бренд__";
	string standart_type = "__Вид__";
	string standart_art = "__Арт__";
	int renta = 0;
	double taxa = 0;

	// Инициализация массива через конструктор с одним параметром
	cout << "Инициализация массива через конструктор с одним параметром\n" << endl;
	shoes para_tmp[2] = { 1000,2000, };
	for (int i = 0; i < 2; i++)
	{
		para_tmp[i].display();
		cout << "\n" << endl;
	}

	int box = 0;
	int k_box = 0;

	// Двойной массив объектов
	shoes p[10][LEN];
	cout << "Введите количество коробок на складе" << endl;
	cin >> box;
	cout << "Введите количество пар в коробке" << endl;
	cin >> k_box;
	for (int i = 0; i < box; i++)
		for (int j = 0; j < k_box; j++)
		{
			p[i][j].read();
		}
	store sklad(box, k_box, p);
	sklad.display_sklad();

	// Одномерный массив объектов
	shoes p1[LEN];
	cout << "Введите количество пар в коробке" << endl;
	cin >> box;
	for (int i = 0; i < box; i++)
		p1[i].read();
	store box1(box, p1);
	box1.display_box();
	
	//Глубокое копирование
	cout << "Глубокое копирование:" << endl;
	char* season;
	season = new char[20];
	strcpy(season, "Зима");
	shoes s (season, 2000);
	shoes s1 = s;
	cout << "\nПосле копирования\n" << endl;
	s.display_copy();
	s1.display_copy();
	strcpy(season, "Лето");
	s.set_season(season);
	cout << "После изменения первого объекта\n" << endl;
	s.set_price(5000);
	s.display_copy();
	s1.display_copy();


	cout << "\n Основная программа:\n" << endl;
	// Констркутор без параметров (динамический объект)
	shoes* para1 = new shoes();

	para1->read();

	// Констркутор со всеми параметрами (статический объект)
	store st(kol, 0, 0, para1);
	
	cout << "Работа со статическими переменными\n" << endl;
	cout << "\nПосле ввода\n" << endl;
	st.display();

	// Статический метод
	st.sale();
	cout << "\nПосле продажи\n" << endl;
	st.display();
	st.tax(&taxa);
	st.back();
	cout << "\nПосле возврата\n" << endl;
	st.display();
	sum = add(sum, para1);
	kol = st.get_kol();
	renta = store::rent(st.get_kol());
	cout << "Налог на обувь: \n" << renta << endl;



	cout << "\n-------------------------------------------------\n" << endl;
	cout << "\nРабота с динамическим объектом класса\n" << endl;
	shoes* para2 = new shoes();
	para2->read();

	//Конструтор со всеми параметрами (динамический объект)
	store* st2 = new store(kol, 0, 0, para2);
	
	cout << "\nПосле ввода\n" << endl;
	st2->display();
	st2->sale();
	cout << "\nПосле продажи\n" << endl;
	st2->display();
	st2->back();
	cout << "\nПосле возврата\n" << endl;
	st2->display();
	renta = store::rent(st2->get_kol());
	cout << "Налог на обувь: \n" << renta << endl;
	sum = add(sum, para2);


	renta = 0;
	cout << "\n-------------------------------------------------\n" << endl;
	cout << "\nРабота с массивом\n" << endl;
	shoes para3[LEN];
	cout << "\nВведите количество позиций\n" << endl;
	cin >> kol;
	for (int i = 0; i < kol; i++)
	{

		para3[i].read();
		sum = add(sum, &para3[i]);
	}
	store* st3 = new store(kol, 0, 0, para3);


	renta = store::rent(st3->get_kol());
	cout << "\nПосле ввода\n" << endl;
	st3->display();
	st3->sale();
	cout << "\nПосле продажи\n" << endl;
	st3->display();
	st3->back();
	cout << "\nПосле возврата\n" << endl;
	st3->display();
	
	cout << "Налог на обувь: \n" << renta << endl;
	delete st3;
	cout << "\n-------------------------------------------------\n" << endl;
	return 0;
}