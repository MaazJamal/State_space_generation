//STATE DEFINITIONS

#define ENTRY 0
#define EXIT 1
#define NOT_OCCUPIED 2
#define OCCUPIED 3



 //PORTS 

struct occupency_defs {
    struct occupency_out : public out_port<string> { };
    struct occupency_in : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::occupency_in>;
    using output_ports = std::tuple<typename defs::occupency_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case ENTRY:
        this->state.state = OCCUPIED;
        this->out_port = "occupency_out";
        this->out = "ocl";
        this->ta = inf;
        break;
    case EXIT:
        this->state.state = NOT_OCCUPIED;
        this->out_port = "occupency_out";
        this->out = "och";
        this->ta = inf;
        break;
}


// External Inputs


    if(this->in_port == "occupency_in") {
        if(this->in == "ocs"){
            switch (this->state.state) {
                case OCCUPIED:
                this->state.state = EXIT;
                this->ta = fin;
                break;
                case NOT_OCCUPIED:
                this->state.state = ENTRY;
                this->ta = fin;
                break;
            }
        }
    }
