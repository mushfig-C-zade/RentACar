#pragma once

#include <string>


class Car
{
	int id;
	std::string model;
	std::string vendor;
	std::string color;
	std::string year;	
	double perDayPrice;
	std::string number;

public:

	Car() = default;

	Car(const std::string& model, const std::string& vendor, const std::string& color, const std::string& year, double perDayPrice, const std::string&number);

	void Info();

	void SetId(int id) 
	{
		this->id = id;
	}

	int GetId() { return this->id; }

	void SetModel(std::string model);

	void SetVendor(std::string vendor);

	void SetColor(std::string color);

	void SetYear(std::string year);

	void SetPerDayPrice(double perDayPrice);
	
	void SetNumber(std::string number);

	std::string GetModel();

	std::string GetVendor();

	std::string GetColor();

	std::string GetYear();	

	double GetPerDayPrice();

	std::string GetNumber();

};

void WriteAppendForCar(std::string path, Car* car);

void WriteForCars(std::string path, Car** cars, int length);

void ExtendCarArray(Car**& cars, int length);

Car** ReadForCar(std::string path, int& size);

Car* SearchByVendor(Car** cars, int length, std::string search);

Car* SearchByColor(Car** cars, int length, std::string search);

Car* SearchByNumber(Car** cars, int length, std::string search);

Car* SearchByYear(Car** cars, int length, std::string search);

Car* SearchByPriceDiapazone(Car** cars, int length, double max, double min);

void removeCar(Car**& cars, int& size, int id);

void showCars(Car** cars, int size);




