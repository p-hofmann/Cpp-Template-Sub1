/**
 * Created by Peter Hofmann on 07.01.19.
 */

#define CATCH_CONFIG_MAIN  // Tells Catch to provide a main()

#include <string>
#include "catch.hpp"
#include "Cpp-Template-Sub1/cpptemplatesub1.h"

using namespace SubModule1;

/*!
 * Testing default getClassName()
 */
TEST_CASE("Test getClassName", "[DummySub1]")
{
    DummySub1 module;
    REQUIRE(module.getClassName() == "DummySub1");
}

/*!
 * Testing setDummyValue getDummyValue
 */
TEST_CASE("Test setDummyValue", "[DummySub1]")
{
    DummySub1 module;
    std::string testValue = "test";
    CHECK(module.getClassName() == "DummySub1");
    module.setDummyValue(testValue);
    REQUIRE(testValue == module.getDummyValue());
}
