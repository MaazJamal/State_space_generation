//STATE DEFINITIONS

#define NO_SMOKE_OFF 0
#define SMOKE_OFF 1
#define NO_SMOKE_ON 2
#define SMOKE_ON 3



 //PORTS 

struct smoke_detector_defs {
    struct smoke_out : public out_port<string> { };
    struct alarm_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::alarm_out>;
    using output_ports = std::tuple<typename defs::smoke_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case NO_SMOKE_OFF:
        this->state.state = SMOKE_OFF;
        this->out_port = "smoke_out";
        this->out = "sch";
        this->ta = fin;
        break;
    case SMOKE_OFF:
        this->state.state = NO_SMOKE_OFF;
        this->out_port = "smoke_out";
        this->out = "scl";
        this->ta = fin;
        break;
    case NO_SMOKE_ON:
        this->state.state = SMOKE_ON;
        this->out_port = "smoke_out";
        this->out = "sch";
        this->ta = fin;
        break;
    case SMOKE_ON:
        this->state.state = NO_SMOKE_ON;
        this->out_port = "smoke_out";
        this->out = "scl";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "alarm_out") {
        if(this->in == "on"){
            switch (this->state.state) {
                case NO_SMOKE_OFF:
                this->state.state = NO_SMOKE_ON;
                this->ta = fin;
                break;
                case SMOKE_OFF:
                this->state.state = SMOKE_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case NO_SMOKE_ON:
                this->state.state = NO_SMOKE_OFF;
                this->ta = fin;
                break;
                case SMOKE_ON:
                this->state.state = SMOKE_OFF;
                this->ta = fin;
                break;
            }
        }
    }
