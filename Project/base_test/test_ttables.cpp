#include "tables.h"
#include <gtest.h>

//линейная таблица на массиве

TEST(TLinearArray, search_is_true )
{

}
TEST(TLinearArray, insert_is_true)
{

}
TEST(TLinearArray, delete_is_true)
{

}

//упорядоченная таблица на массиве

TEST(TOrderedArray, search_is_true)
{

}
TEST(TOrderedArray, insert_is_true)
{
	TableOrdered t;
	t.Add(123, "123");
	EXPECT_FALSE(t.IsEmpty());
}
TEST(TOrderedArray, delete_is_true)
{

}
//линейная таблица на списке
TEST(TLinearList, search_is_true)
{

}
TEST(TLinearList, insert_is_true)
{

}
TEST(TLinearList, delete_is_true)
{

}

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

//хэш-таблица

TEST(THashTable, search_is_true)
{

}
TEST(THashTable, insert_is_true)
{

}
TEST(THashTable, delete_is_true)
{

}

//хэш-таблица 2

TEST(THashTable, search_is_true)
{

}
TEST(THashTable, insert_is_true)
{

}
TEST(THashTable, delete_is_true)
{

}