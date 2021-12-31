#ifndef __OCCUP__HPP__
#define __OCCUP__HPP__
//STATE DEFINITIONS

#define OCCUPENCY_OFF 0
#define OCCUPENCY_ON 1
 

#include <cadmium/modeling/ports.hpp>
#include <cadmium/modeling/message_bag.hpp>
#include <limits>
#include <math.h>
#include <assert.h>
#include <memory>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <limits>
#include <random>

using namespace cadmium;
using namespace std;

#ifdef RT_ARM_MBED

#include "../mbed-os/mbed.h"
#include <cadmium/real_time/arm_mbed/embedded_error.hpp>

using namespace mbed;
#endif 


 //PORTS 

struct occup_defs {
    struct occ_out : public out_port<string> { };
    struct x : public in_port<string> { };
};



        template <typename TIME>
class occup
{
  using defs = occup_defs; // putting definitions in context
public:
  //Parameters to be overwriten when instantiating the atomic model
  bool fin;
  bool inf;
  bool ta;
  string out_port;
  string out;
  string in;
  string in_port;

  // default constructor
  occup() noexcept
  {
    fin = true;
    inf = false;
    ta = fin;
    out_port = "";
    out = "";
    in = "";
    in_port = "";
    this->state.state = 0;
  } 
  
    // state definition
  struct state_type
  {
    int state;
  } state;
  
  //port deifinitions

    using input_ports = std::tuple<typename defs::x>;
    using output_ports = std::tuple<typename defs::occ_out>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case OCCUPENCY_ON:
        this->state.state = OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case OCCUPENCY_OFF:
        this->state.state = OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::x>(mbs))
    {

      this->in_port = "x";
      this->in = x;
    }
    if(this->in_port == "x") {
    }
}
 // confluence transition
  void confluence_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    internal_transition();
    external_transition(TIME(), std::move(mbs));
  }

  // output function
  typename make_message_bags<output_ports>::type output() const
  {
    typename make_message_bags<output_ports>::type bags;
    if (this->out_port == "occ_out")
    {
      get_messages<typename defs::occ_out>(bags).push_back(out);
    }
    return bags;
  }

  // time_advance function
  TIME time_advance() const
  {
    if (ta)
    {
      return TIME("00:00:00:500");
    }
    else
    {
      return numeric_limits<TIME>::infinity();
    }
  }

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename occup<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif