#include <stdio.h>

#define SIZE(X) (((sizeof(X)) / sizeof(int)) - 1)

#define ZERO          (0)

static int A[] = {-1, 0, 1};
static int B[] = { 1, 2, 3};
static int C[] = {-2, 1, 2};

static int aMax = ZERO, bMax = ZERO, cMax = ZERO;
static int ci = ZERO, cj = ZERO, ck = ZERO;
static int gi = ZERO, gj = ZERO, gk = ZERO;

enum RES { NONE = ZERO, CONTINUE, FINDED };

static enum RES reCalc();
static void reNext(enum RES*);
static int reSum();
static void reDisp();

int main(argc, argv)
  int argc;
  char** argv;
{
  int nRes = ZERO;

  aMax = SIZE(A);
  bMax = SIZE(B);
  cMax = SIZE(C);

  while( (nRes = reCalc()) != NONE ) 
    if(nRes == FINDED)
      reDisp();

  return ZERO;
}

static enum RES reCalc()
{
  enum RES aRes = CONTINUE;

  if((A[gi] + B[gj] + C[gk]) == ZERO)
    ci = gi, 
      cj = gj, 
        ck = gk, 
          aRes = FINDED;
    
  reNext(&aRes);
  
  return aRes;
}

static void reNext(enum RES* aRes)
{
  if(gk < cMax)
    gk++;
  else
  {
    gk = ZERO;

    if(gj < bMax) gj++;
    else
    {
      gj = ZERO;

      if(gi < aMax) gi++;
      else
      {
        *aRes = NONE;
        gk = ZERO;
        gj = ZERO;
        gi = ZERO;
        goto LL;
      }
    }
  }
LL:
  return;
}

static int reSum() 
{ 
  return A[ci] + B[cj] + C[ck];
}

static void reDisp()
{
  printf("A = %02d, B = %02d, C = %02d = %d\n", A[ci], B[cj], C[ck], reSum());
}
