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

string Directory::find(vector<string> currentLevelDirs, string targetDir)
{
  vector<string> nextLevelDirs;
  string currentDirLevel;
  string currentDir;

  for (int i = 0; i < currentLevelDirs.size(); i++)
  {
    currentDirLevel = currentLevelDirs.at(i);
    vector<string> dirs = open(currentDirLevel);

    for (int j = 0; j < dirs.size(); j++)
    {
      currentDir = dirs.at(j);
      if (currentDir == "." || currentDir == "..") continue;

      if (currentDir == targetDir)
      {
        return currentDirLevel + "/" + targetDir;
      }
      else
      {
        nextLevelDirs.push_back(currentDirLevel + "/" + currentDir);
      }
    }
  }

  return find(nextLevelDirs, targetDir);
}
