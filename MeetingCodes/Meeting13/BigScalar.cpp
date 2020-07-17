#include <cstddef>
#include <gsl/gsl>
#include <iostream>
#include <vector>
#include <limits>

class BigScalar {
  public:
    std::vector<double> data{};

    BigScalar(gsl::not_null<std::vector<double>*> initial_data,
              const double special_value) {
      (*initial_data)[4] = special_value;
      data = *initial_data;
    }

    BigScalar(std::vector<double>&& initial_data,
              const double special_value) {
      initial_data[4] = special_value;
      data = std::move(initial_data);
    }
};

// a sketch of an example function where std::move is preferred
/*template<size_t Size>
std::array<double, Size + 1> append_to_array(
    std::array<double, Size>&& input_array, double new_value) {
  std::array<double, Size + 1> new_array{};
  for (...) {
    gsl::at(new_array, i) = gsl::at(old_array, i);
  }
  new_array[Size] = new_value;
  return new_array;
}*/

int main() {
  constexpr size_t size = 100;
  constexpr double special_value = 4.0;
  std::vector<double> test_vector{};
  test_vector.resize(size);

  for (double& element : test_vector) {
    element = 5.0;
  }

  //BigScalar big_scalar{gsl::make_not_null(&test_vector), special_value};
  BigScalar big_scalar{std::move(test_vector), special_value};

  //std::cout << test_vector[4] << "\n";

  // gsl::at gives protection for index out of bounds
  std::cout << gsl::at(big_scalar.data, size / 2) << "\n";
  std::cout << big_scalar.data[4] << "\n";


  // this is an attempt to try and prevent the mistake where you
  // initialize something to 0 first and then forget to set it and
  // then in your result, it's hard to tell that there is a problem.
  // This way (using th enumeric limits) will make the error much more
  // noticeable, because the value of x is initialized to NaN
  double x = std::numeric_limits<double>::signaling_NaN();
  // ... say you forget to set x to value you meant to here
  std::cout << x + big_scalar.data[4] << "\n";

  return 0;
}
