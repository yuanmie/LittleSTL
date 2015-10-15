#include <string.h>
#include <iostream>
using namespace std;

class String
{
 public:
  String():_data(new char[1])
    {
      *_data = '\0';
    }

  String(const char *str)
    :_data(new char[strlen(str) + 1])
    {
      strcpy(_data, str);
    }

  String(const String& rhs)
    :_data(new char[rhs.size() + 1])
    {
      strcpy(_data, rhs.c_str());
    }

  ~String()
    {
      delete[] _data;
    }

  String& operator= (const String &rhs);
  //返回的是值，而不是引用
  String operator+ (const String &rhs);
  String& operator+= (const String &rhs);
  bool operator== (const String& rhs);
  char& operator[] (int n) const;
  
  size_t size() const
  {
    return strlen(_data);
  }

  const char* c_str() const
  {
    return _data;
  }

  friend istream& operator>> (istream &is, String& rhs);
  friend ostream& operator<< (ostream &os, const String& rhs);

 private:
  char *_data;
};

String& String::operator= (const String &rhs)
{
  if (this != &rhs)
    {
      String strTemp(rhs);

      char *pTemp = strTemp._data;
      strTemp._data = _data;
      _data = pTemp;
    }

  return *this;
}
    
//另一种写法
//String& String::operator= (const String &rhs)
//{
//  if (this == &str)
//    return *this;

//  delete[] _data;
//  _data = NULL:

//  _data = new char[strlen(str._data) + 1];
//  strcpy(_data, rhs._data);

//  return *this;
//}
      
  String String::operator+ (const String &rhs)
  {
    size_t length = size() + rhs.size();
    char *_newData = new char[length + 1];
    strcpy(_newData, _data);
    strcat(_newData, rhs._data);
    String str(_newData);
    return str;
  }

   String& String::operator+= (const String &rhs)
   {
     size_t length = size() + rhs.size();
     char *_newData = new char[length + 1];
     strcpy(_newData, _data);
     strcat(_newData, rhs.c_str());
     delete[] _data;
     _data = NULL;
     _data = _newData;
     return *this;
   }

inline bool String::operator== (const String& rhs)
{
  if (size() != rhs.size())
    return false;

  if (strcmp(_data, rhs.c_str()) == 0)
    return true;

  return false;
}

inline char& String::operator[] (int n) const
{
  if (n >= size())
    return _data[size()];
  else
    return _data[n];
}

istream& operator>> (istream &is, String &rhs)
{
  char temp[1000];
  is >> temp;
  delete[] rhs._data;
  rhs._data = NULL;
  rhs._data = new char[strlen(temp) + 1];
  strcpy(rhs._data, temp);
  return is;
}

ostream& operator<< (ostream& os, const String &rhs)
{
  os << rhs._data;
  return os;
}
