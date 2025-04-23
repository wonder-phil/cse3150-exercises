#include <iostream>
#include <cstring>
#include <string>

#define STR_LEN 10

using namespace std;




struct Sub_struct {
  int cost;
  char * name = NULL;
  Sub_struct(int _cost, char * _name) : cost(_cost) {
    name = new char[STR_LEN];
    strcpy(name, _name);
  };
  
  ~Sub_struct() {
    if (name != NULL) {
      delete [] name;
    }
  };    
};


struct My_struct {
  int units;
  Sub_struct * s_struct;
  My_struct(int _units, Sub_struct * ss) : units(_units), s_struct(ss) {};
  ~My_struct() {
    delete s_struct;
  };  
};

ostream & operator<<(ostream& os, const Sub_struct & s_s_e)
{
  os << s_s_e.name << " cost of "  << s_s_e.cost;
  return os;
}

ostream & operator<<(ostream& os, const My_struct & my_s)
{
  os << "Units: " << my_s.units << " " << *my_s.s_struct;
  return os;
}

int main() {
  char * stuff = new char[20];
  strcpy(stuff,"<C++ compiler>");
  Sub_struct * s_s = new Sub_struct(5,stuff);
  My_struct * m_s = new My_struct(11, s_s);

  cout << *m_s << endl;

  //delete m_s->s_struct;
  delete m_s;

  delete [] stuff;
}