#include "include.hpp"

void saveAuton (const char* filename) {
  FILE* file = fopen(filename, "w");
  std::unique_ptr<double[]> doubles;
  for (int i = 0; i < loadedAuton.size(); i++) {
    doubles = std::move(loadedAuton[i]);
    fwrite(doubles.get(), sizeof(double), 4, file);
  }
  fclose(file);
}