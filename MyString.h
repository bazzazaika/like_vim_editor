#pragma once
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <vector>

class MyString
{

private:

    char* string_;
    int lengthVal_;
    int capacityVal_;

    const char* StrToCharPtr(const std::string& str) const;
    void computeLPSArray(const char* str, int m, std::vector<int>& lps) const;

public:
    MyString(void);
    MyString(const char* str);
    MyString(const std::initializer_list<char>& list);
    MyString(const std::string& str);
    MyString(const char* str, int count);
    MyString(int count, const char c);
    MyString(const MyString& other);
    ~MyString();

    MyString operator+(const MyString& right);
    MyString operator+(const char* str);
    MyString operator+(const std::string& str);

    MyString& operator+=(const char* str);
    MyString& operator+=(const MyString& other);
    MyString& operator+=(const std::string& str);

    MyString& operator=(const std::string& str);
    MyString& operator=(const char* str);
    MyString& operator=(const char c);
    MyString& operator=(const MyString& other);

    char operator[](int i) const;

    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator==(const MyString& other) const;

    char* c_str(void) const;
    char* data(void) const;
    int length(void) const;
    int size(void) const;
    bool empty(void) const;
    int capacity(void) const;
    void shrink_to_fit();
    void clear();

    void insert(int index, int count, const char c);
    void insert(int index, const char* str);
    void insert(int index, const char* str, int count);
    void insert(int index, const std::string& str);
    void insert(int index, const std::string& str, int count);

    void erase(int index, int count);

    void append(int count, const char c);
    void append(const char* str);
    void append(const std::string& str);
    void append(const std::string& str, int index, int count);
    void append(const char* str, int index, int count);

    void replace(const int index, const int count, const char* str);
    void replace(const int index, const int count, const std::string& str);

    MyString substr(int index) const;
    MyString substr(int index, int count) const;

    int find(const char* str) const;
    int find(const char* str, int index) const;
    int find(const std::string& str) const;
    int find(const std::string& str, int index) const;


    friend std::ostream& operator<<(std::ostream& os, const MyString& other);
    friend std::istream& operator>>(std::istream& is, MyString& obj);

    int Print();
};

#endif //_MYSTRING_H_