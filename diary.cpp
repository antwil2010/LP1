#include "diary.h"
#include "diahora.h"
#include <ctime>
#include <fstream>
#include <iostream>

Diary::Diary(const std::string& name) : filename(name), messages (nullptr), messages_size(0),  messages_capacity(10)
{
    messages = new Message[messages_capacity];
}
Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if(messages_size == messages_capacity){
        return;
    }
    Message m;
	m.content = message;
	m.date.set_from_string(get_current_date());
	m.time.set_from_string(get_current_time());
	messages[messages_size] = m;
	messages_size++;

    for (size_t i = 0; i < 10; i++)
    {
        std::cout<<messages[i].content << " " << i+1 <<std::endl;
    }
    //delete[] messages;
    /*for(size_t i = 2; i < argc; i++){
        message += argv[i];
        message += " ";
    }
    // adicionar mensagem no array de mensagens*/
}

void Diary::write(const std::string& message)
{
    /*int existe = 0;
    //std::string data = "# ";

    std::string hora;
    hora = get_current_time();

    //data += get_current_date();

    filename << "- " << hora << " " << message << std::endl;
    std::cout << "Mensagem: " << message << " Adicionada" << std::endl;*/
    // gravar as mensagens no disco
}

