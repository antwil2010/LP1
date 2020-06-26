#ifndef PROJETOTESTE_TIME_H
#define PROJETOTESTE_TIME_H
#include <string>
#include <ctime>

struct Time
{
    Time();
    unsigned hour;
    unsigned minute;
    unsigned second;

    void set_from_string(const std::string& time);
    std::string hour_to_string();
};

#endif //PROJETO_TESTE_TIME_H
