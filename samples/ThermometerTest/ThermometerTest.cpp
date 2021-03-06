/*
The MIT License (MIT)

Copyright (c) 2016 Lancaster University.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MKR1300.h"

MKR1300 mkr1300;

void onHot(DeviceEvent)
{
    mkr1300.serial.printf("*** HOT ***\n");
}

void onCold(DeviceEvent)
{
    mkr1300.serial.printf("*** COLD ***\n");
}

int main()
{
    mkr1300.messageBus.listen(DEVICE_ID_THERMOMETER, ANALOG_THRESHOLD_HIGH, onHot);
    mkr1300.messageBus.listen(DEVICE_ID_THERMOMETER, ANALOG_THRESHOLD_LOW, onCold);

    mkr1300.thermometer.setLowThreshold(26);
    mkr1300.thermometer.setHighThreshold(29);

    while (1)
    {
        mkr1300.sleep(1000);
        mkr1300.serial.printf("TEMP: %d\n", (int) mkr1300.thermometer.getValue());
    }
}

