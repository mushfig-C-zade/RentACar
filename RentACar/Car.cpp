#include "Car.h"
#include <fstream>
#include <iostream>

void Car::SetModel(std::string model)
{
	if (!model.empty())
		this->model = model;
}

void Car::SetVendor(std::string vendor)
{
	if (!vendor.empty())
		this->vendor = vendor;
}

void Car::SetColor(std::string color)
{
	if (!color.empty())
		this->color = color;
}

void Car::SetYear(std::string year)
{
	if (!year.empty())
		this->year = year;
}

void Car::SetPerDayPrice(double perDayPrice)
{
	if (perDayPrice > 0)
		this->perDayPrice = perDayPrice;
}

void Car::SetNumber(std::string number)
{
	if (!number.empty())
		this->number = number;
}


std::string Car::GetModel() { return this->model; }

std::string Car::GetVendor() { return this->vendor; }

std::string Car::GetColor() { return this->color; }

std::string Car::GetYear() { return this->year; }

double Car::GetPerDayPrice() { return this->perDayPrice; }

std::string Car::GetNumber() { return this->number; }

Car::Car(const std::string& model, const std::string& vendor, const std::string& color, const std::string& year, double perDayPrice, const std::string& number)
{
	this->SetModel(model);
	this->SetVendor(vendor);
	this->SetColor(color);
	this->SetYear(year);
	this->SetPerDayPrice(perDayPrice);
	this->SetNumber(number);
}

void Car::Info() {
	std::cout << "Id: " << id << '\t';
	std::cout << "Modeli: " << model << "\t";
	std::cout << "Vendoru: " << vendor << "\t";
	std::cout << "Coloru: " << color << "\t";
	std::cout << "Yeari: " << year << "\t";
	std::cout << "Perdayi: " << perDayPrice << "\t";
}

void WriteAppendForCar(std::string path, Car* car)
{
	std::ofstream fout(path, std::ios_base::app);

	if (fout.is_open())
	{
		fout << car->GetId() << '\r';
		fout << car->GetVendor() << '\r';
		fout << car->GetModel() << '\r';
		fout << car->GetColor() << '\r';
		fout << car->GetYear() << '\r';
		fout << car->GetPerDayPrice() << '\r';
	}
}

void WriteForCars(std::string path, Car** cars, int length)
{
	std::ofstream fout(path);

	if (fout.is_open())
	{
		for (size_t i = 0; i < length; i++)
		{
			fout << cars[i]->GetId() << '\r';
			fout << cars[i]->GetVendor() << '\r';
			fout << cars[i]->GetModel() << '\r';
			fout << cars[i]->GetColor() << '\r';
			fout << cars[i]->GetYear() << '\r';
			fout << cars[i]->GetPerDayPrice() << '\r';
		}
	}


}

void ExtendCarArray(Car**& cars, int length)
{
	Car** tmp = new Car * [length + 1];

	for (size_t i = 0; i < length; i++)
	{
		tmp[i] = cars[i];
	}
	if (!length)
		delete[]cars;
	cars = tmp;
	tmp = 0;
}

Car** ReadForCar(std::string path, int& size)
{
	std::ifstream fin(path);

	Car** cars = 0;

	size = 0;

	int id;
	std::string model;
	std::string vendor;
	std::string color;
	std::string year;
	double perDayPrice;
	std::string number;

	if (fin.is_open())
	{
		Car* car = 0;

		if (fin.peek() == fin.eof()) return 0;

		while (fin.peek() + 1 == fin.eof())
		{
			fin >> id;
			fin >> vendor;
			fin >> model;
			fin >> color;
			fin >> year;
			fin >> perDayPrice;
			fin >> number;


			car = new Car(model, vendor, color, year, perDayPrice, number);

			car->SetId(id);

			ExtendCarArray(cars, size);

			size++;

			cars[size - 1] = car;
		}

	}
	return cars;

}

Car* SearchByVendor(Car** cars, int length, std::string search)
{
	for (size_t i = 0; i < length; i++)
	{
		if (cars[i]->GetVendor() == search)
		{
			return cars[i];
		}
	}

	return 0;
}

Car* SearchByColor(Car** cars, int length, std::string search)
{
	for (size_t i = 0; i < length; i++)
	{
		if (cars[i]->GetColor() == search)
		{
			return cars[i];
		}
	}

	return 0;
}

Car* SearchByNumber(Car** cars, int length, std::string search)
{
	for (size_t i = 0; i < length; i++)
	{
		if (cars[i]->GetNumber() == search)
		{
			return cars[i];
		}
	}

	return 0;
}

Car* SearchByYear(Car** cars, int length, std::string search)
{
	for (size_t i = 0; i < length; i++)
	{
		if (cars[i]->GetYear() == search)
		{
			return cars[i];
		}
	}

	return 0;
}



Car* SearchByPriceDiapazone(Car** cars, int length, double max, double min)
{

	for (size_t i = 0; i < length; i++)
	{
		if (cars[i]->GetPerDayPrice() >= min && cars[i]->GetPerDayPrice() <= max)
		{
			return cars[i];
		}
	}

	return 0;
}


void removeCar(Car**& cars, int& size, int id)
{
	Car** tmp = new Car * [--size];

	for (size_t i = 0, k = 0; i < size + 1; i++)
	{
		if (cars[i]->GetId() != id)
		{
			tmp[k++] = cars[i];
		}
	}

	delete[]cars;
	cars = tmp;
	tmp = 0;
}

void showCars(Car** cars, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cars[i]->Info();
	}
}