#include "complexo.h"
#include <cmath>

Complexo::Complexo() : Complexo(0, 0) {
}

Complexo::Complexo(double a) : Complexo(a, 0) {
}

Complexo::Complexo(double a, double b) : real_(a), imag_(b) {
}

double Complexo::real() const {
  return real_;
}

double Complexo::imag() const {
  return imag_;
}

bool Complexo::operator==(Complexo x) const {
  // Precisão numérica utilizada.
  static const double epsilon = 1E-6;

  return fabs(x.real_ - real_) < epsilon &&
         fabs(x.imag_ - imag_) < epsilon;
}

void Complexo::operator=(Complexo x) {
  real_ = x.real_;
  imag_ = x.imag_;
}

double Complexo::modulo() const {
  return sqrt(real_ * real_ + imag_ * imag_);
}

Complexo Complexo::conjugado() const {
  return Complexo(real_, -imag_);
}

Complexo Complexo::operator-() const {
  return Complexo(-real_, -imag_);
}

Complexo Complexo::inverso() const {
  double divisor = real_ * real_ + imag_ * imag_;
  return Complexo(real_ / divisor, -imag_ / divisor);
}

Complexo Complexo::operator+(Complexo y) const {
  return Complexo(real_ + y.real_, imag_ + y.imag_);
}

Complexo Complexo::operator-(Complexo y) const {
  return Complexo(real_ - y.real_, imag_ - y.imag_);
}

Complexo Complexo::operator*(Complexo y) const {
  double a = real_ * y.real_ - imag_ * y.imag_;
  double b = real_ * y.imag_ + imag_ * y.real_;
  return Complexo(a, b);
}

Complexo Complexo::operator/(Complexo y) const {
  double divisor = y.real_ * y.real_ + y.imag_ * y.imag_;
  double a = (real_ * y.real_ + imag_ * y.imag_) / divisor;
  double b = (imag_ * y.real_ - real_ * y.imag_) / divisor;
  return Complexo(a, b);
}
