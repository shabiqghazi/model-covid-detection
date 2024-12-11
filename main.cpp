#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#include <wspiapi.h>
#else
#include <unistd.h>  // untuk Linux/Unix
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
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
