#pragma once

#include "itemDB.h"

ItemDB::ItemDB()
	: itemList{}
{
	createItems();
}

ItemDB::~ItemDB()
{
	itemList.clear();
}

void ItemDB::createItems()
{
	Item01 item01{};
	itemList.push_back(item01);
}