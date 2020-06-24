#ifndef PROJETOTESTE_APP_H
#define PROJETOTESTE_APP_H
#include "diary.h"
#include <string>
#include <ctime>

struct App
{
    Diary diary;

    App(const std::string& filename);
    int run(int argc, char* argv[]);
    int show_usage();
    void add();
    void add(std::string message);
    void list_messages();
};

#endif //PROJETO_TESTE_APP_H
