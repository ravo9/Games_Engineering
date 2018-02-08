#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

namespace sf {
	// Create a definition for a sf::vector using size_t types
	typedef Vector2<size_t> Vector2ul;
	
	// Returns the length of a sf::vector
	template <typename T> double length(const Vector2<T> &v) {
	return sqrt(v[0]*v[0] + v[1]*v[1]);
	}
	
	// Return normalized sf::vector
	template <typename T> Vector2<T> normalize(const Vector2<T> &v) {
		Vector2<T> vector;
		double l = length(v);
		if (l != 0){
			vector.x = vector.x/l;
			vector.y = vecotr.y/l;
		}
		return vector;
	}
	
	// Allow casting from one sf::vector internal type to another
	template <typename T, typename U>
	Vector2<T> Vcast(const Vector2<U> &v) {
		return Vector2<T>(static_cast<T>(v.x), static_cast<T>(v.y));
	};
	
	// Degrees to radians conversion
	static double deg2rad(double degrees) {
		return ((degrees * (atan(1) * 4)) / 180 );
	}
	
	// Rotate a sf::vector by an angle(degrees)
	template <typename T>
	Vector2<T> rotate(const Vector2<T> &v, const double degrees) {
			const double theta = deg2rad(degrees);
			const double cs = cos(theta);
			const double sn = sin(theta);
			return {(T)(v.x * cs - v.y * sn), (T)(v.x * sn + v.y * cs)};
	}
	
	// Allow sf::vectors to be cout'ed
	template <typename T>
	std::ostream &operator<<(std::ostream &os, const Vector2<T> &v) {
		os << '(' << v.x << ',' << v.y << ')';
		return os;
	}
}