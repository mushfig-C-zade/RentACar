#pragma once

#include <string>

class Customer
{
	int id = 0;
	int carId = 0;
	std::string fullname;
	std::string rentDate;

public:

	void SetId(int id);

	int GetId();

	void SetCarId(int id);

	int GetCarId();

	void Info();

	Customer(const std::string& fullname, const std::string& rentDate, int carId);

	void SetFullname(std::string fullname);

	void SetRentDate(std::string rentDate);

	std::string GetFullname();

	std::string GetRentDate();

};


void WriteAppendForCustomer(std::string path, Customer* customer);

void WriteForCustomer(std::string path, Customer** customers, int length);

void ExtendCustomerArray(Customer**& customers, int length);

Customer** ReadForCustomer(std::string path, int& size);

Customer* SearchByCustomer(Customer** customers, int length, std::string search);

void removeCustomer(Customer**& customers, int& size, int id);

void showCustomers(Customer** customers, int size);



