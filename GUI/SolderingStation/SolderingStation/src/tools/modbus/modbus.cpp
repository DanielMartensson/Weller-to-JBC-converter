#include "nanomodbus/nanomodbus.h"
#include "modbus.h"
#include "../usb/usb.h"

#define RTU_SERVER_ADDRESS 1

static nmbs_t nmbs_client;

int32_t read_serial(uint8_t data[], uint16_t size, int32_t timeout_ms, void* arg) {
    const char* port = (const char*)arg;
    return USB_readProcess(port, data, size, timeout_ms);
}

int32_t write_serial(const uint8_t data[], uint16_t size, int32_t timeout_ms, void* arg) {
    const char* port = (const char*)arg;
    return USB_writeProcess(port, data, size, timeout_ms);
}

void* arg_serial(const char port[]) {
    return (void*)port;
}

bool createModbusClient() {

    // Create platform configuration
    nmbs_platform_conf platform_conf;
    nmbs_platform_conf_create(&platform_conf);
    platform_conf.transport = NMBS_TRANSPORT_RTU;
    platform_conf.read = read_serial;
    platform_conf.write = write_serial;
    platform_conf.arg = arg_serial;

    // Create client
    nmbs_error err = nmbs_client_create(&nmbs_client, &platform_conf);
    if (err != NMBS_ERROR_NONE) {
        return false;
    }

    // Set time out
    nmbs_set_read_timeout(&nmbs_client, 1000);
    nmbs_set_byte_timeout(&nmbs_client, 100);

    // Set address
    nmbs_set_destination_rtu_address(&nmbs_client, RTU_SERVER_ADDRESS);

    // OK
    return true;
}

bool readHoldingRegister(const char port[], uint16_t address, uint16_t quantity, uint16_t registers[]) {
    // Pass the port name first
    arg_serial(port);

    // Then read
    nmbs_error err = nmbs_read_holding_registers(&nmbs_client, address, quantity, registers);
    return err == NMBS_ERROR_NONE ? true : false;
}

bool writeSingleRegister(const char port[], uint16_t address, uint16_t value) {
    // Pass the port name first
    arg_serial(port);

    // Then write
    nmbs_error err = nmbs_write_single_register(&nmbs_client, address, value);
    return err == NMBS_ERROR_NONE ? true : false;
}

bool writeMultipleRegisters(const char port[], uint16_t address, uint16_t quantity, const uint16_t registers[]) {
    // Pass the port name first
    arg_serial(port);

    // Then write
    nmbs_error err = nmbs_write_multiple_registers(&nmbs_client, address, quantity, registers);
    return err == NMBS_ERROR_NONE ? true : false;
}

bool readInputRegisters(const char port[], uint16_t address, uint16_t quantity, uint16_t registers[]) {
    // Pass the port name first
    arg_serial(port);

    // Then write
    nmbs_error err = nmbs_read_input_registers(&nmbs_client, address, quantity, registers);
    return err == NMBS_ERROR_NONE ? true : false;
}