#include "stdafx.h"

class BaseAlgorithm {
  protected:
    int median;
  public:
    virtual int findMedian() =0;
	int getInt();
  };