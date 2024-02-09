#define POSCMD_HS_MODE 2
#define POSCMD_XT_MODE 1
#define POSCMD_EC_MODE 0

//PLLDIV
#define PLLCON_ON_1 0x8000
#define PLLCON_OE_1 0x1000

//BOSC
#define PLLCON_BOSC_1 0x100
#define PLLCON_BOSC_2 0x200
#define PLLCON_BOSC_3 0x300
#define PLLCON_BOSC_4 0x400
#define PLLCON_BOSC_5 0x500
#define PLLCON_BOSC_6 0x600
#define PLLCON_BOSC_7 0x700

//FSCMEN
#define PLLCON_FSCMEN 0x100000

//NOSC
#define PLLCON_NOSC_PGC 0x000
#define PLLCON_NOSC_FRC 0x100
#define PLLCON_NOSC_BFRC 0x200
#define PLLCON_NOSC_POSC 0x300
#define PLLCON_NOSC_REFI1 0x900
#define PLLCON_NOSC_REFI2 0xA00

//PLLDIV 
//POSTDIV2
#define PLLDIV_POSTDIV2_1 0x1
#define PLLDIV_POSTDIV2_2 0x2
#define PLLDIV_POSTDIV2_3 0x3
#define PLLDIV_POSTDIV2_4 0x4
#define PLLDIV_POSTDIV2_5 0x5
#define PLLDIV_POSTDIV2_6 0x6
#define PLLDIV_POSTDIV2_7 0x7

//POSTDIV1
#define PLLDIV_POSTDIV1_1 0x08
#define PLLDIV_POSTDIV1_2 0x10
#define PLLDIV_POSTDIV1_3 0x18
#define PLLDIV_POSTDIV1_4 0x20
#define PLLDIV_POSTDIV1_5 0x28
#define PLLDIV_POSTDIV1_6 0x30
#define PLLDIV_POSTDIV1_7 0x38


//PLLFBDIV
#define PLLDIV_PLLFBDIV(x) ((x)<<8)

//REFDIV
#define PLLDIV_RFDIV(x) ((x)<<24)

//VCODIV
#define VCO1DIV_INTDIV(x) ((x)<<16)

//CLKCON
#define CLKCON_ON_1 0x8000
#define CLKCON_OE_1 0x1000

//BOSC
#define CLKCON_BOSC_PGC 0x00000
#define CLKCON_BOSC_FRC 0x10000
#define CLKCON_BOSC_BFRC 0x20000
#define CLKCON_BOSC_POSC 0x30000
#define CLKCON_BOSC_LPRC 0x40000
#define CLKCON_BOSC_PLL1 0x50000
#define CLKCON_BOSC_PLL2 0x60000
#define CLKCON_BOSC_PLL1_VCO 0x70000
#define CLKCON_BOSC_PLL2_VCO 0x80000
#define CLKCON_BOSC_REFI1 0x90000
#define CLKCON_BOSC_REFI2 0xA0000
#define CLKCON_BOSC_SOSC 0xB0000

//FSCMEN
#define CLKCON_FSCMEN_1 0x10000

//NOSC
#define CLKCON_NOSC_PGC 0x000
#define CLKCON_NOSC_FRC 0x100
#define CLKCON_NOSC_BFRC 0x200
#define CLKCON_NOSC_POSC 0x300
#define CLKCON_NOSC_LPRC 0x400
#define CLKCON_NOSC_PLL1 0x500
#define CLKCON_NOSC_PLL2 0x600
#define CLKCON_NOSC_PLL1_VCO 0x700
#define CLKCON_NOSC_PLL2_VCO 0x800
#define CLKCON_NOSC_REFI1 0x900
#define CLKCON_NOSC_REFI2 0xA00
#define CLKCON_NOSC_SOSC 0xB00

//CLKDIV
//FRCDIV
#define CLKDIV_FRACDIV_2_P1x(x) ((x)<<7)
#define CLKDIV_INTDIV_2x(x) ((x)<<16)