#include "diary.h"
#include "diahora.h"
#include "date.h"
#include "message.h"
#include <sstream>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>

Diary::Diary(const std::string& name) : filename(name), messages (nullptr), messages_size(0),  messages_capacity(10)
{
    //Verifica a quantidade de linhas com mensagens do arquivo para gerar um array com a quantidade ideal
    std::ifstream filename;
    std::string verifica;
    filename.open("diary.md");
    if(!filename.is_open()){
        std::cout << "Erro ao abrir arquivo!" << std::endl;
        return;
    }
    while(!filename.eof()){
            std::getline(filename, verifica);
            if(verifica[0] == '#'){
                continue;
            }
            if(verifica.size() == 0){
                continue;
            }
            messages_size++;
    }
    std::cout << "Quantidade de mensagens salvas no programa: " << messages_size << std::endl;
    messages = new Message[messages_size];
    filename.close();
    //Verifica as datas ou mensagens de cada linha e armazena o conteúdo no array gerado anteriormente
    //Note: A quantidade de datas pode no mínimo ser igual a quantidade de mensagens já que para cada mensagem existe 1 data, seja ela igual ou diferente
    //logo sempre a quantidade alocada no array será igual ou maior que a quantidade de datas, e se for igual ao adicionar mensagem ela aumenta o tamanho do array, não entrando em conflito
    std::ifstream filename2;
    std::string verifica2;
    filename2.open("diary.md");
    int contador2 = 0;
    int contador3 = 0;
    char discard;
    while(!filename2.eof()){
            std::getline(filename2, verifica2);
            if(verifica2[0] == '#'){
                std::string Data = verifica2;
                std::stringstream stream(Data);
                stream >> discard;
                stream >> messages[contador3].date.day;
                stream >> discard;
                stream >> messages[contador3].date.month;
                stream >> discard;
                stream >> messages[contador3].date.year;
                contador3++;
                continue;
            } else if(verifica2.size() == 0){
                continue;
            } else if(verifica2[0] == '-'){
                std::stringstream stream(verifica2);
                for(size_t i=0;i<9;i++){
                    stream >> discard;
                }
                std::getline(stream, messages[contador2].content);
                contador2++;
            } else{
                std::cout << "Erro ao ler linha do arquivo, formato desconhecido" << std::endl;
            }
    }
}
Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if(messages_size >= messages_capacity){
        novoarray();
    }
    Message m;
	m.content = message;
	m.date.set_from_string(get_current_date());
	m.time.set_from_string(get_current_time());
	messages[messages_size] = m;
	messages_size++;
}

void Diary::write(const std::string& message)
{
    std::ifstream filename;
    std::ofstream filename2;
    std::string verifica;
    filename.open("diary.md");
    std::string data = "# ";
    data += get_current_date();
    int existe = 0;
    while(!filename.eof()){
            std::getline(filename, verifica);
            if(verifica == data){
              existe = 1;
              continue;
            }
    }
    filename.close();
    filename2.open("diary.md", std::ios::app);
    if(existe != 1){
            filename2 << "\n" << "# " << messages[messages_size-1].date.to_string() << "\n" <<std::endl;
    }
    filename2 << "- " << messages[messages_size-1].time.to_string() << " " << messages[messages_size-1].content << std::endl;
    std::cout << "Mensagem: " << messages[messages_size-1].content << " Adicionada" << std::endl;
    filename2.close();
    // gravar as mensagens no disco
}

std::vector<Message*> Diary::search(const std::string& acha) {
  std::vector<Message*> procura;

  for (size_t i = 0; i < messages_size; ++i) {
    if (messages[i].content.find(acha) != std::string::npos) {
      procura.push_back(&messages[i]);
    }
  }

  return procura;
}

