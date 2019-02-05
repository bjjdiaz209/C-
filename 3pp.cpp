#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdexcept>
#include <sstream>
#include <typeinfo>
#include <memory>


using namespace std;
class json
{
public:
  // virtual json();
  virtual ~json(){}
  virtual  string to_string(){}
};

class json_null : public json
{
    string null;
    public:
  json_null()
  :null{"null"}
  {}
  ~json_null()
  {}
   string to_string() override
  {
    return null;
  }
};

class json_number:public json
{
int number;
public:
  json_number(int src)
  :number{src}
  {}
  ~json_number()
  {
  }
  string to_string() override
  {
    return std::to_string(number);
  }
};
class json_bool: public json
{
  bool bol;
  public:
  json_bool(bool src)
  : bol{src}
  {}
  ~json_bool()
  {}
  string to_string()  override
  {
    if(bol)
    return "true";
    else return "false";
  }
};

class json_string: public json
{
  string chain;
  bool tochar = false;
public:
  json_string(const char* src)
  :chain{string{src}}
  {}

  ~json_string()
  {
  }
  string to_string()override
  {
    std::stringstream entry;
    entry<< "\""s;
    for (size_t i = 0; i < chain.length(); i++)
    {
      if(chain[i] == '"')
      {
        entry<< "\\"s;
      }
      entry<<chain[i];
    }

    entry<< "\""s;
    return  entry.str();

  }
};

class json_object: public json
{
  string object;
  std::stringstream array;
public:
  json_object()
  :object{"{"}
  {}
  ~json_object()
  {}

  string to_string() override
  {

    if(object == "{")
    {
      return object+= " }";
    }
    else
    {
      object.erase(object.length() -2);
      return object+= " }"s;
    }
  }
  template <typename a, typename b>
  void add(const a& src1 , const b& src2)
  {
    bool flag = false;
    if(typeid(src2).name() == "i"s)
    {
      flag = true;
    }

    if(object =="{")
    {
      array<<object;
      array<< " "s;
      array<< "\""s ;
      array<< src1;
      array<< "\""s;
      array<< " : "s;
      if(flag == true)
      {
        array <<src2;
      }
      else
      {
        array<< "\""s ;
        array<< src2;
        array<< "\""s ;
      }
      array<< ", "s;
      object = array.str();
    }
    else
    {
      array<< "\""s ;
      array<< src1;
      array<< "\""s;
      array<< " : "s;
      if(flag == true)
      {
        array <<src2;
      }
      else
      {
        array<< "\""s ;
        array<< src2;
        array<< "\""s ;
      }
      array<< ", "s;
      object = array.str();
    }

  }
  template<typename obj>
  void add(const obj& ob)
  {

  }
};

class json_array: public json
{
  std::stringstream array;

public:
  json_array()
  // :array{"[ "}
  {
    array<<"["s;
  }
  ~json_array()
  {}
  template <typename TIPO>
  void add(const TIPO& src)
  {
    if(typeid(src).name() == "b"s)
    {
      array<< "true"s;
    }
    else if(typeid(src).name() == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE"s)
    {
      array<<"\"";
      array<<src;
      array<<"\"";
    }
    else
    {
      array<<src;
    }
    array<< ", "s;
  }
  json_array& add( json_object& job)
  {
    array<< job.to_string();
    array<< ", "s;
    return *this;
  }

  string to_string() override
  {
    string aux = array.str();
    aux.erase(aux.length() -2);
    aux += "]"s;
    return aux;
  }
};




bool test0()
{
    json_null j;
    return j.to_string() == "null";
}

bool test1()
{
    json_number j { 125 };
    return j.to_string() == "125";
}

bool test2()
{
    json_bool j { true };
    json_bool k { false };
    return j.to_string() == "true" && k.to_string() == "false";
}

bool test3()
{
    json_string j { "hello world" };
    return j.to_string() == "\"hello world\"";
}

bool test4()
{
    json_string j = "my name is \"Michael\"";
    return j.to_string() == "\"my name is \\\"Michael\\\"\"";
}

bool test5()
{
    json_object j;
    return j.to_string() == "{ }";
}

bool test6()
{
    json_array ja;
    ja.add(true);
    ja.add("hello world"s);
    ja.add(237);
    return ja.to_string() == "[true, \"hello world\", 237]";
}

bool test7()
{
    json_object jo;
    jo.add("first_name", "juan");
    jo.add("last_name", "perez");
    jo.add("birth_year", 1970);
    return jo.to_string() == "{ \"first_name\" : \"juan\", \"last_name\" : \"perez\", \"birth_year\" : 1970 }";
}

bool test8()
{
    json_array ja;

    json_object jo1;
    jo1.add("first_name", "juan");
    jo1.add("last_name", "perez");
    jo1.add("birth_year", 1970);

    json_object jo2;
    jo2.add("first_name", "omar");
    jo2.add("last_name", "vera");
    jo2.add("birth_year", 1995);

    ja.add(jo1).add(jo2);
    return ja.to_string() == "[{ \"first_name\" : \"juan\", \"last_name\" : \"perez\", \"birth_year\" : 1970 }, { \"first_name\" : \"omar\", \"last_name\" : \"vera\", \"birth_year\" : 1995 }]";
}
/*
bool test9()
{
    // json_object jo;
    // jo.add("marca", "volkswagen");
    // jo.add("modelos", json_array {}.add("jetta").add("new beetle").add("golf"));
    // jo.add("descripcion", json_object {}.add("pais", "alemania").add("produccion_anual", 50000));
    // return jo.to_string() == "{ \"marca\" : \"volkswagen\", \"modelos\" : [\"jetta\", \"new beetle\", \"golf\"], \"descripcion\" : { \"pais\" : \"alemania\", \"produccion_anual\" : 50000 } }";
    return false;
}
*/


int main()
{
    auto score = 0.0;

    score += 0.5 * static_cast<double>(test0());
    score += 0.5 * static_cast<double>(test1());
    score += 0.5 * static_cast<double>(test2());
    score += 0.5 * static_cast<double>(test3());
    score += 0.5 * static_cast<double>(test4());
    score += 0.5 * static_cast<double>(test5());
    score += 1.6 * static_cast<double>(test6());
    score += 1.7 * static_cast<double>(test7());
    score += 1.8 * static_cast<double>(test8());/*
    score += 1.9 * static_cast<double>(test9());*/

    cout << score * 10 << " / 100\n";

    return 0;
}