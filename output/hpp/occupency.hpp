//STATE DEFINITIONS

#define OC_ON 0
#define OC_OFF 1
#define NOC_ON 2
#define NOC_OFF 3



 //PORTS 

struct occupency_defs {
    struct occ_out : public out_port<string> { };
    struct light_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::light_out>;
    using output_ports = std::tuple<typename defs::occ_out>;

//INTERNAL TRANSITIONS

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
}


// External Inputs


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
