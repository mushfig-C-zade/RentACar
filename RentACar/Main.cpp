#include <iostream>
#include <fstream>
#include "Car.h"
#include "Customer.h"
#include<conio.h>

using namespace std;




int main()
{
	size_t carId = 0, customerId = 0;

	std::string carPath = "cars.txt";
	std::string customerPath = "customer.txt";

	int customerSize = 0, carSize = 0;

	Customer** customers = 0;
	Car** cars = 0;

	char menu[5]{ '>',' ',' ',' ',' ' };
	int menuStep = 0;
	int ch = 0;

	cars = ReadForCar(carPath, carSize);
	customers = ReadForCustomer(customerPath, customerSize);

	if (carId > 0)
	{
		carId = cars[carSize - 1]->GetId();
	}

	if (customerId > 0)
	{
		customerId = customers[customerSize - 1]->GetId();
	}

	do
	{
		system("cls");

		if (ch == 224)
		{
			ch = _getch();
			if (ch == 72)
			{
				if (menuStep - 1 >= 0)
				{
					swap(menu[menuStep], menu[menuStep - 1]);
					menuStep--;
				}
			}

			else if (ch == 80)
			{
				if (menuStep + 1 <= 4)
				{
					swap(menu[menuStep], menu[menuStep + 1]);
					menuStep++;
				}
			}
		}

		if (ch == 13 && menu[0] == '>')
		{
			system("cls");
			char menu1[6]{ '>',' ',' ',' ',' ',' ' };
			int menuStep1 = 0;
			int ch1 = 0;

			do
			{
				system("cls");

				if (ch1 == 224)
				{
					ch1 = _getch();
					if (ch1 == 72)
					{
						if (menuStep1 - 1 >= 0)
						{
							swap(menu1[menuStep1], menu1[menuStep1 - 1]);
							menuStep1--;
						}
					}

					else if (ch1 == 80)
					{
						if (menuStep1 + 1 <= 5)
						{
							swap(menu1[menuStep1], menu1[menuStep1 + 1]);
							menuStep1++;
						}
					}
				}

				if (ch1 == 13 && menu1[0] == '>')
				{
					string marka;
					system("cls");
					cout << "Axtarmaq istediyiniz markani yazin" << "\n";
					cin >> marka;
					auto result = SearchByVendor(cars, carSize, marka);
					result->Info();
					break;
				}
				else if (ch1 == 13 && menu1[1] == '>')
				{
					string color;
					system("cls");
					cout << "Axtarmaq istediyiniz coloru yazin" << "\n";
					cin >> color;
					auto result = SearchByColor(cars, carSize, color);
					result->Info();
					break;

				}
				else if (ch1 == 13 && menu1[2] == '>')
				{
					string number;
					system("cls");
					cout << "Axtarmaq istediyiniz numberi yazin" << "\n";
					cin >> number;
					auto result = SearchByNumber(cars, carSize, number);
					result->Info();
					break;
				}
				else if (ch1 == 13 && menu1[3] == '>')
				{
					string year;
					system("cls");
					cout << "Axtarmaq istediyiniz ili yazin" << "\n";
					cin >> year;
					auto result = SearchByYear(cars, carSize, year);
					result->Info();
					break;
				}
				else if (ch1 == 13 && menu1[4] == '>')
				{
					string fullName;
					system("cls");
					cout << "Axtarmaq istediyiniz Musterini yazin" << "\n";
					cin >> fullName;
					auto result = SearchByCustomer(customers, customerSize, fullName);
					result->Info();
					break;
				}
				else if (ch1 == 13 && menu1[5] == '>')
				{
					system("cls");
					double min;
					cout << "Minimum qiymeti yazin: ";
					cin >> min;
					double max;
					cout << "Maxsimum qiymeti yazin: ";
					cin >> max;
					auto result = SearchByPriceDiapazone(cars, carSize, max, min);
					result->Info();
					break;
				}

				cout << menu1[0] << "Marka" << "\n";
				cout << menu1[1] << "Reng" << "\n";
				cout << menu1[2] << "Nomre" << "\n";
				cout << menu1[3] << "Buraxilis ili" << "\n";
				cout << menu1[4] << "Aliciya gore" << "\n";
				cout << menu1[5] << "Qiymet diapazonuna gore" << "\n";

			} while (ch1 = _getch());
			cout << "\n";
			system("pause");
			break;
		}
		else if (ch == 13 && menu[1] == '>')
		{
			system("cls");
			char menu2[3]{ '>',' ',' ' };
			int menuStep2 = 0;
			int ch2 = 0;

			do
			{
				system("cls");

				if (ch2 == 224)
				{
					ch2 = _getch();
					if (ch2 == 72)
					{
						if (menuStep2 - 1 >= 0)
						{
							swap(menu2[menuStep2], menu2[menuStep2 - 1]);
							menuStep2--;
						}
					}

					else if (ch2 == 80)
					{
						if (menuStep2 + 1 <= 2)
						{
							swap(menu2[menuStep2], menu2[menuStep2 + 1]);
							menuStep2++;
						}
					}
				}

				if (ch2 == 13 && menu2[0] == '>')
				{
					string model;
					string vendor;
					string color;
					string year;
					double perDayPrice;
					string number;
					cout << "Model daxil edin: ";
					cin >> model;
					cout << "Vendor daxil edin: ";
					cin >> vendor;
					cout << "Color daxil edin: ";
					cin >> color;
					cout << "Year daxil edin: ";
					cin >> year;
					cout << "Per Day Price daxil edin: ";
					cin >> perDayPrice;
					cout << "Number daxil edin: ";
					cin >> number;

					Car* car = new Car(model, vendor, color, year, perDayPrice, number);

					car->SetId(++carId);

					ExtendCarArray(cars, carSize);

					cars[carSize - 1] = car;

					WriteAppendForCar(carPath, car);

				}
				else if (ch2 == 13 && menu2[1] == '>')
				{
					string fullname;
					string rentDate;
					int carId;

					cin.clear();
					cin.ignore();
					cout << "FullName daxil edin: ";
					getline(cin, fullname);
					cout << "RentDate-i daxil edin: ";
					getline(cin, rentDate);
					cout << "CarId: ";
					cin >> carId;

					Customer* customer = new Customer(fullname, rentDate, carId);

					WriteAppendForCustomer(customerPath, customer);

				}
				else if (ch2 == 13 && menu2[2] == '>')
				{
					break;
				}

				cout << menu2[0] << "Teze avto" << "\n";
				cout << menu2[1] << "Teze alici(muqavile)" << "\n";
				cout << menu2[2] << "Back" << "\n";

			} while (ch2 = _getch());


		}
		else if (ch == 13 && menu[2] == '>')
		{
			system("cls");
			char menu3[3]{ '>',' ',' ' };
			int menuStep3 = 0;
			int ch3 = 0;

			do
			{
				system("cls");

				if (ch3 == 224)
				{
					ch3 = _getch();
					if (ch3 == 72)
					{
						if (menuStep3 - 1 >= 0)
						{
							swap(menu3[menuStep3], menu3[menuStep3 - 1]);
							menuStep3--;
						}
					}

					else if (ch3 == 80)
					{
						if (menuStep3 + 1 <= 2)
						{
							swap(menu3[menuStep3], menu3[menuStep3 + 1]);
							menuStep3++;
						}
					}
				}

				if (ch3 == 13 && menu3[0] == '>')
				{
					system("cls");
					int id;
					cout << "Id ni daxil edin";
					cin >> id;
					removeCar(cars, carSize, id);
					WriteForCars(carPath, cars, carSize);
					break;
				}
				else if (ch3 == 13 && menu3[1] == '>')
				{
					system("cls");
					int id;
					cout << "Id ni daxil edin";
					cin >> id;
					removeCustomer(customers, customerSize, id);
					WriteForCustomer(customerPath, customers, customerSize);
					break;
				}
				else if (ch3 == 13 && menu3[2] == '>')
				{
					system("cls");
					cout << "Bu islemir";
					break;

				}
				cout << menu3[0] << "Avto" << "\n";
				cout << menu3[1] << "Muqavile" << "\n";
				cout << menu3[2] << "Muqavile" << "\n";


			} while (ch3 = _getch());
			cout << "\n";
			system("pause");
			break;
		}
		else if (ch == 13 && menu[3] == '>')
		{
			system("cls");
			cout << "1";
			break;
		}
		else if (ch == 13 && menu[4] == '>')
		{
			system("cls");
			cout << "Customerler"<<"\n";
			showCustomers(customers, customerSize);
			cout << "Carlar";
			showCars(cars, carSize);			
			break;
		}

		cout << "Rent a Car-a xos gelmisiniz" << "\n";
		cout << "Zehmet olmasa seciminizi qeyd ederdiz" << "\n" << "\n" << "\n";
		cout << menu[0] << "Informasiya axtarisi" << "\n";
		cout << menu[1] << "Melumatin elave edilmesi" << "\n";
		cout << menu[2] << "Melumatin silinmesi" << "\n";
		cout << menu[3] << "Musterinin borcu" << "\n";
		cout << menu[4] << "Butun melumatlari goster" << "\n";

	} while (ch = _getch());
	cout << "\n";
	system("pause");




}