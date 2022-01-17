#ifndef __OCCUPENCY__HPP__
#define __OCCUPENCY__HPP__
//STATE DEFINITIONS

#define ENTRY 0
#define EXIT 1
#define NOT_OCCUPIED 2
#define OCCUPIED 3
 

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
    struct occupency_out : public out_port<string> { };
    struct occupency_in : public in_port<string> { };
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
  } 
  
    // state definition
  struct state_type
  {
    int state;
  } state;
  
  //port deifinitions

    using input_ports = std::tuple<typename defs::occupency_in>;
    using output_ports = std::tuple<typename defs::occupency_out>;

//INTERNAL TRANSITIONS

  void internal_transition()
  {
switch (this->state.state) {
    case ENTRY:
        this->state.state = OCCUPIED;
        this->out_port = "occupency_out";
        this->out = "ocl";
        this->ta = inf;
        break;
    case EXIT:
        this->state.state = NOT_OCCUPIED;
        this->out_port = "occupency_out";
        this->out = "och";
        this->ta = inf;
        break;
}}


// External Inputs


  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {
    for (const auto &x : get_messages<typename defs::occupency_in>(mbs))
    {

      this->in_port = "occupency_in";
      this->in = x;
    }
    if(this->in_port == "occupency_in") {
        if(this->in == "ocs"){
            switch (this->state.state) {
                case OCCUPIED:
                this->state.state = EXIT;
                this->ta = fin;
                break;
                case NOT_OCCUPIED:
                this->state.state = ENTRY;
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
    if (this->out_port == "occupency_out")
    {
      get_messages<typename defs::occupency_out>(bags).push_back(out);
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