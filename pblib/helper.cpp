#include "helper.h"

#include <iostream>

using namespace std;
using namespace PBLib;

uint64_t RandomCounter::callCount = 0;

int RandomCounter::rand() {
  callCount++;
  return std::rand();
}
