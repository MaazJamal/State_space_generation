#ifndef __FIRE_ALARM__HPP__
#define __FIRE_ALARM__HPP__
//STATE DEFINITIONS

#define ALARM_ON 0
#define ALARM_OFF 1
#define SWITCH_ON 2
#define SWITCH_OFF 3
 

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

struct fire_alarm_defs {
    struct alarm_out : public out_port<string> { };
    struct smoke_out : public in_port<string> { };
};



        template <typename TIME>
class fire_alarm
{
  using defs = fire_alarm_defs; // putting definitions in context
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
  fire_alarm() noexcept
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

    using input_ports = std::tuple<typename defs::smoke_out>;
    using output_ports = std::tuple<typename defs::alarm_out>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case SWITCH_ON:
        this->state.state = ALARM_ON;
        this->out_port = "alarm_out";
        this->out = "on";
        this->ta = inf;
        break;
    case SWITCH_OFF:
        this->state.state = ALARM_OFF;
        this->out_port = "alarm_out";
        this->out = "off";
        this->ta = inf;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::smoke_out>(mbs))
    {

      this->in_port = "smoke_out";
      this->in = x;
    }
    if(this->in_port == "smoke_out") {
        if(this->in == "sch"){
            switch (this->state.state) {
                case ALARM_OFF:
                this->state.state = SWITCH_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "scl"){
            switch (this->state.state) {
                case ALARM_ON:
                this->state.state = SWITCH_OFF;
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
    if (this->out_port == "alarm_out")
    {
      get_messages<typename defs::alarm_out>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename fire_alarm<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif