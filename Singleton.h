#pragma once

template <typename T>
class Singleton
{
protected:
    // Protected constructor
    Singleton() = default;

    // Protected destructor
    virtual ~Singleton() = default;

public:
    // Delete copy constructor
    Singleton(const Singleton&) = delete;

    // Delete copy assignment operator
    Singleton& operator=(const Singleton&) = delete;

    // Get the singleton instance
    static T& getInstance()
    {
        static T instance;
        return instance;
    }
};
