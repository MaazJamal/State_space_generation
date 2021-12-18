//STATE DEFINITIONS

#define OCCUPENCY_OFF 0
#define OCCUPENCY_ON 1



 //PORTS 

struct occupency_defs {
    struct occ_out : public out_port<string> { };
    struct x : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::x>;
    using output_ports = std::tuple<typename defs::occ_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case OCCUPENCY_ON:
        this->state.state = OCCUPENCY_OFF;
        this->out_port = "occ_out";
        this->out = "oclow";
        this->ta = fin;
        break;
    case OCCUPENCY_OFF:
        this->state.state = OCCUPENCY_ON;
        this->out_port = "occ_out";
        this->out = "ochigh";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "x") {
    }
