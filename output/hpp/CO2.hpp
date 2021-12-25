#ifndef __CO2__HPP__
#define __CO2__HPP__
//STATE DEFINITIONS

#define CO2_LOW_OPEN_VENTS_SHUT 0
#define CO2_MEDIUM_OPEN_VENTS_SHUT 1
#define CO2_LOW_OPEN_VENTS_CLOSING 2
#define CO2_MEDIUM_OPEN_VENTS_CLOSING 3
#define CO2_LOW_OPEN_VENTS_OPENING 4
#define CO2_MEDIUM_OPEN_VENTS_OPENING 5
#define CO2_MEDIUM_OPEN_VENTS_FULL_OPEN 6
#define CO2_HIGH_OPEN_VENTS_SHUT 7
#define CO2_HIGH_OPEN_VENTS_OPENING 8
#define CO2_HIGH_OPEN_VENTS_FULL_OPEN 9
#define CO2_LOW_CLOSED_VENTS_SHUT 10
#define CO2_MEDIUM_CLOSED_VENTS_SHUT 11
#define CO2_LOW_CLOSED_VENTS_CLOSING 12
#define CO2_MEDIUM_CLOSED_VENTS_CLOSING 13
#define CO2_MEDIUM_CLOSED_VENTS_OPENING 14
#define CO2_LOW_CLOSED_VENTS_FULL_OPEN 15
#define CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN 16
#define CO2_HIGH_CLOSED_VENTS_CLOSING 17
#define CO2_HIGH_CLOSED_VENTS_OPENING 18
#define CO2_HIGH_CLOSED_VENTS_FULL_OPEN 19
 

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

struct CO2_defs {
    struct vents_out : public out_port<string> { };
    struct vents_in : public out_port<string> { };
    struct vents_in : public out_port<string> { };
    struct vents_out : public in_port<string> { };
    struct co2_out : public in_port<string> { };
    struct co2_out : public in_port<string> { };
    struct vents_out : public in_port<string> { };
};



        template <typename TIME>
class CO2
{
  using defs = CO2_defs; // putting definitions in context
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
  CO2() noexcept
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

    using input_ports = std::tuple<typename defs::vents_out,typename defs::co2_out,typename defs::co2_out,typename defs::vents_out>;
    using output_ports = std::tuple<typename defs::vents_out,typename defs::vents_in,typename defs::vents_in>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case CO2_LOW_OPEN_VENTS_SHUT:
        this->state.state = CO2_LOW_OPEN_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "on";
        this->ta = fin;
        break;
    case CO2_MEDIUM_OPEN_VENTS_SHUT:
        this->state.state = CO2_MEDIUM_OPEN_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "on";
        this->ta = fin;
        break;
    case CO2_HIGH_OPEN_VENTS_SHUT:
        this->state.state = CO2_HIGH_OPEN_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "on";
        this->ta = fin;
        break;
    case CO2_LOW_CLOSED_VENTS_SHUT:
        this->state.state = CO2_LOW_CLOSED_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "on";
        this->ta = fin;
        break;
    case CO2_MEDIUM_CLOSED_VENTS_SHUT:
        this->state.state = CO2_MEDIUM_CLOSED_VENTS_OPENING;
        this->out_port = "vents_in";
        this->out = "on";
        this->ta = fin;
        break;
    case CO2_MEDIUM_OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM_OPEN_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "off";
        this->ta = fin;
        break;
    case CO2_HIGH_OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH_OPEN_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "off";
        this->ta = fin;
        break;
    case CO2_LOW_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_LOW_CLOSED_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "off";
        this->ta = fin;
        break;
    case CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_MEDIUM_CLOSED_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "off";
        this->ta = fin;
        break;
    case CO2_HIGH_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH_CLOSED_VENTS_CLOSING;
        this->out_port = "vents_in";
        this->out = "off";
        this->ta = fin;
        break;
    case CO2_LOW_OPEN_VENTS_SHUT:
        this->state.state = CO2_LOW_CLOSED_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_HIGH_OPEN_VENTS_SHUT:
        this->state.state = CO2_HIGH_CLOSED_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_HIGH_OPEN_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH_CLOSED_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = fin;
        break;
    case CO2_LOW_CLOSED_VENTS_SHUT:
        this->state.state = CO2_LOW_OPEN_VENTS_SHUT;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_LOW_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_LOW_OPEN_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = fin;
        break;
    case CO2_HIGH_CLOSED_VENTS_FULL_OPEN:
        this->state.state = CO2_HIGH_OPEN_VENTS_FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = fin;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::vents_out>(mbs))
    {

      this->in_port = "vents_out";
      this->in = x;
    }
    if(this->in_port == "vents_out") {
        if(this->in == "venth"){
            switch (this->state.state) {
                case CO2_LOW_OPEN_VENTS_OPENING:
                this->state.state = CO2_LOW_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_MEDIUM_OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_HIGH_OPEN_VENTS_OPENING:
                this->state.state = CO2_HIGH_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_HIGH_CLOSED_VENTS_OPENING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_LOW_OPEN_VENTS_OPENING:
                this->state.state = CO2_LOW_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_MEDIUM_OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_HIGH_OPEN_VENTS_OPENING:
                this->state.state = CO2_HIGH_OPEN_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
                case CO2_HIGH_CLOSED_VENTS_OPENING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_FULL_OPEN;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "ventl"){
            switch (this->state.state) {
                case CO2_LOW_OPEN_VENTS_CLOSING:
                this->state.state = CO2_LOW_OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_MEDIUM_OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_LOW_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_LOW_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_HIGH_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_LOW_OPEN_VENTS_CLOSING:
                this->state.state = CO2_LOW_OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_MEDIUM_OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_LOW_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_LOW_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
                case CO2_HIGH_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_SHUT;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "co2_out") {
        if(this->in == "co2m"){
            switch (this->state.state) {
                case CO2_LOW_OPEN_VENTS_SHUT:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_LOW_OPEN_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_LOW_OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH_OPEN_VENTS_SHUT:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_HIGH_OPEN_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH_OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM_OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_LOW_CLOSED_VENTS_SHUT:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_LOW_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_LOW_CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_HIGH_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_HIGH_CLOSED_VENTS_OPENING:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_HIGH_CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "co2h"){
            switch (this->state.state) {
                case CO2_MEDIUM_OPEN_VENTS_SHUT:
                this->state.state = CO2_HIGH_OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_CLOSING:
                this->state.state = CO2_HIGH_OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_OPENING:
                this->state.state = CO2_HIGH_OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_HIGH_OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_SHUT:
                this->state.state = CO2_HIGH_CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_OPENING:
                this->state.state = CO2_HIGH_CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_HIGH_CLOSED_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "co2l"){
            switch (this->state.state) {
                case CO2_MEDIUM_OPEN_VENTS_SHUT:
                this->state.state = CO2_LOW_OPEN_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_CLOSING:
                this->state.state = CO2_LOW_OPEN_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_OPENING:
                this->state.state = CO2_LOW_OPEN_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_OPEN_VENTS_FULL_OPEN:
                this->state.state = CO2_LOW_OPEN_VENTS_FULL_OPEN;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_SHUT:
                this->state.state = CO2_LOW_CLOSED_VENTS_SHUT;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_CLOSING:
                this->state.state = CO2_LOW_CLOSED_VENTS_CLOSING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_OPENING:
                this->state.state = CO2_LOW_CLOSED_VENTS_OPENING;
                this->ta = fin;
                break;
                case CO2_MEDIUM_CLOSED_VENTS_FULL_OPEN:
                this->state.state = CO2_LOW_CLOSED_VENTS_FULL_OPEN;
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename CO2<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif