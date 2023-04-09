#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

class Complexo {
private:
    double real;
    double imag;

public:
    Complexo (double _real, double _imag) {
        real = _real;
        imag = _imag;
    }
    double modulo() {
        return sqrt(real*real + imag*imag);
    }

    Complexo conjugado() {
        return Complexo(real, -imag);
    }

    Complexo inverso() {
        double denom = real*real + imag*imag;
        return Complexo(real/denom, -imag/denom);
    }

    Complexo soma(Complexo y) {
        return Complexo(real + y.real, imag + y.imag);
    }

    Complexo subtrair(Complexo y) {
        return Complexo(real - y.real, imag - y.imag);
    }

    Complexo multiplicar(Complexo y) {
        double re = real*y.real - imag*y.imag;
        double im = real*y.imag + imag*y.real;
        return Complexo(re, im);
    }

    Complexo dividir(Complexo y) {
        double denom = y.real*y.real + y.imag*y.imag;
        double re = (real*y.real + imag*y.imag) / denom;
        double im = (imag*y.real - real*y.imag) / denom;
        return Complexo(re, im);
    }
    double getReal() const {
    return real;
    }
    double getImag() const {
        return imag;
    }
};

pair<Complexo, Complexo> raizes(double a, double b, double c) {
    double delta = b*b - 4*a*c;
    if (delta >= 0) {
        double x1 = (-b + sqrt(delta)) / (2*a);
        double x2 = (-b - sqrt(delta)) / (2*a);
        return make_pair(Complexo(x1, 0), Complexo(x2, 0));
    } else {
        double re = -b / (2*a);
        double im = sqrt(-delta) / (2*a);
        return make_pair(Complexo(re, im), Complexo(re, -im));
    }
}

int main() {
    cout << "Digite os coeficientes da equação f(x) = ax^2 + bx + c:" << endl;
    double a, b, c;
    cin >> a >> b >> c;
    auto r = raizes(a, b, c);
    cout << "(" << r.first.getReal() << ", " << r.first.getImag() << ")" << r.second.getReal() << ", " << r.second.getImag() << endl;

    return 0;
}
