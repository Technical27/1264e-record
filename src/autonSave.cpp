#include "include.hpp"

void saveAuton (const char* filename) {
  FILE* file = fopen(filename, "w");
  for (int i = 0; i < loadedAuton.size(); i++) {
    std::unique_ptr<double[]> doubles (std::move(loadedAuton[i]));
    fwrite(doubles.get(), sizeof(double), 4, file);
  }
  fclose(file);
}