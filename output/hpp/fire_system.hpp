#ifndef __FIRE_SYSTEM__HPP__
#define __FIRE_SYSTEM__HPP__
//STATE DEFINITIONS

#define SMOKE_SMOKE_OFF_ALARM_ALARM_ON 0
#define SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF 1
#define SMOKE_SMOKE_OFF_ALARM_ALARM_OFF 2
#define SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON 3
#define SMOKE_SMOKE_OFF_ALARM_SWITCH_ON 4
#define SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF 5
#define SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF 6
#define SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON 7
#define SMOKE_SMOKE_ON_ALARM_ALARM_ON 8
#define SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF 9
#define SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON 10
#define SMOKE_SMOKE_ON_ALARM_SWITCH_ON 11
#define SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF 12
#define SMOKE_SMOKE_ON_ALARM_SWITCH_OFF 13
 

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

struct fire_system_defs {
    struct alarm_in : public out_port<string> { };
    struct alarm_out : public out_port<string> { };
    struct alarm : public out_port<string> { };
    struct alarm_out : public in_port<string> { };
    struct smoke_out : public in_port<string> { };
    struct smoke : public in_port<string> { };
    struct alarm_out : public in_port<string> { };
};



        template <typename TIME>
class fire_system
{
  using defs = fire_system_defs; // putting definitions in context
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
  fire_system() noexcept
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

    using input_ports = std::tuple<typename defs::alarm_out,typename defs::smoke_out,typename defs::smoke,typename defs::alarm_out>;
    using output_ports = std::tuple<typename defs::alarm_in,typename defs::alarm_out,typename defs::alarm>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF:
        this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON;
        this->out_port = "alarm_in";
        this->out = "h";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_OFF_ALARM_ALARM_OFF:
        this->state.state = SMOKE_SMOKE_OFF_ALARM_SWITCH_ON;
        this->out_port = "alarm_in";
        this->out = "h";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF:
        this->state.state = SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON;
        this->out_port = "alarm_in";
        this->out = "h";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_OFF_ALARM_ALARM_ON:
        this->state.state = SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF;
        this->out_port = "alarm_in";
        this->out = "l";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON:
        this->state.state = SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF;
        this->out_port = "alarm_in";
        this->out = "l";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_ON_ALARM_ALARM_ON:
        this->state.state = SMOKE_SMOKE_ON_ALARM_SWITCH_OFF;
        this->out_port = "alarm_in";
        this->out = "l";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF:
        this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF;
        this->out_port = "alarm_out";
        this->out = "on";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON:
        this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_ON;
        this->out_port = "alarm_out";
        this->out = "off";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF:
        this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF;
        this->out_port = "alarm_out";
        this->out = "off";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_ON_ALARM_ALARM_ON:
        this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_ON;
        this->out_port = "alarm_out";
        this->out = "off";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_OFF_ALARM_ALARM_ON:
        this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_ON;
        this->out_port = "alarm_out";
        this->out = "on";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_OFF_ALARM_ALARM_OFF:
        this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_OFF;
        this->out_port = "alarm_out";
        this->out = "on";
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
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "smoke_out") {
        if(this->in == "sch"){
            switch (this->state.state) {
                case SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_SWITCH_ON;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_ON_ALARM_SWITCH_ON;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_ON_ALARM_SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "scl"){
            switch (this->state.state) {
                case SMOKE_SMOKE_OFF_ALARM_ALARM_ON:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_OFF_ALARM_ALARM_OFF:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_ON_ALARM_ALARM_ON:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "smoke") {
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
    if (this->out_port == "alarm_in")
    {
      get_messages<typename defs::alarm_in>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename fire_system<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif