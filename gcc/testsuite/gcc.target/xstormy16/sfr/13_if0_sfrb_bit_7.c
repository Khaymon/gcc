/* { dg-options { -nostartfiles below100.o -Tbelow100.ld -O2 } } */

#define SFRA (*((volatile unsigned char*)0x7f14))
unsigned char *pA = (unsigned char *) 0x7f14;
#define SFRB (*((volatile unsigned char*)0x7f10))
unsigned char *pB = (unsigned char *) 0x7f10;

char *
Do (void)
{
  if (!(SFRA & 0x80))
    {
      if (!(SFRB & 0x80))
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
  *pA = 0x34;
  *pB = 0xcb;
  return Do ()[0] == 'F';
}

/* { dg-final { scan-file "13_if0_sfrb_bit_7.s" "b\[np\] " } } */

