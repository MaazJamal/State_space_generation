#ifndef __ROOM_TEMPERATURE_CONTROL__HPP__
#define __ROOM_TEMPERATURE_CONTROL__HPP__
//STATE DEFINITIONS

#define ROOM_COOL_OFF_AC_OFF 0
#define ROOM_COLD_OFF_AC_OFF 1
#define ROOM_COOL_OFF_AC_SWITCH_ON 2
#define ROOM_COOL_OFF_AC_SWITCH_OFF 3
#define ROOM_COLD_OFF_AC_SWITCH_OFF 4
#define ROOM_WARM_OFF_AC_OFF 5
#define ROOM_WARM_OFF_AC_SWITCH_ON 6
#define ROOM_WARM_OFF_AC_SWITCH_OFF 7
#define ROOM_HOT_OFF_AC_ON 8
#define ROOM_HOT_OFF_AC_OFF 9
#define ROOM_HOT_OFF_AC_SWITCH_ON 10
#define ROOM_HOT_OFF_AC_SWITCH_OFF 11
#define ROOM_COOL_ON_AC_ON 12
#define ROOM_COOL_ON_AC_OFF 13
#define ROOM_COOL_ON_AC_SWITCH_ON 14
#define ROOM_COOL_ON_AC_SWITCH_OFF 15
#define ROOM_WARM_ON_AC_ON 16
#define ROOM_WARM_ON_AC_SWITCH_ON 17
#define ROOM_WARM_ON_AC_SWITCH_OFF 18
#define ROOM_HOT_ON_AC_ON 19
#define ROOM_HOT_ON_AC_OFF 20
#define ROOM_HOT_ON_AC_SWITCH_ON 21
#define ROOM_HOT_ON_AC_SWITCH_OFF 22
#define ROOM_VERYHOT_ON_AC_ON 23
#define ROOM_VERYHOT_ON_AC_SWITCH_ON 24
 

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

struct room_temperature_control_defs {
    struct ac_out : public out_port<string> { };
    struct room : public out_port<string> { };
    struct ac_in : public out_port<string> { };
    struct ac_out : public in_port<string> { };
    struct ac : public in_port<string> { };
    struct room_out : public in_port<string> { };
};



        template <typename TIME>
class room_temperature_control
{
  using defs = room_temperature_control_defs; // putting definitions in context
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
  room_temperature_control() noexcept
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

    using input_ports = std::tuple<typename defs::ac_out,typename defs::ac,typename defs::room_out>;
    using output_ports = std::tuple<typename defs::ac_out,typename defs::room,typename defs::ac_in>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case ROOM_COLD_OFF_AC_OFF:
        this->state.state = ROOM_COLD_OFF_AC_SWITCH_ON;
        this->out_port = "ac_in";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_COOL_OFF_AC_OFF:
        this->state.state = ROOM_COOL_OFF_AC_SWITCH_ON;
        this->out_port = "ac_in";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_WARM_OFF_AC_OFF:
        this->state.state = ROOM_WARM_OFF_AC_SWITCH_ON;
        this->out_port = "ac_in";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_HOT_OFF_AC_OFF:
        this->state.state = ROOM_HOT_OFF_AC_SWITCH_ON;
        this->out_port = "ac_in";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_COOL_ON_AC_OFF:
        this->state.state = ROOM_COOL_ON_AC_SWITCH_ON;
        this->out_port = "ac_in";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_HOT_ON_AC_OFF:
        this->state.state = ROOM_HOT_ON_AC_SWITCH_ON;
        this->out_port = "ac_in";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_HOT_OFF_AC_ON:
        this->state.state = ROOM_HOT_OFF_AC_SWITCH_OFF;
        this->out_port = "ac_in";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_COOL_ON_AC_ON:
        this->state.state = ROOM_COOL_ON_AC_SWITCH_OFF;
        this->out_port = "ac_in";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_WARM_ON_AC_ON:
        this->state.state = ROOM_WARM_ON_AC_SWITCH_OFF;
        this->out_port = "ac_in";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_HOT_ON_AC_ON:
        this->state.state = ROOM_HOT_ON_AC_SWITCH_OFF;
        this->out_port = "ac_in";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_VERYHOT_ON_AC_ON:
        this->state.state = ROOM_VERYHOT_ON_AC_SWITCH_OFF;
        this->out_port = "ac_in";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_COOL_ON_AC_ON:
        this->state.state = ROOM_COOL_OFF_AC_ON;
        this->out_port = "ac_out";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_COOL_ON_AC_OFF:
        this->state.state = ROOM_COOL_OFF_AC_OFF;
        this->out_port = "ac_out";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_WARM_ON_AC_ON:
        this->state.state = ROOM_WARM_OFF_AC_ON;
        this->out_port = "ac_out";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_HOT_ON_AC_ON:
        this->state.state = ROOM_HOT_OFF_AC_ON;
        this->out_port = "ac_out";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_HOT_ON_AC_OFF:
        this->state.state = ROOM_HOT_OFF_AC_OFF;
        this->out_port = "ac_out";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_VERYHOT_ON_AC_ON:
        this->state.state = ROOM_VERYHOT_OFF_AC_ON;
        this->out_port = "ac_out";
        this->out = "off";
        this->ta = fin;
        break;
    case ROOM_COLD_OFF_AC_OFF:
        this->state.state = ROOM_COLD_ON_AC_OFF;
        this->out_port = "ac_out";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_COOL_OFF_AC_OFF:
        this->state.state = ROOM_COOL_ON_AC_OFF;
        this->out_port = "ac_out";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_WARM_OFF_AC_OFF:
        this->state.state = ROOM_WARM_ON_AC_OFF;
        this->out_port = "ac_out";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_HOT_OFF_AC_ON:
        this->state.state = ROOM_HOT_ON_AC_ON;
        this->out_port = "ac_out";
        this->out = "on";
        this->ta = fin;
        break;
    case ROOM_HOT_OFF_AC_OFF:
        this->state.state = ROOM_HOT_ON_AC_OFF;
        this->out_port = "ac_out";
        this->out = "on";
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
        if(this->in == "on"){
            switch (this->state.state) {
                case ROOM_COOL_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_COOL_OFF_AC_ON;
                this->ta = inf;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_WARM_OFF_AC_ON;
                this->ta = inf;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_HOT_OFF_AC_ON;
                this->ta = inf;
                break;
                case ROOM_COOL_ON_AC_SWITCH_ON:
                this->state.state = ROOM_COOL_ON_AC_ON;
                this->ta = inf;
                break;
                case ROOM_WARM_ON_AC_SWITCH_ON:
                this->state.state = ROOM_WARM_ON_AC_ON;
                this->ta = inf;
                break;
                case ROOM_HOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_HOT_ON_AC_ON;
                this->ta = inf;
                break;
                case ROOM_VERYHOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_VERYHOT_ON_AC_ON;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case ROOM_COLD_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_COLD_OFF_AC_OFF;
                this->ta = inf;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_COOL_OFF_AC_OFF;
                this->ta = inf;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_WARM_OFF_AC_OFF;
                this->ta = inf;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_HOT_OFF_AC_OFF;
                this->ta = inf;
                break;
                case ROOM_COOL_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_COOL_ON_AC_OFF;
                this->ta = inf;
                break;
                case ROOM_WARM_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_WARM_ON_AC_OFF;
                this->ta = inf;
                break;
                case ROOM_HOT_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_HOT_ON_AC_OFF;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "ac") {
    }
    if(this->in_port == "room_out") {
        if(this->in == "vlow"){
            switch (this->state.state) {
                case ROOM_COOL_OFF_AC_OFF:
                this->state.state = ROOM_COLD_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_COLD_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_COLD_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_OFF:
                this->state.state = ROOM_COLD_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_COLD_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_COLD_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_ON:
                this->state.state = ROOM_COLD_OFF_AC_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_OFF:
                this->state.state = ROOM_COLD_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_COLD_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_COLD_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_ON:
                this->state.state = ROOM_COLD_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_OFF:
                this->state.state = ROOM_COLD_ON_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_SWITCH_ON:
                this->state.state = ROOM_COLD_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_COLD_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_ON:
                this->state.state = ROOM_COLD_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_SWITCH_ON:
                this->state.state = ROOM_COLD_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_COLD_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_ON:
                this->state.state = ROOM_COLD_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_OFF:
                this->state.state = ROOM_COLD_ON_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_COLD_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_COLD_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_VERYHOT_ON_AC_ON:
                this->state.state = ROOM_COLD_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_VERYHOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_COLD_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "low"){
            switch (this->state.state) {
                case ROOM_COLD_OFF_AC_OFF:
                this->state.state = ROOM_COOL_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COLD_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_COOL_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_OFF:
                this->state.state = ROOM_COOL_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_COOL_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_COOL_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_ON:
                this->state.state = ROOM_COOL_OFF_AC_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_OFF:
                this->state.state = ROOM_COOL_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_COOL_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_COOL_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_ON:
                this->state.state = ROOM_COOL_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_SWITCH_ON:
                this->state.state = ROOM_COOL_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_COOL_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_ON:
                this->state.state = ROOM_COOL_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_OFF:
                this->state.state = ROOM_COOL_ON_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_COOL_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_COOL_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_VERYHOT_ON_AC_ON:
                this->state.state = ROOM_COOL_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_VERYHOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_COOL_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "med"){
            switch (this->state.state) {
                case ROOM_COLD_OFF_AC_OFF:
                this->state.state = ROOM_WARM_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COLD_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_WARM_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_OFF:
                this->state.state = ROOM_WARM_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_WARM_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_WARM_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_ON:
                this->state.state = ROOM_WARM_OFF_AC_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_OFF:
                this->state.state = ROOM_WARM_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_WARM_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_WARM_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_ON:
                this->state.state = ROOM_WARM_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_OFF:
                this->state.state = ROOM_WARM_ON_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_SWITCH_ON:
                this->state.state = ROOM_WARM_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_WARM_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_ON:
                this->state.state = ROOM_WARM_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_OFF:
                this->state.state = ROOM_WARM_ON_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_WARM_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_WARM_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_VERYHOT_ON_AC_ON:
                this->state.state = ROOM_WARM_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_VERYHOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_WARM_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "high"){
            switch (this->state.state) {
                case ROOM_COLD_OFF_AC_OFF:
                this->state.state = ROOM_HOT_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COLD_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_HOT_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_OFF:
                this->state.state = ROOM_HOT_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_HOT_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_HOT_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_OFF:
                this->state.state = ROOM_HOT_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_HOT_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_HOT_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_ON:
                this->state.state = ROOM_HOT_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_OFF:
                this->state.state = ROOM_HOT_ON_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_SWITCH_ON:
                this->state.state = ROOM_HOT_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_HOT_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_ON:
                this->state.state = ROOM_HOT_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_SWITCH_ON:
                this->state.state = ROOM_HOT_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_HOT_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_VERYHOT_ON_AC_ON:
                this->state.state = ROOM_HOT_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_VERYHOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_HOT_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "vhigh"){
            switch (this->state.state) {
                case ROOM_COLD_OFF_AC_OFF:
                this->state.state = ROOM_VERYHOT_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COLD_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_VERYHOT_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_OFF:
                this->state.state = ROOM_VERYHOT_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_VERYHOT_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_VERYHOT_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_OFF:
                this->state.state = ROOM_VERYHOT_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_VERYHOT_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_VERYHOT_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_ON:
                this->state.state = ROOM_VERYHOT_OFF_AC_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_OFF:
                this->state.state = ROOM_VERYHOT_OFF_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_ON:
                this->state.state = ROOM_VERYHOT_OFF_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_OFF_AC_SWITCH_OFF:
                this->state.state = ROOM_VERYHOT_OFF_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_ON:
                this->state.state = ROOM_VERYHOT_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_OFF:
                this->state.state = ROOM_VERYHOT_ON_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_SWITCH_ON:
                this->state.state = ROOM_VERYHOT_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_COOL_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_VERYHOT_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_ON:
                this->state.state = ROOM_VERYHOT_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_SWITCH_ON:
                this->state.state = ROOM_VERYHOT_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_WARM_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_VERYHOT_ON_AC_SWITCH_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_ON:
                this->state.state = ROOM_VERYHOT_ON_AC_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_OFF:
                this->state.state = ROOM_VERYHOT_ON_AC_OFF;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_SWITCH_ON:
                this->state.state = ROOM_VERYHOT_ON_AC_SWITCH_ON;
                this->ta = fin;
                break;
                case ROOM_HOT_ON_AC_SWITCH_OFF:
                this->state.state = ROOM_VERYHOT_ON_AC_SWITCH_OFF;
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
    if (this->out_port == "ac_out")
    {
      get_messages<typename defs::ac_out>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename room_temperature_control<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif