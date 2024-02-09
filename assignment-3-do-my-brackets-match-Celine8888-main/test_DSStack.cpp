#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes
#include "DSStack.h"

TEST_CASE("Check that DSStack works", "[DSStack]")
{
    // add test cases (create lists and specify what the expected output is)
    SECTION("Testing default constructor", "[DSStack()]")
    {
        DSStack<int> dummyList;
        REQUIRE(dummyList.getSize() == 0);
        REQUIRE(dummyList.getCapacity() == 1);
    }
    SECTION("Testing push back function", "[DSStack()]")
    {
        DSStack<int> dummyList;
        dummyList.push_back(1);
        dummyList.push_back(2);
        dummyList.push_back(3);
        dummyList.push_back(4);
        REQUIRE(dummyList.getSize() == 4);
        REQUIRE(dummyList.empty() == false);
        REQUIRE(dummyList.find(1) == 0);
        REQUIRE(dummyList.find(2) == 1);
        REQUIRE(dummyList.find(3) == 2);
        REQUIRE(dummyList.find(4) == 3);
    }
    SECTION("Testing copy constructor", "[DSStack()]")
    {
        DSStack<int> dummyList;
        dummyList.push_back(1);
        dummyList.push_back(2);
        dummyList.push_back(3);
        dummyList.push_back(4);
        DSStack<int> newList(dummyList);
        REQUIRE(newList.getSize() == 4);
        REQUIRE(newList.empty() == false);
        REQUIRE(newList.find(1) == 0);
        REQUIRE(newList.find(2) == 1);
        REQUIRE(newList.find(3) == 2);
        REQUIRE(newList.find(4) == 3);
    }
    SECTION("Testing copy assignment constructor", "[DSStack()]")
    {
        DSStack<int> dummyList;
        dummyList.push_back(1);
        dummyList.push_back(2);
        dummyList.push_back(3);
        dummyList.push_back(4);
        DSStack<int> newList = dummyList;
        REQUIRE(newList.getSize() == 4);
        REQUIRE(newList.empty() == false);
        REQUIRE(newList.find(1) == 0);
        REQUIRE(newList.find(2) == 1);
        REQUIRE(newList.find(3) == 2);
        REQUIRE(newList.find(4) == 3);
        dummyList = dummyList;
    }
    SECTION("Testing clear function", "[DSStack()]")
    {
        DSStack<int> dummyList;
        dummyList.clear();
        REQUIRE(dummyList.getSize() == 0);
        dummyList.push_back(1);
        dummyList.push_back(2);
        dummyList.push_back(3);
        dummyList.push_back(4);
        REQUIRE(dummyList.getSize() == 4);
        dummyList.clear();
        REQUIRE(dummyList.getSize() == 0);
    }
    SECTION("Testing push front function", "[DSList()]")
    {
        DSStack<int> dummyList;
        dummyList.push_front(2);
        REQUIRE(dummyList.find(2) == 0);
    }
    SECTION("Testing pop back function", "[DSList()]")
    {
        DSStack<int> dummyList;
        dummyList.pop_back();
        REQUIRE(dummyList.getSize() == 0);
        SECTION("Testing find function", "[DSList()]")
        {
            DSStack<int> dummyList;
            dummyList.push_back(2);
            REQUIRE(dummyList.getSize() == 1);
            REQUIRE(dummyList.find(1) == -1);
        }
    }
}

// you can run the test using Run CTest in the task bar or by running the tests executable.