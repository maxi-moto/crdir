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
  string path = directory.find($HOME, targetDir);

  cout << "PATH:" << path << endl;
}

void printUsage()
{
  cout << "usage: crdir <base-name> <new-name>" << endl;
  exit(0);
}

