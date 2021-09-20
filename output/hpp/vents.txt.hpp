//STATE DEFINITIONS

#define SHUT 0
#define CLOSING 1
#define OPENING 2
#define FULL_OPEN 3



 //PORTS 

struct vents_defs {
    struct vent_out : public out_port<string> { };
    struct co2_out : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::co2_out>;
    using output_ports = std::tuple<typename defs::vent_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case OPENING:
        this->state.state = FULL_OPEN;
        this->out_port = "vent_out";
        this->out = "venth";
        this->ta = inf;
        break;
    case CLOSING:
        this->state.state = SHUT;
        this->out_port = "vent_out";
        this->out = "ventl";
        this->ta = inf;
        break;
}


// External Inputs


    if(this->in_port == "co2_out") {
        if(this->in == "co2h"){
            switch (this->state.state) {
                case SHUT:
                this->state.state = OPENING;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "co2l"){
            switch (this->state.state) {
                case FULL_OPEN:
                this->state.state = CLOSING;
                this->ta = fin;
                break;
            }
        }
    }
