#ifndef PROJETOTESTE_MESSAGE_H
#define PROJETOTESTE_MESSAGE_H
#include "date.h"
#include "time.h"
#include <string>
#include <ctime>

struct Message
{
    std::string content;
    Date date;
    Time time;
};

#endif //PROJETO_TESTE_MESSAGE_H
