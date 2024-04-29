#include "functions.hpp"
#include <algorithm>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <random>
#include <vector>

using namespace std;

vector<int> random_vector(int length) {
  random_device rd;
  default_random_engine rng(rd());
  uniform_int_distribution<> random_int(0, length);
  vector<int> v{};
  for (int i{0}; i < length; ++i) {
    v.push_back(random_int(rng));
  }
  return v;
}

string random_string(int length) {
  random_device rd;
  default_random_engine rng(rd());
  uniform_int_distribution<> random_int(20, 126);
  string s;
  for (int i{0}; i < length; ++i) {
    s.push_back(random_int(rng));
  }
  return s;
}

ostream &operator<<(ostream &os, const vector<int> &v) {
  for (const auto x : v) {
    os << x << " ";
  }
  return os;
}

TEST_CASE("Potencia de exponente positivo", "[potenciap]") {
  REQUIRE(potenciap(3, 1) == 3);
  REQUIRE(potenciap(3, 4) == 81);
  REQUIRE(potenciap(0.5, 3) == 0.125);
  REQUIRE(potenciap(0, 5) == 0);
}

TEST_CASE("Potencia de exponente negativo", "[potencia]") {
  REQUIRE(potencia(2, -3) == 0.125);
  REQUIRE(potencia(0.5, -2) == 4);
  REQUIRE(potencia(2, 0) == 1);
  REQUIRE(potencia(1.5, 0) == 1);
}

TEST_CASE("Invertir string", "[invertido]") {
  REQUIRE(invertido("abc") == "cba");
  REQUIRE(invertido("") == "");
  REQUIRE(invertido("a") == "a");
}

TEST_CASE("Máximo valor de un vector", "[maxv]") {
  vector<int> v{random_vector(10)};
  auto it = max_element(v.begin(), v.end());
  REQUIRE(maxv(v) == *it);
  REQUIRE(maxv(vector<int>{1, 1, 1}) == 1);
  REQUIRE(maxv(vector<int>{5}) == 5);
}

TEST_CASE("Mínimo valor de un vector", "[minv]") {
  vector<int> v{random_vector(10)};
  auto it = min_element(v.begin(), v.end());
  REQUIRE(minv(v) == *it);
  REQUIRE(minv(vector<int>{1, 1, 1}) == 1);
  REQUIRE(minv(vector<int>{5}) == 5);
}

TEST_CASE("Measure speed of algorithms",
          "[potencia][potenciap][maxv][minv][speed]") {
  BENCHMARK("Potencia de base entera con exponente positivo grande") {
    potenciap(2, 30);
  };
  BENCHMARK("Potencia de base no entera con exponente positivo grande") {
    potenciap(0.5, 30);
  };
  BENCHMARK("Invertir string largo") { invertido(random_string(10)); };
  BENCHMARK("Máximo de vector largo") { maxv(random_vector(10)); };
  BENCHMARK("Mínimo de vector largo") { minv(random_vector(10)); };
}
