#ifndef PROJETOTESTE_DIARY_H
#define PROJETOTESTE_DIARY_H
#include "message.h"
#include <string>
#include <ctime>

struct Diary
{
    Diary(const std::string& filename);

    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(std::string& message);
    void write(const std::string& message);
};

#endif //PROJETO_TESTE_DIARY_H
