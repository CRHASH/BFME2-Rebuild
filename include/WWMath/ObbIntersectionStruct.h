// Portions derived from Command & Conquer Generals and Command & Conquer Generals Zero Hour, (c) Electronic Arts Inc., GPL-3.0-or-later; see LICENSE and NOTICE.
// ObbIntersectionStruct.h: the working state of WWMath's oriented-box overlap test (Zero Hour's colmathobbobb.cpp keeps
// it local to that unit). Target facts (retail game.dat): intersect_obb_obb 0x007277C0 and its axis helpers address the
// box pointers at +0x78 and +0x7C and the dot-product table at +0x54; CollisionMath::Intersection_Test
// 0x007283D0 builds one in a 0x80-byte frame. SIZE 0x80.
#pragma once
#ifndef BFME2_OBBINTERSECTIONSTRUCT_H
#define BFME2_OBBINTERSECTIONSTRUCT_H

#include "WWMath/OBBoxClass.h"
#include "WWMath/Vector3.h"

struct ObbIntersectionStruct
{
	ObbIntersectionStruct(const OBBoxClass &box0, const OBBoxClass &box1) :
		Box0(box0),
		Box1(box1)
	{
		Vector3::Subtract(box1.Center, box0.Center, &C);	// vector from center of box0 to center of box1

		A[0].Set(box0.Basis[0][0], box0.Basis[1][0], box0.Basis[2][0]);
		A[1].Set(box0.Basis[0][1], box0.Basis[1][1], box0.Basis[2][1]);
		A[2].Set(box0.Basis[0][2], box0.Basis[1][2], box0.Basis[2][2]);

		B[0].Set(box1.Basis[0][0], box1.Basis[1][0], box1.Basis[2][0]);
		B[1].Set(box1.Basis[0][1], box1.Basis[1][1], box1.Basis[2][1]);
		B[2].Set(box1.Basis[0][2], box1.Basis[1][2], box1.Basis[2][2]);
	}

	Vector3 C;		// Vector from the center0 to center1
	Vector3 A[3];		// basis vectors for box0
	Vector3 B[3];		// basis vectors for box1
	float AB[3][3];		// dot products of the basis vectors

	const OBBoxClass &Box0;
	const OBBoxClass &Box1;

private:
	// not implemented
	ObbIntersectionStruct(const ObbIntersectionStruct &);
	ObbIntersectionStruct &operator=(const ObbIntersectionStruct &);
};

typedef char ObbIntersectionStructSize[(sizeof(ObbIntersectionStruct) == 0x80) ? 1 : -1];

bool intersect_obb_obb(ObbIntersectionStruct &context);	// 0x007277C0

#endif
