## Lesson 4
  - Template wrap-up: SpatialVector of DataVector
    - Clean-up and test SpatialVector<double>
      - Start with last time's SpatialVector code
      - Rename to SpatialVector.hpp, remove main()
      - Add container to_string()
      - Add SpatialVector to_string()
      - In new SpatialVector.cpp, print out dot product of vector of doubles in 2D
    - Draw the idea of a grid and our 1D representation
      - valarray as DataVector stand-in
      - In SpatialVector.cpp, make DataVectors to loop over points of a grid in 2D
      - In SpatialVector.cpp, make a spatial vector of the coordinates
      - In SpatialVector.cpp, print the dot product
      - In SpatialVector.cpp, print out a gaussian in 2D
  - Lambdas and functors
    - Revisit trapezoid integrator
      - Template on type instead of taking a function pointer
      - Pass in a function
      - Pass in a functor (struct with operator() const member function)
      - Pass in a lambda
  - Metaprogramming
    - brigand library
    - tmpl::list<>
    - printing types at runtime
    - printing types at compile time
    - integer arithmetic, boolean logic at compile time