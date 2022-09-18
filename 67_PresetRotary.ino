void rotaryRight(int analogPin, int switchNumber, int fieldPlacement, int pos1, int pos2, int pos3, int pos4, int pos5, int pos6, int pos7, int pos8, int pos9, int pos10, int pos11, int pos12, bool reverse)
{
    int Pin = analogPin;
    int Pos1 = pos1;
    int Pos2 = pos2;
    int Pos3 = pos3;
    int Pos4 = pos4;
    int Pos5 = pos5;
    int Pos6 = pos6;
    int Pos7 = pos7;
    int Pos8 = pos8;
    int Pos9 = pos9;
    int Pos10 = pos10;
    int Pos11 = pos11;
    int Pos12 = pos12;

    bool Reverse = reverse;

    int N = switchNumber - 1;

    int Number = analogButtonNumber[N];
    int FieldPlacement = fieldPlacement;

    int maxPos = 12;


    int value = analogRead(Pin);

    int positions[12] = { Pos1, Pos2, Pos3, Pos4, Pos5, Pos6, Pos7, Pos8, Pos9, Pos10, Pos11, Pos12 };

    int differ = 0;
    int result = 0;
    for (int i = 0; i < 12; i++)
    {
        if (i == 0 || abs(positions[i] - value) < differ)
        {
            result++;
            differ = abs(positions[i] - value);
        }
    }

    result--;

    if (Reverse)
    {
        result = 11 - result;
    }

    //Short debouncer on switch rotation

    if (analogLastCounter[N] != result)
    {
        if (globalClock - analogTimer1[N] > analogPulse)
        {
            analogTimer1[N] = globalClock;
        }
        else if (globalClock - analogTimer1[N] > analogWait)
        {

            //----------------------------------------------
            //----------------MODE CHANGE-------------------
            //----------------------------------------------

            //Due to placement of this scope, mode change will only occur on switch rotation.
            //If you want to avoid switching mode, set fieldPlacement to 0.

            if (pushState[modButtonRow - 1][modButtonCol - 1] == 1)
            {
                for (int i = 0; i < maxPos + 1; i++) //Remove the remnants from SWITCH MODE 1
                {
                    Joystick.releaseButton(i - 1 + Number);
                }

                analogSwitchMode1[N] = !analogSwitchMode1[N]; //SWAP MODE
            }

            //Engage encoder pulse timer
            analogTimer2[N] = globalClock;

            //Update difference, storing the value in pushState on pin 2
            analogTempState[N] = result - analogLastCounter[N];

            //Give new value to pushState
            analogLastCounter[N] = result;

            if (pushState[presetButtonRow - 1][presetButtonCol - 1] == 1) //Standard
            {
                //Set the preset value
                switchPreset = result;

                //Push the preset value
                long push = 0;
                push = push | (switchPreset << 10);
                buttonField = buttonField | push;

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

                //-------HERE BEGINS ALL PRESETS THAT SET UP ONCE WHEN ENTERING A NEW PRESET------

                switch (switchPreset)
                {
                case 0: //LOAD PRESET 1
                    switchMode[5][2] = 1;
                    switchMode[6][1] = 1;
                    bitePoint = 265;
                    brakeMagicValue = 200;
                    break;
                case 1: //LOAD PRESET 2
                    bitePoint = 300;
                    break;
                case 2: //LOAD PRESET 3
                    bitePoint = 500;
                    break;
                case 3: //LOAD PRESET 4
                    bitePoint = 200;
                    switchMode[4][2] = 1;
                    break;
                case 4: //LOAD PRESET 5
                    break;
                case 5: //LOAD PRESET 6
                    break;
                case 6: //LOAD PRESET 7
                    break;
                case 7: //LOAD PRESET 8
                    break;
                case 8: //LOAD PRESET 9
                    break;
                case 9: //LOAD PRESET 10
                    break;
                case 10: //LOAD PRESET 11
                    break;
                case 11: //LOAD PRESET 12
                    break;
                }
            }
        }
    }

    //SWITCH MODE 1: 12 - position switch

    if (!analogSwitchMode1[N] && !biteButtonBit1 && !biteButtonBit2)
    {
        analogTempState[N] = 0; //Refreshing encoder mode difference

        for (int i = 0; i < 12; i++)
        {
            if (i == analogLastCounter[N])
            {
                Joystick.pressButton(i + Number);
            }
            else
            {
                Joystick.releaseButton(i + Number);
            }
        }
    }

    //SWITCH MODE 2: Incremental switch

    else if (analogSwitchMode1[N] && !biteButtonBit1 && !biteButtonBit2)
    {
        Number = analogButtonNumberIncMode[N];
        int difference = analogTempState[N];
        if (difference != 0)
        {
            if (globalClock - analogTimer2[N] < encoderPulse)
            {
                if ((difference > 0 && difference < 5) || difference < -5)
                {
                    Joystick.setButton(Number, 1);
                    Joystick.setButton(Number + 1, 0);
                }
                else
                {
                    Joystick.setButton(Number, 0);
                    Joystick.setButton(Number + 1, 1);
                }
            }
            else
            {
                analogTempState[N] = 0;
                Joystick.setButton(Number, 0);
                Joystick.setButton(Number + 1, 0);
            }
        }
    }

    //Push switch mode
    long push = 0;
    push = push | analogSwitchMode1[N];
    push = push << (2 * (FieldPlacement - 1));
    encoderField = encoderField | push;


}
