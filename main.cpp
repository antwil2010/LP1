#include "app.h"
#include <ctime>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[])
{
    App App("diary.md");
    return App.run(argc, argv);
}

