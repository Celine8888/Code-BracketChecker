#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes
#include "DSList.h"

// you can run the test using Run CTest in the task bar or by running the tests executable.

TEST_CASE("Testing DSList", "[DSList]")
{
    SECTION("Testing default constructor", "[DSList()]")
    {
        DSList<int> dummyList;
        REQUIRE(dummyList.size() == 0);
    }
    SECTION("Testing push back function", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.push_back(1);
        dummyList.push_back(2);
        dummyList.push_back(3);
        dummyList.push_back(4);
        REQUIRE(dummyList.size() == 4);
        REQUIRE(dummyList.empty() == false);
        REQUIRE(dummyList.find(1) == 0);
        REQUIRE(dummyList.find(2) == 1);
        REQUIRE(dummyList.find(3) == 2);
        REQUIRE(dummyList.find(4) == 3);
    }
    SECTION("Testing copy constructor", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.push_back(1);
        dummyList.push_back(2);
        dummyList.push_back(3);
        dummyList.push_back(4);
        DSList<int> newList(dummyList);
        REQUIRE(newList.size() == 4);
        REQUIRE(newList.empty() == false);
        REQUIRE(newList.find(1) == 0);
        REQUIRE(newList.find(2) == 1);
        REQUIRE(newList.find(3) == 2);
        REQUIRE(newList.find(4) == 3);
    }
    SECTION("Testing copy assignment constructor", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.push_back(1);
        dummyList.push_back(2);
        dummyList.push_back(3);
        dummyList.push_back(4);
        DSList<int> newList = dummyList;
        REQUIRE(newList.size() == 4);
        REQUIRE(newList.empty() == false);
        REQUIRE(newList.find(1) == 0);
        REQUIRE(newList.find(2) == 1);
        REQUIRE(newList.find(3) == 2);
        REQUIRE(newList.find(4) == 3);
        dummyList = dummyList;
    }
    SECTION("Testing clear function", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.clear();
        REQUIRE(dummyList.size() == 0);
        dummyList.push_back(1);
        dummyList.push_back(2);
        dummyList.push_back(3);
        dummyList.push_back(4);
        REQUIRE(dummyList.size() == 4);
        dummyList.clear();
        REQUIRE(dummyList.size() == 0);
    }
    SECTION("Testing push front function", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.push_front(2);
        REQUIRE(dummyList.find(2) == 0);
    }
    SECTION("Testing extreme pop back function", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.pop_back();
        REQUIRE(dummyList.size() == 0);
    }
    SECTION("Testing extreme pop front function", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.pop_front();
        REQUIRE(dummyList.size() == 0);
    }
    SECTION("Testing find function", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.push_back(2);
        REQUIRE(dummyList.size() == 1);
        REQUIRE(dummyList.find(1) == -1);
    }
    SECTION("Testing top function", "[DSList()]")
    {
        DSList<int> dummyList;
        dummyList.push_front(2);
        dummyList.push_front(1);
        REQUIRE(dummyList.top() == 1);
    }
}

/*
TEST_CASE represents a class, SECTION represents a function
*/