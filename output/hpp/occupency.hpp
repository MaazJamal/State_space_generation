#ifndef __OCCUPENCY__HPP__
#define __OCCUPENCY__HPP__
//STATE DEFINITIONS

#define OC_ON 0
#define OC_OFF 1
#define NOC_ON 2
#define NOC_OFF 3
 

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

struct occupency_defs {
    struct occ_out : public out_port<string> { };
    struct light_out : public in_port<string> { };
};



        template <typename TIME>
class occupency
{
  using defs = occupency_defs; // putting definitions in context
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
  occupency() noexcept
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

    using input_ports = std::tuple<typename defs::light_out>;
    using output_ports = std::tuple<typename defs::occ_out>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case NOC_OFF:
        this->state.state = OC_OFF;
        this->out_port = "occ_out";
        this->out = "och";
        this->ta = fin;
        break;
    case NOC_ON:
        this->state.state = OC_ON;
        this->out_port = "occ_out";
        this->out = "och";
        this->ta = fin;
        break;
    case OC_ON:
        this->state.state = NOC_ON;
        this->out_port = "occ_out";
        this->out = "ocl";
        this->ta = fin;
        break;
    case OC_OFF:
        this->state.state = NOC_OFF;
        this->out_port = "occ_out";
        this->out = "ocl";
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
        if(this->in == "off"){
            switch (this->state.state) {
                case OC_ON:
                this->state.state = OC_OFF;
                this->ta = fin;
                break;
                case NOC_ON:
                this->state.state = NOC_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "on"){
            switch (this->state.state) {
                case OC_OFF:
                this->state.state = OC_ON;
                this->ta = fin;
                break;
                case NOC_OFF:
                this->state.state = NOC_ON;
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
    if (this->out_port == "occ_out")
    {
      get_messages<typename defs::occ_out>(bags).push_back(out);
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

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename occupency<TIME>::state_type &i)
  {
    os << "Output: " << i.state;
    return os;
  }
};
#endif