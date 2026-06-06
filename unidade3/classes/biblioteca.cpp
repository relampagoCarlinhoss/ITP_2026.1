#include <iostream>
class Usuario{
    std::string nome;
    int id; 
    int quantidadeDeLivros;
    
    public:
    //constrtutor
    Usuario() = default;
    Usuario(int id, std::string nome): id(id), nome(nome),quantidadeDeLivros(0){}

    int idDoUsuario(){return id;}
    int qtdLivro(){return quantidadeDeLivros;}
  
    bool pegarLivro(){
        quantidadeDeLivros++;
        return true;
    }

    bool devolverLivro(){
        if(quantidadeDeLivros > 0){
        quantidadeDeLivros--;
        return true;
        }
        return false;
    }

};

class Livro{
    std::string nomeLivro;
    std::string autor;
    long int isbn;
    bool emprestado = false; 

    public:
    //construtor 
    Livro() = default;
    Livro(std::string nomeLivro, std::string autor, long int isbn):
         nomeLivro(nomeLivro),autor(autor),isbn(isbn){}
    
     //operações
    long int consultarIsbn(){return isbn;}
    bool estado(){return emprestado;}
    void emprestimo(){emprestado = true;}    
    void devolvido(){emprestado = false;}
};

class Biblioteca{
    Livro livros[500];
    Usuario usuarios[500];
    int qtdDeLivro = 0;
    public:

    bool cadastrarLivro(Livro livro){
        livros[qtdDeLivro] = livro;
        qtdDeLivro++;
        return true;
    }

    bool cadastrarUsuario(Usuario usuario){
        usuarios[usuario.idDoUsuario()] = usuario;
        return true;
    }

    bool emprestarLivro(long int isbn, int id){
        
        for(int i = 0; i < qtdDeLivro;i++){
            if(livros[i].consultarIsbn() == isbn){
                if(livros[i].estado() == false){
                     usuarios[id].pegarLivro();
                     livros[i].emprestimo();
                     return true;
                }
                return false;
            }
        }
        return false;
    }

    bool devolverLivro(long int isbn, int id){
        for(int i = 0; i < qtdDeLivro; i++){
            if(livros[i].consultarIsbn() == isbn){
                usuarios[id].devolverLivro();
                livros[i].devolvido();
                qtdDeLivro--;
                return true;
            }
        }
        return false;
    }

    int quantidadeLivros(int id){
       return usuarios[id].qtdLivro();
    }


};