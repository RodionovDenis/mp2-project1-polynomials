#include "tables.h"
#include <gtest.h>
#include "TableLinear.cpp"
#include "TableList.cpp"
#include "TableHash.cpp"

//линейная таблица на массиве

TEST(Table1, search_is_true )
{
	Table1 t;
	t.Add("123", 123);
	EXPECT_EQ(t.Find(123).key, 123);
}
TEST(Table1, insert_is_true)
{
	Table1 t;
	t.Add("123", 123);
	EXPECT_FALSE(t.IsEmpty());
}
TEST(TLinearArray, delete_is_true)
{
	Table1 t;
	t.Add("123", 123);
	t.Remove(123);
	EXPECT_TRUE(t.IsEmpty());
}
/*
//упорядоченная таблица на массиве

TEST(TOrderedArray, search_is_true)
{

}
TEST(TOrderedArray, insert_is_true)
{

}
TEST(TOrderedArray, delete_is_true)
{

}
*/
//линейная таблица на списке
TEST(ListTable, search_is_true)
{
	ListTable t;
	t.Add(123, "123");
	EXPECT_EQ(t.Find(123)->key, 123);
}
TEST(ListTable, insert_is_true)
{
	ListTable t;
	t.Add(123, "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(ListTable, delete_is_true)
{
	ListTable t;
	t.Add(123, "123");
	t.Delete(123);
	EXPECT_TRUE(t.IsEmpty());
}
/*
//дерево поиска

TEST(TSearchTree, search_is_true)
{

}
TEST(TSearchTree, insert_is_true)
{

}
TEST(TSearchTree, delete_is_true)
{

}
*/
//хэш-таблица

TEST(HashTable, search_is_true)
{
	HashTable t;
	t.Add("123", "123");
	EXPECT_EQ(t.Find("123")->key, "123");
}
TEST(HashTable, insert_is_true)
{
	HashTable t;
	t.Add("123", "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(HashTable, delete_is_true)
{
	HashTable t;
	t.Add("123", "123");
	t.Remove("321");
	EXPECT_FALSE(t.IsEmpty());
}