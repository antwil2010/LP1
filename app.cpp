#include "app.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        std::cout << "Uso ./prog add <mensagem> ou /.prog list ou /.prog search <mensagem>" << std::endl;
        return show_usage();
    }
    std::string action = argv[1];
    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") {
        if(argc == 2){
            search();
        } else {
            search(argv[2]);
        }
    } else {
        return show_usage();
    }
    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write(message);
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

void App::search() {
  std::string acha;
  std::cout << "digite a mensagem para procurar: " << std::endl;
  getline(std::cin, acha);
  search(acha);
}

void App::search(const std::string& acha){
    std::vector<Message*> procura = diary.search(acha);
    if(!procura.empty()){
        std::cout << "encontrou!" << std::endl;
        for(size_t i = 0; i < procura.size(); i++){
            std::cout << procura[i]->content << std::endl;
        }
        return;
    }
    std::cout << "não encontrou!" << std::endl;
};

int App::show_usage()
{
    return 1;
}