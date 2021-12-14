//STATE DEFINITIONS

#define COLD_OFF 0
#define COOL_OFF 1
#define WARM_OFF 2
#define HOT_OFF 3
#define VERYHOT_OFF 4
#define COLD_ON 5
#define COOL_ON 6
#define WARM_ON 7
#define HOT_ON 8
#define VERYHOT_ON 9



 //PORTS 

struct room_temperature_defs {
    struct room_out : public out_port<string> { };
    struct ac_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::ac_out>;
    using output_ports = std::tuple<typename defs::room_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case COOL:
        this->state.state = COLD;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case WARM:
        this->state.state = COLD;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case HOT:
        this->state.state = COLD;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case VERYHOT:
        this->state.state = COLD;
        this->out_port = "room_out";
        this->out = "vlow";
        this->ta = fin;
        break;
    case COLD:
        this->state.state = COOL;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case WARM:
        this->state.state = COOL;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case HOT:
        this->state.state = COOL;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case VERYHOT:
        this->state.state = COOL;
        this->out_port = "room_out";
        this->out = "low";
        this->ta = fin;
        break;
    case COLD:
        this->state.state = WARM;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case COOL:
        this->state.state = WARM;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case HOT:
        this->state.state = WARM;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case VERYHOT:
        this->state.state = WARM;
        this->out_port = "room_out";
        this->out = "med";
        this->ta = fin;
        break;
    case COLD:
        this->state.state = HOT;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case COOL:
        this->state.state = HOT;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case WARM:
        this->state.state = HOT;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case VERYHOT:
        this->state.state = HOT;
        this->out_port = "room_out";
        this->out = "high";
        this->ta = fin;
        break;
    case COLD:
        this->state.state = VERYHOT;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case COOL:
        this->state.state = VERYHOT;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case WARM:
        this->state.state = VERYHOT;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
    case HOT:
        this->state.state = VERYHOT;
        this->out_port = "room_out";
        this->out = "vhigh";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "ac_out") {
        if(this->in == "off"){
            switch (this->state.state) {
                case COLD_ON:
                this->state.state = COLD_OFF;
                this->ta = fin;
                break;
                case COOL_ON:
                this->state.state = COOL_OFF;
                this->ta = fin;
                break;
                case WARM_ON:
                this->state.state = WARM_OFF;
                this->ta = fin;
                break;
                case HOT_ON:
                this->state.state = HOT_OFF;
                this->ta = fin;
                break;
                case VERYHOT_ON:
                this->state.state = VERYHOT_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "on"){
            switch (this->state.state) {
                case COLD_OFF:
                this->state.state = COLD_ON;
                this->ta = fin;
                break;
                case COOL_OFF:
                this->state.state = COOL_ON;
                this->ta = fin;
                break;
                case WARM_OFF:
                this->state.state = WARM_ON;
                this->ta = fin;
                break;
                case HOT_OFF:
                this->state.state = HOT_ON;
                this->ta = fin;
                break;
                case VERYHOT_OFF:
                this->state.state = VERYHOT_ON;
                this->ta = fin;
                break;
            }
        }
    }
