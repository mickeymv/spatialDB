#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "poi2D.h"

using namespace std;

int main(int argc, char* argv[]) {
  vector<poi2D> input;
  ifstream infile;
  infile.open(argv[1], ios::binary | ios::in);

  poi2D fileRead;

  while (infile.read((char*)&fileRead, sizeof(poi2D))) {
    input.push_back(fileRead);
  }

  clock_t begin = clock();

  computeHull(input);

  clock_t end = clock();
  double elapsed_secs = double(end - begin);
  cout << elapsed_secs << endl;
}