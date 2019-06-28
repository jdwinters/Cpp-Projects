#pragma once

#include "resource.h"

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


