#include "CMSIS/stm32f10x.h"
#include "stdint.h"
int32_t a;
int32_t strToInt( const char * str )
{
  int32_t i=0;
  int32_t ans = 0; 
  int32_t sign = 0;
  int32_t n = strlen(str); 
  if (str[i] == '-') 
  {
    sign = 1;
    i++;
  }
  for (i;i<n;i++) 
  {
    if (str[i] >= 0x30 && str[i] <= 0x39) 
    {
      ans = ans + (str[i] & 0x0F);
      ans = ans*10; 
    }
  }
  ans = ans/10; 
  if (sign == 1)
  ans = -ans;
  return ans;
}

uint8_t countSetBits(uint32_t arg) 
{ 
arg = (arg & 0x55555555) + ((arg >> 1) & 0x55555555); 
arg = (arg & 0x33333333) + ((arg >> 2) & 0x33333333); 
arg = (arg & 0x0F0F0F0F) + ((arg >> 4) & 0x0F0F0F0F); 
arg = (arg & 0x00FF00FF) + ((arg >> 8) & 0x00FF00FF); 
arg = (arg & 0x0000FFFF) + ((arg >>16) & 0x0000FFFF); 
return arg; 
} 

uint8_t countLeadingZeros(uint32_t k) 
{
    int16_t l, m, n;
    l = -(k >> 16);
    m = (l >> 16) & 16;
    n = 16 - m;
    k = k >> m;
    l = k - 0x100;
    m = (l >> 16) & 8;
    n = n + m;
    k = k << m;
    l = k - 0x1000;
    m = (l >> 16) & 4;
    n = n + m;
    k = k << m;
    l = k - 0x4000;
    m = (l >> 16) & 2;
    n = n + m;
    k = k << m;
    l = k >> 14;
    m = l & ~(l >> 1);
    n = n + 2;
    n = n - m;
    return n;
}

int main(void)
{
  int64_t a=strToInt("-140");
  uint8_t b=countSetBits(5);
  uint8_t c=countLeadingZeros(5);   
}
