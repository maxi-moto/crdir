#ifndef Directory_h
#define Directory_h

class Directory
{
  public:
    vector<string> open(string dirPath);
    string find(vector<string> currentLevelDirs, string targetDir);

  private:
};

#endif
