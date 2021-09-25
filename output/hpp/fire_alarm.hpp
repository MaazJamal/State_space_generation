//STATE DEFINITIONS

#define ALARM_ON 0
#define ALARM_OFF 1
#define SWITCH_ON 2
#define SWITCH_OFF 3



 //PORTS 

struct fire_alarm_defs {
    struct alarm_out : public out_port<string> { };
    struct smoke_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::smoke_out>;
    using output_ports = std::tuple<typename defs::alarm_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case SWITCH_ON:
        this->state.state = ALARM_ON;
        this->out_port = "alarm_out";
        this->out = "on";
        this->ta = inf;
        break;
    case SWITCH_OFF:
        this->state.state = ALARM_OFF;
        this->out_port = "alarm_out";
        this->out = "off";
        this->ta = inf;
        break;
}


// External Inputs


    if(this->in_port == "smoke_out") {
        if(this->in == "sch"){
            switch (this->state.state) {
                case ALARM_OFF:
                this->state.state = SWITCH_ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "scl"){
            switch (this->state.state) {
                case ALARM_ON:
                this->state.state = SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
    }
