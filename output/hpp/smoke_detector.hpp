#ifndef __SMOKE_DETECTOR__HPP__
#define __SMOKE_DETECTOR__HPP__
//STATE DEFINITIONS

#define NO_SMOKE_OFF 0
#define SMOKE_OFF 1
#define NO_SMOKE_ON 2
#define SMOKE_ON 3
 

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

struct smoke_detector_defs {
    struct smoke_out : public out_port<string> { };
    struct alarm_out : public in_port<string> { };
};



        template <typename TIME>
class smoke_detector
{
  using defs = smoke_detector_defs; // putting definitions in context
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
  smoke_detector() noexcept
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

    using input_ports = std::tuple<typename defs::alarm_out>;
    using output_ports = std::tuple<typename defs::smoke_out>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case NO_SMOKE_OFF:
        this->state.state = SMOKE_OFF;
        this->out_port = "smoke_out";
        this->out = "sch";
        this->ta = fin;
        break;
    case SMOKE_OFF:
        this->state.state = NO_SMOKE_OFF;
        this->out_port = "smoke_out";
        this->out = "scl";
        this->ta = fin;
        break;
    case NO_SMOKE_ON:
        this->state.state = SMOKE_ON;
        this->out_port = "smoke_out";
        this->out = "sch";
        this->ta = fin;
        break;
    case SMOKE_ON:
        this->state.state = NO_SMOKE_ON;
        this->out_port = "smoke_out";
        this->out = "scl";
        this->ta = fin;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::alarm_out>(mbs))
    {

      this->in_port = "alarm_out";
      this->in = x;
    }
    if(this->in_port == "alarm_out") {
        if(this->in == "on"){
            switch (this->state.state) {
                case NO_SMOKE_OFF:
                this->state.state = NO_SMOKE_ON;
                this->ta = fin;
                break;
                case SMOKE_OFF:
                this->state.state = SMOKE_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case NO_SMOKE_ON:
                this->state.state = NO_SMOKE_OFF;
                this->ta = fin;
                break;
                case SMOKE_ON:
                this->state.state = SMOKE_OFF;
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
    if (this->out_port == "smoke_out")
    {
      get_messages<typename defs::smoke_out>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename smoke_detector<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif