/*
 * @Author: your name
 * @Date: 2020-05-14 15:19:37
 * @LastEditTime: 2020-05-14 15:26:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\c++_oo\string.h
 */
#ifndef STRING_H
#define STRING_H

#include <string.h>

class String {
 public:
  String(const char* cstr = 0);
  String(const String& str);
  String& operator=(const String& str);
  ~String();
  char* get_c_str() const { return m_data; }

 private:
  char* m_data;
}

inline
String::String(const char* cstr = 0){
    if(cstr){
        m_data = new char[strlen(cstr)+1];
        strcopy(m_data,cstr);
    }
    else{
        m_data = new char[1];
        *m_data = '\0';
    }
}
inline
String::~String(){
    delete[] m_data;
}

inline
String::String(const String& str){
    m_data = new char[strlen(str.m_data)+1];
    strcopy(m_data,str.m_data);
}

inline
String& String::operator=(const String& str){
    //自我赋值检验
    if(this == &str){
        return *this;
    }
    delete[] m_data;
    m_data = new char(strlen[str.m_data]+1);
    strcopy(m_data,str.m_data);
    return *this;
}

#endif