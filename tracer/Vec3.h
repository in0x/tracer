#pragma once

template<typename T>
struct Vec3
{
public:
	T x;
	T y;
	T z;

	bool operator==(const Vec3& rhs)
	{
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	Vec3& operator+=(const Vec3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	Vec3& operator-=(const Vec3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	Vec3& operator*=(const Vec3& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	Vec3& operator/=(const Vec3& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	Vec3& operator+=(const T t)
	{
		x += t;
		y += t;
		z += t;
		return *this;
	}

	Vec3& operator*=(const T t)
	{
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}

	Vec3& operator/=(const T t)
	{
		x /= t;
		y /= t;
		z /= t;
		return *this;
	}
};

template<typename T>
Vec3<T> operator-(const Vec3<T>& vec)
{
	return Vec3<T>{-vec.x, -vec.y, -vec.z};
};

template<typename T>
T length(const Vec3<T>& vec)
{
	return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}

template<typename T>
T length2(const Vec3<T>& vec)
{
	return vec.x*vec.x + vec.y*vec.y + vec.z*vec.z;
}

template<typename T>
inline Vec3<T> operator+(Vec3<T> lhs, const Vec3<T>& rhs)
{
	lhs += rhs;
	return lhs;
}

template<typename T>
inline Vec3<T> operator-(Vec3<T> lhs, const Vec3<T>& rhs)
{
	lhs -= rhs;
	return lhs;
}

template<typename T>
inline Vec3<T> operator*(Vec3<T> lhs, const Vec3<T>& rhs)
{
	lhs *= rhs;
	return lhs;
}

template<typename T>
inline Vec3<T> operator/(Vec3<T> lhs, const Vec3<T>& rhs)
{
	lhs /= rhs;
	return lhs;
}

template<typename T>
inline Vec3<T> operator*(Vec3<T> lhs, T rhs)
{
	lhs *= rhs;
	return lhs;
}

template<typename T>
inline Vec3<T> operator/(Vec3<T> lhs, T rhs)
{
	lhs /= rhs;
	return lhs;
}

template<typename T>
inline Vec3<T> operator+(Vec3<T> lhs, T rhs)
{
	lhs += rhs;
	return lhs;
}

template<typename T>
inline Vec3<T> operator*(T lhs, Vec3<T> rhs)
{
	rhs *= lhs;
	return rhs;
}

template<typename T>
void normalize(Vec3<T>& vec)
{
	T len = 1 / length(vec);
	vec *= len;
}

template<typename T>
Vec3<T> normalized(const Vec3<T>& vec)
{
	return vec / length(vec);
}

template<typename T>
T dot(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

template<typename T>
Vec3<T> cross(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return Vec3<T>(
		lhs.y * rhs.z - lhs.z * rhs.y,
		-(lhs.x * rhs.z - lhs.z * rhs.x),
		lhs.x * rhs.y - lhs.y * rhs.x
		);
}

template<typename T>
Vec3<T> reflect(const Vec3<T>& v, const Vec3<T>& n)
{
	return v - 2.0f * dot(v, n) * n;
}

// Returns refracted vector if refraction occurs, else 0-vector
template<typename T>
Vec3<T> refract(const Vec3<T>& v, const Vec3<T>& n, float ni_over_nt)
{
	Vec3<T> unitV = normalized(v);

	T dotVN = dot(unitV, n);
	T discriminant = 1.0f - ni_over_nt * ni_over_nt * (1.0f - dotVN * dotVN);

	Vec3<T> refracted{ 0.0f, 0.0f, 0.0f };	

	if (discriminant > 0.0f)
	{
		refracted = ni_over_nt * (unitV - n * dotVN) - n * sqrt(discriminant);
	}

	return refracted;
}

typedef Vec3<float> Vec3f;
