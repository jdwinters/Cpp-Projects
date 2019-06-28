// Animate.cpp
// 
// inline assembly for CIS020_F2015_Lab15
//                     CIS020
//                     Fall, 2015
//
// Student Name: Jonathan Winters
//
//

#include "stdafx.h"
#include "Animate.h"

int	moveCheck = 1;			//This is a global variable, but whatever.
int	llswingCheck = 1;		// These are directional checks for the logic to work correctly
int	rlswingCheck = 1;
int	laswingCheck = 1;
int	raswingCheck = 1;

int	cmpPos = 200;
int	cmpNeg = 400;

int	cmpLLegF = 18;
int	cmpLLegB = 36;
int	cmpRLegF = 36;
int	cmpRLegB = 18;
int	LegNumberAdd = 36;

int	cmpLArmF = 18;
int	cmpLArmB = 36;
int	cmpRArmF = 36;
int	cmpRArmB = 18;
int	ArmNumberAdd = 36;

int lnAB;
int lnAC;
int lnBC;
int fpuCheck;

int	unHuit = 180;								// These two make up the angle at which the leg moves each run through
int	apxChange = 2;
int	lpxChange = 1;
int	TWO = 2;
int	lDeltaX;									// left leg delta x
int	lradianHolder;								// left leg delta x made in order to make fpu easier
int	lDeltaY;									// left leg delta y
int	aDeltaX;
int	aradianHolder;								// left arm delta x made in order to make fpu easier
int	aDeltaY;
Animate::Animate(void)
{
	fig.head.left = 80;
	fig.head.top = 60;
	fig.head.right = 120;
	fig.head.bottom = 100;
	fig.back_top.x = 100;
	fig.back_top.y = 100;
	fig.back_bottom.x = 100;
	fig.back_bottom.y = 175;
	fig.arm_1_top.x = 100;
	fig.arm_1_top.y = 120;
	fig.arm_1_bottom.x = 75;
	fig.arm_1_bottom.y = 145;
	fig.arm_2_top.x = 100;
	fig.arm_2_top.y = 120;
	fig.arm_2_bottom.x = 125;
	fig.arm_2_bottom.y = 145;
	fig.leg_1_top.x = 100;
	fig.leg_1_top.y = 175;
	fig.leg_1_bottom.x = 75;
	fig.leg_1_bottom.y = 225;
	fig.leg_2_top.x = 100;
	fig.leg_2_top.y = 175;
	fig.leg_2_bottom.x = 125;
	fig.leg_2_bottom.y = 225;
}


Animate::~Animate(void)
{
}


void Animate::DrawFigure(HDC hdc) // draws the stick figure based on values of struct fig
{
	HPEN pen, oldPen;

	pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // blue
	oldPen = (HPEN)SelectObject(hdc, pen);


	// draw head
	Ellipse(hdc, fig.head.left, fig.head.top, fig.head.right, fig.head.bottom);

	// draw back
	MoveToEx(hdc, fig.back_top.x, fig.back_top.y, NULL);
	LineTo(hdc, fig.back_bottom.x, fig.back_bottom.y);
		
	// draw arm 1
	MoveToEx(hdc, fig.arm_1_top.x, fig.arm_1_top.y, NULL);
	LineTo(hdc, fig.arm_1_bottom.x, fig.arm_1_bottom.y);

	// draw arm 2
	MoveToEx(hdc, fig.arm_2_top.x, fig.arm_2_top.y, NULL);
	LineTo(hdc, fig.arm_2_bottom.x, fig.arm_2_bottom.y);

	// draw leg 1
	MoveToEx(hdc, fig.leg_1_top.x, fig.leg_1_top.y, NULL);
	LineTo(hdc, fig.leg_1_bottom.x, fig.leg_1_bottom.y);

	// draw leg 2
	MoveToEx(hdc, fig.leg_2_top.x, fig.leg_2_top.y, NULL);
	LineTo(hdc, fig.leg_2_bottom.x, fig.leg_2_bottom.y);

	SelectObject(hdc, oldPen);	// release the line pen
	DeleteObject(pen);
}

Animate::FIGURE Animate::GetFig()
{
	return fig;
}

