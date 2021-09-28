//STATE DEFINITIONS

#define NOT_OCCUPIED_ON 0
#define OCCUPIED_ON 1
#define NOT_OCCUPIED_OFF 2
#define OCCUPIED_OFF 3



 //PORTS 

struct occupency_defs {
    struct occupency_out : public out_port<string> { };
    struct light_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::light_out>;
    using output_ports = std::tuple<typename defs::occupency_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case NOT_OCCUPIED:
        this->state.state = OCCUPIED_OFF;
        this->out_port = "occupency_out";
        this->out = "och";
        this->ta = fin;
        break;
    case OCCUPIED:
        this->state.state = NOT_OCCUPIED;
        this->out_port = "occupency_out";
        this->out = "ocl";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "light_out") {
    }
