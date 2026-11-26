#pragma once
struct Vec2
{
    float x;
    float y;
    Vec2();
	Vec2(float px, float py);
	Vec2 AddVec(Vec2 other);
	float Length() const;
};

//ƒƒ“ƒoŠO‚ÌŠÖ”
Vec2 AddVec(Vec2 a, Vec2 b);