void Animate::SetFig(FIGURE figIn)
{
		fig.head.left		= figIn.head.left;
		fig.head.top		= figIn.head.top;
		fig.head.right		= figIn.head.right;
		fig.head.bottom		= figIn.head.bottom;
		fig.back_top.x		= figIn.back_top.x;
		fig.back_top.y		= figIn.back_top.y;
		fig.back_bottom.x	= figIn.back_bottom.x;
		fig.back_bottom.y	= figIn.back_bottom.y;
		fig.arm_1_top.x		= figIn.arm_1_top.x;
		fig.arm_1_top.y		= figIn.arm_1_top.y;
		fig.arm_1_bottom.x	= figIn.arm_1_bottom.x;
		fig.arm_1_bottom.y	= figIn.arm_1_bottom.y;
		fig.arm_2_top.x		= figIn.arm_2_top.x;
		fig.arm_2_top.y		= figIn.arm_2_top.y;
		fig.arm_2_bottom.x	= figIn.arm_2_bottom.x;
		fig.arm_2_bottom.y	= figIn.arm_2_bottom.y;
		fig.leg_1_top.x		= figIn.leg_1_top.x;
		fig.leg_1_top.y		= figIn.leg_1_top.y;
		fig.leg_1_bottom.x	= figIn.leg_1_bottom.x;
		fig.leg_1_bottom.y	= figIn.leg_1_bottom.y;
		fig.leg_2_top.x		= figIn.leg_2_top.x;
		fig.leg_2_top.y		= figIn.leg_2_top.y;
		fig.leg_2_bottom.x	= figIn.leg_2_bottom.x;
		fig.leg_2_bottom.y	= figIn.leg_2_bottom.y;
}



int Animate::DoAssembly(FIGURE StickFig, int FrameNumber)
{
	int iReturnCode = 0;							// integer to continue or stop animation
	int	QuatCent = 400;								// float used to add to cmpPos/Neg in order to cmp the FrameNumber to change the direction when it hits a certain #


	__asm {
		pushad
		finit										; initialize revolver FPU
MOVELEGS:
;--------------------------- Leg length calculation
;StickFig.leg_1_top.x = 100;
;StickFig.leg_1_top.y = 175;
;StickFig.leg_1_bottom.x = 75;
;StickFig.leg_1_bottom.y = 225;

		fild	StickFig.leg_1_top.x				; ST(0) = leg_1_bottom.x
		fisub	StickFig.leg_1_bottom.x				; ST(0) = leg_1_top.x - leg_1_bottom.x
		fistp	lnAB								; store value into lnAB for now.

		fild	StickFig.leg_1_bottom.y				; ST(0) = leg_1_bottom.y
		fisub	StickFig.leg_1_top.y				; ST(0) = leg_1_top.y - leg_1_bottom.y
		fistp	lnBC								; store value into lnBC for now.

		fild	lnAB								; ST(0) = lnAB
		fild	lnAB								; ST(0) = lnAB, ST(1) = lnAB
		fmul										; ST(0) = lnAB^2		
		fild	lnBC								; ST(0) = lnBC, ST(1) = lnAB^2
		fild	lnBC								; ST(0) = lnBC, ST(1) = lnBC, ST(2) = lnAB^2
		fmul										; ST(0) = lnBC^2, ST(1) = lnAB^2
		fsubr										; ST(0) = lnAB^2 - lnBC^2
		fsqrt										; ST(0) = sqrt(lnAB^2 - lnBC^2)
		fistp	lnAC								; lnAC should be the length of the leg.
;---------------------------- Leg length calculation
;---------------------------- Calculate the legs delta x and delta y
		fild	lpxChange							; ST(0) = pxChange
		fldpi										; ST(0) = pi, ST(1) = pxChange
		fmul										; ST(0) = pi * pxChange
		fidiv	unHuit								; ST(0) = (pi * pxChange) / 180, this is the degrees in radians
		fist	lradianHolder						; load later to find delta y
		fsin										; ST(0) = sin(radians)
		fimul	lnAC								; ST(0) = sin(radians) * lnAC, ST(1) = radians
		fistp	lDeltaX

		fild	lradianHolder
		fsin										; ST(0) = sin(radians)
		fimul	lnAC								; ST(0) = sin(radians)*lnAC
		fistp	lDeltaY							
;--------------------------- Legs delta x and delta y are calculated

;--------------------------- This moves the left leg back and forth
LEFTLEG:
		mov		ebx, llswingCheck
		cmp		ebx, 0
		je		MOVE_LEFT_LEG_BACKWARDS
MOVE_LEFT_LEG_FORWARD:
		mov		edx, lDeltaX
		add		StickFig.leg_1_bottom.x, edx
		mov		edx, lDeltaY
		add		StickFig.leg_1_bottom.y, edx

		; stop going forward at the 40th frame
		mov		eax, FrameNumber
		cmp		eax, cmpLLegF
		je		CHANGETO_LEFT_LEG_BACKWARDS
		jmp		RIGHTLEG

MOVE_LEFT_LEG_BACKWARDS:
		mov		edx, lDeltaX
		sub		StickFig.leg_1_bottom.x, edx
		mov		edx, lDeltaY
		sub		StickFig.leg_1_bottom.y, edx

		; stop going backward at the 80th frame
		mov		eax, FrameNumber
		cmp		eax, cmpLLegB
		je		CHANGETO_LEFT_LEG_FORWARDS
		jmp		RIGHTLEG
CHANGETO_LEFT_LEG_BACKWARDS:
		fild	cmpLLegF							; Add 80 for next turn, or pace direction, ST(0) = cmpLLegF
		fiadd	LegNumberAdd						; ST(0) = cmpLLegF + '#'
		fistp	cmpLLegF							; Pop and store into cmpLLeg
		mov		llswingCheck, 0						; change to negative directional movement
		jmp		RIGHTLEG

CHANGETO_LEFT_LEG_FORWARDS:
		fild	cmpLLegB							; Add 80 for next turn, or pace direction, ST(0) = cmpLLegB
		fiadd	LegNumberAdd						; ST(0) = cmpLLegB + '#'
		fistp	cmpLLegB							; Pop and store into cmpLLeg
		mov		llswingCheck, 1						; change to negative directional movement
		jmp		RIGHTLEG

;--------------------------- This moves the right leg back and forth
RIGHTLEG:
		mov		ebx, rlswingCheck
		cmp		ebx, 0
		je		MOVE_RIGHT_LEG_FORWARD
MOVE_RIGHT_LEG_BACKWARDS:
		mov		edx, lDeltaX
		sub		StickFig.leg_2_bottom.x, edx
		mov		edx, lDeltaY
		sub		StickFig.leg_2_bottom.y, edx

		; stop going backward at the 80th frame
		mov		eax, FrameNumber
		cmp		eax, cmpRLegB
		je		CHANGETO_RIGHT_LEG_FORWARDS
		jmp		MOVEARMS

MOVE_RIGHT_LEG_FORWARD:
		mov		edx, lDeltaX
		add		StickFig.leg_2_bottom.x, edx
		mov		edx, lDeltaY
		add		StickFig.leg_2_bottom.y, edx

		; stop going forward at the 40th frame
		mov		eax, FrameNumber
		cmp		eax, cmpRLegF
		je		CHANGETO_RIGHT_LEG_BACKWARDS
		jmp		MOVEARMS

CHANGETO_RIGHT_LEG_FORWARDS:
		fild	cmpRLegB							; Add 80 for next turn, or pace direction, ST(0) = cmpLLegB
		fiadd	LegNumberAdd						; ST(0) = cmpLLegB + #
		fistp	cmpRLegB							; Pop and store into cmpLLeg
		mov		rlswingCheck, 0						; change to negative directional movement
		jmp		MOVEARMS

CHANGETO_RIGHT_LEG_BACKWARDS:
		fild	cmpRLegF							; Add 80 for next turn, or pace direction, ST(0) = cmpLLegF
		fiadd	LegNumberAdd						; ST(0) = cmpLLegF + #
		fistp	cmpRLegF							; Pop and store into cmpLLeg
		mov		rlswingCheck, 1						; change to negative directional movement
		jmp		MOVEARMS

;--------------------------- Arm length calculations
MOVEARMS:
;fig.arm_1_top.x = 100;
;fig.arm_1_top.y = 120;
;fig.arm_1_bottom.x = 75;
;fig.arm_1_bottom.y = 145;

		fild	StickFig.arm_1_top.x				; ST(0) = arm_1_top.x
		fisub	StickFig.arm_1_bottom.x				; ST(0) = arm_1_top.x - arm_1_bottom.x
		fistp	lnBC								; store value into lnAC for now.

		fild	StickFig.arm_1_bottom.y				; ST(0) = arm_1_bottom.y
		fisub	StickFig.arm_1_top.y				; ST(0) = arm_1_bottom.y - arm_1_top.y
		fistp	lnAC								; store value into lnBC for now.

		fild	lnAC								; ST(0) = lnAB
		fild	lnAC								; ST(0) = lnAB, ST(1) = lnAB
		fmul										; ST(0) = lnAB^2		
		fild	lnBC								; ST(0) = lnBC, ST(1) = lnAB^2
		fild	lnBC								; ST(0) = lnBC, ST(1) = lnBC, ST(2) = lnAB^2
		fmul										; ST(0) = lnBC^2, ST(1) = lnAB^2
		fadd										; ST(0) = lnAB^2 + lnBC^2
		fsqrt										; ST(0) = sqrt(lnAB^2 + lnBC^2)
		fistp	lnAB								; lnAC should be the length of the arm.
;----------------------------
;---------------------------- Calculate the arms delta x and delta y
		fild	apxChange							; ST(0) = pxChange
		fldpi										; ST(0) = pi, ST(1) = pxChange
		fmul										; ST(0) = pi * pxChange
		fidiv	unHuit								; ST(0) = (pi * pxChange) / 180, this is the degrees in radians
		fist	aradianHolder						; load later to find delta y
		fsin										; ST(0) = sin(radians)
		fimul	lnAB								; ST(0) = sin(radians) * lnAC, ST(1) = radians
		fistp	aDeltaX

		fild	aradianHolder
		fsin										; ST(0) = sin(radians)
		fimul	lnAB								; ST(0) = sin(radians)*lnAC
		fistp	aDeltaY
;--------------------------- Arms delta x and delta y are calculated
;--------------------------- This moves the left arm back and forth
LEFTARM:
		mov		ebx, laswingCheck
		cmp		ebx, 0
		je		MOVE_LEFT_ARM_BACKWARDS
MOVE_LEFT_ARM_FORWARD:
		mov		edx, aDeltaX
		add		StickFig.arm_1_bottom.x, edx
		mov		edx, aDeltaY
		add		StickFig.arm_1_bottom.y, edx

		; stop going forward at the 40th frame
		mov		eax, FrameNumber
		cmp		eax, cmpLArmF
		je		CHANGETO_LEFT_ARM_BACKWARDS
		jmp		RIGHTARM

MOVE_LEFT_ARM_BACKWARDS:
		mov		edx, aDeltaX
		sub		StickFig.arm_1_bottom.x, edx
		mov		edx, aDeltaY
		sub		StickFig.arm_1_bottom.y, edx

		; stop going backward at the 80th frame
		mov		eax, FrameNumber
		cmp		eax, cmpLArmB
		je		CHANGETO_LEFT_ARM_FORWARDS
		jmp		RIGHTARM
CHANGETO_LEFT_ARM_BACKWARDS:
		fild	cmpLArmF							; Add 80 for next turn, or pace direction, ST(0) = cmpLLegF
		fiadd	ArmNumberAdd						; ST(0) = cmpLAegF + #
		fistp	cmpLArmF							; Pop and store into cmpLLeg
		mov		laswingCheck, 0						; change to negative directional movement
		jmp		RIGHTARM

CHANGETO_LEFT_ARM_FORWARDS:
		fild	cmpLArmB							; Add 80 for next turn, or pace direction, ST(0) = cmpLLegB
		fiadd	ArmNumberAdd						; ST(0) = cmpLAegB + #
		fistp	cmpLArmB							; Pop and store into cmpLLeg
		mov		laswingCheck, 1						; change to negative directional movement


RIGHTARM:
		mov		ebx, raswingCheck
		cmp		ebx, 0
		je		MOVE_RIGHT_ARM_FORWARD
MOVE_RIGHT_ARM_BACKWARDS:
		mov		edx, aDeltaX
		sub		StickFig.arm_2_bottom.x, edx
		mov		edx, aDeltaY
		sub		StickFig.arm_2_bottom.y, edx

		; stop going backward at the 80th frame
		mov		eax, FrameNumber
		cmp		eax, cmpRArmB
		je		CHANGETO_RIGHT_ARM_FORWARDS
		jmp		MOVEBODY

MOVE_RIGHT_ARM_FORWARD:
		mov		edx, aDeltaX
		add		StickFig.arm_2_bottom.x, edx
		mov		edx, aDeltaY
		add		StickFig.arm_2_bottom.y, edx

		; stop going forward at the 40th frame
		mov		eax, FrameNumber
		cmp		eax, cmpRArmF
		je		CHANGETO_RIGHT_ARM_BACKWARDS
		jmp		MOVEBODY

CHANGETO_RIGHT_ARM_FORWARDS:
		fild	cmpRArmB							; Add 80 for next turn, or pace direction, ST(0) = cmpLLegB
		fiadd	ArmNumberAdd						; ST(0) = cmpLLegB + #
		fistp	cmpRArmB							; Pop and store into cmpLLeg
		mov		raswingCheck, 0						; change to negative directional movement
		jmp		MOVEBODY

CHANGETO_RIGHT_ARM_BACKWARDS:
		fild	cmpRArmF							; Add 80 for next turn, or pace direction, ST(0) = cmpLLegF
		fiadd	ArmNumberAdd						; ST(0) = cmpLLegF + #
		fistp	cmpRArmF							; Pop and store into cmpLLeg
		mov		raswingCheck, 1						; change to negative directional movement
		jmp		MOVEBODY

MOVEBODY:
		mov		ecx, moveCheck						; move moveCheck into ecx
		cmp		ecx, 0								; was the direction changed?
		je		NEGATIVE							; yes? Go do negative movements then, if not, do positive movement on the x-axis.
POSITIVE:
		inc		StickFig.head.left					; move head
		inc		StickFig.head.right
		inc		StickFig.back_top.x					; move back
		inc		StickFig.back_bottom.x
		inc		StickFig.arm_1_top.x				; move left arm
		inc		StickFig.arm_1_bottom.x
		inc		StickFig.arm_2_top.x				; move right arm
		inc		StickFig.arm_2_bottom.x
		inc		StickFig.leg_1_top.x				; move left leg
		inc		StickFig.leg_1_bottom.x
		inc		StickFig.leg_2_top.x				; move right leg
		inc		StickFig.leg_2_bottom.x

		; stop the animation at the 200th frame
		mov		eax, FrameNumber					; move FrameNumber to EAX
		cmp		eax, cmpPos							; is this a number that is cmpPos + 400*x? Where x starts with 0, incrementing each time.
		je		CHANGETONEG							; yes, don't reset return code
		mov		iReturnCode, 1						; no, set return code to 1, which will cause animation to continue
		jmp		DONE
NEGATIVE:
		dec		StickFig.head.left					; move head
		dec		StickFig.head.right
		dec		StickFig.back_top.x					; move back
		dec		StickFig.back_bottom.x
		dec		StickFig.arm_1_top.x				; move left arm
		dec		StickFig.arm_1_bottom.x
		dec		StickFig.arm_2_top.x				; move right arm
		dec		StickFig.arm_2_bottom.x
		dec		StickFig.leg_1_top.x				; move left leg
		dec		StickFig.leg_1_bottom.x
		dec		StickFig.leg_2_top.x				; move right leg
		dec		StickFig.leg_2_bottom.x

		; stop the animation at the 400th frame
		mov		eax, FrameNumber					; move FrameNumber to EAX
		cmp		eax, cmpNeg							; is this a number that is cmpNeg + 400*x? Where x starts with 0, incrementing each time.
		je		CHANGETOPOS							; yes, don't reset return code
		mov		iReturnCode, 1						; no, set return code to 1, which will cause animation to continue
		jmp		DONE

CHANGETONEG:
		fild	cmpPos								; Add 400 for next turn, or pace direction, ST(0) = cmpPos
		fiadd	QuatCent							; ST(0) = cmpPos + 400
		fistp	cmpPos								; Pop and store into cmpPos
		mov		moveCheck, 0						; change to negative directional movement
		mov		iReturnCode, 1						; no, set return code to 1, which will cause animation to continue
		jmp		DONE
CHANGETOPOS:
		fild	cmpNeg								; Add 400 for next turn, or pace direction
		fiadd	QuatCent							; ST(0) = cmpNeg + 400
		fistp	cmpNeg								; Pop and store into cmpPos
		mov		moveCheck, 1						; change to positive directional movement
		mov		iReturnCode, 1						; no, set return code to 1, which will cause animation to continue
		jmp		DONE
DONE:
		popad	
	}

	SetFig(StickFig);							// save the values set in the inline assembly

	// return 0 when you wish to stop animation
	// return any other number and animation continues
	return iReturnCode;
}

