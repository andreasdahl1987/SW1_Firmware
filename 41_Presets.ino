void presets(int8_t presetNumber)
{
    int8_t PresetNumber = presetNumber;

    //Clear all buttons
    for (int i = 0; i < BUTTONCOUNT; i++)
    {
        Joystick.setButton(i, 0);
    }

    //Clear all switch modes
    for (int i = 0; i < rowCount; i++)
    {
        for (int a = 0; a < colCount; a++)
        {
            switchMode[i][a] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        analogSwitchMode1[i] = 0;
        analogSwitchMode2[i] = 0;
    }

    //Default values set

    bitePoint = 300;
    brakeMagicValue = 50;
    throttleHold = 1000;
    leftQuickValue = 11;
    rightQuickValue = 11;

    //----------------------------------------
    //-----BUILD YOUR PRESETS HERE------------
    //----------------------------------------

    switch (presetNumber)
    {
        case 0: //PRESET 1 - iRacing PORSCHE 911 CUP CAR
            switchMode[5][2] = 1;
            switchMode[6][1] = 1;
            bitePoint = 265;
            brakeMagicValue = 200;
            break;
        case 1: //PRESET 2 - iRacing PORSCHE 911 GT3
            bitePoint = 300;
            break;
        case 2: //PRESET 3 - iRacing FERRARI 488 GT3
            bitePoint = 500;
            break;
        case 3: //PRESET 4 - iRacing MERCEDES AMG GT3
            bitePoint = 200;
            switchMode[4][2] = 1;
            break;
        case 4: //PRESET 5 - iRacing F3
            break;
        case 5: //PRESET 6 - iRacing F4
            break;
        case 6: //PRESET 7 - iRacing MERCEDES W12
            break;
        case 7: //PRESET 8 - iRacing RADICAL SR10
            break;
        case 8: //PRESET 9 - ACC MERCEDES AMG GT3
            break;
        case 9: //PRESET 10 - ACC LAMBORGHINI HURACAN
            break;
        case 10: //PRESET 11 - ACC FERRARI 488 GT3
            break;
        case 11: //PRESET 12 - F1 2022
            break;
    }
}
