#include "functions.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  double base;
  int exponente{0};
  cout << "Escriba la base: ";
  cin >> base;
  while (exponente <= 0) {
    cout << "Escriba un exponente entero positivo: ";
    cin >> exponente;
  }
  cout << base << "^" << exponente << " = " << potenciap(base, exponente)
       << "\n";
  cout << "Escriba otra base: ";
  cin >> base;
  cout << "Escriba un exponente entero (positivo, negativo o nulo): ";
  cin >> exponente;
  cout << base << "^" << exponente << " = " << potencia(base, exponente)
       << "\n";
  string texto;
  cout << "Escriba un texto: ";
  cin.ignore();
  getline(cin, texto);
  cout << "Texto invertido: " << invertido(texto) << "\n";
  vector<int> v{};
  int size{0};
  cout << "Escriba cuántos elementos quiere introducir en el vector: ";
  cin >> size;
  cout << "Escriba los elementos del vector separados por un espacio o un "
          "salto de línea: ";
  for (int i{0}; i < size; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  cout << "El valor máximo del vector es: " << maxv(v) << "\n";
  cout << "El valor mínimo del vector es: " << minv(v) << "\n";
}
