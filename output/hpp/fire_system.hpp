//STATE DEFINITIONS

#define SMOKE_SMOKE_OFF_ALARM_ALARM_ON 0
#define SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF 1
#define SMOKE_SMOKE_OFF_ALARM_ALARM_OFF 2
#define SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON 3
#define SMOKE_SMOKE_OFF_ALARM_SWITCH_ON 4
#define SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF 5
#define SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF 6
#define SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON 7
#define SMOKE_SMOKE_ON_ALARM_ALARM_ON 8
#define SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF 9
#define SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON 10
#define SMOKE_SMOKE_ON_ALARM_SWITCH_ON 11
#define SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF 12
#define SMOKE_SMOKE_ON_ALARM_SWITCH_OFF 13



 //PORTS 

struct fire_system_defs {
    struct alarm_in : public out_port<string> { };
    struct alarm_out : public out_port<string> { };
    struct alarm : public out_port<string> { };
    struct alarm_out : public in_port<string> { };
    struct smoke_out : public in_port<string> { };
    struct smoke : public in_port<string> { };
    struct alarm_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::alarm_out,typename defs::smoke_out,typename defs::smoke,typename defs::alarm_out>;
    using output_ports = std::tuple<typename defs::alarm_in,typename defs::alarm_out,typename defs::alarm>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF:
        this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON;
        this->out_port = "alarm_in";
        this->out = "h";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_OFF_ALARM_ALARM_OFF:
        this->state.state = SMOKE_SMOKE_OFF_ALARM_SWITCH_ON;
        this->out_port = "alarm_in";
        this->out = "h";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF:
        this->state.state = SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON;
        this->out_port = "alarm_in";
        this->out = "h";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_OFF_ALARM_ALARM_ON:
        this->state.state = SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF;
        this->out_port = "alarm_in";
        this->out = "l";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON:
        this->state.state = SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF;
        this->out_port = "alarm_in";
        this->out = "l";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_ON_ALARM_ALARM_ON:
        this->state.state = SMOKE_SMOKE_ON_ALARM_SWITCH_OFF;
        this->out_port = "alarm_in";
        this->out = "l";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF:
        this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF;
        this->out_port = "alarm_out";
        this->out = "on";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON:
        this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_ON;
        this->out_port = "alarm_out";
        this->out = "off";
        this->ta = fin;
        break;
    case SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF:
        this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF;
        this->out_port = "alarm_out";
        this->out = "off";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_ON_ALARM_ALARM_ON:
        this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_ON;
        this->out_port = "alarm_out";
        this->out = "off";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_OFF_ALARM_ALARM_ON:
        this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_ON;
        this->out_port = "alarm_out";
        this->out = "on";
        this->ta = fin;
        break;
    case SMOKE_SMOKE_OFF_ALARM_ALARM_OFF:
        this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_OFF;
        this->out_port = "alarm_out";
        this->out = "on";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "alarm_out") {
        if(this->in == "on"){
            switch (this->state.state) {
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "smoke_out") {
        if(this->in == "sch"){
            switch (this->state.state) {
                case SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_SWITCH_ON;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_ALARM_OFF:
                this->state.state = SMOKE_SMOKE_ON_ALARM_ALARM_OFF;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_SMOKE_ON_ALARM_SWITCH_ON;
                this->ta = fin;
                break;
                case SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_SMOKE_ON_ALARM_SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "scl"){
            switch (this->state.state) {
                case SMOKE_SMOKE_OFF_ALARM_ALARM_ON:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_ON;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_OFF_ALARM_ALARM_OFF:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_ALARM_OFF;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_ON;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_OFF_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_OFF_ALARM_SWITCH_OFF;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_ON_ALARM_ALARM_ON:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_ALARM_ON;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_ON:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_SWITCH_ON;
                this->ta = fin;
                break;
                case SMOKE_SMOKE_ON_ALARM_SWITCH_OFF:
                this->state.state = SMOKE_NO_SMOKE_ON_ALARM_SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "smoke") {
    }
