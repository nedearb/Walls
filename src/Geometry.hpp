//
//  Geometry.hpp
//  Walls
//
//  Created by Emily Atlee on 8/15/16.
//  Copyright © 2016 Emily Atlee. All rights reserved.
//

#ifndef Geometry_hpp
#define Geometry_hpp

#include "Headers.hpp"
#include "Ray.hpp"

struct Point2{
    int x, y;
    
    Point2(int x, int y) : x(x), y(y){}
    Point2() : x(0), y(0){}
};

Point2 operator+(const Point2& a, const Point2& b);
Point2 operator-(const Point2& a, const Point2& b);
Point2 operator*(const Point2& a, const Point2& b);
Point2 operator/(const Point2& a, const Point2& b);

Point2 operator+(const Point2& a, const int b);
Point2 operator-(const Point2& a, const int b);
Point2 operator*(const Point2& a, const int b);
Point2 operator/(const Point2& a, const int b);

struct AABB{
    vec3 center = vec3(0, 0, 0);
    vec3 radii = vec3(0, 0, 0);
    
    bool intersects(AABB& other);
    
    bool intersects(vec3 origin, vec3 look, vec3& hit, float& dist, Side& side);

    string save();
};

AABB loadAABB(stringstream& stream);

float roundTo(float v, float m);
vec3 roundTo(vec3 v, float m);

#endif /* Geometry_hpp */
