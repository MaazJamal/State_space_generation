//STATE DEFINITIONS

#define ON 0
#define OFF 1
#define SWITCH_ON 2
#define SWITCH_OFF 3



 //PORTS 

struct light_actuator_defs {
    struct light_out : public out_port<string> { };
    struct light_in : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::light_in>;
    using output_ports = std::tuple<typename defs::light_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case SWITCH_OFF:
        this->state.state = OFF;
        this->out_port = "light_out";
        this->out = "off";
        this->ta = inf;
        break;
    case SWITCH_ON:
        this->state.state = ON;
        this->out_port = "light_out";
        this->out = "on";
        this->ta = inf;
        break;
}


// External Inputs


    if(this->in_port == "light_in") {
        if(this->in == "ocl"){
            switch (this->state.state) {
                case ON:
                this->state.state = SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "och"){
            switch (this->state.state) {
                case OFF:
                this->state.state = SWITCH_ON;
                this->ta = fin;
                break;
            }
        }
    }
