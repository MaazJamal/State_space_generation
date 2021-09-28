//STATE DEFINITIONS

#define SHUT 0
#define CLOSING 1
#define OPENING 2
#define FULL_OPEN 3



 //PORTS 

struct vents_defs {
    struct vents_out : public out_port<string> { };
    struct vents_in : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::vents_in>;
    using output_ports = std::tuple<typename defs::vents_out>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case OPENING:
        this->state.state = FULL_OPEN;
        this->out_port = "vents_out";
        this->out = "venth";
        this->ta = inf;
        break;
    case CLOSING:
        this->state.state = SHUT;
        this->out_port = "vents_out";
        this->out = "ventl";
        this->ta = inf;
        break;
}


// External Inputs


    if(this->in_port == "vents_in") {
        if(this->in == "venth"){
            switch (this->state.state) {
                case SHUT:
                this->state.state = OPENING;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "ventl"){
            switch (this->state.state) {
                case FULL_OPEN:
                this->state.state = CLOSING;
                this->ta = fin;
                break;
            }
        }
    }
