#include "mnblas.h"
#include "complexe.h"

void mnblas_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y, const int incY)
{
  //register unsigned int i = 0, j = 0;
//#pragma omp parallel for
  for (unsigned int i=0,j=0 ; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y[j] += alpha * X[i];
  }

  return;
}

void mnblas_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y, const int incY){
  //register unsigned int i = 0, j = 0;
//#pragma omp parallel for
  for (unsigned int i=0,j=0 ; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y[j] += alpha * X[i];
  }

  return;
}
void mnblas_caxpy(const int N, const void *alpha, const void *X,
                  const int incX, void *Y, const int incY){
  complexe_float_t *X_tmp = (complexe_float_t *)X;
  complexe_float_t *Y_tmp = (complexe_float_t *)Y;
  complexe_float_t *alpha_tmp=(complexe_float_t *)alpha;
  //register unsigned int i = 0;
  //register unsigned int j = 0;
  //#pragma omp parallel for
  for (unsigned int i=0,j=0 ; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y_tmp[j].real += alpha_tmp->real * X_tmp[j].real - alpha_tmp->imaginary * X_tmp[j].imaginary ;
      Y_tmp[j].imaginary += alpha_tmp->real * X_tmp[j].imaginary + alpha_tmp->imaginary * X_tmp[j].real ;
  }
  return;
}

void mnblas_zaxpy(const int N, const void *alpha, const void *X,
                  const int incX, void *Y, const int incY){
  complexe_double_t *X_tmp = (complexe_double_t *)X;
  complexe_double_t *Y_tmp = (complexe_double_t *)Y;
  complexe_double_t *alpha_tmp=(complexe_double_t *)alpha;

//register unsigned int i = 0;
  //register unsigned int j = 0;

//#pragma omp parallel for
  for (unsigned int i=0,j=0 ; ((i < N) && (j < N)); i += incX, j += incY)
  {
    Y_tmp[j].real += alpha_tmp->real * X_tmp[j].real - alpha_tmp->imaginary * X_tmp[j].imaginary ;
      Y_tmp[j].imaginary += alpha_tmp->real * X_tmp[j].imaginary + alpha_tmp->imaginary * X_tmp[j].real ;
  }
  
  return;
}