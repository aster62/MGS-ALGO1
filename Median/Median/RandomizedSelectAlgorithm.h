#include "stdafx.h"

class RandomizedSelectAlgorithm : public BaseAlgorithm {
public:
    int getMedian(int*, int, int, int);
	int random_partition(int*, int, int);
	int random_selection(int*, int, int, int);
  };