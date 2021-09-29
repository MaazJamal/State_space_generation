//STATE DEFINITIONS

#define OCC_OC_OFF_LIGHT_ON 0
#define OCC_NOC_OFF_LIGHT_OFF 1
#define OCC_OC_OFF_LIGHT_OFF 2
#define OCC_NOC_OFF_LIGHT_SWITCH_ON 3
#define OCC_OC_OFF_LIGHT_SWITCH_ON 4
#define OCC_NOC_OFF_LIGHT_SWITCH_OFF 5
#define OCC_OC_OFF_LIGHT_SWITCH_OFF 6
#define OCC_NOC_ON_LIGHT_ON 7
#define OCC_OC_ON_LIGHT_ON 8
#define OCC_NOC_ON_LIGHT_OFF 9
#define OCC_OC_ON_LIGHT_OFF 10
#define OCC_NOC_ON_LIGHT_SWITCH_ON 11
#define OCC_OC_ON_LIGHT_SWITCH_ON 12
#define OCC_NOC_ON_LIGHT_SWITCH_OFF 13
#define OCC_OC_ON_LIGHT_SWITCH_OFF 14



 //PORTS 

struct occupency_defs {
    struct light_in : public out_port<string> { };
    struct light_out : public out_port<string> { };
    struct light_s : public out_port<string> { };
    struct light_out : public in_port<string> { };
    struct occ_out : public in_port<string> { };
    struct occ : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::light_out,typename defs::occ_out,typename defs::occ>;
    using output_ports = std::tuple<typename defs::light_in,typename defs::light_out,typename defs::light_s>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case OCC_OC_ON_LIGHT_OFF:
        this->state.state = OCC_OC_ON_LIGHT_SWITCH_ON;
        this->out_port = "light_in";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_OC_OFF_LIGHT_OFF:
        this->state.state = OCC_OC_OFF_LIGHT_SWITCH_ON;
        this->out_port = "light_in";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_NOC_ON_LIGHT_OFF:
        this->state.state = OCC_NOC_ON_LIGHT_SWITCH_ON;
        this->out_port = "light_in";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_NOC_OFF_LIGHT_OFF:
        this->state.state = OCC_NOC_OFF_LIGHT_SWITCH_ON;
        this->out_port = "light_in";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_OC_ON_LIGHT_ON:
        this->state.state = OCC_OC_ON_LIGHT_SWITCH_OFF;
        this->out_port = "light_in";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_OC_OFF_LIGHT_ON:
        this->state.state = OCC_OC_OFF_LIGHT_SWITCH_OFF;
        this->out_port = "light_in";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_NOC_ON_LIGHT_ON:
        this->state.state = OCC_NOC_ON_LIGHT_SWITCH_OFF;
        this->out_port = "light_in";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_OC_ON_LIGHT_ON:
        this->state.state = OCC_OC_OFF_LIGHT_ON;
        this->out_port = "light_out";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_OC_ON_LIGHT_OFF:
        this->state.state = OCC_OC_OFF_LIGHT_OFF;
        this->out_port = "light_out";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_OC_OFF_LIGHT_ON:
        this->state.state = OCC_OC_ON_LIGHT_ON;
        this->out_port = "light_out";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_OC_OFF_LIGHT_OFF:
        this->state.state = OCC_OC_ON_LIGHT_OFF;
        this->out_port = "light_out";
        this->out = "on";
        this->ta = fin;
        break;
    case OCC_NOC_ON_LIGHT_ON:
        this->state.state = OCC_NOC_OFF_LIGHT_ON;
        this->out_port = "light_out";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_NOC_ON_LIGHT_OFF:
        this->state.state = OCC_NOC_OFF_LIGHT_OFF;
        this->out_port = "light_out";
        this->out = "off";
        this->ta = fin;
        break;
    case OCC_NOC_OFF_LIGHT_OFF:
        this->state.state = OCC_NOC_ON_LIGHT_OFF;
        this->out_port = "light_out";
        this->out = "on";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "light_out") {
        if(this->in == "on"){
            switch (this->state.state) {
                case OCC_OC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_ON_LIGHT_ON;
                this->ta = inf;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_OFF_LIGHT_ON;
                this->ta = inf;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_ON_LIGHT_ON;
                this->ta = inf;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_OFF_LIGHT_ON;
                this->ta = inf;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case OCC_OC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_ON_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_OFF_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_ON_LIGHT_OFF;
                this->ta = inf;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_OFF_LIGHT_OFF;
                this->ta = inf;
                break;
            }
        }
    }
    if(this->in_port == "occ_out") {
        if(this->in == "och"){
            switch (this->state.state) {
                case OCC_NOC_OFF_LIGHT_OFF:
                this->state.state = OCC_OC_OFF_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_OFF_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_NOC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_OFF_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_ON:
                this->state.state = OCC_OC_ON_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_OFF:
                this->state.state = OCC_OC_ON_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_OC_ON_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_NOC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_OC_ON_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "ocl"){
            switch (this->state.state) {
                case OCC_OC_ON_LIGHT_ON:
                this->state.state = OCC_NOC_ON_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_OC_ON_LIGHT_OFF:
                this->state.state = OCC_NOC_ON_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_OC_ON_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_ON_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_OC_ON_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_ON_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_ON:
                this->state.state = OCC_NOC_OFF_LIGHT_ON;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_OFF:
                this->state.state = OCC_NOC_OFF_LIGHT_OFF;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_ON:
                this->state.state = OCC_NOC_OFF_LIGHT_SWITCH_ON;
                this->ta = fin;
                break;
                case OCC_OC_OFF_LIGHT_SWITCH_OFF:
                this->state.state = OCC_NOC_OFF_LIGHT_SWITCH_OFF;
                this->ta = fin;
                break;
            }
        }
    }
    if(this->in_port == "occ") {
    }
