//STATE DEFINITIONS

#define LOW_OPEN 0
#define MEDIUM_OPEN 1
#define HIGH_OPEN 2
#define LOW_CLOSED 3
#define MEDIUM_CLOSED 4
#define HIGH_CLOSED 5



 //PORTS 

struct CO2_detector_defs {
    struct co2_out : public out_port<string> { };
    struct vents_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::vents_out>;
    using output_ports = std::tuple<typename defs::co2_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case LOW_OPEN:
        this->state.state = MEDIUM_OPEN;
        this->out_port = "co2_out";
        this->out = "co2m";
        this->ta = inf;
        break;
    case MEDIUM_OPEN:
        this->state.state = HIGH_OPEN;
        this->out_port = "co2_out";
        this->out = "co2h";
        this->ta = inf;
        break;
    case HIGH_OPEN:
        this->state.state = MEDIUM_OPEN;
        this->out_port = "co2_out";
        this->out = "co2m";
        this->ta = inf;
        break;
    case MEDIUM_OPEN:
        this->state.state = LOW_OPEN;
        this->out_port = "co2_out";
        this->out = "co2l";
        this->ta = inf;
        break;
    case LOW_CLOSED:
        this->state.state = MEDIUM_CLOSED;
        this->out_port = "co2_out";
        this->out = "co2m";
        this->ta = inf;
        break;
    case MEDIUM_CLOSED:
        this->state.state = HIGH_CLOSED;
        this->out_port = "co2_out";
        this->out = "co2h";
        this->ta = inf;
        break;
    case HIGH_CLOSED:
        this->state.state = MEDIUM_CLOSED;
        this->out_port = "co2_out";
        this->out = "co2m";
        this->ta = inf;
        break;
    case MEDIUM_CLOSED:
        this->state.state = LOW_CLOSED;
        this->out_port = "co2_out";
        this->out = "co2l";
        this->ta = inf;
        break;
}


// External Inputs


    if(this->in_port == "vents_out") {
        if(this->in == "ventl"){
            switch (this->state.state) {
                case LOW_OPEN:
                this->state.state = LOW_CLOSED;
                this->ta = fin;
                break;
                case MEDIUM_OPEN:
                this->state.state = MEDIUM_CLOSED;
                this->ta = fin;
                break;
                case HIGH_OPEN:
                this->state.state = HIGH_CLOSED;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "venth"){
            switch (this->state.state) {
                case LOW_CLOSED:
                this->state.state = LOW_OPEN;
                this->ta = fin;
                break;
                case MEDIUM_CLOSED:
                this->state.state = MEDIUM_OPEN;
                this->ta = fin;
                break;
                case HIGH_CLOSED:
                this->state.state = HIGH_OPEN;
                this->ta = fin;
                break;
            }
        }
    }
