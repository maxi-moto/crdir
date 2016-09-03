#ifndef Utils_h
#define Utils_h

#include <iostream>
using std::cout;
using std::endl;

static void logError(const string message) {
  cout << "[ERROR]:" << message << endl;
  exit(0);
}

#endif
