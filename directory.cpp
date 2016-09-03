#include <vector>
using std::vector;

#include <string>
using std::string;

#include <cstdlib>
#include <dirent.h>
#include <sys/types.h>

#include "directory.h"
#include "utils.h"


vector<string> Directory::open(string dirPath)
{
  vector<string> dirs;

  DIR *dir;
  struct dirent *entity;

  if ((dir = opendir(dirPath.c_str())) == NULL) {
    logError("directory not found");
  }

  while ((entity = readdir(dir)) != NULL)
  {
    if (entity->d_type == DT_DIR)
    {
      dirs.push_back(string(entity->d_name));
    }
  }

  closedir(dir);
  return dirs;
}

string Directory::find(string currentDirPath, string targetDir)
{
  vector<string> dirs = open(currentDirPath);

  for (int i = 0; i < dirs.size(); i++)
  {
    if (dirs.at(i) == targetDir)
    {
      return currentDirPath + "/" + targetDir;
    }
  }

  return "NEVER FOUND";
}

