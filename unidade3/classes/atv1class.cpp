#include <iostream>


struct Contato{
    std::string nome;
    std::string telefone;
    std::string email;
    
    //construtores
    public : 
    Contato(std::string nome = " ", std::string telefone = " ", std::string email = " "): 
    nome(nome), email(email),telefone(telefone){};

    Contato(Contato &c1): nome(c1.nome), telefone(c1.telefone), email(c1.email){}
};

class ListaContatos{
    int qtdContatos = 0;
    Contato listaCtt[100];

    public:
    //construtores
    ListaContatos(int a = 0):qtdContatos(a){
        if(a > 100){
            qtdContatos = a;
        }}

    //getters
    int consultaQuantidade(){
        return qtdContatos;
    }

    //operações
    bool adicionarContato(Contato const &c1){
        if(qtdContatos < 100){
            listaCtt[qtdContatos] = c1;
            qtdContatos++;
            return true;
            }
        return false;
    }
    
    bool removerContato(std::string nome){
        for(int i = 0; i < qtdContatos; i++){
            if(nome == listaCtt[i].nome){
              listaCtt[i] = listaCtt[qtdContatos - 1];
              qtdContatos--;
              return true;   
            }
        }
        return false;
    }

    bool buscarContato(std:: string nome, Contato & c1){
        for(int i = 0; i < qtdContatos; i++){
            if(nome == listaCtt[i].nome){
                c1.nome = listaCtt[i].nome;
                c1.telefone = listaCtt[i].telefone;
                c1.email = listaCtt[i].email;
                    return true;
                }
        }
        return false;
    }
        
};