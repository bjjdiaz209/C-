#include <iostream>
#include <vector>
#include <string_view>
#include <variant>
#include <string>
#include <map>
#include <memory>


using namespace std;

constexpr string_view OPEN = "<";
constexpr string_view CLOSE = ">";
constexpr string_view SLASH = "/";
constexpr string_view OPEN_COMMENT = "<!-- ";

constexpr string_view CLOSE_COMMENT = " -->";
constexpr string_view EQUAL = "=";

constexpr string_view TAB = "\t";
constexpr string_view QUOTE = "\"";


constexpr string_view END_L = "\n";

class text
{
private:
  string name;
public:
  text(const string_view& name)
  :name{name}
  {}

  void serialize(string& text)const
  {
      text += name;
  }
  ~text() { }
};

class comment
{
private:
  string name;
public:
  comment(const string_view& name)
  :name{name}
  {}

  void serialize(string& comment )const
  {
      comment += OPEN_COMMENT;
      comment += name;
      comment += CLOSE_COMMENT;
  }
  ~comment() { }
};
class element;
using node = variant<shared_ptr<element>, shared_ptr<text>, shared_ptr<comment>>;

class element
{
    private:
  string name;
  vector<node> children;
  map<string, string> atributes;

  public:
  element(const string_view& name);
  
  void set_attribute (const string &key, const string &value);
  
  template<typename T>
  void append_child(const T& value)
  {
      children.push_back(value);
  }

  void serialize(string& str) const;
};

void serialize_children(string& str, const vector<node>& children)
{

for(auto& x: children)

{

visit(


[&str](auto& e){e->serialize(str);},

x

);


}

}
    


void serialize_element(string& str, const string& name, const vector<node>& children,

const map<string, string>& atributes)
{
    str += OPEN;
    str += name;
    for(auto& e: atributes){
    str += " ";
    str += e.first;
    str += EQUAL;
    str += QUOTE;
    str += e.second;
    str += QUOTE;
}
   if(children.size())
   {
     str += CLOSE;
     serialize_children(str, children);

    str+=OPEN;
    str+=SLASH;
    str+=name;
    str+=CLOSE;

   }
   else
  {
    str+=" ";
    str+=SLASH;
    str+=CLOSE;
  }

}
element::element(const string_view& name):name{name}

{

}

void element::set_attribute (const string &key, const string &value)
{
atributes.insert(make_pair(key, value));
}
void element::serialize(string& str) const
{
serialize_element(str, name, children, atributes);
}


class document
{
    string name;
    vector<node>children;

    public:
     document(const string_view& name)
     :name{name}
     
     {
        
     }

shared_ptr<element> create_element (const string_view& name) const
  {
return make_shared<element>(name);

    
  }
  template<typename T>
  void append_child(const T& ele)
  {
    children.push_back(ele);
    
  }
  shared_ptr<comment> create_comment(const string_view& com) const
  {
    return make_shared<comment>(com);
  }

  shared_ptr<text> create_text(const string_view& tex) const
  {
    return make_shared<text>(tex);

  }

  string serialize() const 
  {
    string str;
    str += OPEN;
    str += name;
    if(children.size())
    {
      str += CLOSE;
      //serialize_children(str);
      str+=OPEN;
      str+=SLASH;
      str+=name;
      str+=CLOSE;
    }
    else{
      str+=" ";
      str+=SLASH;
      str+=CLOSE;
    }
  
    return str;
  }
  private:
};

class xml_writer
{
    public:
    document create_document(const string_view document_name)
    {
      return document{document_name};   
    }
    
};

ostream& operator<<(ostream& os, const document& ws)
{
  return os << ws.serialize();
}

auto main() -> int
{
  xml_writer ws;

  auto doc = ws.create_document("students");

  auto e1 = doc.create_element("student");
  e1->set_attribute("name", "Juan Perez");
  e1->set_attribute("age", "22");
  e1->set_attribute("id", "2193281");

  auto e2 = doc.create_element("student");
  e2->set_attribute("name", "Jorge Lopez");
  e2->set_attribute("age", "25");
  e2->set_attribute("id", "12312312");

  doc.append_child(e1);
  doc.append_child(e2);

  auto c = doc.create_comment("This is a comment");
  doc.append_child(c);

  auto e3 = doc.create_element("info");
  doc.append_child(e3);

  auto text = doc.create_text("This is a text");
  e3->append_child(text);

  cout << doc << "\n";

  /*

  //Sin herencia, sin polimorfismo, sin raw pointers

  <? xml version="1.0" ?>
  <students>
    <student name="Juan Perez" age="22" id="2193281" />
    <student name="Jorge Lopez" age="25" id="12312312" />
    <!-- This is a comment -->
    <info>
      This is a text
    </info>
  </students>

  */
}