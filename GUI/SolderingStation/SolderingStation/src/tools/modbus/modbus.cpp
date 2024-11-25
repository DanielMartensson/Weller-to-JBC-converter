#include "nanomodbus/nanomodbus.h"
#include "../usb/usb.h"

void InitModbusRTU() {
    // Create platform configuration
    nmbs_platform_conf platform_conf;
    nmbs_platform_conf_create(&platform_conf);
    platform_conf.transport = NMBS_TRANSPORT_RTU;
    platform_conf.read = my_transport_read;
    platform_conf.write = my_transport_write;
    platform_conf.arg = conn;    // Passing our TCP connection handle to the read/write functions
}

bool ConnectModbus(const char port[]) {

    
}