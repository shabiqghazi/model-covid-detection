#include <iostream>
#include <string>
#include <windows.h>
#include <wspiapi.h>
//#include "input.h"
#include "native-lib-pc.h"

using namespace std;
int native_lib_main(std::string& name, std::string filename);

int main(int argc, char *argv[])
{
    std::string report;

    native_lib_main(report, argv[1]);
    cout << report << endl;

    return 0;
}
