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



 //PORTS 

struct room_temperature_defs {
    struct ac_out : public out_port<string> { };
    struct room : public out_port<string> { };
    struct ac_in : public out_port<string> { };
    struct ac_out : public in_port<string> { };
    struct ac : public in_port<string> { };
    struct room_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::ac_out,typename defs::ac,typename defs::room_out>;
    using output_ports = std::tuple<typename defs::ac_out,typename defs::room,typename defs::ac_in>;

//INTERNAL TRANSITIONS

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
}


// External Inputs


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
