#include <stdio.h>

#define INDEX_SIZE(X) (((sizeof(X)) / sizeof(int)) - 1)

static int A[] = {-1, 0, 1};
static int B[] = { 1, 2, 3};
static int C[] = {-2, 1, 2};

static int aMax = 0, bMax = 0, cMax = 0;
static int ci = 0, cj = 0, ck = 0;
static int gi = 0, gj = 0, gk = 0;

enum RES { NONE = 0, CONTINUE, FINDED };

enum RES reCalc();
int reSum();

int main(argc, argv)
  int argc;
  char** argv;
{
  int nRes = 0;

  aMax = INDEX_SIZE(A);
  bMax = INDEX_SIZE(B);
  cMax = INDEX_SIZE(C);

  while( (nRes = reCalc()) > 0 ) 
  {
    if(nRes == 2)
      printf("A = %02d, B = %02d, C = %02d = %d\n", A[ci], B[cj], C[ck], reSum());
  }

  return 0;
}

enum RES reCalc()
{
  enum RES aRes = CONTINUE;

  if((A[gi] + B[gj] + C[gk]) == 0)
    ci = gi, cj = gj, ck = gk, aRes = FINDED;

  if(gk < cMax)
    gk++;
  else
  {
    gk = 0;

    if(gj < bMax) gj++;
    else
    {
      gj = 0;

      if(gi < aMax) gi++;
      else
      {
        aRes = NONE;
        goto LL;
      }
    }
  }
LL:
  return aRes;
}

int reSum() 
{ 
  return A[ci] + B[cj] + C[ck];
}
