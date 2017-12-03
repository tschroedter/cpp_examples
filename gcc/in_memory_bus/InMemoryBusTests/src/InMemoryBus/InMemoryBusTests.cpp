//============================================================================
// Name        : InMemoryBusTests.cpp
// Author      : Thomas Schroedter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return (RUN_ALL_TESTS());
}
