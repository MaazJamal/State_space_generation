//STATE DEFINITIONS

#define STOP 0
#define ON 1
#define PUMPING 2
#define OFF 3



 //PORTS 

struct pump_defs {
    struct w : public out_port<string> { };
    struct pw : public in_port<string> { };
};


//port deifinitions

    using input_ports = std::tuple<typename defs::pw>;
    using output_ports = std::tuple<typename defs::w>;

//INTERNAL TRANSITIONS

switch (this->state.state) {
    case OFF:
        this->state.state = STOP;
        this->out_port = "w";
        this->out = "wstop";
        this->ta = inf;
        break;
    case ON:
        this->state.state = PUMPING;
        this->out_port = "w";
        this->out = "wstrt";
        this->ta = inf;
        break;
}


// External Inputs


    if(this->in_port == "pw") {
        if(this->in == "on"){
            switch (this->state.state) {
                case STOP:
                this->state.state = ON;
                this->ta = fin;
                break;
            }
        }
        if(this->in == "off"){
            switch (this->state.state) {
                case PUMPING:
                this->state.state = OFF;
                this->ta = fin;
                break;
            }
        }
    }
