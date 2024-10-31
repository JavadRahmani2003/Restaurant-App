#pragma once

#include "AllHeaders.h"

namespace Database
{
	void CreateTable(sqlite3* db);
	void InsertIntoDb(sqlite3* db, std::string FoodName, const int FoodPrice);
	void ShowMenu(sqlite3* db);
};
//void EditFrmDb();

//void DeleteFrmDb();
