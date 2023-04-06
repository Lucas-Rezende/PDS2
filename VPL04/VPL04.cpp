// números complexos são numeros compostos
// por uma parte real somada a uma parte imaginária

#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

// Tipo abastrato de dados que representa uma número complexo. 
class Complexo {
  // Atributos.
  private:
    double _real;
    double _imag;

  // Métodos.
  public:
    Complexo (double real = 0.0, double imag = 0.0) {
        _real = real;
        _imag = imag;
    }
    double modulo() {
      return sqrt(_real * _real + _imag * _imag);
    }
    Complexo conjugado() {
      return Complexo(_real, _imag);
    }
    Complexo inverso() {
      double mod = modulo();
      return Complexo(_real / mod / mod, _imag / mod / mod);
    }
    Complexo soma(Complexo y) {
      return Complexo(_real + y._real, _imag + y._imag);
    }
    Complexo subtrair(Complexo y) {
      return Complexo(_real - y._real, _imag - y._imag);
    }
    /*Complexo multiplicar(Complexo y) {
    }
    Complexo dividir(Complexo y) {
    }*/
};

pair<double, double> raizes(double a, double b, double c) {
    double delta = pow(b, 2) - 4*a*c;
    double first = (-b + sqrt(delta))/2*a;
    double second = (-b - sqrt(delta))/2*a;
    return make_pair(first, second);
}

int main () {
  cout << "Digite os coeficientes da equação f(x) = ax^2 + bx + c:" << endl;
  double a, b, c;
  cin >> a >> b >> c;
  auto r = raizes(a, b, c);
  cout << "(" << r.first._real << ", " << r.first._imag << ") "
       << "(" << r.second._real << ", " << r.second._imag << ")" << endl;
  return 0;
}