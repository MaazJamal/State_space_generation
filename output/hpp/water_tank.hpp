#ifndef __WATER_TANK__HPP__
#define __WATER_TANK__HPP__
//STATE DEFINITIONS

#define P_STOP_T_INIT 0
#define P_ON_T_INIT 1
#define P_STOP_T_HIGH_IN 2
#define P_ON_T_HIGH_IN 3
#define P_STOP_T_FILLED_IN 4
#define P_ON_T_FILLED_IN 5
#define P_STOP_T_LOW_IN 6
#define P_ON_T_LOW_IN 7
#define P_STOP_T_HIGH_OUT 8
#define P_ON_T_HIGH_OUT 9
#define P_STOP_T_FILLED_OUT 10
#define P_ON_T_FILLED_OUT 11
#define P_STOP_T_LOW_OUT 12
#define P_ON_T_LOW_OUT 13
#define P_PUMPING_T_INIT 14
#define P_OFF_T_INIT 15
#define P_PUMPING_T_HIGH_IN 16
#define P_OFF_T_HIGH_IN 17
#define P_PUMPING_T_FILLED_IN 18
#define P_OFF_T_FILLED_IN 19
#define P_PUMPING_T_LOW_IN 20
#define P_OFF_T_LOW_IN 21
#define P_PUMPING_T_HIGH_OUT 22
#define P_OFF_T_HIGH_OUT 23
#define P_PUMPING_T_FILLED_OUT 24
#define P_OFF_T_FILLED_OUT 25
#define P_PUMPING_T_LOW_OUT 26
#define P_OFF_T_LOW_OUT 27
 

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

struct water_tank_defs {
    struct pw : public out_port<string> { };
    struct w : public out_port<string> { };
    struct pw : public out_port<string> { };
    struct w : public in_port<string> { };
    struct ls : public in_port<string> { };
    struct hs : public in_port<string> { };
    struct e : public in_port<string> { };
    struct ls : public in_port<string> { };
    struct hs : public in_port<string> { };
    struct ls : public in_port<string> { };
    struct e : public in_port<string> { };
};



        template <typename TIME>
class water_tank
{
  using defs = water_tank_defs; // putting definitions in context
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
  water_tank() noexcept
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

    using input_ports = std::tuple<typename defs::w,typename defs::ls,typename defs::hs,typename defs::e,typename defs::ls,typename defs::hs,typename defs::ls,typename defs::e>;
    using output_ports = std::tuple<typename defs::pw,typename defs::w,typename defs::pw>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case P_STOP_T_INIT:
        this->state.state = P_ON_T_INIT;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_HIGH_IN:
        this->state.state = P_ON_T_HIGH_IN;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_FILLED_IN:
        this->state.state = P_ON_T_FILLED_IN;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_IN:
        this->state.state = P_ON_T_LOW_IN;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_HIGH_OUT:
        this->state.state = P_ON_T_HIGH_OUT;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_FILLED_OUT:
        this->state.state = P_ON_T_FILLED_OUT;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_OUT:
        this->state.state = P_ON_T_LOW_OUT;
        this->out_port = "pw";
        this->out = "on";
        this->ta = fin;
        break;
    case P_PUMPING_T_INIT:
        this->state.state = P_OFF_T_INIT;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_HIGH_IN:
        this->state.state = P_OFF_T_HIGH_IN;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_FILLED_IN:
        this->state.state = P_OFF_T_FILLED_IN;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_IN:
        this->state.state = P_OFF_T_LOW_IN;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_HIGH_OUT:
        this->state.state = P_OFF_T_HIGH_OUT;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_FILLED_OUT:
        this->state.state = P_OFF_T_FILLED_OUT;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_OUT:
        this->state.state = P_OFF_T_LOW_OUT;
        this->out_port = "pw";
        this->out = "off";
        this->ta = fin;
        break;
    case P_STOP_T_HIGH_IN:
        this->state.state = P_STOP_T_HIGH_OUT;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = fin;
        break;
    case P_PUMPING_T_HIGH_IN:
        this->state.state = P_PUMPING_T_HIGH_OUT;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_IN:
        this->state.state = P_STOP_T_LOW_OUT;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_IN:
        this->state.state = P_PUMPING_T_LOW_OUT;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = fin;
        break;
    case P_STOP_T_HIGH_OUT:
        this->state.state = P_STOP_T_HIGH_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_PUMPING_T_HIGH_OUT:
        this->state.state = P_PUMPING_T_HIGH_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_STOP_T_FILLED_OUT:
        this->state.state = P_STOP_T_FILLED_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_PUMPING_T_FILLED_OUT:
        this->state.state = P_PUMPING_T_FILLED_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_OUT:
        this->state.state = P_STOP_T_LOW_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_OUT:
        this->state.state = P_PUMPING_T_LOW_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_STOP_T_LOW_OUT:
        this->state.state = P_STOP_T_LOW_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
    case P_PUMPING_T_LOW_OUT:
        this->state.state = P_PUMPING_T_LOW_IN;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = fin;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::w>(mbs))
    {

      this->in_port = "w";
      this->in = x;
    }
    if(this->in_port == "w") {
        if(this->in == "wstop"){
            switch (this->state.state) {
                case P_OFF_T_INIT:
                this->state.state = P_STOP_T_INIT;
                this->ta = inf;
                break;
                case P_OFF_T_HIGH_IN:
                this->state.state = P_STOP_T_HIGH_IN;
                this->ta = inf;
                break;
                case P_OFF_T_FILLED_IN:
                this->state.state = P_STOP_T_FILLED_IN;
                this->ta = inf;
                break;
                case P_OFF_T_LOW_IN:
                this->state.state = P_STOP_T_LOW_IN;
                this->ta = inf;
                break;
                case P_OFF_T_HIGH_OUT:
                this->state.state = P_STOP_T_HIGH_OUT;
                this->ta = inf;
                break;
                case P_OFF_T_FILLED_OUT:
                this->state.state = P_STOP_T_FILLED_OUT;
                this->ta = inf;
                break;
                case P_OFF_T_LOW_OUT:
                this->state.state = P_STOP_T_LOW_OUT;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "wstrt"){
            switch (this->state.state) {
                case P_ON_T_INIT:
                this->state.state = P_PUMPING_T_INIT;
                this->ta = inf;
                break;
                case P_ON_T_HIGH_IN:
                this->state.state = P_PUMPING_T_HIGH_IN;
                this->ta = inf;
                break;
                case P_ON_T_FILLED_IN:
                this->state.state = P_PUMPING_T_FILLED_IN;
                this->ta = inf;
                break;
                case P_ON_T_LOW_IN:
                this->state.state = P_PUMPING_T_LOW_IN;
                this->ta = inf;
                break;
                case P_ON_T_HIGH_OUT:
                this->state.state = P_PUMPING_T_HIGH_OUT;
                this->ta = inf;
                break;
                case P_ON_T_FILLED_OUT:
                this->state.state = P_PUMPING_T_FILLED_OUT;
                this->ta = inf;
                break;
                case P_ON_T_LOW_OUT:
                this->state.state = P_PUMPING_T_LOW_OUT;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "ls") {
        if(this->in == "L"){
            switch (this->state.state) {
                case P_STOP_T_INIT:
                this->state.state = P_STOP_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_ON_T_INIT:
                this->state.state = P_ON_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_INIT:
                this->state.state = P_PUMPING_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_INIT:
                this->state.state = P_OFF_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_STOP_T_LOW_IN:
                this->state.state = P_STOP_T_FILLED_IN;
                this->ta = fin;
                break;
                case P_ON_T_LOW_IN:
                this->state.state = P_ON_T_FILLED_IN;
                this->ta = fin;
                break;
                case P_PUMPING_T_LOW_IN:
                this->state.state = P_PUMPING_T_FILLED_IN;
                this->ta = fin;
                break;
                case P_OFF_T_LOW_IN:
                this->state.state = P_OFF_T_FILLED_IN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "NL"){
            switch (this->state.state) {
                case P_STOP_T_INIT:
                this->state.state = P_STOP_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_ON_T_INIT:
                this->state.state = P_ON_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_INIT:
                this->state.state = P_PUMPING_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_INIT:
                this->state.state = P_OFF_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_STOP_T_FILLED_OUT:
                this->state.state = P_STOP_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_ON_T_FILLED_OUT:
                this->state.state = P_ON_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_FILLED_OUT:
                this->state.state = P_PUMPING_T_LOW_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_FILLED_OUT:
                this->state.state = P_OFF_T_LOW_OUT;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "hs") {
        if(this->in == "H"){
            switch (this->state.state) {
                case P_STOP_T_INIT:
                this->state.state = P_STOP_T_HIGH_OUT;
                this->ta = fin;
                break;
                case P_ON_T_INIT:
                this->state.state = P_ON_T_HIGH_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_INIT:
                this->state.state = P_PUMPING_T_HIGH_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_INIT:
                this->state.state = P_OFF_T_HIGH_OUT;
                this->ta = fin;
                break;
                case P_STOP_T_FILLED_IN:
                this->state.state = P_STOP_T_HIGH_IN;
                this->ta = fin;
                break;
                case P_ON_T_FILLED_IN:
                this->state.state = P_ON_T_HIGH_IN;
                this->ta = fin;
                break;
                case P_PUMPING_T_FILLED_IN:
                this->state.state = P_PUMPING_T_HIGH_IN;
                this->ta = fin;
                break;
                case P_OFF_T_FILLED_IN:
                this->state.state = P_OFF_T_HIGH_IN;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "NH"){
            switch (this->state.state) {
                case P_STOP_T_HIGH_OUT:
                this->state.state = P_STOP_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_ON_T_HIGH_OUT:
                this->state.state = P_ON_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_PUMPING_T_HIGH_OUT:
                this->state.state = P_PUMPING_T_FILLED_OUT;
                this->ta = fin;
                break;
                case P_OFF_T_HIGH_OUT:
                this->state.state = P_OFF_T_FILLED_OUT;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "e") {
        if(this->in == "null"){
            switch (this->state.state) {
                case P_STOP_T_LOW_OUT:
                this->state.state = P_STOP_T_EXHAUSTED;
                this->ta = fin;
                break;
                case P_ON_T_LOW_OUT:
                this->state.state = P_ON_T_EXHAUSTED;
                this->ta = fin;
                break;
                case P_PUMPING_T_LOW_OUT:
                this->state.state = P_PUMPING_T_EXHAUSTED;
                this->ta = fin;
                break;
                case P_OFF_T_LOW_OUT:
                this->state.state = P_OFF_T_EXHAUSTED;
                this->ta = fin;
                break;
                case P_STOP_T_HIGH_IN:
                this->state.state = P_STOP_T_OVERFLOW;
                this->ta = fin;
                break;
                case P_ON_T_HIGH_IN:
                this->state.state = P_ON_T_OVERFLOW;
                this->ta = fin;
                break;
                case P_PUMPING_T_HIGH_IN:
                this->state.state = P_PUMPING_T_OVERFLOW;
                this->ta = fin;
                break;
                case P_OFF_T_HIGH_IN:
                this->state.state = P_OFF_T_OVERFLOW;
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
    if (this->out_port == "pw")
    {
      get_messages<typename defs::pw>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename water_tank<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif