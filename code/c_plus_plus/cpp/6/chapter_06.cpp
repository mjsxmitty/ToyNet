

#include <istream>
#include <ostream>
#include <fstream>
#include "chapter_06.h"

using namespace std;

namespace chapter_06
{

bool FileCopy(const char *in_file_name, const char *out_file_name)
{
    char buff[1024] = {0};
    ifstream in_file;
    ofstream out_file;

    in_file.open(in_file_name);
    out_file.open(out_file_name);

    in_file.seekg(0, ios::end);
    int file_len = in_file.tellg();
    in_file.seekg(0, ios::beg);
    in_file.read(buff, file_len);

    out_file << buff;

    in_file.close();
    out_file.close();

    return true;
}


}
