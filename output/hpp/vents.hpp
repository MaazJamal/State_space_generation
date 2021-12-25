#ifndef __VENTS__HPP__
#define __VENTS__HPP__
//STATE DEFINITIONS

#define SHUT 0
#define CLOSING 1
#define OPENING 2
#define FULL_OPEN 3
 

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

struct vents_defs {
    struct vents_out : public out_port<string> { };
    struct vents_in : public in_port<string> { };
};



        template <typename TIME>
class vents
{
  using defs = vents_defs; // putting definitions in context
public:
  //Parameters to be overwriten when instantiating the atomic model
  bool fin;
  bool inf;
  bool ta;
  string out_port;
  string out;
  string in;
  string in_port;
  bool increment;

  // default constructor
  vents() noexcept
  {
    fin = true;
    inf = false;
    ta = fin;
    out_port = "";
    out = "";
    in = "";
    in_port = "";
    this->state.state = 0;
    increment = true;
  } 
  
    // state definition
  struct state_type
  {
    int state;
  };
  
  //port deifinitions

    using input_ports = std::tuple<typename defs::vents_in>;
    using output_ports = std::tuple<typename defs::vents_out>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case OPENING:
        this->state.state = FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = inf;
        break;
    case CLOSING:
        this->state.state = SHUT;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = inf;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::vents_in>(mbs))
    {

      this->in_port = "vents_in";
      this->in = x;
    }
    if(this->in_port == "vents_in") {
        if(this->in == "on"){
            switch (this->state.state) {
                case SHUT:
                this->state.state = OPENING;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case FULL_OPEN:
                this->state.state = CLOSING;
                this->ta = fin;
                break;
            }
        }
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
    if (this->out_port == "vents_out")
    {
      get_messages<typename defs::vents_out>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename vents<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif