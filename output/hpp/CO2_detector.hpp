#ifndef __CO2_DETECTOR__HPP__
#define __CO2_DETECTOR__HPP__
//STATE DEFINITIONS

#define LOW 0
#define MEDIUM 1
#define HIGH 2
 

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

struct CO2_detector_defs {
    struct co2_out : public out_port<string> { };
    struct x : public in_port<string> { };
};



        template <typename TIME>
class CO2_detector
{
  using defs = CO2_detector_defs; // putting definitions in context
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
  CO2_detector() noexcept
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
    using output_ports = std::tuple<typename defs::co2_out>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case LOW:
        this->state.state = MEDIUM;
        this->out_port = "co2_out";
        this->out = "co2h";
        this->ta = fin;
        break;
    case LOW:
        this->state.state = HIGH;
        this->out_port = "co2_out";
        this->out = "co2h";
        this->ta = fin;
        break;
    case MEDIUM:
        this->state.state = HIGH;
        this->out_port = "co2_out";
        this->out = "co2h";
        this->ta = fin;
        break;
    case HIGH:
        this->state.state = MEDIUM;
        this->out_port = "co2_out";
        this->out = "co2h";
        this->ta = fin;
        break;
    case HIGH:
        this->state.state = LOW;
        this->out_port = "co2_out";
        this->out = "co2h";
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
    if (this->out_port == "co2_out")
    {
      get_messages<typename defs::co2_out>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename CO2_detector<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif