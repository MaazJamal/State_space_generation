#ifndef __ROOM_TEMPERATURE__HPP__
#define __ROOM_TEMPERATURE__HPP__
//STATE DEFINITIONS

#define COLD_OFF 0
#define COOL_OFF 1
#define WARM_OFF 2
#define HOT_OFF 3
#define VERYHOT_OFF 4
#define COLD_ON 5
#define COOL_ON 6
#define WARM_ON 7
#define HOT_ON 8
#define VERYHOT_ON 9
 

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

struct room_temperature_defs {
    struct room_out : public out_port<string> { };
    struct ac_out : public in_port<string> { };
};



        template <typename TIME>
class room_temperature
{
  using defs = room_temperature_defs; // putting definitions in context
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
  room_temperature() noexcept
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

    using input_ports = std::tuple<typename defs::ac_out>;
    using output_ports = std::tuple<typename defs::room_out>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case COOL_OFF:
        this->state.state = COLD_OFF;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case WARM_OFF:
        this->state.state = COLD_OFF;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case HOT_OFF:
        this->state.state = COLD_OFF;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case VERYHOT_OFF:
        this->state.state = COLD_OFF;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case COLD_OFF:
        this->state.state = COOL_OFF;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case WARM_OFF:
        this->state.state = COOL_OFF;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case HOT_OFF:
        this->state.state = COOL_OFF;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case VERYHOT_OFF:
        this->state.state = COOL_OFF;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case COLD_OFF:
        this->state.state = WARM_OFF;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case COOL_OFF:
        this->state.state = WARM_OFF;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case HOT_OFF:
        this->state.state = WARM_OFF;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case VERYHOT_OFF:
        this->state.state = WARM_OFF;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case COLD_OFF:
        this->state.state = HOT_OFF;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case COOL_OFF:
        this->state.state = HOT_OFF;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case WARM_OFF:
        this->state.state = HOT_OFF;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case VERYHOT_OFF:
        this->state.state = HOT_OFF;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case COLD_OFF:
        this->state.state = VERYHOT_OFF;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case COOL_OFF:
        this->state.state = VERYHOT_OFF;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case WARM_OFF:
        this->state.state = VERYHOT_OFF;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case HOT_OFF:
        this->state.state = VERYHOT_OFF;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case COOL_ON:
        this->state.state = COLD_ON;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case WARM_ON:
        this->state.state = COLD_ON;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case HOT_ON:
        this->state.state = COLD_ON;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case VERYHOT_ON:
        this->state.state = COLD_ON;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case COLD_ON:
        this->state.state = COOL_ON;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case WARM_ON:
        this->state.state = COOL_ON;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case HOT_ON:
        this->state.state = COOL_ON;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case VERYHOT_ON:
        this->state.state = COOL_ON;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case COLD_ON:
        this->state.state = WARM_ON;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case COOL_ON:
        this->state.state = WARM_ON;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case HOT_ON:
        this->state.state = WARM_ON;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case VERYHOT_ON:
        this->state.state = WARM_ON;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case COLD_ON:
        this->state.state = HOT_ON;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case COOL_ON:
        this->state.state = HOT_ON;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case WARM_ON:
        this->state.state = HOT_ON;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case VERYHOT_ON:
        this->state.state = HOT_ON;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case COLD_ON:
        this->state.state = VERYHOT_ON;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case COOL_ON:
        this->state.state = VERYHOT_ON;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case WARM_ON:
        this->state.state = VERYHOT_ON;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case HOT_ON:
        this->state.state = VERYHOT_ON;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::ac_out>(mbs))
    {

      this->in_port = "ac_out";
      this->in = x;
    }
    if(this->in_port == "ac_out") {
        if(this->in == "off"){
            switch (this->state.state) {
                case COLD_ON:
                this->state.state = COLD_OFF;
                this->ta = fin;
                break;
                case COOL_ON:
                this->state.state = COOL_OFF;
                this->ta = fin;
                break;
                case WARM_ON:
                this->state.state = WARM_OFF;
                this->ta = fin;
                break;
                case HOT_ON:
                this->state.state = HOT_OFF;
                this->ta = fin;
                break;
                case VERYHOT_ON:
                this->state.state = VERYHOT_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "on"){
            switch (this->state.state) {
                case COLD_OFF:
                this->state.state = COLD_ON;
                this->ta = fin;
                break;
                case COOL_OFF:
                this->state.state = COOL_ON;
                this->ta = fin;
                break;
                case WARM_OFF:
                this->state.state = WARM_ON;
                this->ta = fin;
                break;
                case HOT_OFF:
                this->state.state = HOT_ON;
                this->ta = fin;
                break;
                case VERYHOT_OFF:
                this->state.state = VERYHOT_ON;
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
    if (this->out_port == "room_out")
    {
      get_messages<typename defs::room_out>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename room_temperature<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif