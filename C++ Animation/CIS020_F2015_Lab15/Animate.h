// Animate.h
// 
// inline assembly for CIS020_F2015_Lab15
//                     CIS020
//                     Fall, 2015

#pragma once
class Animate
{
public:
	Animate(void);
	~Animate(void);

		// struct FIGURE has values for stick figure
	typedef struct tagFIGURE {
		RECT head;
		POINT back_top;
		POINT back_bottom;
		POINT arm_1_top;
		POINT arm_1_bottom;
		POINT arm_2_top;
		POINT arm_2_bottom;
		POINT leg_1_top;
		POINT leg_1_bottom;
		POINT leg_2_top;
		POINT leg_2_bottom;
	} FIGURE;

	void Animate::DrawFigure(HDC);				// draws fig
	FIGURE Animate::GetFig();					// pass pack the fig structure
	void Animate::SetFig(FIGURE);				// used in DoAssembly, sets the class fig
	int Animate::DoAssembly(FIGURE, int);		// calculates new location of coordinates for fig
	
private:

	// fig is a struct with stick figure coordinates
	FIGURE fig;

};
