
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/OrgChart.hpp"
#include "doctest.h"
#include <string>

using namespace ariel;
using namespace std;

TEST_CASE("Good Input")
{

    OrgChart organization;
    organization.add_root("CEO");

    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
    CHECK(organization.getroot()=="CEO");
}

TEST_CASE("Bad Input")
{
    OrgChart organization1;
    organization1.add_root("CEO");

    CHECK_THROWS(organization1.add_sub("NO", "CTO"));
    CHECK_THROWS(organization1.add_sub("NO", "CT]"));
    CHECK_THROWS(organization1.add_sub("NO", "CTO"));
    CHECK_THROWS(organization1.add_sub("NO", "CTjO"));
    CHECK_THROWS(organization1.add_sub("NO", "CTO"));
    CHECK_THROWS(organization1.add_sub("NO", "CTjO"));
    CHECK_THROWS(organization1.add_sub("NO", "CTO"));
    CHECK_THROWS(organization1.add_sub("NO", "CjTO"));
    CHECK_THROWS(organization1.add_sub("NO", "CTO"));
    CHECK_THROWS(organization1.add_sub("NO", "CoTO"));
}
