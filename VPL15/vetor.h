#include <vector>

using namespace std;

struct ExcecaoIntervaloVazio {
  int inicio;
  int fim;
};

struct ExcecaoIndiceInvalido {
  int inicio;
  int fim;
  int indice;
};

struct ExcecaoIndiceNaoInicializado {
  int indice;
};

template <class Tipo>
class Vetor {
private:
  int inicio_;
  int fim_;
  vector<Tipo*> elementos_; // vector de ponteiros

public:
  Vetor(int inicio, int fim) : inicio_(inicio), fim_(fim) {
    if (fim < inicio)
      throw ExcecaoIntervaloVazio{inicio, fim};

    int tamanho = fim - inicio + 1;
    elementos_.resize(tamanho, nullptr); // inicializa com nullptr
  }

  void atribuir(int i, Tipo valor) {
    int deslocamento = i - inicio_;
    if (deslocamento < 0 || deslocamento >= elementos_.size())
      throw ExcecaoIndiceInvalido{inicio_, fim_, i};

    elementos_[deslocamento] = new Tipo(valor); // aloca um novo objeto
  }

  Tipo valor(int i) const {
    int deslocamento = i - inicio_;
    if (deslocamento < 0 || deslocamento >= elementos_.size())
      throw ExcecaoIndiceInvalido{inicio_, fim_, i};

    if (elementos_[deslocamento] == nullptr) // compara com nullptr
      throw ExcecaoIndiceNaoInicializado{i};

    return *elementos_[deslocamento]; // retorna o valor apontado
  }
};
