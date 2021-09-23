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
    case NOT_OCCUPIED_OFF:
        this->state.state = OCCUPIED_OFF;
        this->out_port = "occupency_out";
        this->out = "och";
        this->ta = fin;
        break;
    case OCCUPIED_OFF:
        this->state.state = NOT_OCCUPIED_OFF;
        this->out_port = "occupency_out";
        this->out = "ocl";
        this->ta = fin;
        break;
    case NOT_OCCUPIED_ON:
        this->state.state = OCCUPIED_ON;
        this->out_port = "occupency_out";
        this->out = "och";
        this->ta = fin;
        break;
    case OCCUPIED_ON:
        this->state.state = NOT_OCCUPIED_ON;
        this->out_port = "occupency_out";
        this->out = "ocl";
        this->ta = fin;
        break;
}


// External Inputs


    if(this->in_port == "light_out") {
        if(this->in == "off"){
            switch (this->state.state) {
                case OCCUPIED_ON:
                this->state.state = OCCUPIED_OFF;
                this->ta = fin;
                break;
                case NOT_OCCUPIED_ON:
                this->state.state = NOT_OCCUPIED_OFF;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "on"){
            switch (this->state.state) {
                case OCCUPIED_OFF:
                this->state.state = OCCUPIED_ON;
                this->ta = fin;
                break;
                case NOT_OCCUPIED_OFF:
                this->state.state = NOT_OCCUPIED_ON;
                this->ta = fin;
                break;
            }
        }
    }
