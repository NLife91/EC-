#pragma once

#include <list> 

#include "item.h"
#include "item01.cpp"
#include "item02.cpp"
#include "item03.cpp"
#include "item04.cpp"
#include "item05.cpp"
#include "item06.cpp"
#include "item07.cpp"
#include "item08.cpp"
#include "item09.cpp"
#include "item10.cpp"
#include "item11.cpp"
#include "item12.cpp"

class ItemDB
{
public:
	ItemDB();
	~ItemDB();

	const size_t GetItemCount()
	{
		return itemList.size();
	}

	const std::list<Item>& GetItemList()
	{
		return itemList;
	}

private:
	void createItems();

private:
	std::list<Item> itemList;
};