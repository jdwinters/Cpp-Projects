// file included in CIS020_F2015_Lab13.cpp
// 
// inline assembly for Lab 13
//                     CIS020
//                     Fall, 2014
//
// Student Name: 
//
//

#include "stdafx.h"


/****************  DEFINED IN CIS020_F2015_Lab13.H

// constants
int iMOVE = 100;
int iRESIZE = 101;

// struct POINT_3 has x, y, z coordinates of a point
typedef struct tagPOINT_3 {
	LONG x;
	LONG y;
	LONG z;
} POINT_3;

// struct TRIANGLE_3 has POINT_3 coordinates for A, B, and C triangles
typedef struct tagTRIANGLE_3 {
	POINT_3 a;
	POINT_3 b;
	POINT_3 c;
} TRIANGLE_3;

// Global variable. Poor practice, but it just makes this lab easier
TRIANGLE_3 triangle;
****************/



TRIANGLE_3 DoAssembly(TRIANGLE_3 triIn, int iMod, signed int iInput)
{
	TRIANGLE_3 triOut;

	__asm {
		pushad
	finit			; initialize the FPU

	fild		triangle.b.y		; load b.y into ST(0)
	fild		triangle.a.y		; load a.y into ST(0), b.y is now in ST(1)
	fsub		ST(0), ST(1) ; ST(0) = ST(1) - ST(0)

						; load into a variable, and then multiply ST(0) by that variable

; fsqrt ; use this later for sqaure rooting
		popad	
	}
	
	return triOut;
}



