void DDSfunky(int Arow, int Acol, int Bcol) {

    int Row = Arow - 1;
    int Column = Acol - 1;
    int Number = buttonNumber[Row][Column];
    if (latchState[ddButtonRow - 1][ddButtonCol - 1])
    {
        Number = Number + 12;
    }
    int FieldPlacement = 5;

    int bCol = Bcol - 1;

    //Reading switch mode
    toggleTimer[Row][bCol] = switchMode[Row][bCol] << 1 | switchMode[Row][Column];

    if (!rawState[Row][Column] && !rawState[Row][bCol])
    {
        pushState[Row][Column] = 1;
    }
    else if (!rawState[Row][Column] && rawState[Row][bCol])
    {
        pushState[Row][Column] = 2;
        latchLock[Row][Column] = 1; //Fetching 01
    }
    else if (rawState[Row][Column] && rawState[Row][bCol])
    {
        pushState[Row][Column] = 3;
    }
    else if (rawState[Row][Column] && !rawState[Row][bCol])
    {
        pushState[Row][Column] = 4;
        latchLock[Row][bCol] = 1; //Fetching 10
    }

    if ((globalClock - switchTimer[Row][Column] > funkyCooldown) && (globalClock - switchTimer[Row][bCol] > funkyCooldown))
    {
        if ((latchLock[Row][bCol] && pushState[Row][Column] == 1) || (latchLock[Row][Column] && pushState[Row][Column] == 3)) //CLOCKWIZE TURN
        {
            switchTimer[Row][Column] = globalClock;

            if (!toggleTimer[Row][bCol] == 1)
            {
                toggleTimer[Row][Column] --; //Counter for position switch
            }
            switchModeLock[Row][bCol] = !switchModeLock[Row][bCol]; //For MODE 4
            if (pushState[modButtonRow - 1][modButtonCol - 1] == 1) //MODE CHANGE
            {
                for (int i = 0; i < 24; i++) //Reset all buttons
                {
                    Joystick.releaseButton(i + buttonNumber[Row][Column]);
                }
                Joystick.releaseButton(buttonNumber[Row][bCol]);
                Joystick.releaseButton(1 + buttonNumber[Row][bCol]);
                latchLock[ddButtonRow - 1][ddButtonCol - 1] = false; //Reset DDButton
                latchState[ddButtonRow - 1][ddButtonCol - 1] = false;
                toggleTimer[Row][bCol] --; //Mode counter
                if (toggleTimer[Row][bCol] == 1) //Skipping closed DDS mode
                {
                    toggleTimer[Row][bCol] = 0;
                }
            }
        }

        else if ((latchLock[Row][bCol] && pushState[Row][Column] == 3) || (latchLock[Row][Column] && pushState[Row][Column] == 1)) //COUNTER CLOCKWIZE TURN
        {
            switchTimer[Row][bCol] = globalClock;

            if (!toggleTimer[Row][bCol] == 1)
            {
                toggleTimer[Row][Column] ++;
            }
            switchModeLock[Row][Column] = !switchModeLock[Row][Column]; //For MODE 4
            if (pushState[modButtonRow - 1][modButtonCol - 1] == 1) //MODE CHANGE
            {
                for (int i = 0; i < 24; i++) //Reset all buttons
                {
                    Joystick.releaseButton(i + buttonNumber[Row][Column]);
                }
                Joystick.releaseButton(buttonNumber[Row][bCol]);
                Joystick.releaseButton(1 + buttonNumber[Row][bCol]);
                latchLock[ddButtonRow - 1][ddButtonCol - 1] = false; //Reset DDButton
                latchState[ddButtonRow - 1][ddButtonCol - 1] = false;
                toggleTimer[Row][bCol] ++; //Mode counter
                if (toggleTimer[Row][bCol] == 1) //Skipping closed DDS mode
                {
                    toggleTimer[Row][bCol] = 2;
                }
            }
        }
    }
    else
    {
        latchLock[Row][bCol] = 0;
        latchLock[Row][Column] = 0;
    }

    //Keep the counters in place
    if (toggleTimer[Row][Column] > 11)
    {
        toggleTimer[Row][Column] = 0;
    }
    else if (toggleTimer[Row][Column] < 0)
    {
        toggleTimer[Row][Column] = 11;
    }
    if (toggleTimer[Row][bCol] > 3)
    {
        toggleTimer[Row][bCol] = 0;
        latchState[hybridButtonRow - 1][hybridButtonCol - 1] = 0; //Resetting hybrid button on entering this mode
    }
    else if (toggleTimer[Row][bCol] < 0)
    {
        toggleTimer[Row][bCol] = 3;
    }
    if (toggleTimer[Row][bCol] == 0 && latchState[hybridButtonRow - 1][hybridButtonCol - 1])
    {
        toggleTimer[Row][bCol] = 1;
    }
    else if (toggleTimer[Row][bCol] == 1 && !latchState[hybridButtonRow - 1][hybridButtonCol - 1])
    {
        toggleTimer[Row][bCol] = 0;
    }


    //MODE 1: DDS open
    if (toggleTimer[Row][bCol] == 0)
    {

        if (latchState[ddButtonRow - 1][ddButtonCol - 1])
        {
            for (int i = 0; i < 12; i++) //Remove the remnants from SWITCH MODE 1
            {
                Joystick.releaseButton(i + buttonNumber[Row][Column]);
            }
        }
        for (int i = 0; i < 24; i++)
        {
            if (i == toggleTimer[Row][Column])
            {
                Joystick.pressButton(i + Number);
            }
            else
            {
                Joystick.releaseButton(i + Number);
            }
        }
    }

    //MODE 2 / MODE 3: INCREMENTAL

    if ((toggleTimer[Row][bCol] == 1 || toggleTimer[Row][bCol] == 2) && !biteButtonBit1 && !biteButtonBit2)
    {
        Number = buttonNumber[Row][bCol];
        Joystick.setButton(Number, (globalClock - switchTimer[Row][Column] < funkyPulse));
        Joystick.setButton(Number + 1, (globalClock - switchTimer[Row][bCol] < funkyPulse));
    }

    //MODE 4: TOGGLE SWITCHES

    if (toggleTimer[Row][bCol] == 3)
    {
        Number = buttonNumber[Row][bCol];
        Joystick.setButton(Number, switchModeLock[Row][bCol]);
        Joystick.setButton(Number + 1, switchModeLock[Row][Column]);;
    }

    //Pushing switch mode

    switchMode[Row][Column] = (toggleTimer[Row][bCol] & B00000001);
    switchMode[Row][bCol] = (toggleTimer[Row][bCol] & B00000010) >> 1;

    int32_t push = 0;
    push = push | toggleTimer[Row][bCol];
    push = push << (2 * (FieldPlacement - 1));
    encoderField = encoderField | push;
}
