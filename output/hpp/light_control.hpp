#ifndef __LIGHT_CONTROL__HPP__
#define __LIGHT_CONTROL__HPP__
//STATE DEFINITIONS

#define OCC_OC_OFF_LIGHT_ON 0
#define OCC_NOC_OFF_LIGHT_OFF 1
#define OCC_OC_OFF_LIGHT_OFF 2
#define OCC_NOC_OFF_LIGHT_SWITCH_ON 3
#define OCC_OC_OFF_LIGHT_SWITCH_ON 4
#define OCC_NOC_OFF_LIGHT_SWITCH_OFF 5
#define OCC_OC_OFF_LIGHT_SWITCH_OFF 6
#define OCC_NOC_ON_LIGHT_ON 7
#define OCC_OC_ON_LIGHT_ON 8
#define OCC_NOC_ON_LIGHT_OFF 9
#define OCC_NOC_ON_LIGHT_SWITCH_ON 10
#define OCC_OC_ON_LIGHT_SWITCH_ON 11
#define OCC_NOC_ON_LIGHT_SWITCH_OFF 12
#define OCC_OC_ON_LIGHT_SWITCH_OFF 13
 

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

struct light_control_defs {
    struct light_in : public out_port<string> { };
    struct light_out : public out_port<string> { };
    struct light_s : public out_port<string> { };
    struct light_out : public in_port<string> { };
    struct occ_out : public in_port<string> { };
    struct occ : public in_port<string> { };
    struct light_out : public in_port<string> { };
};



        template <typename TIME>
class light_control
{
  using defs = light_control_defs; // putting definitions in context
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
  light_control() noexcept
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

    using input_ports = std::tuple<typename defs::light_out,typename defs::occ_out,typename defs::occ,typename defs::light_out>;
    using output_ports = std::tuple<typename defs::light_in,typename defs::light_out,typename defs::light_s>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case OCC_OC_OFF_LIGHT_OFF:
        this->state.state = OCC_OC_OFF_LIGHT_SWITCH_ON;
        this->out_port = "light_in";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_NOC_ON_LIGHT_OFF:
        this->state.state = OCC_NOC_ON_LIGHT_SWITCH_ON;
        this->out_port = "light_in";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_NOC_OFF_LIGHT_OFF:
        this->state.state = OCC_NOC_OFF_LIGHT_SWITCH_ON;
        this->out_port = "light_in";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_OC_ON_LIGHT_ON:
        this->state.state = OCC_OC_ON_LIGHT_SWITCH_OFF;
        this->out_port = "light_in";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_OC_OFF_LIGHT_ON:
        this->state.state = OCC_OC_OFF_LIGHT_SWITCH_OFF;
        this->out_port = "light_in";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_NOC_ON_LIGHT_ON:
        this->state.state = OCC_NOC_ON_LIGHT_SWITCH_OFF;
        this->out_port = "light_in";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_OC_ON_LIGHT_ON:
        this->state.state = OCC_OC_OFF_LIGHT_ON;
        this->out_port = "light_out";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_OC_OFF_LIGHT_ON:
        this->state.state = OCC_OC_ON_LIGHT_ON;
        this->out_port = "light_out";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_OC_OFF_LIGHT_OFF:
        this->state.state = OCC_OC_ON_LIGHT_OFF;
        this->out_port = "light_out";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_NOC_ON_LIGHT_ON:
        this->state.state = OCC_NOC_OFF_LIGHT_ON;
        this->out_port = "light_out";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_NOC_ON_LIGHT_OFF:
        this->state.state = OCC_NOC_OFF_LIGHT_OFF;
        this->out_port = "light_out";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_NOC_OFF_LIGHT_OFF:
        this->state.state = OCC_NOC_ON_LIGHT_OFF;
        this->out_port = "light_out";
        this->out = "on";
        this->ta = fin;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::light_out>(mbs))
    {

      this->in_port = "light_out";
      this->in = x;
    }
    if(this->in_port == "light_out") {
        if(this->in == "on"){
            switch (this->state.state) {
                case OCC_OC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_ON_LIGHT_ON;
                this->ta = inf;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_OFF_LIGHT_ON;
                this->ta = inf;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_ON_LIGHT_ON;
                this->ta = inf;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_OFF_LIGHT_ON;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case OCC_OC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_ON_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_OFF_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_ON_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_OFF_LIGHT_OFF;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "occ_out") {
        if(this->in == "och"){
            switch (this->state.state) {
                case OCC_NOC_OFF_LIGHT_OFF:
                this->state.state = OCC_OC_OFF_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_OFF_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_OFF_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_ON:
                this->state.state = OCC_OC_ON_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_OFF:
                this->state.state = OCC_OC_ON_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_ON_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_ON_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_OFF_LIGHT_OFF:
                this->state.state = OCC_OC_OFF_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_OFF_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_OFF_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_ON:
                this->state.state = OCC_OC_ON_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_OFF:
                this->state.state = OCC_OC_ON_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_ON_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_ON_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "ocl"){
            switch (this->state.state) {
                case OCC_OC_ON_LIGHT_ON:
                this->state.state = OCC_NOC_ON_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_OC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_ON_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_OC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_ON_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_ON:
                this->state.state = OCC_NOC_OFF_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_OFF:
                this->state.state = OCC_NOC_OFF_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_OFF_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_OFF_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
                case OCC_OC_ON_LIGHT_ON:
                this->state.state = OCC_NOC_ON_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_OC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_ON_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_OC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_ON_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_ON:
                this->state.state = OCC_NOC_OFF_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_OFF:
                this->state.state = OCC_NOC_OFF_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_OFF_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_OFF_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "occ") {
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
    if (this->out_port == "light_in")
    {
      get_messages<typename defs::light_in>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename light_control<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif