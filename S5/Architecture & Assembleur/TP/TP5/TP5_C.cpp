#include <iostream>
#include <cstdlib>
using namespace std;
#include <getopt.h>
#include <xmmintrin.h>

int method = 1;
int size = 131072;
int zillions = 100000;
float *x, *y;

typedef float (*ScalarProductionType)(float *x, float *y, size_t size);

extern "C" {
  float ps_x87(float *x, float *y, size_t size);
  float ps_sse(float *x, float *y, size_t size);
  float ps_sse_u4(float *x, float *y, size_t size);
}

ScalarProductionType tab_fns[] = {
  nullptr,
  ps_x87,
  ps_sse
};

int main(int argc, char *argv[]){
  int opt;

  while ((opt = getopt(argc, argv, "m:s:z")) != -1) {
    switch (opt) {
    case 'm': method=atoi(optarg);break;
    case 's': size= atoi(optarg);break;
    case 'z': zillions=atoi(optarg);break;
    default: // '?'
        cerr<<"Error :"<<endl;
        exit(EXIT_FAILURE);
    }
  }
  //allocation of resources
  x=(float *) _mm_malloc(size * sizeof(float), 32);
  y=(float *) _mm_malloc(size * sizeof(float), 32);

  //initialisation
  const size_t modulo=17;
  for (size_t i = 0; i < size; ++i) {
  	x[i] = 1.0;
  	y[i] = 1 + (i % modulo);
  }

  //computations
  float result=0.0;
  for (int z=1;z<=zillions;++z){
    result=tab_fns[method](x,y,size);
  }
  cout<<"result="<<result<<endl;

  //free
  _mm_free(x);
  _mm_free(y);

  return EXIT_SUCCESS;
}
