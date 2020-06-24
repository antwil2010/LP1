#ifndef PROJETOTESTE_DATE_H
#define PROJETOTESTE_DATE_H
#include <string>
#include <ctime>

struct Date
{
    unsigned year;
    unsigned month;
    unsigned day;

    void set_from_string(const std::string& date);
};

#endif //PROJETO_TESTE_DATE_H
