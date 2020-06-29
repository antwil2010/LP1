#ifndef PROJETOTESTE_DIARY_H
#define PROJETOTESTE_DIARY_H
#include "message.h"
#include "diary.h"
#include "diahora.h"
#include "date.h"
#include <sstream>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary();

    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void write(const std::string& message);
    void novoarray(){
        while(messages_size >= messages_capacity){
            messages_capacity = messages_capacity * 2;
        }
        Message* newarray;
        newarray = new Message[messages_size];
        for(size_t i=0; i < messages_size-1;i++){
            newarray[i] = messages[i];
        }
        delete[] messages;
        messages = new Message[messages_capacity];
        for(size_t i=0; i < messages_size;i++){
            messages[i] = newarray[i];
        }
        delete[] newarray;
    }
};


#endif //PROJETO_TESTE_DIARY_H
