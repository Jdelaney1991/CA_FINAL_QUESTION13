#include "mbed.h"

// Include the header for PinNames
#include "PinNames.h"

DigitalOut myled(LED1);

// Use USBTX and USBRX for the onboard ST-LINK Virtual COM port
Serial pc(USBTX, USBRX);
// Use D1 and D0 for serial communication
Serial dev(D1, D0);

void dev_recv() {
    while (dev.readable()) {
        pc.putc(dev.getc());
    }
}

void pc_recv() {
    while (pc.readable()) {
        dev.putc(pc.getc());
    }
}

int main() {
    pc.baud(9600);
    dev.baud(115200);
    pc.attach(&pc_recv);
    dev.attach(&dev_recv);
    pc.printf("Hello!! \r\n");

    while (1) {
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
    }
}
