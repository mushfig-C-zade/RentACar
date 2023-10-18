#include "Customer.h"
#include <fstream>
#include <iostream>


void Customer::SetFullname(std::string fullname)
{
	if (!fullname.empty())
		this->fullname = fullname;
}

void Customer::SetRentDate(std::string rentDate)
{
	if (!rentDate.empty())
		this->rentDate = rentDate;
}

std::string Customer::GetFullname() { return this->fullname; }

std::string Customer::GetRentDate() { return this->rentDate; }

Customer::Customer(const std::string& fullname, const std::string& rentDate, int carId)
{
	this->SetFullname(fullname);
	this->SetRentDate(rentDate);
	this->SetCarId(carId);
}

void WriteAppendForCustomer(std::string path, Customer* customer)
{
	std::ofstream fout(path, std::ios_base::app);

	if (fout.is_open())
	{
		fout << customer->GetFullname() << '\r';
		fout << customer->GetRentDate() << '\r';
		fout << customer->GetCarId() << '\r';
	}
}

void WriteForCustomer(std::string path, Customer** customers, int length)
{
	std::ofstream fout(path);

	if (fout.is_open())
	{
		for (size_t i = 0; i < length; i++)
		{
			fout << customers[i]->GetFullname() << '\r';
			fout << customers[i]->GetRentDate() << '\r';
			fout << customers[i]->GetCarId() << '\r';
		}
	}
}


void ExtendCustomerArray(Customer**& customers, int length)
{
	Customer** tmp = new Customer * [length + 1];

	for (size_t i = 0; i < length; i++)
	{
		tmp[i] = customers[i];
	}

	if (!length)
		delete[]customers;

	customers = tmp;

	tmp = 0;
}

Customer** ReadForCustomer(std::string path, int& size)
{
	std::ifstream fin(path);

	Customer** customers = 0;

	size = 0;

	int id;
	std::string fullname;
	std::string rentDate;
	int carId;

	if (fin.is_open())
	{
		Customer** customers = 0;

		if (fin.peek() == fin.eof()) return 0;

		while (fin.peek() + 1 == fin.eof())
		{
			fin >> id;
			fin >> fullname;
			fin >> rentDate;
			fin >> carId;

			Customer* customer = new Customer(fullname, rentDate, carId);

			customer->SetId(id);

			ExtendCustomerArray(customers, size);

			size++;

			customers[size - 1] = customer;
		}

	}
	return customers;

}

Customer* SearchByCustomer(Customer** customers, int length, std::string search)
{
	for (size_t i = 0; i < length; i++)
	{
		if (customers[i]->GetFullname() == search)
		{
			return customers[i];
		}
	}

	return 0;
}


void Customer::Info() {

	std::cout << "Full-Namei: " << fullname << "\t";
	std::cout << "RentDatei: " << rentDate << "\t";

}

void Customer::SetId(int id)
{
	this->id = id;
}

int Customer::GetId()
{
	return this->id;
}

void Customer::SetCarId(int id)
{
	this->carId = id;
}

int Customer::GetCarId()
{
	return this->carId;
}



void removeCustomer(Customer**& customers, int& size, int id)
{
	Customer** tmp = new Customer * [--size];

	for (size_t i = 0, k = 0; i < size + 1; i++)
	{
		if (customers[i]->GetId() != id)
		{
			tmp[k++] = customers[i];
		}
	}

	delete[]customers;
	customers = tmp;
	tmp = 0;
}

void showCustomers(Customer** customers, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		customers[i]->Info();
	}
}