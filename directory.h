#ifndef Directory_h
#define Directory_h

class Directory
{
  public:
    vector<string> open(string dirPath);
    string find(string currentDir, string targetDir);

  private:
};

#endif
