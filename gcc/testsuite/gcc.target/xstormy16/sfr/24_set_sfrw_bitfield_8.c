/* { dg-options { -nostartfiles below100.o -Tbelow100.ld -O2 } } */

typedef struct
{
  unsigned short b0:1;
  unsigned short b1:1;
  unsigned short b2:1;
  unsigned short b3:1;
  unsigned short b4:1;
  unsigned short b5:1;
  unsigned short b6:1;
  unsigned short b7:1;
  unsigned short b8:1;
  unsigned short b9:1;
  unsigned short b10:1;
  unsigned short b11:1;
  unsigned short b12:1;
  unsigned short b13:1;
  unsigned short b14:1;
  unsigned short b15:1;
} BitField;

#define SFR (*((volatile BitField*)0x7f14))
unsigned short *p = (unsigned short *) 0x7f14;

void
Do (void)
{
  SFR.b8 = 1;
}

int
main (void)
{
  *p = 0x1234;
  Do ();
  return (*p == 0x1334) ? 0 : 1;
}

/* { dg-final { scan-file "24_set_sfrw_bitfield_8.s" "set1 32533,#0" } } */

