#include "database.h"

void Database::CreateTable(sqlite3* db)
{
	string sql = "CREATE TABLE FoodReg ( ID INTEGER PRIMARY KEY AUTOINCREMENT, FoodName VARCHAR (50) NOT NULL, FoodPrice NUMERIC (10) NOT NULL";

	char* errorMSG;

	if (sqlite3_exec(db, sql.c_str(), nullptr, 0, &errorMSG) != SQLITE_OK)
	{
		cout << "Error Creating table! " << errorMSG << endl;
		sqlite3_free(errorMSG);
	}
}

void Database::InsertIntoDb(sqlite3* db, string FoodName, const int FoodPrice)
{
	string sql = "INSERT INTO FoodReg ( FoodName, FoodPrice ) VALUES ( ? , ? )";

	sqlite3_stmt* stmt;

	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
	{
		sqlite3_bind_text(stmt, 1, FoodName.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(stmt, 2, FoodPrice);

		if (sqlite3_step(stmt) != SQLITE_DONE)
		{
			cout << "Error Inserting User: " << sqlite3_errmsg(db) << endl;
		}
		else
		{
			cout << "Inserting user success!" << endl;
		}
	}
	else
	{
		cout << "Error Perparing statement: ", sqlite3_errmsg(db);

		sqlite3_finalize(stmt);
	}
}

void Database::ShowMenu(sqlite3* db)
{
	string sql = "SELECT * FROM FoodReg";

	sqlite3_stmt* stmt;

	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
	{
		while (sqlite3_step(stmt) == SQLITE_ROW)
		{
			int id = sqlite3_column_int(stmt, 0);
			const char* FoodName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
			int FoodPrice = sqlite3_column_int(stmt, 2);
			cout << "ID: " << id + "\nFoodName: " << FoodName << "\nFoodPrice: " << FoodPrice << endl;
		}
	}
	else
	{
		cout << "Error perparing statement: " << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(stmt);
}