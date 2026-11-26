#include "Vec2.h"
#include <cmath>

Vec2::Vec2() : x(0.0f), y(0.0f)
{}

Vec2::Vec2(float px, float py) : x(px), y(py)
{}

Vec2 Vec2::AddVec(Vec2 other)
{
    Vec2 ans;
	ans.x = x + other.x;
	ans.y = y + other.y;
    return ans;
}
//ベクトルの長さを返すメンバ関数を考えよう！
float Vec2::Length() const
{
  return sqrt(x * x + y * y);
}

//メンバ外のグローバル関数としてのベクトルの加算を考えよう！
Vec2 AddVec(Vec2 a, Vec2 b)
{
    Vec2 ans;
	ans.x = a.x + b.x;
	ans.y = a.y + b.y;
	return ans;
}

