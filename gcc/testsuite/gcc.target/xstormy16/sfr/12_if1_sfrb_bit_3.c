/* { dg-options { -nostartfiles below100.o -Tbelow100.ld -O2 } } */

#define SFRA (*((volatile unsigned char*)0x7f14))
unsigned char *pA = (unsigned char *) 0x7f14;
#define SFRB (*((volatile unsigned char*)0x7f10))
unsigned char *pB = (unsigned char *) 0x7f10;

char *
Do (void)
{
  if (SFRA & 0x08)
    {
      if (SFRB & 0x08)
	return "Fail";
      else
	return "Success";
    }
  else
    return "Fail";
}

int
main (void)
{
  *pA = 0xcb;
  *pB = 0x34;
  return Do ()[0] == 'F';
}

/* { dg-final { scan-file "12_if1_sfrb_bit_3.s" "b\[np\] " } } */

