#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstdlib>

#include "directory.h"

#define $HOME getenv("HOME")

void printUsage();

int main(int argc, const char *argv[])
{
  if (argc < 3)
  {
    printUsage();
  }

  string targetDir = argv[1];
  string newDir = argv[2];

  Directory directory;
  vector<string> homePathVec (1, $HOME);
  string path = directory.find(homePathVec, targetDir);
  cout << "[PATH]: " << path + newDir << endl;
  directory.make(path, newDir);
}

void printUsage()
{
  cout << "usage: crdir <base-name> <new-name>" << endl;
  exit(0);
}

