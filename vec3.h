#pragma once
#include <iostream>

class vec3
{
private:
    double m_vec[3];
public:

    vec3(); // Create a zero vector
    vec3(double x, double y, double z);
    bool operator==(vec3 &rhs);
    vec3 operator+(vec3 &rhs);
    vec3 operator-(vec3 &rhs);
    vec3 operator*(vec3 &rhs);
    vec3 operator/(vec3 &rhs);
    vec3 operator+(double scalar);
    vec3 operator-(double scalar);
    vec3 operator*(double scalar);
    vec3 operator/(double scalar);
    // void add(vec3 &rhs); // Possibly broken
    // void addAndMultiply(vec3 &rhs, double scalar); // Possibly broken
    vec3 cross(vec3 &rhs);
    double dot(vec3 &rhs);
    double length();
    double lengthSquared();
    void normalize();
    void setToZero();
    void randomGaussian(double mean, double standardDeviation);
    void randomUniform(double min, double max);
    void set(double x, double y, double z);
    inline double x() const { return m_vec[0]; }
    inline double y() const { return m_vec[1]; }
    inline double z() const { return m_vec[2]; }
    inline double &operator[](int index) { return m_vec[index]; }
    inline double operator[](int index) const { return m_vec[index]; }

private:
    friend std::ostream& operator<<(std::ostream&stream, vec3 &vec);


};
