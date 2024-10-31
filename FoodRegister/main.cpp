//Main header Connected to File
#include "main.h"

int main()
{
	sqlite3* db;
	if (sqlite3_open("Database.db", &db) != SQLITE_OK)
	{
		Database::CreateTable(db);
	}
	else
	{
		//std::cerr << "Can\'t Error Creating and opening database: " << sqlite3_errmsg(db) << std::endl;
		cout << "Database Opened and loaded Successfully :)\n";
	}

	std::cin.get();

	while (!NotAppClose)
	{
		system("cls");

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 6);

		cout << "~~~~~~~~~~~~~~~~~~~~~~{{| Resturant menu -> Food Section |}}~~~~~~~~~~~~~~~~~~~~~~~~";
		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n\t Tip: to add food and price press (o) and to delete press (d)";
		cout << "\n\t To save into database and give to other parts press (esc) to save and quit";
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\n\n\t\t\t\tMenu: \n";

		Database::ShowMenu(db);


		cout << "Enter a key To Perpare An Action:\n\n";
		switch (_getch())
		{
		case 111: // o (small)
			cout << "Enter your Food name: ";
			cin >> foodname;
			cout << "Enter your Food name: ";
			cin >> foodprice;
			Database::InsertIntoDb(db,foodname,foodprice);
			break;

		case 100: // d (small)
			cout << "U pressed d";
			//DeleteFrmDb();
			break;

		case 27: // esc key
			cout << "U pressed esc" << std::endl;
			NotAppClose = true;
			break;
		}

		//system("pause");
		return 0;
	}
}