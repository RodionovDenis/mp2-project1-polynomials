#include <gtest.h>
#include "tables.h"
#include "LinearArray.cpp"
#include "TableList.cpp"
#include "HashTable1.cpp"
#include "polynomials.h"

//линейная таблица на массиве

TEST(LinearArray, can_create)
{
	ASSERT_NO_THROW(LinearArray t);
}
TEST(LinearArray, search_is_true )
{
	LinearArray t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_EQ(t.Find("123")->key, "123");
}

TEST(LinearArray, insert_is_true)
{
	LinearArray t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(LinearArray, delete_is_true)
{
	LinearArray t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	t.Remove("123");
	EXPECT_TRUE(t.IsEmpty());
}

//упорядоченная таблица на массиве
TEST(OrderedArray, can_create)
{
	ASSERT_NO_THROW(OrderedArray t);
}
TEST(OrderedArray, search_is_true )
{
	OrderedArray t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_EQ(t.Find("123")->key, "123");
}

TEST(OrderedArray, insert_is_true)
{
	OrderedArray t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(OrderedArray, delete_is_true)
{
	OrderedArray t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	t.Remove("123");
	EXPECT_TRUE(t.IsEmpty());
}

//линейная таблица на списке
TEST(ListTable, can_create)
{
	ASSERT_NO_THROW(ListTable t);
}
TEST(ListTable, search_is_true)
{
	ListTable t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_EQ(t.Find("123")->key, "123");
}
TEST(ListTable, insert_is_true)
{
	ListTable t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(ListTable, delete_is_true)
{
	ListTable t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	t.Remove("123");
	EXPECT_TRUE(t.IsEmpty());
}

//дерево поиска
TEST(SearchTree, can_create)
{
	ASSERT_NO_THROW(SearchTree t);
}
TEST(SearchTree, search_is_true)
{
	SearchTree t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(SearchTree, insert_is_true)
{
	SearchTree t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_EQ(t.Find("123")->key, "123");
}
/*
TEST(SearchTree, delete_is_true)
{
	SearchTree t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	t.Remove("123");
	EXPECT_TRUE(t.IsEmpty());
}
*/
//хэш-таблица "Цепочки"
TEST(HashTable1, can_create)
{
	ASSERT_NO_THROW(HashTable1 t);
}
TEST(HashTable1, insert_is_true)
{
	HashTable1 t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(HashTable1, search_is_true)
{
	HashTable1 t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_EQ(t.Find("123")->key, "123");
}

TEST(HashTable1, delete_is_true)
{
	HashTable1 t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	t.Remove("123");
	EXPECT_TRUE(t.IsEmpty());
}
//хэш-таблица "Открытая адресация"
TEST(HashTable2, can_create)
{
	ASSERT_NO_THROW(HashTable2 t);
}
TEST(HashTable2, insert_is_true)
{
	HashTable2 t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(HashTable2, search_is_true)
{
	HashTable2 t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	EXPECT_EQ(t.Find("123")->key, "123");
}

TEST(HashTable2, delete_is_true)
{
	HashTable2 t;
	Polynom t1("1x1y1z1");
	t.Add(t1, "123");
	t.Remove("123");
	EXPECT_TRUE(t.IsEmpty());
}