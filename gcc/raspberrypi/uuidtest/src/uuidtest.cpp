//============================================================================
// Name        : uuidtest.cpp
// Author      : Thomas Schroedter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <uuid/uuid.h>
#include <iostream>
#include "InMemoryBus/Subscribtions/SubscribtionManager.h"

int main(int argc, char *argv[])
{
  InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity entity{};

  uuid_t id;
  uuid_generate(id);

  char *string = new char[100];
  uuid_unparse(id, string);

  int result = uuid_parse(string, id);
  std::cout << result << std::endl;

  uuid_t other;
  uuid_copy(other, id);

  std::cout << string << std::endl;
  bool compare = uuid_compare(id, other) == 0;

  std::cout << compare << std::endl;

  return 0;
}
