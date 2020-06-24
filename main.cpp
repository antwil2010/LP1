#include "app.h"
#include <ctime>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
    std::ofstream filename;
    filename.open("teste.md");
    App app("diary.md");
    return app.run(argc, argv);
}

